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

class NumberHelper {
private:
	int argc;
	std::vector<std::string> argv;

	NumberHelper(int argc, std::vector<std::string> argv);
public:
	~NumberHelper();
	static NumberHelper &getNumberHelper(int argc, std::vector<std::string> argv);

	std::vector<GiNaC::ex> process();
};


#endif //AMATH2_NUMBER_HELPER_H
