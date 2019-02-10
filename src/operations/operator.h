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
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,
	MODULUS,
	EXPONENTIATION,
	SQUARE_ROOT,
	FACTORIAL,
	FACTOR,
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

	INVALID_OPERATION
};

class Operator {
private:
	int argc;
	std::vector<std::string> argv;

	Operator(int argc, char* argv[]);

	Operation getOperation(const std::string &operation);

public:
	~Operator();
	static Operator &getOperator(int argc, char* argv[]);

	void evaluate();
};


#endif //AMATH2_OPERATOR_H
