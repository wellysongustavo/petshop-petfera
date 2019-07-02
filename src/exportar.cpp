#include <iostream>
#include "petfera.h"

int main() {
	Petshop* p = new Petshop("PetFera");
	std::cout << "************************ [ " << p->m_nome << " não exporta ainda ] *************************" << std::endl;

}