#include <iostream>

#include "Ini.hpp"

int main() {
	Ini ini("test.ini");
	std::cout << ini.getInt("test", "a", 404) << std::endl;
	std::cout << ini.getString("aaa", "b", "Nothing") << std::endl;
	std::cout << ini.getBool("bbb", "a", false) << std::endl;
	return 0;
}
