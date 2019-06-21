#include "Instruction.class.hpp"
#include <iostream>
#include "OperandFactory.class.hpp"

/* * * * * * * * * * * *\
|	Instruction Start 	|
\* * * * * * * * * * * */

Instruction *Instruction::createInstruction(std::string op, std::string param){
	if(op == "push")
		return new Push(param);
	if(op == "dump")
		return new Dump();
	if(op == "sum")
		return new Sum();
	if(op == "sub")
		return new Sub();
	if(op == "mul")
		return new Mul();
	if(op == "div")
		return new Div();

	throw Instruction::InvalidInstruction();
}


Instruction::Instruction(std::string par) : _paramString(par){}
Instruction::Instruction(Instruction & cp) : Instruction(cp._paramString){}
Instruction::~Instruction(){}

/* * * * * * * * * * * *\
|	Instruction End 	|
\* * * * * * * * * * * */

/* * * * * * * * * * * *\
|		Push Start	 	|
\* * * * * * * * * * * */

const std::regex Push::paramRegex = std::regex("^(\\w+)\\((.+)\\)$", std::regex_constants::ECMAScript | std::regex_constants::icase);
const std::string Push::opperandIndex[5] = {"int8", "int16", "int32", "float", "double"};
const OperandFactory Push::factory = OperandFactory();

Push::Push(std::string par) : Instruction(par){}
Push::~Push(){}

bool Push::execute(std::vector<IOperand const *> &s){
	std::smatch match;
	std::regex_match(_paramString, match, this->paramRegex);
	int t;
	if(match.size() != 3) throw OperandFactory::InvalidOperand();
	for(t = 0; t < 5; t++)
		if(match[1].str() == this->opperandIndex[t]) break;
	if(t == 5) throw OperandFactory::InvalidOperand();
	IOperand const *i = this->factory.createOperand((eOperandType) t, match[2]);
	s.push_back(i);
	return true;
}

/* * * * * * * * * * * *\
|		Push End	 	|
\* * * * * * * * * * * */

/* * * * * * * * * * * *\
|		Dump Start	 	|
\* * * * * * * * * * * */

Dump::Dump(std::string par) : Instruction(par){}
Dump::~Dump(){}

bool Dump::execute(std::vector<IOperand const *> &s){
	for(std::vector<IOperand const *>::iterator e = s.begin(); e != s.end(); e++)
		std::cout << (*e)->toString() << std::endl;
	return true;
}

/* * * * * * * * * * * *\
|		Dump End	 	|
\* * * * * * * * * * * */

/* * * * * * * * * * * *\
|		Sum Start	 	|
\* * * * * * * * * * * */

Sum::Sum(std::string par) : Instruction(par){}
Sum::~Sum(){}

bool Sum::execute(std::vector<IOperand const *> &s){
	IOperand const *a = *(s.end() - 1);
	IOperand const *b = *(s.end() - 2);
	IOperand const *c = *a + *b;
	s.pop_back();
	s.pop_back();
	s.push_back(c);
	return true;
}

/* * * * * * * * * * * *\
|		Sum Start	 	|
\* * * * * * * * * * * */

/* * * * * * * * * * * *\
|		Sub Start	 	|
\* * * * * * * * * * * */

Sub::Sub(std::string par) : Instruction(par){}
Sub::~Sub(){}

bool Sub::execute(std::vector<IOperand const *> &s){
	IOperand const *a = *(s.end() - 1);
	IOperand const *b = *(s.end() - 2);
	IOperand const *c = *a - *b;
	s.pop_back();
	s.pop_back();
	s.push_back(c);
	return true;
}

/* * * * * * * * * * * *\
|		Sub Start	 	|
\* * * * * * * * * * * */

/* * * * * * * * * * * *\
|		Mul Start	 	|
\* * * * * * * * * * * */

Mul::Mul(std::string par) : Instruction(par){}
Mul::~Mul(){}

bool Mul::execute(std::vector<IOperand const *> &s){
	IOperand const *a = *(s.end() - 1);
	IOperand const *b = *(s.end() - 2);
	IOperand const *c = *a * *b;
	s.pop_back();
	s.pop_back();
	s.push_back(c);
	return true;
}

/* * * * * * * * * * * *\
|		Mul Start	 	|
\* * * * * * * * * * * */

/* * * * * * * * * * * *\
|		Div Start	 	|
\* * * * * * * * * * * */

Div::Div(std::string par) : Instruction(par){}
Div::~Div(){}

bool Div::execute(std::vector<IOperand const *> &s){
	IOperand const *a = *(s.end() - 1);
	IOperand const *b = *(s.end() - 2);
	IOperand const *c = *a / *b;
	s.pop_back();
	s.pop_back();
	s.push_back(c);
	return true;
}

/* * * * * * * * * * * *\
|		Div Start	 	|
\* * * * * * * * * * * */



