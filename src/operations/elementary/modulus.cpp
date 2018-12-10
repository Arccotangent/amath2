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

#include "modulus.h"
#include <chrono>

using namespace std;
using namespace GiNaC;

Modulus::Modulus(vector<ex> args) {
	this->args = move(args);
}

Modulus &Modulus::getInstance(vector<ex> args) {
	static Modulus *instance = nullptr;

	if (instance == nullptr) {
		instance = new Modulus(move(args));
	}

	return *instance;
}

double Modulus::evaluate() {
	auto start = chrono::high_resolution_clock::now();
	this->result = mod(args[0].integer_content(), args[1].integer_content());

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
}

ex Modulus::getResult() {
	return this->result;
}
