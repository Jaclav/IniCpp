#ifndef GETINI_HPP
#define GETINI_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Ini {
public:
    Ini();
    Ini(const std::string name);

    ~Ini();

    void setName(const std::string name);

    std::string readString(const std::string section, const std::string key, const std::string def);
    int readInt(const std::string section, const std::string key, const int def);
    bool readBool(const std::string section, const std::string key, const bool def);

    char writeString(const std::string section, const std::string key, const std::string value);
    /*
     * This function raturns:
     * 0  - ok
     * -1 - file not found
     * 1  - section not found
     * 2  - key not found
     * */

private:
    std::string name;
    std::fstream file;
    std::vector<std::string> loaded;
};

#endif // GETINI_HPP
