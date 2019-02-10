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
#include "elementary/modulus.h"
#include "elementary/exponentiation.h"
#include "elementary/square-root.h"
#include "elementary/factorial.h"
#include "elementary/factor.h"
#include "elementary/gcd.h"
#include "elementary/lcm.h"

#include "algebra/quadratic.h"
#include "algebra/cubic.h"
#include "algebra/logarithm.h"
#include "algebra/base-10-logarithm.h"
#include "algebra/binary-logarithm.h"
#include "algebra/custom-base-logarithm.h"
#include "algebra/compound-interest.h"
#include "algebra/continuous-compound-interest.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
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

Operation Operator::getOperation(const string &operation) {
	if (operation == "add")
		return Operation::ADDITION;
	else if (operation == "sub")
		return Operation::SUBTRACTION;
	else if (operation == "mul")
		return Operation::MULTIPLICATION;
	else if (operation == "div")
		return Operation::DIVISION;
	else if (operation == "mod")
		return Operation::MODULUS;
	else if (operation == "pow")
		return Operation::EXPONENTIATION;
	else if (operation == "sqrt")
		return Operation::SQUARE_ROOT;
	else if (operation == "fct")
		return Operation::FACTORIAL;
	else if (operation == "fac")
		return Operation::FACTOR;
	else if (operation == "gcd")
		return Operation::GREATEST_COMMON_DENOMINATOR;
	else if (operation == "lcm")
		return Operation::LEAST_COMMON_MULTIPLE;
	else if (operation == "qdr")
		return Operation::SOLVE_QUADRATIC;
	else if (operation == "cbc")
		return Operation::SOLVE_CUBIC;
	else if (operation == "log")
		return Operation::NATURAL_LOGARITHM;
	else if (operation == "log10")
		return Operation::BASE_10_LOGARITHM;
	else if (operation == "log2")
		return Operation::BINARY_LOGARITHM;
	else if (operation == "logb")
		return Operation::CUSTOM_BASE_LOGARITHM;
	else if (operation == "cpi")
		return Operation::COMPOUND_INTEREST;
	else if (operation == "ccpi")
		return Operation::CONTINUOUS_COMPOUND_INTEREST;
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
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed at least 2." << endl;
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
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed at least 2." << endl;
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
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed at least 2." << endl;
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
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed at least 2." << endl;
				break;
			}

			Division division = Division::getInstance(args);
			double time = division.evaluate();

			cout << "Division complete in " << time << " us" << endl;
			cout << division.getResult() << endl;
			break;
		}
		case Operation::MODULUS: {
			if (operationArgCount != 2) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 2." << endl;
				break;
			}

			Modulus modulus = Modulus::getInstance(args);
			double time = modulus.evaluate();

			cout << "Modulus calculation complete in " << time << " us" << endl;
			cout << modulus.getResult() << endl;
			break;
		}
		case Operation::EXPONENTIATION: {
			if (operationArgCount != 2) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 2." << endl;
				break;
			}

			Exponentiation exponentiation = Exponentiation::getInstance(args);
			double time = exponentiation.evaluate();

			cout << "Exponentiation complete in " << time << " us" << endl;
			cout << exponentiation.getResult() << endl;
			break;
		}
		case Operation::SQUARE_ROOT: {
			if (operationArgCount != 1) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 1." << endl;
				break;
			}

			SquareRoot squareRoot = SquareRoot::getInstance(args);
			double time = squareRoot.evaluate();

			cout << "Square root calculation complete in " << time << " us" << endl;
			cout << squareRoot.getResult() << endl;
			break;
		}
		case Operation::FACTORIAL: {
			if (operationArgCount != 1) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 1." << endl;
				break;
			}

			Factorial factorial = Factorial::getInstance(args);
			double time = factorial.evaluate();

			cout << "Factorial calculation complete in " << time << " us" << endl;
			cout << factorial.getResult() << endl;
			break;
		}
		case Operation::FACTOR: {
			if (operationArgCount != 1) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 1." << endl;
				break;
			}

			Factor factor = Factor::getInstance(args);
			double time = factor.evaluate();

			cout << "Factorization complete in " << time << " us" << endl;
			cout << factor.getResult() << endl;
			break;
		}
		case Operation::GREATEST_COMMON_DENOMINATOR: {
			if (operationArgCount < 2) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed at least 2." << endl;
				break;
			}

			GCD gcd = GCD::getInstance(args);
			double time = gcd.evaluate();

			cout << "GCD calculation complete in " << time << " us" << endl;
			cout << gcd.getResult() << endl;
			break;
		}
		case Operation::LEAST_COMMON_MULTIPLE: {
			if (operationArgCount < 2) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed at least 2." << endl;
				break;
			}

			LCM lcm = LCM::getInstance(args);
			double time = lcm.evaluate();

			cout << "LCM calculation complete in " << time << " us" << endl;
			cout << lcm.getResult() << endl;
			break;
		}
		case Operation::SOLVE_QUADRATIC: {
			if (operationArgCount != 3) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 3." << endl;
				break;
			}

			Quadratic quadratic = Quadratic::getInstance(args);
			double time = quadratic.evaluate();

			cout << "Quadratic equation solved in " << time << " us" << endl;
			cout << quadratic.getX1() << endl;
			cout << quadratic.getX2() << endl;
			break;
		}
		case Operation::SOLVE_CUBIC: {
			if (operationArgCount != 4) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 4." << endl;
				break;
			}

			Cubic cubic = Cubic::getInstance(args);
			double time = cubic.evaluate();

			cout << "Cubic equation solved in " << time << " us" << endl;
			cout << cubic.getX1() << endl;
			cout << cubic.getX2() << endl;
			cout << cubic.getX3() << endl;
			break;
		}
		case Operation::NATURAL_LOGARITHM: {
			if (operationArgCount != 1) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 1." << endl;
				break;
			}

			Logarithm logarithm = Logarithm::getInstance(args);
			double time = logarithm.evaluate();

			cout << "Logarithm calculated in " << time << " us" << endl;
			cout << logarithm.getResult() << endl;
			break;
		}
		case Operation::BASE_10_LOGARITHM: {
			if (operationArgCount != 1) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 1." << endl;
				break;
			}

			Base10Logarithm base10Logarithm = Base10Logarithm::getInstance(args);
			double time = base10Logarithm.evaluate();

			cout << "Base 10 logarithm calculated in " << time << " us" << endl;
			cout << base10Logarithm.getResult() << endl;
			break;
		}
		case Operation::BINARY_LOGARITHM: {
			if (operationArgCount != 1) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 1." << endl;
				break;
			}

			BinaryLogarithm binaryLogarithm = BinaryLogarithm::getInstance(args);
			double time = binaryLogarithm.evaluate();

			cout << "Binary logarithm calculated in " << time << " us" << endl;
			cout << binaryLogarithm.getResult() << endl;
			break;
		}
		case Operation::CUSTOM_BASE_LOGARITHM: {
			if (operationArgCount != 2) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 2." << endl;
				break;
			}

			CustomBaseLogarithm customBaseLogarithm = CustomBaseLogarithm::getInstance(args);
			double time = customBaseLogarithm.evaluate();

			cout << "Custom base logarithm calculated in " << time << " us" << endl;
			cout << customBaseLogarithm.getResult() << endl;
			break;
		}
		case Operation::COMPOUND_INTEREST: {
			if (operationArgCount != 4) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 4." << endl;
				break;
			}

			CompoundInterest compoundInterest = CompoundInterest::getInstance(args);
			double time = compoundInterest.evaluate();

			cout << "Compound interest calculated in " << time << " us" << endl;
			cout << compoundInterest.getResult() << endl;
			break;
		}
		case Operation::CONTINUOUS_COMPOUND_INTEREST: {
			if (operationArgCount != 3) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 3." << endl;
				break;
			}

			ContinuousCompoundInterest continuousCompoundInterest = ContinuousCompoundInterest::getInstance(args);
			double time = continuousCompoundInterest.evaluate();

			cout << "Continuous compound interest calculated in " << time << " us" << endl;
			cout << continuousCompoundInterest.getResult() << endl;
			break;
		}
		case Operation::INVALID_OPERATION: {
			cout << "ERROR: You have specified an invalid operation! Please run amath2 with no arguments to print usage documentation if needed." << endl;
			break;
		}
	}
}
