#include "Ini.hpp"

Ini::Ini(){

}

Ini::Ini(std::string n){
	name = n;
}

Ini::~Ini(){
	file.close();
}

std::string Ini::getString(const std::string section, const std::string key, const std::string def) {
	file.open(name, std::ios::in);
	if(!file.good()){
		return def;
	}

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
			file.close();
			return value;
		}
	}
	file.close();
	return def;
}

int Ini::getInt(const std::string section, const std::string key, const int def) {
	try{
		return std::atoi(getString(section, key, std::to_string(def)).c_str());
	}
	catch(...){
		std::cerr<<"Error atoi threw an exception!\n";
		return def;
	}
}

bool Ini::getBool(const std::string section, const std::string key, const bool def) {
	return getString(section, key, std::to_string(def)) == "true" ? true : false;
}

void Ini::setName(const std::string n){
	name = n;
}
