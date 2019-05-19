#include <iostream>
#include <string>

#include "petshop.h"

int main() {

	//Teste instancia petshop
	Petshop* pet = new Petshop("PetGarrafa");

	//pet->removerFuncionario();
	//pet->cadastrarFuncionario();
	pet->cadastrarAnimal();
	pet->listarAnimais();
	pet->removerAnimal();


	return 0;
}