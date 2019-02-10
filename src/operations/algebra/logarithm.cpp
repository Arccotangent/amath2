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

#include "logarithm.h"
#include <chrono>

using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using namespace GiNaC;

Logarithm::Logarithm(vector<ex> args) {
	this->args = move(args);
}

Logarithm &Logarithm::getInstance(vector<ex> args) {
	static Logarithm *instance = nullptr;

	if (instance == nullptr) {
		instance = new Logarithm(move(args));
	}

	return *instance;
}

double Logarithm::evaluate() {
	auto start = high_resolution_clock::now();

	result = log(args[0]);

	auto end = high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) duration_cast<microseconds>(elapsed).count();
}

ex Logarithm::getResult() {
	return this->result;
}
