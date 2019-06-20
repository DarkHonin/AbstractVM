#include "Operands.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstring>

template <typename T, eOperandType t>Operand<T, t>::Operand(T e) : 
	_value(e), _presision(sizeof(T) * 8), _type(t){}

template <typename T, eOperandType t>Operand<T, t>::Operand(Operand<T, t> &toclone) :
	_value(toclone._value), _presision(sizeof(T) * 8), _type(t){}

template <typename T, eOperandType t>Operand<T, t>::~Operand(){}

template <typename T, eOperandType t>
IOperand const * Operand<T, t>::operator+(IOperand const &rhs) const{
	if(this->getPrecision() < rhs.getPrecision())
		return *this + rhs;
	Operand *B;
	switch(rhs.getType()){
		case eOperandType::Int8:
			B = &rhs;
			break;
		case eOperandType::Int16:;
		case eOperandType::Int32:;
		case eOperandType::Float:;
		case eOperandType::Double:;
	}
	std::cout << this->getPrecision() << " + " << rhs.getPrecision() << std::endl;
	//return SpawnOp(a.getValue() + b.getValue());
}

template <typename T, eOperandType t>
IOperand const * Operand<T, t>::operator-(IOperand const &rhs) const{}
template <typename T, eOperandType t>
IOperand const * Operand<T, t>::operator*(IOperand const &rhs) const{}
template <typename T, eOperandType t>
IOperand const * Operand<T, t>::operator/(IOperand const &rhs) const{}
template <typename T, eOperandType t>
IOperand const * Operand<T, t>::operator%(IOperand const &rhs) const{}

template <typename T, eOperandType t>
int Operand<T, t>::getPrecision(void) const{
	return this->_presision;
}

template <typename T, eOperandType t>
std::string const & Operand<T, t>::toString(void) const{
	return *(new std::string(std::to_string(this->_value))); }

template <typename T, eOperandType t>
T Operand<T, t>::getValue(void) const{
	return this->_value;
}

template <typename T, eOperandType t>
eOperandType Operand<T, t>::getType(void)	const{
	return this->_type;
}

Operand<int8_t, eOperandType::Int8>   *SpawnOp(int8_t q){ return new Operand<int8_t, eOperandType::Int8>(q); }
Operand<int16_t, eOperandType::Int16> *SpawnOp(int16_t q){ return new Operand<int16_t, eOperandType::Int16>(q); }
Operand<int32_t, eOperandType::Int32> *SpawnOp(int32_t q){ return new Operand<int32_t, eOperandType::Int32>(q); }
Operand<float_t, eOperandType::Float> *SpawnOp(float_t q){ return new Operand<float_t, eOperandType::Float>(q); }
Operand<double_t, eOperandType::Double> *SpawnOp(double_t q){ return new Operand<double_t, eOperandType::Double>(q); }
