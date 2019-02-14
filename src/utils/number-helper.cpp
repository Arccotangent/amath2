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

#include "number-helper.h"
#include <map>
#include <boost/assign/list_of.hpp>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::map;
using boost::assign::map_list_of;
using namespace GiNaC;

NumberHelper::NumberHelper(int argc, vector<string> argv) {
	this->argc = argc;
	this->argv = move(argv);
}

NumberHelper::~NumberHelper() = default;

NumberHelper& NumberHelper::getNumberHelper(int argc, vector<string> argv) {
	static NumberHelper *instance = nullptr;

	if (instance == nullptr) {
		instance = new NumberHelper(argc, move(argv));
	}

	return *instance;
}

Constant NumberHelper::getConstant(string arg) {
	map<string, Constant> constants = map_list_of
			("e", E)
			("pi", PI)
			("y", EULER_MASCHERONI_CONSTANT);

	return constants[move(arg)];
}

ex NumberHelper::getConstantValue(Constant constant) {
	switch (constant) {
		case E: {
			ex prev;
			ex curr = 1;

			ex currentDenominator = 1;

			do {
				prev = curr;
				curr += 1 / factorial(currentDenominator);

				currentDenominator++;
			} while (curr - prev >= pow(10, -30));

			return evalf(curr);
		}
		case PI: {
			return evalf(GiNaC::Pi);
		}
		case EULER_MASCHERONI_CONSTANT: {
			return evalf(GiNaC::Euler);
		}
		default: {
			return ex(0.0);
		}
	}
}

vector<ex> NumberHelper::process() {
	vector<ex> args;

	for (int i = 2; i < argc; i++) {
		try {
			parser reader;
			ex expression;
			Constant constant = getConstant(argv[i]);

			if (constant == INVALID_CONSTANT)
				expression = reader(argv[i]);
			else
				expression = getConstantValue(constant);

			args.emplace_back(expression);
		} catch (parse_error &error) {
			cout << "ERROR: Exception caught in parsing: " << error.what() << endl;
		}
	}

	return args;
}
