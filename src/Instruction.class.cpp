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

void Push::execute(std::vector<IOperand> &s){
	std::smatch match;
	std::regex_match(_paramString, match, this->paramRegex);
	int t;
	if(match.size() < 3) throw "Heck"; // Coming soon
	for(t = 0; t < 5; t++)
		if(match[1].str() == this->opperandIndex[t]) break;
	std::cout << this->factory.createOperand((eOperandType) t, match[2])->toString() << std::endl;
	std::cout << "It works" << t << std::endl;
}

/* * * * * * * * * * * *\
|		Push End	 	|
\* * * * * * * * * * * */

/* * * * * * * * * * * *\
|		Dump Start	 	|
\* * * * * * * * * * * */

Dump::Dump(std::string par) : Instruction(par){}
Dump::~Dump(){}

void Dump::execute(std::vector<IOperand> &s){
	for(std::vector<IOperand>::iterator e = s.begin(); e != s.end(); e++)
		std::cout << e->toString() << std::endl;
}

/* * * * * * * * * * * *\
|		End Start	 	|
\* * * * * * * * * * * */