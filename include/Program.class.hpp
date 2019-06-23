#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <regex>
#include "IOperand.class.hpp"
#include "Instruction.class.hpp"
#include <exception>
#include <vector>

class Program{
	public:
		class ValueOverflow : public std::exception{};
		class ValueUnderflow : public std::exception{};
		class StackOverflow : public std::exception{};
		class StackUnderflow : public std::exception{};
		class ExpectedOpperhand : public std::exception{};

		Program();
		Program(Program &);
		~Program();

		bool readProgram(std::istream &in);
		bool readProgram(std::ifstream &in);
		bool runProgram();

	private:
		std::vector<IOperand const *> _stack;
		std::vector<std::pair<instruction, IOperand const *>*> op;
		Instructions lexigon;
};

#endif