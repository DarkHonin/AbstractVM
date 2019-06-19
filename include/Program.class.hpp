#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <regex>
#include "IOperand.class.hpp"

#include <vector>

class Program{
	static const std::regex command_regex;
	public:
		Program(std::istream &);
		Program(Program &);
		~Program();

		bool next();

	private:
		std::istream & _in;
		std::vector<IOperand> _stack;
};

#endif