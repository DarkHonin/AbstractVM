#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <regex>
#include "IOperand.class.hpp"
#include <exception>
#include <vector>

class Program{
	static const std::regex command_regex;
	public:

		
		class ValueOverflow : public std::exception{};
		class ValueUnderflow : public std::exception{};
		class StackOverflow : public std::exception{};
		class StackUnderflow : public std::exception{};
		

		Program(std::istream &);
		Program(Program &);
		~Program();

		bool next();

	private:
		std::istream & _in;
		std::vector<IOperand const *> _stack;
};

#endif