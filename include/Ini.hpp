#ifndef GETINI_HPP
#define GETINI_HPP

#include <iostream>
#include <fstream>
#include <sstream>

std::string getIniString(const std::string section, const std::string key, const std::string def, const std::string name);
int getIniInt(const std::string section, const std::string key, const int def, const std::string name);
int getIniBool(const std::string section, const std::string key, const bool def, const std::string name);

#endif // GETINI_HPP
