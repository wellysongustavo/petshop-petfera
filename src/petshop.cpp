#include <iostream>
#include <string>
#include <vector>

#include "funcionario.h"
#include "tratador.h"
#include "veterinario.h"
#include "animal.h"
#include "animal_silvestre.h"
#include "animal_nativo.h"
#include "animal_exotico.h"
#include "anfibio.h"
#include "anfibio_nativo.h"
#include "anfibio_exotico.h"
#include "mamifero.h"
#include "reptil.h"
#include "reptil_nativo.h"
#include "ave.h"
#include "date.h"
#include "petshop.h"

Petshop::Petshop(std::string nome) : m_nome(nome) { /* void */ }

Petshop::~Petshop() { /* void */ }

void Petshop::cadastrarAnfibio(int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {
	
	//criaçao dos veterinario e tratador só pra conseguir instanciar já que tá no construtor da classe animal
	Veterinario* vet1 = new Veterinario(2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador(1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);

	int total_de_mudas_;
	std::cout << "- Total de mudas do anfíbio: ";
	std::cin >> total_de_mudas_;

	int dia_, mes_, ano_;
	std::cout << "- Data da última muda do anfíbio (dia mês ano): ";
	std::cin >> dia_; std::cin >> mes_; std::cin >> ano_;
	date data_(dia_, mes_, ano_);

	int especie;
	std::cout << "- Espécie do anfíbio (1- Silvestre | 2- Doméstico): ";
	std::cin >> especie;

	if(especie == 1){
		std::string autorizacao_;
		std::cout << "- Autorização do anfíbio nativo: ";
		std::cin.ignore();
		std::getline( cin, autorizacao_);

		int area;
		std::cout << "- Área pertencente do anfíbio silvestre (1- Nativo | 2- Exótico): ";
		std::cin >> area;
		if(area == 1) {
			std::string uf_origem_;
			std::cout << "- Região de origem do anfíbio silvestre nativo: ";
			std::cin.ignore();
			std::getline( cin, uf_origem_);

			AnfibioNativo* nativo = new AnfibioNativo(id_, "Anfíbio", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, total_de_mudas_, data_, 
				autorizacao_, uf_origem_);

			this->vector_animais.push_back(*nativo);
			std::cout << "\nAnfibio " << nativo->getNomeCientifico() << " adicionado com sucesso." << std::endl;
			std::cout << this->vector_animais[0].getNomeCientifico() << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do anfíbio silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			AnfibioExotico* exotico = new AnfibioExotico(id_, "Anfíbio", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, total_de_mudas_, data_, 
				autorizacao_, pais_origem_);

			this->vector_animais.push_back(*exotico);
			std::cout << "\nAnfibio " << exotico->getNomeBatismo() << " adicionado com sucesso." << std::endl;	
		}
	}else {
		Anfibio* anfibio_domestico = new Anfibio(id_, "Anfíbio", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, total_de_mudas_, data_);
		this->vector_animais.push_back(*anfibio_domestico);
			std::cout << "\nAnfíbio " << anfibio_domestico->getNomeBatismo() << " adicionado com sucesso." << std::endl;
	}
}

void Petshop::cadastrarAnimal() { 
	int escolha_classe;
	std::cout << "\n****************************** CADASTRO DE ANIMAIS ******************************\n\n- Insira da classe do animal (1- Anfíbio | 2- Ave | 3- Mamífero | 4- Réptil): ";
	do{
		std::cin >> escolha_classe;
	}while(escolha_classe < 1 || escolha_classe > 4);

	int id_;
	std::cout << "- Id do animal: ";
	std::cin >> id_;

	std::string nome_cientifico_;
	std::cout << "- Insira o nome científico: ";
	std::cin.ignore();
	std::getline( cin, nome_cientifico_);

	char sexo_;
	std::cout << "- Sexo: ";
	std::cin >> sexo_;

	double tamanho_;
	std::cout << "- Tamanho: ";
	std::cin >> tamanho_;

	std::string dieta_;
	std::cout << "- Dieta: ";
	std::cin.ignore();
	std::getline( cin, dieta_);	

	int id_veterinario_;
	std::cout << "- Id do veterinário: ";
	std::cin >> id_veterinario_;

	int id_tratador_;
	std::cout << "- Id do tratador: ";
	std::cin >> id_tratador_;

	std::string nome_batismo_;
	std::cout << "- Nome de batismo: ";
	std::cin.ignore();
	std::getline( cin, nome_batismo_);

	switch(escolha_classe) {
		case 1:
			cadastrarAnfibio(id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;
		case 2:
			//cadastrarAve(id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;
		case 3:
			//cadastrarMamifero(id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;
		case 4:
			//cadastrarReptil(id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;

	}
}