#ifndef PRIMITIVEOPERAND_H
#define PRIMITIVEOPERAND_H

#include "IOperand.class.hpp"

class PrimitiveOperand : public IOperand{
	public:
		PrimitiveOperand(byte *value);
		PrimitiveOperand(PrimitiveOperand &toclone);
		~PrimitiveOperand();

		virtual int getPrecision(void) const;
		virtual eOperandType getType(void)	const;

		IOperand const * operator+(IOperand const &rhs) const;
		IOperand const * operator-(IOperand const &rhs) const;
		IOperand const * operator*(IOperand const &rhs)	const;
		IOperand const * operator/(IOperand const &rhs)	const;
		IOperand const * operator%(IOperand const &rhs)	const;

		virtual std::string const & toString(void) const;

		byte * const getValue() const;

	private:
		const byte *_value;
};

#endif