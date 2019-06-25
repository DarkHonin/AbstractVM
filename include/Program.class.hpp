#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <regex>
#include "IOperand.class.hpp"
#include "Instruction.class.hpp"
#include <exception>
#include <vector>
#include "ProgramE.class.hpp"

class Program{
	public:
		static const ProgramException ValueOverflow;
		static const ProgramException ValueUnderflow;
		static const ProgramException StackOverflow;
		static const ProgramException StackUnderflow;
		static const ProgramException ExpectedOperhand;
		static const ProgramException AssertFailed;

		Program();
		Program(Program &);
		~Program();

		bool readProgram(std::istream &in);
		bool readProgram(std::ifstream &in);
		bool runProgram();
		void handleNext(std::string line);

	private:
		std::vector<IOperand const *> _stack;
		std::vector<std::pair<instruction, IOperand const *>*> op;
		Instructions lexigon;
};

#endif