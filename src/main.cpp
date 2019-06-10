#include <iostream>
#include <string>

#include "petshop.h"

int main() {

	//Teste instancia petshop
	Petshop* pet = new Petshop("PetGarrafa");

	pet->lerArquivo();
	//pet->cadastrarFuncionario();
	pet->cadastrarFuncionario();
	//pet->editarFuncionario();
	//pet->consultarFuncionario();
	//pet->removerFuncionario();
	//pet->cadastrarAnimal();
	//pet->cadastrarAnimal();
	//pet->editarAnimal();
	//pet->removerAnimal();
	pet->listarAnimais();
	pet->consultarAnimal();
	return 0;
}