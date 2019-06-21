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
	return new Operand<int8_t, eOperandType::Int8>((int8_t)std::stoi(value));
}
IOperand const * OperandFactory::createInt16(std::string const & value ) const{
	return new Operand<int16_t, eOperandType::Int16>((int16_t)std::stoi(value));
}
IOperand const * OperandFactory::createInt32(std::string const & value ) const{
	return new Operand<int32_t, eOperandType::Int32>((int32_t)std::stoi(value));
}
IOperand const * OperandFactory::createFloat(std::string const & value ) const{
	return new Operand<float_t, eOperandType::Float>((float_t)std::stof(value));
}
IOperand const * OperandFactory::createDouble(std::string const & value ) const{
	return new Operand<double_t, eOperandType::Double>((double_t)std::stod(value));
}