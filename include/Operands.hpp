#ifndef OPERANDS_H
#define OPERANDS_H

#include <exception>
#include "IOperand.class.hpp"
#include "OperandFactory.class.hpp"

template <typename to>
void toValue(std::string v, eOperandType e, void *place){
	to *ret = new to;
	switch(e){
		case eOperandType::Int8:
		case eOperandType::Int16:
		case eOperandType::Int32:
			*ret = std::stoi(v);
			break;
		case eOperandType::Float:
			*ret = std::stof(v);
			break;
		case eOperandType::Double:
			*ret = std::stod(v);
			break;
	}
	std::memcpy(place, ret, sizeof(to));
}

static const OperandFactory factory = OperandFactory();

template <typename T, eOperandType t>
class Operand : public IOperand{
	public:
		class InvalidValue : public std::exception{};


		Operand(Operand &toclone) : _value(toclone._value){}
		Operand(T e) : _value(e){};
		~Operand(){};

		int getPrecision(void) const { return sizeof(T) * 8;};
		eOperandType getType(void)	const {return t;};

		IOperand const * operator+(IOperand const &rhs) const{
			eOperandType retT = std::max(this->getType(), rhs.getType());
			void *hold = (void *) new byte[rhs.getPrecision() / 8];
			switch(rhs.getType()){
				case eOperandType::Int8:
					toValue<int8_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() + *((int8_t *)hold)));
				case eOperandType::Int16:
					toValue<int16_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() + *((int16_t *)hold)));
				case eOperandType::Int32:
					toValue<int32_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() + *((int32_t *)hold)));
				case eOperandType::Float:
					toValue<float_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() + *((float_t *)hold)));
				case eOperandType::Double:
					toValue<double_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() + *((double_t *)hold)));
			}
		}
		IOperand const * operator-(IOperand const &rhs) const{
			eOperandType retT = std::max(this->getType(), rhs.getType());
			void *hold = (void *) new byte[rhs.getPrecision() / 8];
			switch(rhs.getType()){
				case eOperandType::Int8:
					toValue<int8_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() - *((int8_t *)hold)));
				case eOperandType::Int16:
					toValue<int16_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() - *((int16_t *)hold)));
				case eOperandType::Int32:
					toValue<int32_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() - *((int32_t *)hold)));
				case eOperandType::Float:
					toValue<float_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() - *((float_t *)hold)));
				case eOperandType::Double:
					toValue<double_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() - *((double_t *)hold)));
			}
		}
		IOperand const * operator*(IOperand const &rhs)	const{
			eOperandType retT = std::max(this->getType(), rhs.getType());
			void *hold = (void *) new byte[rhs.getPrecision() / 8];
			switch(rhs.getType()){
				case eOperandType::Int8:
					toValue<int8_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() * *((int8_t *)hold)));
				case eOperandType::Int16:
					toValue<int16_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() * *((int16_t *)hold)));
				case eOperandType::Int32:
					toValue<int32_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() * *((int32_t *)hold)));
				case eOperandType::Float:
					toValue<float_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() * *((float_t *)hold)));
				case eOperandType::Double:
					toValue<double_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() * *((double_t *)hold)));
			}
		}
		IOperand const * operator/(IOperand const &rhs)	const{
			if(rhs.toString() == "0")throw "Heck"; // Coming soon
			eOperandType retT = std::max(this->getType(), rhs.getType());
			void *hold = (void *) new byte[rhs.getPrecision() / 8];
			switch(rhs.getType()){
				case eOperandType::Int8:
					toValue<int8_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() / *((int8_t *)hold)));
				case eOperandType::Int16:
					toValue<int16_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() / *((int16_t *)hold)));
				case eOperandType::Int32:
					toValue<int32_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() / *((int32_t *)hold)));
				case eOperandType::Float:
					toValue<float_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() / *((float_t *)hold)));
				case eOperandType::Double:
					toValue<double_t>(rhs.toString(), rhs.getType(), hold);
					return factory.createOperand(retT, std::to_string(this->getValue() / *((double_t *)hold)));
			}
		}
		IOperand const * operator%(IOperand const &rhs)	const{
	
		}

		std::string const & toString(void) const {return *(new std::string(std::to_string(this->_value)));}

		T getValue() const { return this->_value; }

	private:
		const T _value;
};

#endif