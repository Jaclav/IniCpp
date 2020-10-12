#include "Ini.hpp"

Ini::Ini() {

}

Ini::Ini(std::string n) {
    name = n;
}

Ini::~Ini() {
    file.close();
}

std::string Ini::getString(const std::string section, const std::string key, const std::string def) {
    file.open(name, std::ios::in);
    if(!file.good()) {
        return def;
    }

    std::string line;
    std::string value;
    std::string _key;

    while(std::getline(file, line)) { //reading line
        value = line.substr(line.find("[") + 1); //value is name of section

        if(value.substr(0, value.find("]")) != section) { //checking section
            continue;
        }

        while(std::getline(file, line)) { //reading line in section
            _key = line.substr(0, line.find("="));

            if(_key.find("[") == 0) { //if start of another section
                break;
            }

            if(_key != key) {
                continue;
            }

            value = line.substr(line.find("=") + 1, line.size());

            file.close();
            return value;
        }
    }
    file.close();
    return def;
}

int Ini::getInt(const std::string section, const std::string key, const int def) {
    try {
        return std::atoi(getString(section, key, std::to_string(def)).c_str());
    }
    catch(...) {
        std::cerr << "Error atoi threw an exception!\n";
        return def;
    }
}

bool Ini::getBool(const std::string section, const std::string key, const bool def) {
    return getString(section, key, std::to_string(def)) == "true" ? true : false;
}

void Ini::setName(const std::string n) {
    name = n;
}
