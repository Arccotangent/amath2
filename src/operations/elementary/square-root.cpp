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

#include "square-root.h"
#include <chrono>

using namespace std;
using namespace GiNaC;

SquareRoot::SquareRoot(vector<ex> args) {
	this->args = move(args);
}

SquareRoot &SquareRoot::getInstance(std::vector<GiNaC::ex> args) {
	static SquareRoot *instance = nullptr;

	if (instance == nullptr) {
		instance = new SquareRoot(move(args));
	}

	return *instance;
}

double SquareRoot::evaluate() {
	auto start = chrono::high_resolution_clock::now();
	this->result = evalf(sqrt(args[0]));

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
}

ex SquareRoot::getResult() {
	return this->result;
}
