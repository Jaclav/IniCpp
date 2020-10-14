#include <iostream>
#include "Ini.hpp"

int main() {
    Ini iniFile("test.ini");
    std::cout << "Name = " << iniFile.readString("user", "name", "UNKNOWN") << std::endl;
    std::cout << "Surname = " << iniFile.readString("user", "surname", "UNKNOWN") << std::endl;
    std::cout << "email = " << iniFile.readString("user", "email", "UNKNOWN@UNKNOWN") << std::endl;
    std::cout << "age = " << iniFile.readInt("user", "age", -1) << std::endl;

    iniFile.writeString("user", "age", "32");
    std::cout << "age = " << iniFile.readInt("user", "age", -1) << std::endl;
    return 0;
}
