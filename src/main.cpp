
#include <iostream>
#include "Program.class.hpp"
#include <iostream>
#include <istream>
#include <fstream>

int main(int ac, char ** av){
	Program r;
	if(ac == 2){
		std::ifstream f = std::ifstream(av[1]);
		if(!r.readProgram(f)) return -1;
	}else
		if(!r.readProgram(std::cin)) return -1;
	
	r.runProgram();
	return 0;
}