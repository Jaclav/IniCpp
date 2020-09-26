#ifndef GETINI_HPP
#define GETINI_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Ini{
public:
	Ini();
	Ini(const std::string n);

	~Ini();

	std::string getString(const std::string section, const std::string key, const std::string def);
	int getInt(const std::string section, const std::string key, const int def);
	bool getBool(const std::string section, const std::string key, const bool def);

	void setName(const std::string n);

private:
	std::string name;
	std::fstream file;
};

#endif // GETINI_HPP
