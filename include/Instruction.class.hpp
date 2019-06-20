#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <vector>
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

class Instruction{
	public:
		class InvalidInstruction : public std::exception{};
		Instruction(std::string param = "");
		Instruction(Instruction &cp);
		~Instruction();

		static Instruction *createInstruction(std::string op, std::string param);
		
		virtual bool execute(std::vector<IOperand const *> &s) = 0;
		const std::string _paramString;
};

class Push : public Instruction{
	public:
		static const std::regex paramRegex;
		static const std::string opperandIndex[5];
		static const OperandFactory factory;

		Push(std::string param = "");
		~Push();
		bool execute(std::vector<IOperand const *> &s);
};

class Dump : public Instruction{
	public:
		Dump(std::string param = "");
		~Dump();
		bool execute(std::vector<IOperand const *> &s);
};

class Sum : public Instruction{
	public:
		Sum(std::string param = "");
		~Sum();
		bool execute(std::vector<IOperand const *> &s);
};

#endif