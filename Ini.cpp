#include "Ini.hpp"

Ini::Ini() {

}

Ini::Ini(const std::string name) {
    Ini::name = name;
}

Ini::~Ini() {
    file.close();
}

void Ini::setName(const std::string name) {
    Ini::name = name;
}

std::string Ini::readString(const std::string section, const std::string key, const std::string def) {
    file.open(name, std::ios::in);
    if(!file.good()) {
        return def;
    }

    std::string line;
    std::string value;
    std::string currentKey;

    while(std::getline(file, line)) { //reading line
        value = line.substr(line.find("[") + 1); //value is name of section

        if(value.substr(0, value.find("]")) != section) { //checking section
            continue;
        }

        while(std::getline(file, line)) { //reading line in section
            currentKey = line.substr(0, line.find("="));

            if(currentKey.find("[") == 0) { //if start of another section
                break;
            }

            if(currentKey != key) {
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

int Ini::readInt(const std::string section, const std::string key, const int def) {
    try {
        return std::atoi(readString(section, key, std::to_string(def)).c_str());
    }
    catch(...) {
        std::cerr << "Error atoi threw an exception!\n";
        return def;
    }
}

bool Ini::readBool(const std::string section, const std::string key, const bool def) {
    return readString(section, key, std::to_string(def)) == "true" ? true : false;
}

bool Ini::writeString(const std::string section, const std::string key, const std::string value) {
    //TODO now works only if key alredy exists, and change him
    file.open(name, std::ios::in);
    if(!file.good()) {
        return -1;
    }

    //loading file into memory
    std::string tmp;
    while(getline(file, tmp)) {
        loaded.push_back(tmp);
    }

    for(unsigned int i = 0; i < loaded.size(); i++) {//search section
        if(loaded[i].size() > 3 && loaded[i][0] == '[' && loaded[i].substr(1, loaded[i].size() - 2) == section) {//if in good section
            while(loaded[i][0] != '[' || i < loaded.size()) { //search key
                i++;
                if(loaded[i].substr(0, loaded[i].find("=")) == key) { //if good key
                    loaded[i] = loaded[i].substr(0, loaded[i].find("=")) + "=" + value;
                    break;
                }
            }
            break;
        }
    }

    file.close();
    remove(name.c_str());
    file.open(name, std::ios::out);

    for(unsigned int i = 0; i < loaded.size(); i++) {
        file << loaded[i] << '\n';
    }

    file.close();
    return 0;
}
