#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Sed {
	public:
		Sed(std::string const filename, std::string const s1, std::string const s2);
		~Sed(void);
		void processFile(void);
	private:
		std::string _fileName;
		std::string _s1;
		std::string _s2;
		std::ifstream _inputFile;
		std::ofstream _outFile;
};

#endif