#include "PrimitiveOperand.class.hpp"
#include "OperandFactory.class.hpp"
#include <iostream>
#include <string>

PrimitiveOperand::PrimitiveOperand(byte* value) : _value(value){}

PrimitiveOperand::PrimitiveOperand(PrimitiveOperand & toclone) : _value(toclone._value){};

PrimitiveOperand::~PrimitiveOperand(){}

IOperand const * PrimitiveOperand::operator+(IOperand const &rhs) const{
	eOperandType nt = std::max(rhs.getType(), this->getType());
	
}

IOperand const * PrimitiveOperand::operator-(IOperand const &rhs) const{

}

IOperand const * PrimitiveOperand::operator*(IOperand const &rhs) const{

}

IOperand const * PrimitiveOperand::operator/(IOperand const &rhs) const{

}

IOperand const * PrimitiveOperand::operator%(IOperand const &rhs) const{

}


