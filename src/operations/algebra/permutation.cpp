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

#include "permutation.h"
#include <chrono>

using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using namespace GiNaC;

Permutation::Permutation(vector<ex> args) {
	this->args = move(args);
}

Permutation &Permutation::getInstance(vector<ex> args) {
	static Permutation *instance = nullptr;

	if (instance == nullptr) {
		instance = new Permutation(move(args));
	}

	return *instance;
}

double Permutation::evaluate() {
	auto start = high_resolution_clock::now();

	result = factorial(args[0]) / factorial(args[0] - args[1]);

	auto end = high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) duration_cast<microseconds>(elapsed).count();
}

ex Permutation::getResult() {
	return this->result;
}
