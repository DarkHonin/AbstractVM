#include "Int8.class.hpp"
#include "OperandFactory.class.hpp"

Int8::Int8(unsigned char value) : PrimitiveOperand(&value){}
Int8::~Int8(){}

int Int8::getPrecision(void)		const{ return 8; }
eOperandType Int8::getType(void)	const{ return eOperandType::Int8; }

std::string const & PrimitiveOperand::toString(void) const{
	int I = *((int*) this->_value);
	std::cout << I;
	return "";
}
