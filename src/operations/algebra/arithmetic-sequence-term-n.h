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

#ifndef AMATH2_ARITHMETIC_SEQUENCE_H
#define AMATH2_ARITHMETIC_SEQUENCE_H

#include <vector>
#include <ginac/ginac.h>

class ArithmeticSequenceTermN {
private:
	std::vector<GiNaC::ex> args;
	GiNaC::ex result;

	explicit ArithmeticSequenceTermN(std::vector<GiNaC::ex>);

public:
	static ArithmeticSequenceTermN &getInstance(std::vector<GiNaC::ex>);

	double evaluate();

	GiNaC::ex getResult();
};


#endif //AMATH2_ARITHMETIC_SEQUENCE_H
