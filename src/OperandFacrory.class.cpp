#include "OperandFactory.class.hpp"
#include "Operands.hpp"
#include <iostream>

const creator OperandFactory::_creators[5] = {
	&OperandFactory::createInt8,
	&OperandFactory::createInt16,
	&OperandFactory::createInt32,
	&OperandFactory::createFloat,
	&OperandFactory::createDouble
};

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const{
	return (this->*_creators[type])(value);
}

IOperand const * OperandFactory::createInt8(std::string const & value ) const{
	return new class Int8(value);
}
IOperand const * OperandFactory::createInt16(std::string const & value ) const{
	return new class Int16(value);
}
IOperand const * OperandFactory::createInt32(std::string const & value ) const{}
IOperand const * OperandFactory::createFloat(std::string const & value ) const{}
IOperand const * OperandFactory::createDouble(std::string const & value ) const{}