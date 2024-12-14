#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		Sed newSed(argv[1], argv[2], argv[3]);
		return 0;
	}
	else {
		std::cout << "This program takes 3 arguments: Filename, s1 and s2." << std::endl;
		return 2;  
	}
}