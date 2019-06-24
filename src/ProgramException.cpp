#include "Program.class.hpp"

ProgramException::ProgramException(std::string e) : ename(e){}
ProgramException::ProgramException() : ProgramException("Unkown"){}
ProgramException::ProgramException(ProgramException const &e) : ProgramException(e.ename){}
ProgramException::~ProgramException(){}
