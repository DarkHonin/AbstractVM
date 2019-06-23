#include "Operands.hpp"
#include "OperandFactory.class.hpp"

//static const OperandFactory factory;

double toData(IOperand const &e){
	switch(e.getType()){
		case eOperandType::Int8:
		case eOperandType::Int16:
		case eOperandType::Int32:
			return std::stoi(e.toString());
		case eOperandType::Float:
			return std::stof(e.toString());
		case eOperandType::Double:
			return std::stod(e.toString());
	}
}

template <typename heck>
void *toPointer(heck ens){
	heck *ons = new heck;
	*ons = ens;
	return ons;
}

Operand::Operand(int8_t const &e): _value(toPointer<int8_t>(e)), _type(eOperandType::Int8), _presision(sizeof(int8_t) * 8){};
Operand::Operand(int16_t const &e): _value(toPointer<int16_t>(e)), _type(eOperandType::Int16), _presision(sizeof(int16_t) * 8){};
Operand::Operand(int32_t const &e): _value(toPointer<int32_t>(e)), _type(eOperandType::Int32), _presision(sizeof(int32_t) * 8){};
Operand::Operand(float_t const &e): _value(toPointer<float_t>(e)), _type(eOperandType::Float), _presision(sizeof(float_t) * 8){};
Operand::Operand(double_t const &e): _value(toPointer<double_t>(e)), _type(eOperandType::Double), _presision(sizeof(double_t) * 8){};
Operand::~Operand(){}

int 			Operand::getPrecision(void) const{ return this->_presision;}
eOperandType 	Operand::getType(void)	const{ return this->_type; }
bool Operand::isIntegral() const { return this->getType() <= eOperandType::Int32; }

std::string const & Operand::toString(void) const{
	switch(this->_type){
		case eOperandType::Int8:
			return *(new std::string(std::to_string(*(int8_t *)this->_value)));
		case eOperandType::Int16:
			return *(new std::string(std::to_string(*(int16_t *)this->_value)));
		case eOperandType::Int32:
			return *(new std::string(std::to_string(*(int32_t *)this->_value)));
		case eOperandType::Float:
			return *(new std::string(std::to_string(*(float_t *)this->_value)));
		case eOperandType::Double:
			return *(new std::string(std::to_string(*(double_t *)this->_value)));
	}
}

IOperand const * Operand::operator+(IOperand const &rhs) const{
	double mine = toData(*this);
	double RHS = toData(rhs);
	eOperandType result = std::max(this->getType(), rhs.getType());	// The resulting type
	return factory.createOperand(result, std::to_string(mine + RHS));
}
IOperand const * Operand::operator-(IOperand const &rhs) const{
	double mine = toData(*this);
	double RHS = toData(rhs);
	eOperandType result = std::max(this->getType(), rhs.getType());	// The resulting type
	return factory.createOperand(result, std::to_string(mine - RHS));
}
IOperand const * Operand::operator*(IOperand const &rhs) const{
	double mine = toData(*this);
	double RHS = toData(rhs);
	eOperandType result = std::max(this->getType(), rhs.getType());	// The resulting type
	return factory.createOperand(result, std::to_string(mine * RHS));
}
IOperand const * Operand::operator/(IOperand const &rhs) const{
	double mine = toData(*this);
	double RHS = toData(rhs);
	eOperandType result = std::max(this->getType(), rhs.getType());	// The resulting type
	return factory.createOperand(result, std::to_string(mine / RHS));
}
IOperand const * Operand::operator%(IOperand const &rhs) const{
	double mine = toData(*this);
	double RHS = toData(rhs);
	eOperandType result = std::max(this->getType(), rhs.getType());	// The resulting type
	double hold = mine / RHS;
	hold -= (int) hold;
	hold *= 10;
	return factory.createOperand(result, std::to_string(hold));
}