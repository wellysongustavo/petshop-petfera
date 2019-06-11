#include <iostream>
#include <string>

#include "petshop.h"

int main() {

	//Teste instancia petshop
	Petshop* pet = new Petshop("PetGarrafa");

	//pet->cadastrarFuncionario();
	//pet->cadastrarFuncionario();
	//pet->editarFuncionario();
	//pet->consultarFuncionario();
	//pet->removerFuncionario();
	//pet->cadastrarAnimal();
	//pet->lerArquivoAnimal();
	//pet->editarAnimal();
	//pet->atualizaArquivoAnimal();
	//pet->removerAnimal();
	//pet->listarAnimais();
	//pet->consultarAnimal();

	pet->lerArquivoFuncionario();
	pet->listarFuncionarios();
	pet->cadastrarFuncionario();
	pet->gravarArquivoFuncionario();
	return 0;
}