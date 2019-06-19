#ifndef OPERANDS_H
#define OPERANDS_H

#include "IOperand.class.hpp"

class Operand : public IOperand{
	public:
		Operand(std::string const & value);
		Operand(byte * value);
		Operand(Operand &toclone);
		~Operand();

		virtual int getPrecision(void) const = 0;
		virtual eOperandType getType(void)	const = 0;

		IOperand const * operator+(IOperand const &rhs) const;
		IOperand const * operator-(IOperand const &rhs) const;
		IOperand const * operator*(IOperand const &rhs)	const;
		IOperand const * operator/(IOperand const &rhs)	const;
		IOperand const * operator%(IOperand const &rhs)	const;

		virtual std::string const & toString(void) const = 0;
		virtual byte *fromString(std::string s) = 0;

		byte * getValue() const;

	private:
		const byte *_value;
};


class Int8: public Operand{
	public:
		Int8(std::string const &value);
		~Int8();

		int getPrecision(void) const;
		eOperandType getType(void)	const;
		std::string const & toString(void) const;
		byte *fromString(std::string s);
};

class Int16: public Operand{
	public:
		Int16(std::string const &value);
		~Int16();

		int getPrecision(void) const;
		eOperandType getType(void)	const;
		std::string const & toString(void) const;
		byte *fromString(std::string s);
};

#endif