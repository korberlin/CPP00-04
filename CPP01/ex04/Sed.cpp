#include "Sed.hpp"

Sed::Sed(std::string const filename, std::string const s1, std::string const s2):_fileName(filename), _s1(s1), _s2(s2) {
	if (_s1 == _s2) {
		std::cerr << "s1 and s2 strings are the same." << std::endl;
		std::exit(1);
	}
	if (_s1.empty() || _s2.empty()) {
		std::cerr << "s1 or s2 is empty." << std::endl;
		std::exit(1);
	}
	_inputFile.open(_fileName.c_str());
	if (!_inputFile.is_open()) {
		std::cerr << "Cannot open file" << std::endl;
		std::exit(1);
	}
	_outFile.open((_fileName + ".replace").c_str());
	if (!_outFile.is_open()) {
		std::cerr << "Cannot open and create output file" << std::endl;
		std::exit(1);
	}
	processFile();
 
}

Sed::~Sed(void) {
	if (_inputFile.is_open())
		_inputFile.close();
	if (_outFile.is_open())
		_outFile.close();		
}

void Sed::processFile(void)
{
	std::string line;
	while (std::getline(_inputFile, line)) {
		std::string newLine;
		size_t pos = 0;
		size_t found;
		while ((found = line.find(_s1, pos)) != std::string::npos) {
			newLine.append(line, pos, found - pos);
			newLine.append(_s2);
			pos = found + _s1.length();
		}
		newLine.append(line, pos, line.length() - pos);
		_outFile << newLine << std::endl;
	}
}
