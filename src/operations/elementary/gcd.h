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

#ifndef AMATH2_GCD_H
#define AMATH2_GCD_H

#include <vector>
#include <ginac/ginac.h>

class GCD {
private:
	std::vector<GiNaC::ex> args;
	GiNaC::ex result;

	explicit GCD(std::vector<GiNaC::ex>);

public:
	static GCD &getInstance(std::vector<GiNaC::ex>);

	double evaluate();
	GiNaC::ex getResult();
};


#endif //AMATH2_GCD_H
