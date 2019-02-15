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
#include "../utils/number-helper.h"
#include <ginac/ginac.h>
#include <map>
#include <boost/assign/list_of.hpp>

#include "elementary/addition.h"
#include "elementary/subtraction.h"
#include "elementary/multiplication.h"
#include "elementary/division.h"
#include "elementary/modulus.h"
#include "elementary/exponentiation.h"
#include "elementary/square-root.h"
#include "elementary/factorial.h"
#include "elementary/factor.h"
#include "elementary/number-factor.h"
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
#include "algebra/arithmetic-sequence-term-n.h"
#include "algebra/arithmetic-sequence-sum.h"
#include "algebra/combination.h"
#include "algebra/permutation.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using boost::assign::map_list_of;
using namespace GiNaC;

Operator::Operator(string operation, vector<string> argv) {
	this->oper = move(operation);
	this->argv = move(argv);
}

Operator::~Operator() = default;

Operator &Operator::getOperator(string operation, vector<string> argv) {
	static Operator *instance = nullptr;

	if (instance == nullptr) {
		instance = new Operator(move(operation), move(argv));
	}

	return *instance;
}

Operation Operator::getOperation(const string &operation) {
	map<string, Operation> operations = map_list_of
			("add", ADDITION)
			("sub", SUBTRACTION)
			("mul", MULTIPLICATION)
			("div", DIVISION)
			("mod", MODULUS)
			("pow", EXPONENTIATION)
			("sqrt", SQUARE_ROOT)
			("fct", FACTORIAL)
			("fac", FACTOR)
			("nfac", NUMBER_FACTOR)
			("gcd", GREATEST_COMMON_DENOMINATOR)
			("lcm", LEAST_COMMON_MULTIPLE)
			("qdr", SOLVE_QUADRATIC)
			("cbc", SOLVE_CUBIC)
			("log", NATURAL_LOGARITHM)
			("log10", BASE_10_LOGARITHM)
			("log2", BINARY_LOGARITHM)
			("logb", CUSTOM_BASE_LOGARITHM)
			("cpi", COMPOUND_INTEREST)
			("ccpi", CONTINUOUS_COMPOUND_INTEREST)
			("st", ARITHMETIC_SEQUENCE_TERM_N)
			("ss", ARITHMETIC_SEQUENCE_SUM)
			("ncr", COMBINATION)
			("npr", PERMUTATION);

	return operations[operation];
}

void Operator::evaluate() {
	Operation operation = getOperation(this->oper);
	NumberHelper helper = NumberHelper::getNumberHelper(argv);

	vector<ex> args = helper.process();

	int operationArgCount = argv.size();

	switch (operation) {
		case ADDITION: {
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
		case SUBTRACTION: {
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
		case MULTIPLICATION: {
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
		case DIVISION: {
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
		case MODULUS: {
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
		case EXPONENTIATION: {
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
		case SQUARE_ROOT: {
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
		case FACTORIAL: {
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
		case FACTOR: {
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
		case NUMBER_FACTOR: {
			if (operationArgCount != 1) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 1." << endl;
				break;
			}

			NumberFactor numberFactor = NumberFactor::getInstance(args);
			double time = numberFactor.evaluate();

			cout << "Factorization complete in " << time << " us" << endl;
			cout << numberFactor.getResult() << endl;
			break;
		}
		case GREATEST_COMMON_DENOMINATOR: {
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
		case LEAST_COMMON_MULTIPLE: {
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
		case SOLVE_QUADRATIC: {
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
		case SOLVE_CUBIC: {
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
		case NATURAL_LOGARITHM: {
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
		case BASE_10_LOGARITHM: {
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
		case BINARY_LOGARITHM: {
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
		case CUSTOM_BASE_LOGARITHM: {
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
		case COMPOUND_INTEREST: {
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
		case CONTINUOUS_COMPOUND_INTEREST: {
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
		case ARITHMETIC_SEQUENCE_TERM_N: {
			if (operationArgCount != 3) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 3." << endl;
				break;
			}

			ArithmeticSequenceTermN arithmeticSequenceTermN = ArithmeticSequenceTermN::getInstance(args);
			double time = arithmeticSequenceTermN.evaluate();

			cout << "Arithmetic sequence term N calculated in " << time << " us" << endl;
			cout << arithmeticSequenceTermN.getResult() << endl;
			break;
		}
		case ARITHMETIC_SEQUENCE_SUM: {
			if (operationArgCount != 3) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 3." << endl;
				break;
			}

			ArithmeticSequenceSum arithmeticSequenceSum = ArithmeticSequenceSum::getInstance(args);
			double time = arithmeticSequenceSum.evaluate();

			cout << "Arithmetic sequence sum calculated in " << time << " us" << endl;
			cout << arithmeticSequenceSum.getResult() << endl;
			break;
		}
		case COMBINATION: {
			if (operationArgCount != 2) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 2." << endl;
				break;
			}

			Combination combination = Combination::getInstance(args);
			double time = combination.evaluate();

			cout << "Combination calculated in " << time << " us" << endl;
			cout << combination.getResult() << endl;
			break;
		}
		case PERMUTATION: {
			if (operationArgCount != 2) {
				cout << "ERROR: Invalid argument count! You supplied " << operationArgCount << " arguments when we needed 2." << endl;
				break;
			}

			Permutation permutation = Permutation::getInstance(args);
			double time = permutation.evaluate();

			cout << "Permutation calculated in " << time << " us" << endl;
			cout << permutation.getResult() << endl;
			break;
		}
		case INVALID_OPERATION: {
			cout << "ERROR: You have specified an invalid operation! Please run amath2 with no arguments to print usage documentation if needed." << endl;
			break;
		}
	}
}
