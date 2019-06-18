#include "petshop.h"

int main() {

	//Teste instancia petshop
	Petshop* pet = new Petshop("PetGarrafa");

	//pet->cadastrarFuncionario();
	//pet->cadastrarFuncionario();
	//pet->editarFuncionario();
	//pet->consultarFuncionario();
	//pet->removerFuncionario();
	pet->lerArquivoAnimal();
	pet->lerArquivoFuncionario();
	pet->cadastrarAnimal();
	//pet->editarAnimal();
	//pet->atualizaArquivoAnimal();
	//pet->removerAnimal();
	pet->listarAnimais();
	//pet->consultarAnimal();
	/*
	pet->lerArquivoFuncionario();
	pet->listarFuncionarios();
	pet->cadastrarFuncionario();
	pet->gravarArquivoFuncionario();
	*/
	return 0;
}