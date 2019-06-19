#include "Instruction.class.hpp"
#include <iostream>
#include "OperandFactory.class.hpp"

/* * * * * * * * * * * *\
|	Instruction Start 	|
\* * * * * * * * * * * */

Instruction *Instruction::createInstruction(std::string op, std::string param){
	std::cout << "Instruction op: " << op << std::endl;
	if(op == "push")
		return new Push(param);
	if(op == "dump")
		return new Dump();

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

const std::regex Push::paramRegex = std::regex("^(\\w+)\\((\\d+)\\)$", std::regex_constants::ECMAScript | std::regex_constants::icase);
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
|		End Start	 	|
\* * * * * * * * * * * */