#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

#include "IOperand.class.hpp"

#include <map>
class OperandFactory;
typedef IOperand const *(OperandFactory::*creator)(std::string const &v) const;

class OperandFactory{
	public:
		class InvalidOperand : public std::exception{};
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	private:
		static const creator _creators[5];
		IOperand const * createInt8(std::string const & value ) const;
		IOperand const * createInt16(std::string const & value ) const;
		IOperand const * createInt32(std::string const & value ) const;
		IOperand const * createFloat(std::string const & value ) const;
		IOperand const * createDouble(std::string const & value ) const;

};

#endif