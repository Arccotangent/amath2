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

#include <fstream>
#include <ginac/ginac.h>
#include <iostream>
#include <map>
#include <cstring>
#include <boost/assign/list_of.hpp>
#include "configuration.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::vector;
using std::map;
using boost::assign::map_list_of;
using namespace GiNaC;

Configuration::Configuration(string file) {
	this->file = move(file);
	this->precision = Digits;
}

vector<string> Configuration::splitConfigLine(const string &line) {
	size_t begin = 0, end = line.find('=');

	vector<string> parts;

	while (end != string::npos) {
		parts.emplace_back(line.substr(begin, end - begin));
		begin = end + 1;
		end = line.find(',');
	}

	parts.emplace_back(line.substr(begin, end));
	return parts;
}

Configuration &Configuration::getConfig(string file) {
	static Configuration *config = nullptr;

	if (config == nullptr) {
		config = new Configuration(move(file));
	}

	return *config;
}

void Configuration::parseConfig() {
	ifstream configStream(file);

	if (!configStream.good()) {
		cout << "WARNING: Could not read configuration file." << endl;
		return;
	}

	map<string, ConfigurationKey> configKeys = map_list_of
			("precision", PRECISION);

	while (configStream.good()) {
		string configLine;
		getline(configStream, configLine);

		vector<string> lineParts = splitConfigLine(configLine);

		switch (configKeys[lineParts[0]]) {
			case PRECISION: {
				precision = strtoul(lineParts[1].c_str(), nullptr, 10);
				break;
			}
			default: {
				cout << "WARNING: Invalid key found in config: " << lineParts[0] << ", ignoring it." << endl;
				break;
			}
		}
	}
}

void Configuration::applyConfig() {
	Digits = precision;
}
