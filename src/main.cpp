#include "petshop.h"

bool menu(Petshop* pet){
	std::cout << "\n************************************** MENU ************************************" << std::endl;
	std::cout << "1 - CADASTRAR ANIMAL\n";
	std::cout << "2 - CADASTRAR FUNCIONÁRIO\n";
	std::cout << "3 - LISTAR ANIMAIS CADASTRADOS\n";
	std::cout << "4 - CONSULTAR ANIMAL\n";
	std::cout << "5 - CONSULTAR FUNCIONÁRIO\n";
	std::cout << "6 - EDITAR ANIMAL\n";
	std::cout << "7 - EDITAR FUNCIONÁRIO\n";
	std::cout << "8 - REMOVER ANIMAL\n";
	std::cout << "9 - REMOVER FUNCIONÁRIO\n\n";
	std::cout << "0 - SAIR\n\n";

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
				pet->listarAnimais();
				break;	
			case 4:
				pet->consultarAnimal();
				break;
			case 5:
				pet->consultarFuncionario();
				break;
			case 6:
				pet->editarAnimal();
				break;
			case 7:
				pet->editarFuncionario();
				break;
			case 8:
				pet->removerAnimal();
				break;
			case 9:
				pet->removerFuncionario();
				break;
			case 0:	
				pet->gravarArquivoFuncionario();
				pet->atualizaArquivoAnimal();
				pet->desalocarObjetos();
				std::cout << "\n****************************** PETSHOP ENCERRADO *******************************\n";
				executa_menu = false;
				break;
			default:
				std::cout << "A opção digitada não existe. Tente novamente!\n";
				break;	
		}
	}while(escolha_menu < 0 || escolha_menu > 9);
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
