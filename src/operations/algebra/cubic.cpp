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

#include "cubic.h"
#include <chrono>

using namespace std;
using namespace GiNaC;

Cubic::Cubic(vector<ex> args) {
	this->args = move(args);
}

Cubic &Cubic::getInstance(std::vector<GiNaC::ex> args) {
	static Cubic *instance = nullptr;

	if (instance == nullptr) {
		instance = new Cubic(move(args));
	}

	return *instance;
}

double Cubic::evaluate() {
	auto start = chrono::high_resolution_clock::now();

	ex discriminant = (18 * args[0] * args[1] * args[2] * args[3]) - (4 * pow(args[1], 3) * args[3]) + (pow(args[1], 2) * pow(args[2], 2)) - (4 * args[0] * pow(args[2], 3)) - (27 * pow(args[0], 2) * pow(args[2], 2));

	ex delta0 = (pow(args[1], 2)) - (3 * args[0] * args[2]);

	if (discriminant == 0 && delta0 == 0) {
		ex tripleRoot = -args[1] / (3 * args[0]);
		x1 = tripleRoot;
		x2 = tripleRoot;
		x3 = tripleRoot;

		auto end = chrono::high_resolution_clock::now();
		auto elapsed = end - start;
		return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
	} else if (discriminant == 0 && delta0 != 0) {
		ex doubleRoot = (9 * args[0] * args[3] - args[1] * args[2]) / (2 * delta0);
		x1 = doubleRoot;
		x2 = doubleRoot;

		x3 = ((4 * args[0] * args[1] * args[2]) - (9 * pow(args[0], 2) * args[3]) - pow(args[1], 3)) / (args[0] * delta0);

		auto end = chrono::high_resolution_clock::now();
		auto elapsed = end - start;
		return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
	}

	ex delta1 = (2 * pow(args[1], 3)) - (9 * args[0] * args[1] * args[2]) + (27 * pow(args[0], 2) * args[3]);

	ex CNumerTerm2 = sqrt(pow(delta1, 2) - (4 * pow(delta0, 3)));

	bool addSign = true;
	if (delta0 == 0) {
		ex CNumerTest = delta1 + CNumerTerm2;
		if (CNumerTest == 0)
			addSign = false;
	}

	ex CNumer = addSign ? delta1 + CNumerTerm2 : delta1 - CNumerTerm2;
	ex C = pow(CNumer / 2, 1/3);

	if (C == 0) {
		cout << "ERROR: C = 0, discriminant != 0, and delta0 != 0!" << endl;
		x1 = 0;
		x2 = 0;
		x3 = 0;

		auto end = chrono::high_resolution_clock::now();
		auto elapsed = end - start;
		return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
	}

	ex cubeRootOfUnity = -0.5 + (0.5 * sqrt(ex(-3)));
	ex neg1Over3A = -1 / (3 * args[0]);

	x1 = neg1Over3A * (args[1] + (pow(cubeRootOfUnity, 0) * C) + (delta0 / (pow(cubeRootOfUnity, 0) * C)));
	x2 = neg1Over3A * (args[1] + (pow(cubeRootOfUnity, 1) * C) + (delta0 / (pow(cubeRootOfUnity, 1) * C)));
	x3 = neg1Over3A * (args[1] + (pow(cubeRootOfUnity, 2) * C) + (delta0 / (pow(cubeRootOfUnity, 2) * C)));

	auto end = chrono::high_resolution_clock::now();
	auto elapsed = end - start;
	return (double) chrono::duration_cast<chrono::microseconds>(elapsed).count();
}

ex Cubic::getX1() {
	return this->x1;
}

ex Cubic::getX2() {
	return this->x2;
}

ex Cubic::getX3() {
	return this->x3;
}

