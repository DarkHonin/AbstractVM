#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <map>
#include "IOperand.class.hpp"
#include "OperandFactory.class.hpp"
#include <regex>


/*
	Instructions:
		push PARAM
		assert PARAM
		pop
		dump
		add
		sub
		mul
		div
		mod
		print
		exit
 */

typedef bool (*instruction)(std::vector<IOperand const *> &, IOperand const *);
class Instructions{
	public:
		class InvalidInstruction : public std::exception{};
		class InvalidValue : public std::exception{};
		class InvalidOperhand : public std::exception{};

		Instructions();
		Instructions(Instructions const &cp);
		~Instructions();

		void regesterInstruction(std::string keyword, instruction action);

		std::pair<instruction, IOperand const *> *parseLine(std::string line);
		
		private:
			std::map<std::string, instruction> entries;

};

#endif