#include "Program.class.hpp"
#include <sstream>
#include <fstream>
#include "Instruction.class.hpp"
#include "Operands.hpp"

bool exit(std::vector<IOperand const *> & stack, IOperand const *opParam){
	return false;
}

bool push(std::vector<IOperand const *> & stack, IOperand const *opParam){
	if(!opParam) throw new Program::ExpectedOpperhand;
	stack.push_back(opParam);
	return true;
}

bool pop(std::vector<IOperand const *> & stack, IOperand const *opParam){
	if(!stack.size()) throw new Program::StackUnderflow;
	stack.pop_back();
	return true;
}

bool dump(std::vector<IOperand const *> & stack, IOperand const *opParam){
	std::vector<IOperand const *>::iterator I = stack.begin();
	while(I != stack.end())
		std::cout << (*I++)->toString() << std::endl;
	return true;
}

bool sum(std::vector<IOperand const *> & stack, IOperand const *opParam){
	if(stack.size() < 2) throw new Program::StackUnderflow;
	IOperand const *A = stack[stack.size() - 1];
	IOperand const *B = stack[stack.size() - 2];
	IOperand const *C = *A + *B;
	delete A;
	delete B;
	pop(stack, nullptr);
	pop(stack, nullptr);
	push(stack, C);
	return true;
}

bool sub(std::vector<IOperand const *> & stack, IOperand const *opParam){
	if(stack.size() < 2) throw new Program::StackUnderflow;
	IOperand const *A = stack[stack.size() - 1];
	IOperand const *B = stack[stack.size() - 2];
	IOperand const *C = *A - *B;
	delete A;
	delete B;
	pop(stack, nullptr);
	pop(stack, nullptr);
	push(stack, C);
	return true;
}

bool mul(std::vector<IOperand const *> & stack, IOperand const *opParam){
	if(stack.size() < 2) throw new Program::StackUnderflow;
	IOperand const *A = stack[stack.size() - 1];
	IOperand const *B = stack[stack.size() - 2];
	IOperand const *C = *A * *B;
	delete A;
	delete B;
	pop(stack, nullptr);
	pop(stack, nullptr);
	push(stack, C);
	return true;
}

bool div(std::vector<IOperand const *> & stack, IOperand const *opParam){
	if(stack.size() < 2) throw new Program::StackUnderflow;
	IOperand const *A = stack[stack.size() - 1];
	IOperand const *B = stack[stack.size() - 2];
	IOperand const *C = *A / *B;
	delete A;
	delete B;
	pop(stack, nullptr);
	pop(stack, nullptr);
	push(stack, C);
	return true;
}

Program::Program() : lexigon(){
	this->lexigon.regesterInstruction("exit", &exit);
	this->lexigon.regesterInstruction("push", &push);
	this->lexigon.regesterInstruction("pop", &pop);
	this->lexigon.regesterInstruction("dump", &dump);
	this->lexigon.regesterInstruction("sum", &sum);
	this->lexigon.regesterInstruction("sub", &sub);
	this->lexigon.regesterInstruction("mul", &mul);
	this->lexigon.regesterInstruction("div", &div);
};

Program::Program(Program &r) : lexigon(r.lexigon){}
Program::~Program(){}

bool Program::readProgram(std::istream &in){
	int linei = 0;
	std::string line;
	while(true){
		std::getline(in, line);
		if(line == ";;") break;
		
		try{
			this->op.push_back(this->lexigon.parseLine(line));
		}catch (Instructions::InvalidInstruction &e){
			std::cout << "Invalid instruction '" << line << "::" << linei << "'" << std::endl;
		}catch (Instructions::InvalidOperhand *e){
			std::cout << "Invalid Operhand '" << line << "::" << linei << "'" << std::endl;
		}
		linei++;
	}
	return true;
}

bool Program::readProgram(std::ifstream &in){
	int linei = 0;
	std::string line;
	std::pair<instruction, IOperand const *> * hold;
	while(std::getline(in, line)){
		if(line.size() == 0) continue;
		int rp = 0;
		while((rp = line.find('\n')) != std::string::npos)
			line.replace(rp, 2, "");
		while((rp = line.find('\r')) != std::string::npos)
			line.replace(rp, 2, "");
		try{
			hold = this->lexigon.parseLine(line);
			if(hold)
				this->op.push_back(hold);
		}catch (Instructions::InvalidInstruction &e){
			std::cout << "Invalid instruction '" << line << "::" << linei << "'" << std::endl;
		}catch (Instructions::InvalidOperhand *e){
			std::cout << "Invalid Operhand '" << line << "::" << linei << "'" << std::endl;
		}
		linei++;
	}
	return true;
}

bool Program::runProgram(){
	std::vector<std::pair<instruction, IOperand const *>*>::iterator point = this->op.begin();
	std::pair<instruction, IOperand const *> currentOP;
	instruction ins;
	int linei = 0;
	while(point != this->op.end()){
		currentOP = **point;
		ins = currentOP.first;
		try{
			if(! ins(this->_stack, currentOP.second)) return false;
		}catch (Program::StackUnderflow *e){
			
			std::cout << "Stack underflow :: " << linei << std::endl;
		}
		point++;
		linei++;
	}
	return true;
}