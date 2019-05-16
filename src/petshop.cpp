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
#include "reptil_exotico.h"
#include "ave.h"
#include "ave_exotica.h"
#include "ave_nativa.h"
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

void Petshop::cadastrarReptil(int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {

	//criaçao dos veterinario e tratador só pra conseguir instanciar já que tá no construtor da classe animal
	Veterinario* vet1 = new Veterinario(2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador(1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);

	bool venenoso_;
	std::cout << "- O réptil é venenoso (1 para verdadeiro, 0 para falso)? ";
	std::cin >> venenoso_;

	std::string tipo_venenoso_;
	std::cout << "- Insira o tipo de veneno: ";
	std::cin.ignore();
	std::getline( cin, tipo_venenoso_);

	int especie;
	std::cout << "- Espécie do réptil (1- Silvestre | 2- Doméstico): ";
	std::cin >> especie;

	if(especie == 1){
		std::string autorizacao_;
		std::cout << "- Autorização do réptil nativo: ";
		std::cin.ignore();
		std::getline( cin, autorizacao_);

		int area;
		std::cout << "- Área pertencente do réptil silvestre (1- Nativo | 2- Exótico): ";
		std::cin >> area;
		if(area == 1) {
			std::string uf_origem_;
			std::cout << "- Região de origem do réptil silvestre nativo: ";
			std::cin.ignore();
			std::getline( cin, uf_origem_);

			ReptilNativo* nativo = new ReptilNativo(id_, "Réptil", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, venenoso_, tipo_venenoso_, 
				autorizacao_, uf_origem_);

			this->vector_animais.push_back(*nativo);
			std::cout << "\nRéptil " << nativo->getNomeCientifico() << " adicionado com sucesso." << std::endl;
			std::cout << this->vector_animais[0].getNomeCientifico() << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do réptil silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			ReptilExotico* exotico = new ReptilExotico(id_, "Réptil", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, venenoso_, tipo_venenoso_,
				autorizacao_, pais_origem_);

			this->vector_animais.push_back(*exotico);
			std::cout << "\nRéptil " << exotico->getNomeBatismo() << " adicionado com sucesso." << std::endl;	
		}
	}else {
		Reptil* reptil_domestico = new Reptil(id_, "Réptil", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, venenoso_, tipo_venenoso_);
			this->vector_animais.push_back(*reptil_domestico);
			std::cout << "\nRéptil " << reptil_domestico->getNomeBatismo() << " adicionado com sucesso." << std::endl;
	}
}

void Petshop::cadastrarAve(int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {

	//criaçao dos veterinario e tratador só pra conseguir instanciar já que tá no construtor da classe animal
	Veterinario* vet1 = new Veterinario(2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador(1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);

	double tamanho_do_bico_cm_;
	std::cout << "- Insira o tamanho do bico da ave (em cm): ";
	std::cin >> tamanho_do_bico_cm_;

	double envergadura_das_asas_;
	std::cout << "- Insira a envergadura das asas: ";
	std::cin >> envergadura_das_asas_;

	int especie;
	std::cout << "- Espécie do réptil (1- Silvestre | 2- Doméstico): ";
	std::cin >> especie;

	if(especie == 1){
		std::string autorizacao_;
		std::cout << "- Autorização da ave nativa: ";
		std::cin.ignore();
		std::getline( cin, autorizacao_);

		int area;
		std::cout << "- Área pertencente da ave silvestre (1- Nativa | 2- Exótica): ";
		std::cin >> area;
		if(area == 1) {
			std::string uf_origem_;
			std::cout << "- Região de origem do ave silvestre nativo: ";
			std::cin.ignore();
			std::getline( cin, uf_origem_);

			AveNativa* nativa = new AveNativa(id_, "Ave", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_, 
				autorizacao_, uf_origem_);

			this->vector_animais.push_back(*nativa);
			std::cout << "\nAve " << nativa->getNomeCientifico() << " adicionada com sucesso." << std::endl;
			std::cout << this->vector_animais[0].getNomeCientifico() << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do ave silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			AveExotica* exotica = new AveExotica(id_, "Ave", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_, 
				autorizacao_, pais_origem_);

			this->vector_animais.push_back(*exotica);
			std::cout << "\nAve " << exotica->getNomeBatismo() << " adicionada com sucesso." << std::endl;	
		}
	}else {
		Ave* ave_domestica = new Ave(id_, "Ave", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_);
		this->vector_animais.push_back(*ave_domestica);
			std::cout << "\nAve " << ave_domestica->getNomeBatismo() << " adicionada com sucesso." << std::endl;
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
			cadastrarAve(id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;
		case 3:
			//cadastrarMamifero(id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;
		case 4:
			cadastrarReptil(id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;

	}
}

void Petshop::cadastrarVeterinario(int id_, std::string nome_, std::string cpf_, int idade_, std::string tipo_sanguineo_, char fator_rh_, std::string especialidade_){
	std::string crmv_;
	std::cout << "- CRMV: ";
	std::cin.ignore();
	std::getline( cin, crmv_);

	Veterinario* vet = new Veterinario(id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_, crmv_);
	vector_veterinarios.push_back(*vet);

	std::cout << "Veterinário cadastrado com sucesso.\n" << std::endl;
	std::cout << vector_veterinarios[0];
}

void Petshop::cadastrarTratador(int id_, std::string nome_, std::string cpf_, int idade_, std::string tipo_sanguineo_, char fator_rh_, std::string especialidade_){
	int nivel_de_seguranca_;
	std::cout << "- Nível de segurança: ";
	std::cin >> nivel_de_seguranca_;	

	Tratador* trat = new Tratador(id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_, nivel_de_seguranca_);
	vector_tratadores.push_back(*trat);

	std::cout << "Tratador cadastrado com sucesso." << std::endl;
	std::cout << vector_tratadores[0];
}

void Petshop::cadastrarFuncionario(){
	int tipo_funcionario;
	std::cout << "\n**************************** CADASTRO DE FUNCIONÁRIOS ****************************\n\n- Insira (1- Veterinário | 2- Tratador ): ";
	do{
		std::cin >> tipo_funcionario;
	}while(tipo_funcionario < 1 || tipo_funcionario > 2);

	int id_;
	std::cout << "- Id do funcionário: ";
	std::cin >> id_;

	std::string nome_;
	std::cout << "- Nome: ";
	std::cin.ignore();
	std::getline( cin, nome_);

	std::string cpf_;
	std::cout << "- CPF: ";
	std::cin.ignore();
	std::getline( cin, cpf_);

	int idade_;
	std::cout << "- Idade: ";
	std::cin >> idade_;		
	
	std::string tipo_sanguineo_;
	std::cout << "- Tipo sanguíneo: ";
	std::cin.ignore();
	std::getline( cin, tipo_sanguineo_);

	char fator_rh_;
	std::cout << "- Fator RH: ";
	std::cin >> fator_rh_;	

	std::string especialidade_;
	std::cout << "- Especialidade: ";
	std::cin.ignore();
	std::getline( cin, especialidade_);

	switch(tipo_funcionario){
		case 1:
			cadastrarVeterinario(id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_);
		break;
		case 2:
			cadastrarTratador(id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_);
		break;
	}
}