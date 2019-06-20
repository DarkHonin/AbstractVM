#ifndef OPERANDS_H
#define OPERANDS_H

#include <exception>
#include "IOperand.class.hpp"
template <typename T, eOperandType t>
class Operand : public IOperand{
	public:
		class InvalidValue : public std::exception{};

		Operand(Operand &toclone);
		Operand(T);
		~Operand();

		int getPrecision(void) const;
		eOperandType getType(void)	const;

		IOperand const * operator+(IOperand const &rhs) const;
		IOperand const * operator-(IOperand const &rhs) const;
		IOperand const * operator*(IOperand const &rhs)	const;
		IOperand const * operator/(IOperand const &rhs)	const;
		IOperand const * operator%(IOperand const &rhs)	const;

		std::string const & toString(void) const;

		T getValue() const;

	private:
		const int _presision;
		const eOperandType _type;
		const T _value;
};

Operand<int8_t, eOperandType::Int8>   *SpawnOp(int8_t);
Operand<int16_t, eOperandType::Int16> *SpawnOp(int16_t);
Operand<int32_t, eOperandType::Int32> *SpawnOp(int32_t);
Operand<float_t, eOperandType::Float> *SpawnOp(float_t);
Operand<double_t, eOperandType::Double> *SpawnOp(double_t);


#endif