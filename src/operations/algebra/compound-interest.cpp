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

#include "compound-interest.h"
#include <chrono>

using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using namespace GiNaC;

CompoundInterest::CompoundInterest(vector<ex> args) {
	this->args = move(args);
}

CompoundInterest &CompoundInterest::getInstance(vector<ex> args) {
	static CompoundInterest *instance = nullptr;

	if (instance == nullptr) {
		instance = new CompoundInterest(move(args));
	}

	return *instance;
}

double CompoundInterest::evaluate() {
	auto start = high_resolution_clock::now();

	// args[0] = P
	// args[1] = r
	// args[2] = n
	// args[3] = t

	result = (args[0] * (pow(1 + ((args[1] / 100) / args[2]), args[2] * args[3]))).evalf();

	auto end = high_resolution_clock::now();
	auto elapsed = end - start;

	return (double) duration_cast<microseconds>(elapsed).count();
}

ex CompoundInterest::getResult() {
	return this->result;
}
