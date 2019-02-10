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

#include "continuous-compound-interest.h"
#include <chrono>

//using std::cout;
//using std::endl;
using std::vector;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using namespace GiNaC;

ContinuousCompoundInterest::ContinuousCompoundInterest(vector<ex> args) {
	this->args = move(args);
}

ex ContinuousCompoundInterest::getE() {
	ex prev;
	ex curr = 1;

	ex currentDenominator = 1;

	do {
		prev = curr;
		curr += 1 / factorial(currentDenominator);

		currentDenominator++;
	} while (curr - prev >= pow(10, -30));

	return curr;
}

ContinuousCompoundInterest &ContinuousCompoundInterest::getInstance(vector<ex> args) {
	static ContinuousCompoundInterest *instance = nullptr;

	if (instance == nullptr) {
		instance = new ContinuousCompoundInterest(move(args));
	}

	return *instance;
}

double ContinuousCompoundInterest::evaluate() {
	auto start = high_resolution_clock::now();

	// args[0] = P
	// args[1] = r
	// args[2] = t

	ex e = getE();
	//cout << "[DEBUG] e = " << e.evalf() << endl;

	result = (args[0] * pow(e, (args[1] / 100) * args[2])).evalf();

	auto end = high_resolution_clock::now();
	auto elapsed = end - start;

	return (double) duration_cast<microseconds>(elapsed).count();
}

ex ContinuousCompoundInterest::getResult() {
	return this->result;
}
