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
	if (type < 0 || type > 5) throw OperandFactory::InvalidOperand();
	return (this->*_creators[type])(value);
}

IOperand const * OperandFactory::createInt8(std::string const & value ) const{
	return new Operand(stow<int8_t>(value));
}
IOperand const * OperandFactory::createInt16(std::string const & value ) const{
	return new Operand(stow<int16_t>(value));
}
IOperand const * OperandFactory::createInt32(std::string const & value ) const{
	return new Operand(stow<int32_t>(value));
}
IOperand const * OperandFactory::createFloat(std::string const & value ) const{
	return new Operand(stow<float_t>(value));
}
IOperand const * OperandFactory::createDouble(std::string const & value ) const{
	return new Operand(stow<double_t>(value));
}