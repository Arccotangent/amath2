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

#include "subtraction.h"
#include <chrono>

using namespace std;
using namespace GiNaC;

Subtraction::Subtraction(vector<ex> args) {
	this->args = move(args);
}

Subtraction &Subtraction::getInstance(vector<ex> args) {
	static Subtraction *instance = nullptr;

	if (instance == nullptr) {
		instance = new Subtraction(move(args));
	}

	return *instance;
}

double Subtraction::evaluate() {
	auto start = chrono::high_resolution_clock::now();
	this->result = args[0];

	for (int i = 1; i < args.size(); i++) {
		this->result -= args[i];
	}

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
}

ex Subtraction::getResult() {
	return this->result;
}
