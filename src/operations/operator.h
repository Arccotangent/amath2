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

#ifndef AMATH2_OPERATOR_H
#define AMATH2_OPERATOR_H

#include <iostream>
#include <vector>

enum Operation {
	INVALID_OPERATION,

	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,
	MODULUS,
	EXPONENTIATION,
	SQUARE_ROOT,
	FACTORIAL,
	FACTOR,
	NUMBER_FACTOR,
	GREATEST_COMMON_DENOMINATOR,
	LEAST_COMMON_MULTIPLE,

	SOLVE_QUADRATIC,
	SOLVE_CUBIC,
	NATURAL_LOGARITHM,
	BASE_10_LOGARITHM,
	BINARY_LOGARITHM,
	CUSTOM_BASE_LOGARITHM,
	COMPOUND_INTEREST,
	CONTINUOUS_COMPOUND_INTEREST,
	ARITHMETIC_SEQUENCE_TERM_N,
	ARITHMETIC_SEQUENCE_SUM,
	COMBINATION,
	PERMUTATION
};

class Operator {
private:
	std::string oper;
	std::vector<std::string> argv;

	Operator(std::string operation, std::vector<std::string> argv);

	static Operation getOperation(const std::string &operation);

public:
	~Operator();

	static Operator &getOperator(std::string operation, std::vector<std::string> argv);

	void evaluate();
};


#endif //AMATH2_OPERATOR_H
