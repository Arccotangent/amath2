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

#ifndef AMATH2_NUMBER_HELPER_H
#define AMATH2_NUMBER_HELPER_H

#include <vector>
#include <ginac/ginac.h>
#include <iostream>
#include <vector>

enum Constant {
	INVALID_CONSTANT,

	E,
	PI,
	EULER_MASCHERONI_CONSTANT
};

class NumberHelper {
private:
	std::vector<std::string> argv;

	explicit NumberHelper(std::vector<std::string> argv);

public:
	~NumberHelper();

	static NumberHelper &getNumberHelper(std::vector<std::string> argv);

	static Constant getConstant(std::string arg);

	static GiNaC::ex getConstantValue(Constant constant);

	std::vector<GiNaC::ex> process();
};


#endif //AMATH2_NUMBER_HELPER_H
