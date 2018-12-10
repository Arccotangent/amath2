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

#include "operator.h"
#include <ginac/ginac.h>
#include "../utils/number-helper.h"

#include "elementary/addition.h"
#include "elementary/subtraction.h"
#include "elementary/multiplication.h"
#include "elementary/division.h"
using namespace std;
using namespace GiNaC;

Operator::Operator(int argc, char *argv[]) {
	this->argc = argc;

	for (int i = 0; i < argc; i++) {
		this->argv.emplace_back(argv[i]);
	}
}

Operator::~Operator() = default;

Operator &Operator::getOperator(int argc, char *argv[]) {
	static Operator *instance = nullptr;

	if (instance == nullptr) {
		instance = new Operator(argc, argv);
	}

	return *instance;
}

Operation Operator::getOperation(string operation) {
	if (operation == "add")
		return Operation::ADDITION;
	else if (operation == "sub")
		return Operation::SUBTRACTION;
	else if (operation == "mul")
		return Operation::MULTIPLICATION;
	else if (operation == "div")
		return Operation::DIVISION;
	else
		return Operation::INVALID_OPERATION;
}

void Operator::evaluate() {
	Operation operation = getOperation(argv[1]);
	NumberHelper helper = NumberHelper::getNumberHelper(argc, argv);

	vector<ex> args = helper.process();

	int operationArgCount = argc - 2;

	switch (operation) {
		case Operation::ADDITION: {
			if (operationArgCount < 2) {
				cout << "ERROR: Invalid argument count! You supplied " << (argc - 2) << " arguments when we needed at least 2." << endl;
				break;
			}

			Addition addition = Addition::getInstance(args);
			double time = addition.evaluate();

			cout << "Addition complete in " << time << " us" << endl;
			cout << addition.getResult() << endl;
			break;
		}
		case Operation::SUBTRACTION: {
			if (operationArgCount < 2) {
				cout << "ERROR: Invalid argument count! You supplied " << (argc - 2) << " arguments when we needed at least 2." << endl;
				break;
			}

			Subtraction subtraction = Subtraction::getInstance(args);
			double time = subtraction.evaluate();

			cout << "Subtraction complete in " << time << " us" << endl;
			cout << subtraction.getResult() << endl;
			break;
		}
		case Operation::MULTIPLICATION: {
			if (operationArgCount < 2) {
				cout << "ERROR: Invalid argument count! You supplied " << (argc - 2) << " arguments when we needed at least 2." << endl;
				break;
			}

			Multiplication multiplication = Multiplication::getInstance(args);
			double time = multiplication.evaluate();

			cout << "Multiplication complete in " << time << " us" << endl;
			cout << multiplication.getResult() << endl;
			break;
		}
		case Operation::DIVISION: {
			if (operationArgCount < 2) {
				cout << "ERROR: Invalid argument count! You supplied " << (argc - 2) << " arguments when we needed at least 2." << endl;
				break;
			}

			Division division = Division::getInstance(args);
			double time = division.evaluate();

			cout << "Division complete in " << time << " us" << endl;
			cout << division.getResult() << endl;
			break;
		}
		case INVALID_OPERATION: {
			cout << "ERROR: You have specified an invalid operation! Please run amath2 with no arguments to print usage documentation if needed." << endl;
			break;
		}
	}
}
