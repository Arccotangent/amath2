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

#include "quadratic.h"
#include <chrono>

using namespace std;
using namespace GiNaC;

Quadratic::Quadratic(vector<ex> args) {
	this->args = move(args);
}

Quadratic &Quadratic::getInstance(std::vector<GiNaC::ex> args) {
	static Quadratic *instance = nullptr;

	if (instance == nullptr) {
		instance = new Quadratic(move(args));
	}

	return *instance;
}

double Quadratic::evaluate() {
	auto start = chrono::high_resolution_clock::now();

	ex discriminant = pow(args[1], 2) - 4 * args[0] * args[2];

	x1 = (-args[1] + discriminant) / (2 * args[0]);
	x2 = (-args[1] - discriminant) / (2 * args[0]);

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
}

ex Quadratic::getX1() {
	return this->x1;
}

ex Quadratic::getX2() {
	return this->x2;
}