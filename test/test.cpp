#include <iostream>
#include "Ini.hpp"

int main(){
	Ini read("test.ini");
	std::cout << "Name = " << read.getString("user", "name", "UNKNOWN") << std::endl;
	std::cout << "Surname = " << read.getString("user", "surname", "UNKNOWN") << std::endl;
	std::cout << "email = " << read.getString("user", "email", "UNKNOWN@UNKNOWN") << std::endl;
	std::cout << "age = " << read.getInt("user", "age", -1) << std::endl;
	return 0;
}
