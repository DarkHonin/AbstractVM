#include "PrimitiveOperand.class.hpp"
#include "Int8.class.hpp"
#include <iostream>



int main(){
	int v = 16;
	Int8 a(v);
	Int8 b(v);
	std::cout << a.toString() << std::endl;	
	//std::cout << b.getType() << " " << b.getPrecision() << std::endl;	
	//std::cout << c.getType() << " " << c.getPrecision() << std::endl;	
	//std::cout << e.getType() << " " << e.getPrecision() << std::endl;	
	//std::cout << d.getType() << " " << d.getPrecision() << std::endl;	
	return 0;
}