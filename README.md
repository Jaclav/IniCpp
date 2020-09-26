# IniCpp
.INI parser written in C++
So far, only reads

# Example in C++
```cpp
#include "Ini.hpp"

int main(){
	Ini read("test.ini");
	std::cout << "Name = " << ini.getString("user", "name", "UNKNOWN") << std::endl;
	std::cout << "Surname = " << ini.getString("user", "surname", "UNKNOWN") << std::endl;
	std::cout << "email = " << ini.getString("user", "email", "UNKNOWN@UNKNOWN") << std::endl;
	std::cout << "age = " << ini.getInt("user", "age", -1) << std::endl;
	return 0;
}
