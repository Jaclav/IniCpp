#include <iostream>
#include "Ini.hpp"

int main() {
    Ini iniFile("test.ini");
	iniFile.writeString("user", "name", "John");
	iniFile.writeString("user", "surname", "Smith");
	iniFile.writeString("user", "email", "john.smith@example.com");
	iniFile.writeInt("user", "age", 32);

    std::cout << "name = " << iniFile.readString("user", "name", "UNKNOWN") << std::endl;
    std::cout << "surname = " << iniFile.readString("user", "surname", "UNKNOWN") << std::endl;
    std::cout << "email = " << iniFile.readString("user", "email", "UNKNOWN@UNKNOWN") << std::endl;
    std::cout << "age = " << iniFile.readInt("user", "age", -1) << std::endl;
    return 0;
}
