#include "Program.class.hpp"
#include <sstream>
#include "Instruction.class.hpp"

const std::regex Program::command_regex = std::regex("^(\\w+)\\s*([\\w\\d\\(\\)]*);?(.*)?", std::regex_constants::ECMAScript | std::regex_constants::icase);

Program::Program(std::istream &in) : _in(in){

};

Program::Program(Program &r) : Program(r._in){}
Program::~Program(){}

bool Program::next(){
	std::string ret;
	std::getline(this->_in, ret);
	std::smatch match;
	std::regex_match(ret, match, this->command_regex);
	if (match.empty())
		return false;
	Instruction* op;
	for(int x = 0; x < match.size(); x++)
		std::cout << x <<": " << match[x] << std::endl;
	op = Instruction::createInstruction(match[1].str(), match[2].str());
	op->execute(this->_stack);
	return false;
}