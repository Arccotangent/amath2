/*
This file is part of amath2.

amath2 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

amath2 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with amath2.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "number-factor.h"
#include <chrono>

using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using namespace GiNaC;

NumberFactor::NumberFactor(vector<ex> args) {
	this->args = move(args);
}

NumberFactor &NumberFactor::getInstance(vector<ex> args) {
	static NumberFactor *instance = nullptr;

	if (instance == nullptr) {
		instance = new NumberFactor(move(args));
	}

	return *instance;
}

double NumberFactor::evaluate() {
	auto start = high_resolution_clock::now();

	while (mod(args[0].integer_content(), 2) == 0) {
		args[0] /= 2;
		result.emplace_back(2);
	}

	for (ex i = 3; i < sqrt(args[0].integer_content()); i += 2) {
		while (mod(args[0].integer_content(), i.integer_content()) == 0) {
			args[0] /= i;
			result.emplace_back(i);
		}
	}

	if (args[0] != 1)
		result.emplace_back(args[0]);

	auto end = high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) duration_cast<microseconds>(elapsed).count();
}

vector<ex> NumberFactor::getResult() {
	return this->result;
}