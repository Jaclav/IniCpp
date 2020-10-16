#include <iostream>
#include "Ini.hpp"

int main() {
    Ini iniFile("test.ini");
    std::cout << "name = " << iniFile.readString("user", "name", "UNKNOWN") << std::endl;
    std::cout << "surname = " << iniFile.readString("user", "surname", "UNKNOWN") << std::endl;
    std::cout << "email = " << iniFile.readString("user", "email", "UNKNOWN@UNKNOWN") << std::endl;
    std::cout << "age = " << iniFile.readInt("user", "age", -1) << std::endl;

    iniFile.writeString("user", "age", "16");
    std::cout << "age = " << iniFile.readInt("user", "age", -1) << std::endl;
	iniFile.writeString("user", "age", "32");
    return 0;
}
