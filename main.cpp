#include <iostream>

#include "Ini.hpp"

int main() {
	std::cout << getIniInt("test", "a", 1, "ini.ini") << std::endl;
	std::cout << getIniString("aaa", "b", "Nothing", "ini.ini") << std::endl;
	std::cout << getIniBool("bbb", "a", false, "ini.ini") << std::endl;
	return 0;
}
