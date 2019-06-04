#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <iterator>
#include <typeinfo>
#include <fstream>

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
#include "mamifero_nativo.h"
#include "mamifero_exotico.h"
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

int Petshop::buscarPorId(std::string tipo_map){
	bool match = false;
	int id;
	do{
		std::cout << "Id: ";
		std::cin >> id;

		if(tipo_map == "Animal"){

			std::map<int,Animal*>::iterator it;
			it = map_animais.find(id);
			if(it != map_animais.end()){
				match = true;
			}else{
				std::cout << "Id inexistente. Tente novamente!" << std::endl;
			}

		}else if(tipo_map == "Funcionario"){

			std::map<int,Funcionario*>::iterator it;
			it = map_funcionarios.find(id);
			if(it != map_funcionarios.end()){
				match = true;
			}else{
				std::cout << "Id inexistente. Tente novamente!" << std::endl;
			}

		}
	}while(match == false);
	return id;
}

std::fstream Petshop::abrirArquivo() {
	std::fstream arquivo_("controle_animais.csv", std::ios::in | std::ios::out | std::ios::app);

	if(!(arquivo_.is_open())) { 
		std::cerr << "ERRO! Abertura de arquivo inválida." << std:: endl; 
		exit(1);
	}
	arquivo_.seekg (0, arquivo_.end);
    int length = arquivo_.tellg();
    arquivo_.seekg (0, arquivo_.beg);

	if(length == 0) {
		arquivo_ << "****************************** CATÁLOGO DOS ANIMAIS ******************************\n\n";
	}
	return arquivo_;
}

void Petshop::cadastrarAnfibio(std::fstream& arquivo_, int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {
	
	//criaçao dos veterinario e tratador só pra conseguir instanciar já que tá no construtor da classe animal
	Veterinario* vet1 = new Veterinario("Veterinario", 2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador("Tratador", 1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);

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
		std::cout << "- Autorização do anfíbio silvestre: ";
		std::cin.ignore();
		std::getline( cin, autorizacao_);

		int area;
		std::cout << "- Área pertencente do anfíbio silvestre (1- Nativa | 2- Exótica): ";
		std::cin >> area;
		if(area == 1) {
			std::string uf_origem_;
			std::cout << "- Região de origem do anfíbio silvestre nativo: ";
			std::cin.ignore();
			std::getline( cin, uf_origem_);

			//SE CONSEGUIR LER DO CSV E SALVAR O QUE TEM NO CSV EM UM MAP, PARTES IGUAL ESSAS SÃO DESNECESSÁRIAS
			AnfibioNativo* nativo = new AnfibioNativo(id_, "AnfibioNativo", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, total_de_mudas_, data_, 
				autorizacao_, uf_origem_);

			this->map_animais.insert({id_, nativo});

			//escrevendo no csv
			arquivo_ <<  id_ << ";" << "AnfibioNativo" << ";" << nome_cientifico_ << ";" << sexo_ << ";" 
			<< tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" << trat1->getId() << ";" << nome_batismo_ 
			<< ";" << total_de_mudas_  << ";" << data_ << ";" << autorizacao_ << ";" << uf_origem_ << std::endl;
			
			std::cout << "\nAnfibio " << nome_batismo_ << " adicionado com sucesso." << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do anfíbio silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			AnfibioExotico* exotico = new AnfibioExotico(id_, "AnfibioExotico", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, total_de_mudas_, data_, 
				autorizacao_, pais_origem_);
			
			this->map_animais.insert({id_, exotico});

			//escrevendo no csv
			arquivo_ <<  id_ << ";" << "AnfibioExotico" << ";" << nome_cientifico_ << ";" << sexo_ << ";" 
			<< tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" << trat1->getId() << ";" << nome_batismo_ 
			<< ";" << total_de_mudas_  << ";" << data_ << ";" << autorizacao_ << ";" << pais_origem_ << std::endl;
			
			std::cout << "\nAnfibio " << nome_batismo_ << " adicionado com sucesso." << std::endl;
		}
	}else {
		Anfibio* anfibio_domestico = new Anfibio(id_, "Anfibio", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, total_de_mudas_, data_);
		
		this->map_animais.insert({id_, anfibio_domestico});

		//escrevendo no csv
		arquivo_ << id_ << ";" << "Anfibio" << ";" << nome_cientifico_ << ";" << sexo_ << ";" 
		<< tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" << trat1->getId() << ";" << nome_batismo_ 
		<< ";" << total_de_mudas_  << ";" << data_ << std::endl;
		
		std::cout << "\nAnfibio " << nome_batismo_ << " adicionado com sucesso." << std::endl;
	}
}

void Petshop::cadastrarReptil(std::fstream& arquivo_, int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {

	//criaçao dos veterinario e tratador só pra conseguir instanciar já que tá no construtor da classe animal
	Veterinario* vet1 = new Veterinario("Veterinario", 2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador("Tratador", 1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);

	bool venenoso_;
	std::cout << "- O réptil é venenoso (1 para verdadeiro, 0 para falso)? ";
	std::cin >> venenoso_;

	std::string tipo_venenoso_;
	if(venenoso_ == 1){
		std::cout << "- Insira o tipo de veneno: ";
		std::cin.ignore();
		std::getline( cin, tipo_venenoso_);
	}
	int especie;
	std::cout << "- Espécie do réptil (1- Silvestre | 2- Doméstico): ";
	std::cin >> especie;

	if(especie == 1){
		std::string autorizacao_;
		std::cout << "- Autorização do réptil silvestre: ";
		std::cin.ignore();
		std::getline( cin, autorizacao_);

		int area;
		std::cout << "- Área pertencente do réptil silvestre (1- Nativa | 2- Exótica): ";
		std::cin >> area;
		if(area == 1) {
			std::string uf_origem_;
			std::cout << "- Região de origem do réptil silvestre nativo: ";
			std::cin.ignore();
			std::getline( cin, uf_origem_);

			ReptilNativo* nativo = new ReptilNativo(id_, "ReptilNativo", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, venenoso_, tipo_venenoso_, 
				autorizacao_, uf_origem_);
			
			this->map_animais.insert({id_, nativo});

			//escrevendo no csv
			arquivo_ << id_ << ";" << "ReptilNativo" << ";" << nome_cientifico_ << ";"
			<< sexo_ << ";" << tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" 
			<< trat1->getId() << ";" << nome_batismo_ << ";" << venenoso_ << ";"
			<< tipo_venenoso_ << ";" << autorizacao_ << ";" << uf_origem_ << std::endl;

			std::cout << "\nRéptil " << nome_batismo_ << " adicionado com sucesso." << std::endl;
			
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do réptil silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			ReptilExotico* exotico = new ReptilExotico(id_, "ReptilExotico", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, venenoso_, tipo_venenoso_,
				autorizacao_, pais_origem_);
			
			this->map_animais.insert({id_, exotico});

			//escrevendo no csv
			arquivo_ << id_ << ";" << "ReptilExotico" << ";" << nome_cientifico_ << ";"
			<< sexo_ << ";" << tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" 
			<< trat1->getId() << ";" << nome_batismo_ << ";" << venenoso_ << ";"
			<< tipo_venenoso_ << ";" << autorizacao_ << ";" << pais_origem_ << std::endl;

			std::cout << "\nRéptil " << nome_batismo_ << " adicionado com sucesso." << std::endl;
		}
	}else {
		Reptil* reptil_domestico = new Reptil(id_, "Reptil", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, venenoso_, tipo_venenoso_);
			
		this->map_animais.insert({id_, reptil_domestico});
		
		//escrevendo no csv
		arquivo_ << id_ << ";" << "Reptil" << ";" << nome_cientifico_ << ";"
		<< sexo_ << ";" << tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" 
		<< trat1->getId() << ";" << nome_batismo_ << ";" << venenoso_ << ";"
		<< tipo_venenoso_ << std::endl;

		std::cout << "\nRéptil " << nome_batismo_ << " adicionado com sucesso." << std::endl;
	}
}

void Petshop::cadastrarAve(std::fstream& arquivo_, int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {

	//criaçao dos veterinario e tratador só pra conseguir instanciar já que tá no construtor da classe animal
	Veterinario* vet1 = new Veterinario("Veterinario", 2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador("Tratador", 1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);

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
		std::cout << "- Autorização da ave silvestre: ";
		std::cin.ignore();
		std::getline( cin, autorizacao_);

		int area;
		std::cout << "- Área pertencente da ave silvestre (1- Nativa | 2- Exótica): ";
		std::cin >> area;
		if(area == 1) {
			std::string uf_origem_;
			std::cout << "- Região de origem do ave silvestre nativa: ";
			std::cin.ignore();
			std::getline( cin, uf_origem_);

			AveNativa* nativa = new AveNativa(id_, "AveNativa", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_, 
				autorizacao_, uf_origem_);
			
			this->map_animais.insert({id_, nativa});

			//escrevendo no csv
			arquivo_ << id_ << ";" << "AveNativa" << ";" << nome_cientifico_ << ";"
			<< sexo_ << ";" << tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" 
			<< trat1->getId() << ";" << nome_batismo_ << ";" << tamanho_do_bico_cm_ << ";" 
			<< envergadura_das_asas_ << ";" << autorizacao_ << ";" << uf_origem_ << std::endl;

			std::cout << "\nAve " << nome_batismo_ << " adicionada com sucesso." << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do ave silvestre exótica: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);
			
			AveExotica* exotica = new AveExotica(id_, "AveExotica", nome_cientifico_, sexo_, tamanho_,
							dieta_, *vet1, *trat1, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_, 
							autorizacao_, pais_origem_);
						
			this->map_animais.insert({id_, exotica});
			
			//escrevendo no csv		
			arquivo_ << id_ << ";" << "AveExotica" << ";" << nome_cientifico_ << ";"
			<< sexo_ << ";" << tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" 
			<< trat1->getId() << ";" << nome_batismo_ << ";" << tamanho_do_bico_cm_ << ";" 
			<< envergadura_das_asas_ << ";" << autorizacao_ << ";" << pais_origem_ << std::endl;

			std::cout << "\nAve " << nome_batismo_ << " adicionada com sucesso." << std::endl;	
		}
	}else {
		Ave* ave_domestica = new Ave(id_, "Ave", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_);
		
		this->map_animais.insert({id_, ave_domestica});
		
		//escrevendo no csv		
		arquivo_ << id_ << ";" << "Ave" << ";" << nome_cientifico_ << ";"
		<< sexo_ << ";" << tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" 
		<< trat1->getId() << ";" << nome_batismo_ << ";" << tamanho_do_bico_cm_ << ";" 
		<< envergadura_das_asas_ << std::endl;

		std::cout << "\nAve " << nome_batismo_ << " adicionada com sucesso." << std::endl;
		
	}
}

void Petshop::cadastrarMamifero(std::fstream& arquivo_, int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {
	
	//criaçao dos veterinario e tratador só pra conseguir instanciar já que tá no construtor da classe animal
	Veterinario* vet1 = new Veterinario("Veterinario", 2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador("Tratador", 1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);

	std::string cor_pelo_;
	std::cout << "- Cor de Pelo: ";
	std::cin >> cor_pelo_;

	int especie;
	std::cout << "- Espécie do mamífero (1- Silvestre | 2- Doméstico): ";
	std::cin >> especie;

	if(especie == 1){
		std::string autorizacao_;
		std::cout << "- Autorização do mamífero silvestre: ";
		std::cin.ignore();
		std::getline( cin, autorizacao_);

		int area;
		std::cout << "- Área pertencente do mamífero silvestre (1- Nativa | 2- Exótica): ";
		std::cin >> area;
		if(area == 1) {
			std::string uf_origem_;
			std::cout << "- Região de origem do mamífero silvestre nativo: ";
			std::cin.ignore();
			std::getline( cin, uf_origem_);

			MamiferoNativo* nativo = new MamiferoNativo(id_, "MamiferoNativo", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, cor_pelo_, autorizacao_, uf_origem_);
			
			this->map_animais.insert({id_, nativo});

			//escrevendo no csv
			arquivo_ << id_ << ";" << "MamiferoNativo" << ";" << nome_cientifico_ << ";"
			<< sexo_ << ";" << tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" 
			<< trat1->getId() << ";" << nome_batismo_ << ";" << cor_pelo_ << ";" 
			<< autorizacao_ << ";" << uf_origem_ << std::endl;

			std::cout << "\nMamífero " << nome_batismo_ << " adicionada com sucesso." << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do mamífero silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			MamiferoExotico* exotico = new MamiferoExotico(id_, "MamiferoExotico", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, cor_pelo_, autorizacao_, pais_origem_);
			
			this->map_animais.insert({id_, exotico});

			//escrevendo no csv
			arquivo_ << id_ << ";" << "MamiferoExotico" << ";" << nome_cientifico_ << ";"
			<< sexo_ << ";" << tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" 
			<< trat1->getId() << ";" << nome_batismo_ << ";" << cor_pelo_ << ";" 
			<< autorizacao_ << ";" << pais_origem_ << std::endl;

			std::cout << "\nMamífero " << nome_batismo_ << " adicionada com sucesso." << std::endl;
		}
	}else {

			Mamifero* mamifero_domestico = new Mamifero(id_, "Mamifero", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, cor_pelo_);
		
			this->map_animais.insert({id_, mamifero_domestico});
			
			//escrevendo no csv
			arquivo_ << id_ << ";" << "MamiferoNativo" << ";" << nome_cientifico_ << ";"
			<< sexo_ << ";" << tamanho_ << ";" << dieta_ << ";" << vet1->getId() << ";" 
			<< trat1->getId() << ";" << nome_batismo_ << ";" << cor_pelo_ << std::endl;

			std::cout << "\nMamífero " << nome_batismo_ << " adicionada com sucesso." << std::endl;
	}
}

void Petshop::cadastrarAnimal() { 
	int escolha_classe;
	std::fstream arquivo = abrirArquivo();

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
			cadastrarAnfibio(arquivo, id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;
		case 2:
			cadastrarAve(arquivo, id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;
		case 3:
			cadastrarMamifero(arquivo, id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;
		case 4:
			cadastrarReptil(arquivo, id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;

	}
	arquivo.close();
}

void Petshop::listarAnimais() {
	std::fstream arquivo = abrirArquivo();

	while(arquivo.good()) {
		std::string linha;
		std::getline(arquivo, linha, ';');
		//std::cout << linha << std::endl;
	}
	/*
	std::map<int, Animal*>::iterator itr_t;
	std::cout << "\n****************************** ANIMAIS CADASTRADOS ******************************\n" << std::endl;
	for(itr_t = map_animais.begin(); itr_t != map_animais.end(); itr_t++){
		//Verificação para anfibios
		if(itr_t->second->getClasse() == "Anfibio"){
			std::cout << *(dynamic_cast<Anfibio*>(itr_t->second)) << std::endl;
		}
		if(itr_t->second->getClasse() == "AnfibioNativo"){
			std::cout << *(dynamic_cast<AnfibioNativo*>(itr_t->second)) << std::endl;
		}
		if(itr_t->second->getClasse() == "AnfibioExotico"){
			std::cout << *(dynamic_cast<AnfibioExotico*>(itr_t->second)) << std::endl;
		}
		//Verificação para aves
		if(itr_t->second->getClasse() == "Ave"){
			std::cout << *(dynamic_cast<Ave*>(itr_t->second)) << std::endl;
		}
		if(itr_t->second->getClasse() == "AveNativa"){
			std::cout << *(dynamic_cast<AveNativa*>(itr_t->second)) << std::endl;
		}
		if(itr_t->second->getClasse() == "AveExotica"){
			std::cout << *(dynamic_cast<AveExotica*>(itr_t->second)) << std::endl;
		}
		//Verificação para mamíferos
		if(itr_t->second->getClasse() == "Mamifero"){
			std::cout << *(dynamic_cast<Mamifero*>(itr_t->second)) << std::endl;
		}
		if(itr_t->second->getClasse() == "MamiferoNativo"){
			std::cout << *(dynamic_cast<MamiferoNativo*>(itr_t->second)) << std::endl;
		}
		if(itr_t->second->getClasse() == "MamiferoExotico"){
			std::cout << *(dynamic_cast<MamiferoExotico*>(itr_t->second)) << std::endl;
		}
		//Verificação para répteis
		if(itr_t->second->getClasse() == "Reptil"){
			std::cout << *(dynamic_cast<Reptil*>(itr_t->second)) << std::endl;
		}
		if(itr_t->second->getClasse() == "ReptilNativo"){
			std::cout << *(dynamic_cast<ReptilNativo*>(itr_t->second)) << std::endl;
		}
		if(itr_t->second->getClasse() == "ReptilExotico"){
			std::cout << *(dynamic_cast<ReptilExotico*>(itr_t->second)) << std::endl;
		}
	}*/
}

void Petshop::editarAnimal() {
	std::cout << "\n********************************* EDITAR ANIMAIS ********************************" << std::endl;
	listarAnimais();
	int id_animal;
	bool match = false;
	std::map<int, Animal*>::iterator it;

	std::string novo_id, novo_nome_cientifico, novo_sexo, novo_tamanho, nova_dieta, novo_nome_batismo;

	do{
		std::cout << "\n- Insira o ID do animal que deseja editar: ";
		std::cin >> id_animal;
		it = map_animais.find(id_animal);
		if(it != map_animais.end()){
			match = true;
			
			std::cout << "\n- Preencha com o novo valor caso deseje alterar ou '*' para manter o antigo:\n\n- Id [" << it->second->getId() << "]: ";
			std::cin >> novo_id;
			if(novo_id != "*") { it->second->setId(std::stoi(novo_id)); }

			std::cout << "- Nome científico [" << it->second->getNomeCientifico() << "]: ";
			std::cin >> novo_nome_cientifico;
			if(novo_nome_cientifico != "*") { it->second->setNomeCientifico(novo_nome_cientifico); }

			std::cout << "- Sexo [" << it->second->getSexo() << "]: ";
			std::cin >> novo_sexo;
			char * aux = new char [novo_sexo.length()+1];
			std::strcpy (aux, novo_sexo.c_str());
			if(novo_sexo != "*") { it->second->setSexo(*aux); }

			std::cout << "- Tamanho [" << it->second->getTamanho() << "]: ";
			std::cin >> novo_tamanho;
			if(novo_tamanho != "*") { it->second->setTamanho(std::stod(novo_tamanho)); }

			std::cout << "- Dieta [" << it->second->getDieta() << "]: ";
			std::cin >> nova_dieta;
			if(nova_dieta != "*") { it->second->setDieta(nova_dieta); }

			std::cout << "- Nome de batismo [" << it->second->getNomeBatismo() << "]: ";
			std::cin >> novo_nome_batismo;
			if(novo_nome_batismo != "*") { it->second->setNomeBatismo(novo_nome_batismo); }

			//FALTA VER COMO PEGAR APENAS ID VETERINARIO E ID TRATADOR
			
			if(it->second->getClasse() == "Anfibio"){
				std::string total_de_mudas, dia, mes, ano;

				std::cout << "- Total de mudas [" << dynamic_cast<Anfibio*>(it->second)->getTotalMudas() << "]: ";
				std::cin >> total_de_mudas;
				if(total_de_mudas != "*") { dynamic_cast<Anfibio*>(it->second)->setTotalMudas(std::stoi(total_de_mudas)); }

				std::cout << "- Data da última muda [" << dynamic_cast<Anfibio*>(it->second)->getUltimaMuda() << "] (dia mes ano): ";
				std::cin >> dia; std::cin >> mes; std::cin >> ano;
				if(dia != "*" && mes != "*" && ano != "*") { 
					date ultima_muda(std::stoi(dia), std::stoi(mes), std::stoi(ano));
					dynamic_cast<Anfibio*>(it->second)->setUltimaMuda(ultima_muda); }
			}
			if(it->second->getClasse() == "AnfibioNativo"){
				std::string total_de_mudas_nativo, dia_nativo, mes_nativo, ano_nativo, autorizacao_nativo, uf_origem_nativo;

				std::cout << "- Total de mudas [" << dynamic_cast<AnfibioNativo*>(it->second)->getTotalMudas() << "]: ";
				std::cin >> total_de_mudas_nativo;
				if(total_de_mudas_nativo != "*") { dynamic_cast<AnfibioNativo*>(it->second)->setTotalMudas(std::stoi(total_de_mudas_nativo)); }

				std::cout << "- Data da última muda [" << dynamic_cast<AnfibioNativo*>(it->second)->getUltimaMuda() << "] (dia mes ano): ";
				std::cin >> dia_nativo; std::cin >> mes_nativo; std::cin >> ano_nativo;
				if(dia_nativo != "*" && mes_nativo != "*" && ano_nativo != "*") { 
					date ultima_muda_nativo(std::stoi(dia_nativo), std::stoi(mes_nativo), std::stoi(ano_nativo));
					dynamic_cast<AnfibioNativo*>(it->second)->setUltimaMuda(ultima_muda_nativo); }

				std::cout << "- Autorização [" << dynamic_cast<AnfibioNativo*>(it->second)->getAutorizacao() << "]: ";
				std::cin >> autorizacao_nativo;
				if(autorizacao_nativo != "*") { dynamic_cast<AnfibioNativo*>(it->second)->setAutorizacao(autorizacao_nativo); }

				std::cout << "- UF de origem [" << dynamic_cast<AnfibioNativo*>(it->second)->getUfOrigem() << "]: ";
				std::cin >> uf_origem_nativo;
				if(uf_origem_nativo != "*") { dynamic_cast<AnfibioNativo*>(it->second)->setUfOrigem(uf_origem_nativo); }
			}
			if(it->second->getClasse() == "AnfibioExotico"){
				std::string total_de_mudas_exotico, dia_exotico, mes_exotico, ano_exotico, autorizacao_exotico, pais_origem_exotico;

				std::cout << "- Total de mudas [" << dynamic_cast<AnfibioExotico*>(it->second)->getTotalMudas() << "]: ";
				std::cin >> total_de_mudas_exotico;
				if(total_de_mudas_exotico != "*") { dynamic_cast<AnfibioExotico*>(it->second)->setTotalMudas(std::stoi(total_de_mudas_exotico)); }

				std::cout << "- Data da última muda [" << dynamic_cast<AnfibioExotico*>(it->second)->getUltimaMuda() << "] (dia mes ano): ";
				std::cin >> dia_exotico; std::cin >> mes_exotico; std::cin >> ano_exotico;
				if(dia_exotico != "*" && mes_exotico != "*" && ano_exotico != "*") { 
					date ultima_muda_exotico(std::stoi(dia_exotico), std::stoi(mes_exotico), std::stoi(ano_exotico));
					dynamic_cast<AnfibioNativo*>(it->second)->setUltimaMuda(ultima_muda_exotico); }

				std::cout << "- Autorização [" << dynamic_cast<AnfibioExotico*>(it->second)->getAutorizacao() << "]: ";
				std::cin >> autorizacao_exotico;
				if(autorizacao_exotico != "*") { dynamic_cast<AnfibioExotico*>(it->second)->setAutorizacao(autorizacao_exotico); }

				std::cout << "- País de origem [" << dynamic_cast<AnfibioExotico*>(it->second)->getPaisOrigem() << "]: ";
				std::cin >> pais_origem_exotico;
				if(pais_origem_exotico != "*") { dynamic_cast<AnfibioExotico*>(it->second)->setPaisOrigem(pais_origem_exotico); }
			}
			//Verificação para aves
			if(it->second->getClasse() == "Ave"){
				std::string tamanho_do_bico_cm, envergadura_das_asas;

				std::cout << "- Tamanho do bico em cm [" << dynamic_cast<Ave*>(it->second)->getTamanhoBico() << "]: ";
				std::cin >> tamanho_do_bico_cm;
				if(tamanho_do_bico_cm != "*") { dynamic_cast<Ave*>(it->second)->setTamanhoBico(std::stod(tamanho_do_bico_cm)); }

				std::cout << "- Envergadura das asas em cm [" << dynamic_cast<Ave*>(it->second)->getEnvergaduraAsas() << "]: ";
				std::cin >> envergadura_das_asas;
				if(envergadura_das_asas != "*") { dynamic_cast<Ave*>(it->second)->setEnvergaduraAsas(std::stod(envergadura_das_asas)); }
			}
			if(it->second->getClasse() == "AveNativa"){
				std::string tamanho_do_bico_cm_nativa, envergadura_das_asas_nativa, autorizacao_nativa, uf_origem_nativa;

				std::cout << "- Tamanho do bico em cm [" << dynamic_cast<AveNativa*>(it->second)->getTamanhoBico() << "]: ";
				std::cin >> tamanho_do_bico_cm_nativa;
				if(tamanho_do_bico_cm_nativa != "*") { dynamic_cast<AveNativa*>(it->second)->setTamanhoBico(std::stod(tamanho_do_bico_cm_nativa)); }

				std::cout << "- Envergadura das asas em cm [" << dynamic_cast<AveNativa*>(it->second)->getEnvergaduraAsas() << "]: ";
				std::cin >> envergadura_das_asas_nativa;
				if(envergadura_das_asas_nativa != "*") { dynamic_cast<AveNativa*>(it->second)->setEnvergaduraAsas(std::stod(envergadura_das_asas_nativa)); }
					
				std::cout << "- Autorização [" << dynamic_cast<AveNativa*>(it->second)->getAutorizacao() << "]: ";
				std::cin >> autorizacao_nativa;
				if(autorizacao_nativa != "*") { dynamic_cast<AveNativa*>(it->second)->setAutorizacao(autorizacao_nativa); }

				std::cout << "- UF de origem [" << dynamic_cast<AveNativa*>(it->second)->getUfOrigem() << "]: ";
				std::cin >> uf_origem_nativa;
				if(uf_origem_nativa != "*") { dynamic_cast<AveNativa*>(it->second)->setUfOrigem(uf_origem_nativa); }			
			}
			if(it->second->getClasse() == "AveExotica"){
				std::string tamanho_do_bico_cm_exotica, envergadura_das_asas_exotica, autorizacao_exotica, pais_origem_exotica;

				std::cout << "- Tamanho do bico em cm [" << dynamic_cast<AveExotica*>(it->second)->getTamanhoBico() << "]: ";
				std::cin >> tamanho_do_bico_cm_exotica;
				if(tamanho_do_bico_cm_exotica != "*") { dynamic_cast<AveExotica*>(it->second)->setTamanhoBico(std::stod(tamanho_do_bico_cm_exotica)); }

				std::cout << "- Envergadura das asas em cm [" << dynamic_cast<AveExotica*>(it->second)->getEnvergaduraAsas() << "]: ";
				std::cin >> envergadura_das_asas_exotica;
				if(envergadura_das_asas_exotica != "*") { dynamic_cast<AveExotica*>(it->second)->setEnvergaduraAsas(std::stod(envergadura_das_asas_exotica)); }
					
				std::cout << "- Autorização [" << dynamic_cast<AveExotica*>(it->second)->getAutorizacao() << "]: ";
				std::cin >> autorizacao_exotica;
				if(autorizacao_exotica != "*") { dynamic_cast<AveExotica*>(it->second)->setAutorizacao(autorizacao_exotica); }

				std::cout << "- UF de origem [" << dynamic_cast<AveExotica*>(it->second)->getPaisOrigem() << "]: ";
				std::cin >> pais_origem_exotica;
				if(pais_origem_exotica != "*") { dynamic_cast<AveExotica*>(it->second)->setPaisOrigem(pais_origem_exotica); }				
			}
			//Verificação para mamíferos
			if(it->second->getClasse() == "Mamifero"){
				std::string cor_pelo;

				std::cout << "- Cor do pelo [" << dynamic_cast<Mamifero*>(it->second)->getCorPelo() << "]: ";
				std::cin >> cor_pelo;
				if(cor_pelo != "*") { dynamic_cast<Mamifero*>(it->second)->setCorPelo(cor_pelo); }	
			}
			if(it->second->getClasse() == "MamiferoNativo"){				
				std::string cor_pelo_nativo, autorizacao_mamifero_nativo, uf_origem_mamifero_nativo;

				std::cout << "- Cor do pelo [" << dynamic_cast<MamiferoNativo*>(it->second)->getCorPelo() << "]: ";
				std::cin >> cor_pelo_nativo;
				if(cor_pelo_nativo != "*") { dynamic_cast<MamiferoNativo*>(it->second)->setCorPelo(cor_pelo_nativo); }
				
				std::cout << "- Autorização [" << dynamic_cast<MamiferoNativo*>(it->second)->getAutorizacao() << "]: ";
				std::cin >> autorizacao_mamifero_nativo;
				if(autorizacao_mamifero_nativo != "*") { dynamic_cast<MamiferoNativo*>(it->second)->setAutorizacao(autorizacao_mamifero_nativo); }

				std::cout << "- UF de origem [" << dynamic_cast<MamiferoNativo*>(it->second)->getUfOrigem() << "]: ";
				std::cin >> uf_origem_mamifero_nativo;
				if(uf_origem_mamifero_nativo != "*") { dynamic_cast<MamiferoNativo*>(it->second)->setUfOrigem(uf_origem_mamifero_nativo); }			
			}
			if(it->second->getClasse() == "MamiferoExotico"){				
				std::string cor_pelo_exotico, autorizacao_mamifero_exotico, pais_origem_mamifero_exotico;

				std::cout << "- Cor do pelo [" << dynamic_cast<MamiferoExotico*>(it->second)->getCorPelo() << "]: ";
				std::cin >> cor_pelo_exotico;
				if(cor_pelo_exotico != "*") { dynamic_cast<MamiferoExotico*>(it->second)->setCorPelo(cor_pelo_exotico); }
				
				std::cout << "- Autorização [" << dynamic_cast<MamiferoExotico*>(it->second)->getAutorizacao() << "]: ";
				std::cin >> autorizacao_mamifero_exotico;
				if(autorizacao_mamifero_exotico != "*") { dynamic_cast<MamiferoExotico*>(it->second)->setAutorizacao(autorizacao_mamifero_exotico); }

				std::cout << "- UF de origem [" << dynamic_cast<MamiferoExotico*>(it->second)->getPaisOrigem() << "]: ";
				std::cin >> pais_origem_mamifero_exotico;
				if(pais_origem_mamifero_exotico != "*") { dynamic_cast<MamiferoExotico*>(it->second)->setPaisOrigem(pais_origem_mamifero_exotico); }			
			}
			//Verificação para répteis
			if(it->second->getClasse() == "Reptil"){
				std::string venenoso, tipo_venenoso;
				
				std::cout << "- Venenoso [" << dynamic_cast<Reptil*>(it->second)->getVenenoso() << "] (1 para verdadeiro, 0 para falso): ";
				std::cin >> venenoso;
				bool bool_venenoso = (venenoso == "1");
				if(venenoso != "*") { dynamic_cast<Reptil*>(it->second)->setVenenoso(bool_venenoso); }	

				if(dynamic_cast<Reptil*>(it->second)->getVenenoso() == 1) {
					std::cout << "- Tipo venenoso [" << dynamic_cast<Reptil*>(it->second)->getTipoVenenoso() << "]: ";
					std::cin >> tipo_venenoso; 
					if(tipo_venenoso != "*") { dynamic_cast<Reptil*>(it->second)->setTipoVenenoso(tipo_venenoso); }
					else {
						dynamic_cast<Reptil*>(it->second)->setTipoVenenoso("Não informado");
					}
				}else {
					dynamic_cast<Reptil*>(it->second)->setTipoVenenoso("");
					std::cout << "- Tipo venenoso [" << dynamic_cast<Reptil*>(it->second)->getTipoVenenoso() << "]: " << std::endl;
				}			
			}
			if(it->second->getClasse() == "ReptilNativo"){
				std::string venenoso_nativo, tipo_venenoso_nativo, autorizacao_reptil_nativo, uf_origem_reptil_nativo;
				
				std::cout << "- Venenoso [" << dynamic_cast<ReptilNativo*>(it->second)->getVenenoso() << "] (1 para verdadeiro, 0 para falso): ";
				std::cin >> venenoso_nativo;
				bool bool_venenoso_nativo = (venenoso_nativo == "1");
				if(venenoso_nativo != "*") { dynamic_cast<ReptilNativo*>(it->second)->setVenenoso(bool_venenoso_nativo); }	

				std::cout << "- Tipo venenoso [" << dynamic_cast<ReptilNativo*>(it->second)->getTipoVenenoso() << "]: ";
				std::cin >> tipo_venenoso_nativo; 
				if(tipo_venenoso_nativo != "*") { dynamic_cast<ReptilNativo*>(it->second)->setTipoVenenoso(tipo_venenoso_nativo); }	

				std::cout << "- Autorização [" << dynamic_cast<ReptilNativo*>(it->second)->getAutorizacao() << "]: ";
				std::cin >> autorizacao_reptil_nativo;
				if(autorizacao_reptil_nativo != "*") { dynamic_cast<ReptilNativo*>(it->second)->setAutorizacao(autorizacao_reptil_nativo); }

				std::cout << "- UF de origem [" << dynamic_cast<ReptilNativo*>(it->second)->getUfOrigem() << "]: ";
				std::cin >> uf_origem_reptil_nativo;
				if(uf_origem_reptil_nativo != "*") { dynamic_cast<ReptilNativo*>(it->second)->setUfOrigem(uf_origem_reptil_nativo); }						
			}
			if(it->second->getClasse() == "ReptilExotico"){
				std::string venenoso_exotico, tipo_venenoso_exotico, autorizacao_reptil_exotico, pais_origem_reptil_exotico;
				
				std::cout << "- Venenoso [" << dynamic_cast<ReptilExotico*>(it->second)->getVenenoso() << "] (1 para verdadeiro, 0 para falso): ";
				std::cin >> venenoso_exotico;
				bool bool_venenoso_exotico = (venenoso_exotico == "1");
				if(venenoso_exotico != "*") { dynamic_cast<ReptilExotico*>(it->second)->setVenenoso(bool_venenoso_exotico); }	

				std::cout << "- Tipo venenoso [" << dynamic_cast<ReptilExotico*>(it->second)->getTipoVenenoso() << "]: ";
				std::cin >> tipo_venenoso_exotico; 
				if(tipo_venenoso_exotico != "*") { dynamic_cast<ReptilExotico*>(it->second)->setTipoVenenoso(tipo_venenoso_exotico); }	

				std::cout << "- Autorização [" << dynamic_cast<ReptilExotico*>(it->second)->getAutorizacao() << "]: ";
				std::cin >> autorizacao_reptil_exotico;
				if(autorizacao_reptil_exotico != "*") { dynamic_cast<ReptilExotico*>(it->second)->setAutorizacao(autorizacao_reptil_exotico); }

				std::cout << "- UF de origem [" << dynamic_cast<ReptilExotico*>(it->second)->getPaisOrigem() << "]: ";
				std::cin >> pais_origem_reptil_exotico;
				if(pais_origem_reptil_exotico != "*") { dynamic_cast<ReptilExotico*>(it->second)->setPaisOrigem(pais_origem_reptil_exotico); }				
			}
			std::cout << "\nAnimal atualizado com sucesso!" << std::endl;
		}else{
			std::cout << "Id inexistente. Tente novamente!" << std::endl;
		}
	}while(match == false);
}	

void Petshop::removerAnimal(){
	int id_animal;
	bool match = false;
	std::map<int, Animal*>::iterator it;

	do{
		std::cout << "Id do animal: ";
		std::cin >> id_animal;
		it = map_animais.find(id_animal);
		if(it != map_animais.end()){
			map_animais.erase(id_animal);
			match = true;
		}else{
			std::cout << "Id inexistente. Tente novamente!" << std::endl;
		}

	}while(match == false);

	std::cout << "Animal removido.\n" << std::endl; 
}

void Petshop::consultarAnimal(){
	int escolha_consulta;

	std::cout << "1 - Pesquisar por id" << std::endl;
	std::cout << "2 - Pesquisar por classe" << std::endl;
	std::cout << "3 - Pesquisar por tratador" << std::endl;
	std::cout << "4 - Pesquisar por veterinário" << std::endl;
	std::cin >> escolha_consulta;

	std::map<int, Animal*>::iterator itr_t;

	 if (escolha_consulta == 1) {
		int id_animal;
		bool match = false;

		do {
			std::cout << "Id do animal: ";
			std::cin >> id_animal;

			itr_t = map_animais.find(id_animal);
			if(itr_t != map_animais.end()){ 
				std::cout << "Animal Encontrado" << std::endl;	
				if(itr_t->second->getClasse() == "Anfibio"){
					std::cout << *(dynamic_cast<Anfibio*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "AnfibioNativo"){
					std::cout << *(dynamic_cast<AnfibioNativo*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "AnfibioExotico"){
					std::cout << *(dynamic_cast<AnfibioExotico*>(itr_t->second)) << std::endl;
				}
				//Verificação para aves
				else if(itr_t->second->getClasse() == "Ave"){
					std::cout << *(dynamic_cast<Ave*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "AveNativa"){
					std::cout << *(dynamic_cast<AveNativa*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "AveExotica"){
					std::cout << *(dynamic_cast<AveExotica*>(itr_t->second)) << std::endl;
				}
				//Verificação para mamíferos
				else if(itr_t->second->getClasse() == "Mamifero"){
					std::cout << *(dynamic_cast<Mamifero*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "MamiferoNativo"){
					std::cout << *(dynamic_cast<MamiferoNativo*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "MamiferoExotico"){
					std::cout << *(dynamic_cast<MamiferoExotico*>(itr_t->second)) << std::endl;
				}
				//Verificação para répteis
				else if(itr_t->second->getClasse() == "Reptil"){
					std::cout << *(dynamic_cast<Reptil*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "ReptilNativo"){
					std::cout << *(dynamic_cast<ReptilNativo*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "ReptilExotico"){
					std::cout << *(dynamic_cast<ReptilExotico*>(itr_t->second)) << std::endl;
				}
					
				match = true;
			}else{
				std::cout << "Id inexistente. Tente novamente!" << std::endl;
			}

		}while(match == false);
		
		
	 } else if (escolha_consulta == 2) {
		
		/* bool match = false;
		int classe_animal;
		int nativo_ou_exotico;
		std::cout << "Insira da classe do animal (1- Anfíbio | 2- Ave | 3- Mamífero | 4- Réptil): ";
		do {
			std::cin >> classe_animal;
		} while (classe_animal < 1 || classe_animal > 4);
		std::cout << "Insira da classe do animal (1- Nativo | 2- Exotico | 3-Doméstico): ";
		do {
			std::cin >> nativo_ou_exotico;
		} while (nativo_ou_exotico < 1 || nativo_ou_exotico > 3);

		do {
			std::cout << "Id do animal: ";
			std::cin >> id_animal;

			itr_t = map_animais.find(id_animal);
			if(itr_t != map_animais.end()){ 
				std::cout << "Animal Encontrado" << std::endl;	
				if(itr_t->second->getClasse() == "Anfibio"){
					std::cout << *(dynamic_cast<Anfibio*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "AnfibioNativo"){
					std::cout << *(dynamic_cast<AnfibioNativo*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "AnfibioExotico"){
					std::cout << *(dynamic_cast<AnfibioExotico*>(itr_t->second)) << std::endl;
				}
				//Verificação para aves
				else if(itr_t->second->getClasse() == "Ave"){
					std::cout << *(dynamic_cast<Ave*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "AveNativa"){
					std::cout << *(dynamic_cast<AveNativa*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "AveExotica"){
					std::cout << *(dynamic_cast<AveExotica*>(itr_t->second)) << std::endl;
				}
				//Verificação para mamíferos
				else if(itr_t->second->getClasse() == "Mamifero"){
					std::cout << *(dynamic_cast<Mamifero*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "MamiferoNativo"){
					std::cout << *(dynamic_cast<MamiferoNativo*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "MamiferoExotico"){
					std::cout << *(dynamic_cast<MamiferoExotico*>(itr_t->second)) << std::endl;
				}
				//Verificação para répteis
				else if(itr_t->second->getClasse() == "Reptil"){
					std::cout << *(dynamic_cast<Reptil*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "ReptilNativo"){
					std::cout << *(dynamic_cast<ReptilNativo*>(itr_t->second)) << std::endl;
				}
				else if(itr_t->second->getClasse() == "ReptilExotico"){
					std::cout << *(dynamic_cast<ReptilExotico*>(itr_t->second)) << std::endl;
				}
					
				match = true;
			}else{
				std::cout << "Id inexistente. Tente novamente!" << std::endl;
			}

		}while(match == false); */

	} else if (escolha_consulta == 3) {

	} else {

	}
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

	if(tipo_funcionario == 1){
		std::string crmv_;
		std::cout << "- CRMV: ";
		std::cin.ignore();
		std::getline( cin, crmv_);

		Veterinario* vet = new Veterinario("Veterinario", id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_, crmv_);
		
		map_funcionarios.insert({id_,vet});
		std::cout << "Veterinário "<< vet->getNome() <<" cadastrado com sucesso.\n" << std::endl;
		//std::cout << *(dynamic_cast<Veterinario*>(map_funcionarios.at(id_))); //FUNCIONANDO
	}else{
		int nivel_de_seguranca_;
		std::cout << "- Nível de segurança: ";
		std::cin >> nivel_de_seguranca_;	

		Tratador* trat = new Tratador("Tratador", id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_, nivel_de_seguranca_);
		
		map_funcionarios.insert({id_,trat});
		std::cout << "Tratador "<< trat->getNome() <<" cadastrado com sucesso.\n" << std::endl;
		//std::cout << *(dynamic_cast<Tratador*>(map_funcionarios.at(id_)));  //FUNCIONANDO
	}
}

void Petshop::listarFuncionarios(){
	std::cout << "\n---------Funcionários cadastrados--------\n" << std::endl;
	std::map<int, Funcionario*>::iterator it;

	for(it = map_funcionarios.begin(); it != map_funcionarios.end(); it++){

		if(it->second->getClasse() == "Veterinario"){
			std::cout << *(dynamic_cast<Veterinario*>(it->second)) << "\n" << std::endl;

		}else if(it->second->getClasse() == "Tratador"){
			std::cout << *(dynamic_cast<Tratador*>(it->second)) << "\n" << std::endl;	
		}
	}
}

void Petshop::removerFuncionario(){
	std::cout << "\n**************************** REMOÇÃO DE FUNCIONÁRIOS ****************************\n\n";
	bool remocao_opcao = false;
	int x;
	listarFuncionarios();

	do{
		int id_remocao = buscarPorId("Funcionario");
		map_funcionarios.erase(id_remocao);

		std::cout << "Para remover outro funcionário: (1-Sim | 2-Não)\n";
		std::cin >> x;
		remocao_opcao = (x == 1) ? true : false;
	}while(remocao_opcao == true);
}

void Petshop::editarFuncionario(){
	
}