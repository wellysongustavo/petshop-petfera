#include "petshop.h"

bool menu(Petshop* pet){
	std::cout << "\n********************************* MENU ********************************" << std::endl;
	std::cout << "1 - CADASTRAR ANIMAL;\n";
	std::cout << "2 - CADASTRAR FUNCIONÁRIO;\n\n";
	std::cout << "3 - CONSULTAR ANIMAL;\n";
	std::cout << "4 - CONSULTAR FUNCIONÁRIO;\n\n";
	std::cout << "5 - EDITAR ANIMAL;\n";
	std::cout << "6 - EDITAR FUNCIONÁRIO;\n\n";
	std::cout << "7 - REMOVER ANIMAL;\n";
	std::cout << "8 - REMOVER FUNCIONÁRIO;\n\n";
	std::cout << "9 - SAIR;\n\n";

	int escolha_menu;
	bool executa_menu = true;
	do{
		std::cout << "Digite a ação desejada: ";
		std::cin >> escolha_menu;

		switch(escolha_menu){
			case 1:
				pet->cadastrarAnimal();
				break;
			case 2:
				pet->cadastrarFuncionario();
				break;
			case 3:
				pet->consultarAnimal();
				break;
			case 4:
				pet->consultarFuncionario();
				break;
			case 5:
				pet->editarAnimal();
				break;
			case 6:
				pet->editarFuncionario();
				break;
			case 7:
				pet->removerAnimal();
				break;
			case 8:
				pet->removerFuncionario();
				break;
			case 9:	
				pet->gravarArquivoFuncionario();
				pet->atualizaArquivoAnimal();
				pet->desalocarObjetos();
				std::cout << "PETSHOP ENCERRADO\n";
				executa_menu = false;
				break;
			default:
				std::cout << "A opção digitada não existe. Tente novamente!\n";
				break;	
		}
	}while(escolha_menu < 1 || escolha_menu > 9);
	return executa_menu;
}

int main(){
	Petshop* pet = new Petshop("PetGarrafa");
	pet->lerArquivoAnimal(); 
	pet->lerArquivoFuncionario(); 
	bool executa_menu = true;
	do{
		executa_menu = menu(pet);
	}while(executa_menu == true);
	
	return 0;
}
