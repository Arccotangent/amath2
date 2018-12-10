/*
amath2 - Yet another new and improved command line calculator
Copyright (C) 2018-present Arccotangent

amath2 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses.
*/

#include <iostream>
#include "main.h"
#include "operations/operator.h"
using namespace std;

void printUsage() {
	cout << "amath2 - Yet another new improved command line calculator by Arccotangent" << endl
	<< endl
	<< "-----Elementary Math-----" << endl
	<< "add <numbers> - Add numbers or polynomials" << endl
	<< "sub <numbers> - Subtract numbers or polynomials" << endl
	<< "mul <numbers> - Multiply numbers or polynomials" << endl
	<< "div <numbers> - Divide numbers or polynomials" << endl
	<< "mod <2 numbers> - Get the modulus of 2 numbers" << endl
	<< "pow <base> <exponent> - Calculate an exponent" << endl
	<< "sqrt <number> - Calculate a square root (approximated)" << endl;
}

int main(int argc, char* argv[]) {
	if (argc < 3) {
		printUsage();
		return 1;
	}

	cout << "This is amath2 " << VERSION << endl;
	cout << "Selected operation: " << argv[1] << endl;

	Operator &oper = Operator::getOperator(argc, argv);
	oper.evaluate();

	return 0;
}
