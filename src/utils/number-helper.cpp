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

using std::vector;
using std::string;
using std::cout;
using std::endl;
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

vector<ex> NumberHelper::process() {
	vector<ex> args;

	for (int i = 2; i < argc; i++) {
		try {
			parser reader;
			ex expression = reader(argv[i]);
			args.emplace_back(expression);
		} catch (parse_error &error) {
			cout << "ERROR: Exception caught in parsing: " << error.what() << endl;
		}
	}

	return args;
}
