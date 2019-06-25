#ifndef OPERANDS_H
#define OPERANDS_H

#include <exception>
#include "IOperand.class.hpp"
#include "OperandFactory.class.hpp"
#include <iostream>


class Operand : public IOperand{
	public:
		Operand(Operand &toclone);
		Operand(int8_t const &e);
		Operand(int16_t const &e);
		Operand(int32_t const &e);
		Operand(float_t const &e);
		Operand(double_t const &e);
		~Operand();

		int getPrecision(void) const;
		eOperandType getType(void)	const;

		IOperand const * operator+(IOperand const &rhs) const;
		IOperand const * operator-(IOperand const &rhs) const;
		IOperand const * operator*(IOperand const &rhs)	const;
		IOperand const * operator/(IOperand const &rhs)	const;
		IOperand const * operator%(IOperand const &rhs)	const;

		std::string const & toString(void) const;// {return *(new std::string(std::to_string(this->_value)));}
		bool isIntegral() const;

	private:
		const void * _value;
		const eOperandType _type;
		const int _presision;
};


#endif