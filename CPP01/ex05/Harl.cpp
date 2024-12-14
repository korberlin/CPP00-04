#include "Harl.hpp"

std::string toUpper(std::string& str) {
	std::string ret;
	for (size_t i = 0 ; i < str.length(); i++) {
		ret += std::toupper(str[i]);
	}
	return ret;
}

Harl::Harl() {

}

Harl::~Harl() {

}

void Harl::debug(void) const {
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-"
	<< "triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) const {
	std::cout << "INFO: I cannot believe adding extra bacon cost more money. "
	<< "You don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void) const {
	std::cout << "WARNING: I've been coming here for years and you just started"
	<< "working here last month." << std::endl;
}

void Harl::error(void) const {
	std::cout << "ERROR: This is unacceptable. I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) const {
	int complain = 0;
	std::string str = toUpper(level);
	void (Harl::*_funcs[4])() const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (str == levels[i]) {
			(this->* _funcs[i])();
			complain = 1;
		}
	}
	if (!complain)
		std::cout << "UNKNOWN: I have nothing to complain about." << std::endl;
}
