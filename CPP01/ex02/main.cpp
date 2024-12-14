#include <string>
#include <iostream>

int main(void) {

	std::string str = "HI THIS IS BRAIN";
	std::string& stringREF = str;
	std::string* stringPTR = &str;

	std::cout << "Memory address of string variable is: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR is:  " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF is:  " << &stringREF << std::endl;

	std::cout << "Value of the string variable is:  " << str << std::endl;
	std::cout << "Value pointed to by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF is: " << stringREF << std::endl;

}
