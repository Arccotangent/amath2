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

#include "multiplication.h"
#include <chrono>

using namespace std;
using namespace GiNaC;

Multiplication::Multiplication(vector<ex> args) {
	this->args = move(args);
}

Multiplication &Multiplication::getInstance(vector<ex> args) {
	static Multiplication *instance = nullptr;

	if (instance == nullptr) {
		instance = new Multiplication(move(args));
	}

	return *instance;
}

double Multiplication::evaluate() {
	auto start = chrono::high_resolution_clock::now();
	this->result = 1;

	for (const ex &argument : args) {
		this->result *= argument;
	}

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
}

ex Multiplication::getResult() {
	return this->result;
}