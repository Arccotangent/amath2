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

#ifndef AMATH2_CONFIGURATION_H
#define AMATH2_CONFIGURATION_H

#include <iostream>
#include <vector>

enum ConfigurationKey {
	INVALID_KEY,

	PRECISION
};

class Configuration {
private:
	std::string file;
	unsigned int precision;

	explicit Configuration(std::string file);

	static std::vector<std::string> splitConfigLine(const std::string &line);

public:
	static Configuration &getConfig(std::string file);

	void parseConfig();

	void applyConfig();
};


#endif //AMATH2_CONFIGURATION_H
