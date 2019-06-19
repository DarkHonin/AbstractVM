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

/* * * * * * * * * * * *\
|	Int8 start			|
\* * * * * * * * * * * */
Int8::Int8(std::string const & value) : Operand(fromString(value)){}
Int8::~Int8(){}

byte * Int8::fromString(std::string s){
	int e = std::stoi(s);
	if (e > 0xFF) throw "Overly Exceptional";
	byte *ret = new byte[2];
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
	std::string *ret = new std::string(std::to_string(*((int *) (this->getValue()))));
	return *ret;
}


/* * * * * * * * * * * *\
|	Int16 start			|
\* * * * * * * * * * * */

Int16::Int16(std::string const & value) : Operand(fromString(value)){}
Int16::~Int16(){}

byte * Int16::fromString(std::string s){
	int e = std::stoi(s);
	if (e > 0xFFFF) throw "Overly Exceptional";
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
	std::string *ret = new std::string(std::to_string(*((int *) (this->getValue()))));
	return *ret;
}

/* * * * * * * * * * * *\
|	Int32 start			|
\* * * * * * * * * * * */

Int32::Int32(std::string const & value) : Operand(fromString(value)){}
Int32::~Int32(){}

byte * Int32::fromString(std::string s){
	long int e = std::stol(s);
	if (e > 0xFFFFFFFF) throw "Overly Exceptional";
	byte *ret = new byte[4];
	ret = (byte *) &e;
	return ret;
}

int Int32::getPrecision(void) const{
	return 32;
}
eOperandType Int32::getType(void)	const{
	return eOperandType::Int32;
}
std::string const & Int32::toString(void) const{
	std::string *ret = new std::string(std::to_string(*((int *) (this->getValue()))));
	return *ret;
}

/* * * * * * * * * * * *\
|	Float start			|
\* * * * * * * * * * * */

Float::Float(std::string const & value) : Operand(fromString(value)){}
Float::~Float(){}

byte * Float::fromString(std::string s){
	float e = std::stof(s);
	if (e > 0xFFFFFFFF) throw "Overly Exceptional";
	byte *ret = new byte[4];
	ret = (byte *) &e;
	return ret;
}

int Float::getPrecision(void) const{
	return 32;
}
eOperandType Float::getType(void)	const{
	return eOperandType::Float;
}
std::string const & Float::toString(void) const{
	std::string *ret = new std::string(std::to_string(*((float *) (this->getValue()))));
	return *ret;
}

/* * * * * * * * * * * *\
|	Double start			|
\* * * * * * * * * * * */

Double::Double(std::string const & value) : Operand(fromString(value)){}
Double::~Double(){}

byte * Double::fromString(std::string s){
	double e = std::stod(s);
	byte *ret = new byte[8];
	ret = (byte *) &e;
	return ret;
}

int Double::getPrecision(void) const{
	return 64;
}
eOperandType Double::getType(void)	const{
	return eOperandType::Double;
}
std::string const & Double::toString(void) const{
	std::string *ret = new std::string(std::to_string(*((double *) (this->getValue()))));
	return *ret;
}