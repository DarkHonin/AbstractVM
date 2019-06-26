#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

#include "IOperand.class.hpp"
#include <limits>
#include "ProgramE.class.hpp"
template<typename t>
t stow(std::string st){
	std::numeric_limits<t> lim;
	try{
		double val = std::stod(st);
		if(val > lim.max()) throw ProgramException("Value overflow") ;
		if(val < lim.min()) throw ProgramException("Value underflow") ;
		return val;
	}catch(std::invalid_argument e){
		throw ProgramException("Invalid value");
	}catch(std::out_of_range e){
		throw ProgramException("Value out of range");
	}
}

class OperandFactory;
typedef IOperand const *(OperandFactory::*creator)(std::string const &v) const;

class OperandFactory{
	public:
		class InvalidOperand : public std::exception{};
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	private:
		static const creator _creators[5];
		IOperand const * createInt8(std::string const & value ) const;
		IOperand const * createInt16(std::string const & value ) const;
		IOperand const * createInt32(std::string const & value ) const;
		IOperand const * createFloat(std::string const & value ) const;
		IOperand const * createDouble(std::string const & value ) const;

};

static const OperandFactory factory = OperandFactory();

#endif