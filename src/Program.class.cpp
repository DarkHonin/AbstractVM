#include "Program.class.hpp"
#include <sstream>
#include "Instruction.class.hpp"
#include "Operands.hpp"

const std::regex Program::command_regex = std::regex("^(\\w+)\\s*([\\w\\d\\(\\)-\\.]*);?(.*)?", std::regex_constants::ECMAScript | std::regex_constants::icase);

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
	try {
		op = Instruction::createInstruction(match[1].str(), match[2].str());
		op->execute(this->_stack);
	} catch (OperandFactory::InvalidOperand &e){
		std::cerr << "Invalid opperand: `" << match[2].str() << "`" << std::endl;
	}catch (Instruction::InvalidInstruction &e){
		std::cerr << "Invalid instruction: `" << match[1].str() << "`" << std::endl;
	}
	return true;
}