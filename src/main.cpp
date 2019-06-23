
#include <iostream>
#include "Program.class.hpp"
#include <iostream>
#include <istream>
#include <fstream>

int main(int ac, char ** av){
	Program r;
	if(ac == 2){
		std::ifstream f = std::ifstream(av[1]);
		r.readProgram(f);
	}else
		r.readProgram(std::cin);
	r.runProgram();
	return 0;
}