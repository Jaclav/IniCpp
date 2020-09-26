#include "Ini.hpp"

std::string getIniString(const std::string section, const std::string key, const std::string def, const std::string name) {

	std::fstream file(name, std::ios::in);
	std::string line;
	std::string value;
	std::string _key;

	while(std::getline(file, line)) { //reading line
		std::stringstream is_line(line);

		std::getline(is_line, _key, '[');//read into start of another section
		std::getline(is_line, value);

		if(value.substr(0, value.find("]")) != section) { //checking section
			continue;
		}

		while(std::getline(file, line)) { //reading line in section
			std::istringstream is_line(line);
			std::getline(is_line, _key, '=');

			if(_key.find("[") == 0) { //if start of another section
				break;
			}

			if(_key != key) {
				continue;
			}

			std::getline(is_line, value);
			return value;
		}
	}
	return def;
}

int getIniInt(const std::string section, const std::string key, const int def, const std::string name) {
	return std::atoi(getIniString(section, key, std::to_string(def), name).c_str());
}

int getIniBool(const std::string section, const std::string key, const bool def, const std::string name) {
	return getIniString(section, key, std::to_string(def), name) == "true" ? true : false;
}

