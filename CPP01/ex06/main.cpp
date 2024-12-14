#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Harl usage: ./HARL_FILTER level(DEBUG, INFO, WARNING, ERROR,)" << std::endl;
		return 1;
	}
	else {
		Harl harl;
		std::string str = toUpper(argv[1]);
		harl.complain(str);
	}
	return 0;
}