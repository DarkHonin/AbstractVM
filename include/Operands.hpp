#ifndef OPERANDS_H
#define OPERANDS_H

#include <exception>
#include "IOperand.class.hpp"

class Operand : public IOperand{
	public:
		class InvalidValue : public std::exception{};
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

class Int32: public Operand{
	public:
		Int32(std::string const &value);
		~Int32();

		int getPrecision(void) const;
		eOperandType getType(void)	const;
		std::string const & toString(void) const;
		byte *fromString(std::string s);
};

class Float: public Operand{
	public:
		Float(std::string const &value);
		~Float();

		int getPrecision(void) const;
		eOperandType getType(void)	const;
		std::string const & toString(void) const;
		byte *fromString(std::string s);
};

class Double: public Operand{
	public:
		Double(std::string const &value);
		~Double();

		int getPrecision(void) const;
		eOperandType getType(void)	const;
		std::string const & toString(void) const;
		byte *fromString(std::string s);
};

#endif