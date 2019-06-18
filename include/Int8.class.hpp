#ifndef INT8_H
#define INT8_H

#include "PrimitiveOperand.class.hpp"

class Int8 : public PrimitiveOperand{
	public:
		Int8(unsigned char value);
		~Int8();

		int getPrecision(void)const;
		eOperandType getType(void)	const;

		std::string const & toString(void) const;
};

#endif