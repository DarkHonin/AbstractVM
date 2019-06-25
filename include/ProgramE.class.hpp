#ifndef PROGRAME_H
#define PROGRAME_H

#include <string>
#include <exception>

class ProgramException : public std::exception{
	public:
		const std::string ename;

		ProgramException(std::string e);
		ProgramException();
		ProgramException(ProgramException const &e);
		~ProgramException();
};

#endif