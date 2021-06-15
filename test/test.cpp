#include <iostream>
#include "Ini.hpp"

int main() {
    Ini iniFile("test.ini");
    iniFile.writeString("user", "name", "John");
    iniFile.writeString("user", "surname", "Smith");
    iniFile.writeString("user", "email", "john.smith@example.com");
    iniFile.writeInt("user", "age", 32);

    iniFile.writeString("user2", "name", "Mark");
    iniFile.writeString("user2", "surname", "Adams");
    iniFile.writeString("user2", "email", "mark.adams@example.com");
    iniFile.writeInt("user2", "age", 44);


    std::cout << "name = " << iniFile.readString("user", "name", "UNKNOWN") << std::endl;
    std::cout << "surname = " << iniFile.readString("user", "surname", "UNKNOWN") << std::endl;
    std::cout << "email = " << iniFile.readString("user", "email", "UNKNOWN@UNKNOWN") << std::endl;
    std::cout << "age = " << iniFile.readInt("user", "age", -1) << std::endl;

    std::cout << "name = " << iniFile.readString("user2", "name", "UNKNOWN") << std::endl;
    std::cout << "surname = " << iniFile.readString("user2", "surname", "UNKNOWN") << std::endl;
    std::cout << "email = " << iniFile.readString("user2", "email", "UNKNOWN@UNKNOWN") << std::endl;
    std::cout << "age = " << iniFile.readInt("user2", "age", -1) << std::endl;

    std::cout << "Sections number = " << iniFile.getNumberOfSections() << std::endl;
    return 0;
}
