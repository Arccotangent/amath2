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

#include "factor.h"
#include <chrono>

using namespace std;
using namespace GiNaC;

Factor::Factor(vector<ex> args) {
	this->args = move(args);
}

Factor &Factor::getInstance(std::vector<GiNaC::ex> args) {
	static Factor *instance = nullptr;

	if (instance == nullptr) {
		instance = new Factor(move(args));
	}

	return *instance;
}

double Factor::evaluate() {
	auto start = chrono::high_resolution_clock::now();
	this->result = factor(args[0], factor_options::all);

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
}

ex Factor::getResult() {
	return this->result;
}
