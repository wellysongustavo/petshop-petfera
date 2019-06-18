#include "petshop.h"

int main() {

	//Teste instancia petshop
	Petshop* pet = new Petshop("PetGarrafa");

	pet->lerArquivoAnimal(); //NÃO TIRE ISSO DAQUI
	pet->lerArquivoFuncionario(); //NÃO TIRE ISSO DAQUI
	//pet->cadastrarFuncionario();
	//pet->cadastrarFuncionario();
	//pet->editarFuncionario();
	//pet->consultarFuncionario();
	//pet->removerFuncionario();
	pet->cadastrarAnimal();
	//pet->editarAnimal();
	//pet->removerAnimal();
	pet->listarAnimais();
	//pet->consultarAnimal();
	/*
	pet->lerArquivoFuncionario();
	pet->listarFuncionarios();
	pet->cadastrarFuncionario();
	*/
	pet->gravarArquivoFuncionario(); //NÃO TIRE ISSO DAQUI
	pet->atualizaArquivoAnimal(); //NÃO TIRE ISSO DAQUI
	return 0;
}