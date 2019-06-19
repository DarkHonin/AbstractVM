#include "Operands.hpp"
#include <iomanip>
#include <iostream>

Operand::Operand(std::string const & s){}
Operand::Operand(Operand & cp) : _value(cp._value){}
Operand::Operand(byte *e) : _value(e){}
Operand::~Operand(){}

IOperand const * Operand::operator+(IOperand const &rhs) const{}
IOperand const * Operand::operator-(IOperand const &rhs) const{}
IOperand const * Operand::operator*(IOperand const &rhs) const{}
IOperand const * Operand::operator/(IOperand const &rhs) const{}
IOperand const * Operand::operator%(IOperand const &rhs) const{}

byte * Operand::getValue() const{ return (byte *)this->_value; }


Int8::Int8(std::string const & value) : Operand(fromString(value)){}
Int8::~Int8(){}

byte * Int8::fromString(std::string s){
	int e = std::stoi(s);
	if (e > 0xFF) throw "Overly Exceptional";
	byte *ret = new byte[1];
	*ret = ((byte *) &e)[0];
	return ret;
}

int Int8::getPrecision(void) const{
	return 8;
}
eOperandType Int8::getType(void)	const{
	return eOperandType::Int8;
}
std::string const & Int8::toString(void) const{
	std::string *ret = new std::string(std::to_string(*((byte *) (this->getValue()))));
	return *ret;
}


Int16::Int16(std::string const & value) : Operand(fromString(value)){}
Int16::~Int16(){}

byte * Int16::fromString(std::string s){
	int e = std::stoi(s);
	if (e > 0xFF) throw "Overly Exceptional";
	byte *ret = new byte[2];
	*ret = ((byte *) &e)[0];
	*(ret + 1) = ((byte *) &e)[1];
	
	return ret;
}

int Int16::getPrecision(void) const{
	return 16;
}
eOperandType Int16::getType(void)	const{
	return eOperandType::Int16;
}
std::string const & Int16::toString(void) const{
	std::string *ret = new std::string(std::to_string(*((byte *) (this->getValue()))));
	return *ret;
}
