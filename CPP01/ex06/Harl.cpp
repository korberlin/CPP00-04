#include "Harl.hpp"

std::string toUpper(std::string const str) {
	std::string ret;
	for (size_t i = 0; i < str.length(); i++)
		ret += std::toupper(str[i]);
	return ret;
}

Harl::Harl(void) {

}

Harl::~Harl(void) {

}

Level Harl::getLevelEnum(std::string& levelStr) const {
	std::string ret = toUpper(levelStr);
	if (ret == "DEBUG")
		return DEBUG;
	else if (ret == "INFO")
		return INFO;
	else if (ret == "WARNING")
		return WARNING;
	else if (ret == "ERROR")
		return ERROR;
	else
		return UNKNOWN;
}

void Harl::debug(void) const {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-"
	<< "triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) const {
	std::cout << "[INFO]" << std::endl;
	std::cout << "INFO: I cannot believe adding extra bacon cost more money. "
	<< "You don't put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void) const {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "WARNING: I've been coming here for years and you just started"
	<< "working here last month." << std::endl;
}

void Harl::error(void) const {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "ERROR: This is unacceptable. I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string& levelStr) const {
	Level level = getLevelEnum(levelStr);
	switch (level) {
		case DEBUG:
			debug();
			// fall through
		case INFO:
			info();
			// fall through
		case WARNING:
			warning();
			// fall through
		case ERROR:
			error();
			break;
		default:
			std::cout << "[UNKNOWN]" << std::endl;
			std::cout << "I have nothing to complain about." << std::endl;
	}
}

