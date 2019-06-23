#include "Instruction.class.hpp"
#include <iostream>
#include "OperandFactory.class.hpp"

const std::string operandIndex[5] = {"int8", "int16", "int32", "float", "double"};
const std::regex OperhandRegex = std::regex("^(\\w+)\\((.+)\\)$", std::regex_constants::ECMAScript | std::regex_constants::icase);

const std::regex Instruction_regex = std::regex("^(\\w+)\\s*([\\w\\d\\(\\)-\\.]*);?(.*)?$", std::regex_constants::ECMAScript | std::regex_constants::icase);

IOperand const * parseOperhand(std::string operhand){
	if(operhand.empty()) return nullptr;
	std::smatch match;
	std::regex_match(operhand, match, OperhandRegex);
	if (match.empty()) throw new Instructions::InvalidOperhand();
	int x;
	for(x = 0;x < 5; x++ )
		if(operandIndex[x] == match[1])
			break;
	if(match[2]=="") throw new Instructions::InvalidValue;

	return factory.createOperand((eOperandType)x, match[2]);
}


/* * * * * * * * * * * *\
|	Instruction Start 	|
\* * * * * * * * * * * */

Instructions::Instructions(Instructions const & cp) : entries(cp.entries){}
Instructions::Instructions() {}
Instructions::~Instructions(){}

void Instructions::regesterInstruction(std::string keyword, instruction action){
	this->entries.insert(std::pair<std::string, instruction>(keyword, action));
	std::cout << "Registered:: " << keyword << std::endl;
}

std::pair<instruction, IOperand const *> *Instructions::parseLine(std::string line){
	std::smatch match;
	std::regex_match(line, match, Instruction_regex);
	if(line[0] == ';') return nullptr;
	if (match.empty()) throw Instructions::InvalidInstruction();
	std::map<std::string, instruction>::iterator entry = this->entries.find(match[1].str());
	if(entry == this->entries.end()) throw Instructions::InvalidInstruction();			// Could not find instruction
	
	return new std::pair<instruction, IOperand const *>(entry->second, parseOperhand(match[2].str()));
}

/* * * * * * * * * * * *\
|	Instruction End 	|
\* * * * * * * * * * * */
