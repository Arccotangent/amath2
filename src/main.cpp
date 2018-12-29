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
	cout << "amath2 - Yet another new and improved command line calculator by Arccotangent" << endl
	<< "Copyright (C) 2018-present Arccotangent" << endl
	<< endl
	<< "This program is free software: you can redistribute it and/or modify" << endl
	<< "it under the terms of the GNU General Public License as published by" << endl
	<< "the Free Software Foundation, either version 3 of the License, or" << endl
	<< "any later version." << endl
	<< endl
	<< "This program is distributed in the hope that it will be useful," << endl
	<< "but WITHOUT ANY WARRANTY; without even the implied warranty of" << endl
	<< "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the" << endl
	<< "GNU General Public License for more details." << endl
	<< endl
	<< "You should have received a copy of the GNU General Public License" << endl
	<< "along with this program. If not, see http://www.gnu.org/licenses." << endl
	<< endl
	<< "-----Elementary Math-----" << endl
	<< "add <numbers/polynomials> - Add numbers or polynomials" << endl
	<< "sub <numbers/polynomials> - Subtract numbers or polynomials" << endl
	<< "mul <numbers/polynomials> - Multiply numbers or polynomials" << endl
	<< "div <numbers/polynomials> - Divide numbers or polynomials" << endl
	<< "mod <2 numbers> - Get the modulus of 2 numbers" << endl
	<< "pow <base> <exponent> - Calculate an exponent" << endl
	<< "sqrt <number/polynomial> - Calculate a square root (approximated)" << endl
	<< "fct <number> - Calculate the factorial value of an integer" << endl
	<< "fac <polynomial> - Factor a polynomial" << endl
	<< "gcd <numbers> - Find the GCD (greatest common denominator) of 2 or more numbers" << endl
	<< "lcm <numbers> - Find the LCM (least common multiple) of 2 or more numbers" << endl
	<< endl
	<< "-----Algebra-----" << endl
	<< "qdr <a> <b> <c> - Solve a univariate quadratic (degree 2) polynomial set equal to 0 for x" << endl
	<< "cbc <a> <b> <c> <d> - Solve a univariate cubic (degree 3) polynomial set equal to 0 for x" << endl;
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
