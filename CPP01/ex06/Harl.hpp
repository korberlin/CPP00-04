#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

enum Level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string& levelStr) const;
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;
		Level getLevelEnum(std::string& levelStr) const;
};

std::string toUpper(std::string const str);

#endif