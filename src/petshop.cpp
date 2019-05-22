#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <typeinfo>

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

			AnfibioNativo* nativo = new AnfibioNativo(id_, "AnfibioNativo", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, total_de_mudas_, data_, 
				autorizacao_, uf_origem_);

			
			this->map_animais.insert({id_, nativo});
			std::cout << "\nAnfibio " << nativo->getNomeBatismo() << " adicionado com sucesso." << std::endl;
			
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
			std::cout << "\nAnfibio " << exotico->getNomeBatismo() << " adicionado com sucesso." << std::endl;	
			
		}
	}else {
		Anfibio* anfibio_domestico = new Anfibio(id_, "Anfibio", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, total_de_mudas_, data_);
		
		this->map_animais.insert({id_, anfibio_domestico});
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
			std::cout << "\nRéptil " << nativo->getNomeBatismo() << " adicionado com sucesso." << std::endl;
			
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
			std::cout << "\nRéptil " << exotico->getNomeBatismo() << " adicionado com sucesso." << std::endl;	
			
		}
	}else {
		Reptil* reptil_domestico = new Reptil(id_, "Reptil", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, venenoso_, tipo_venenoso_);
			
		this->map_animais.insert({id_, reptil_domestico});
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
			std::cout << "\nAve " << nativa->getNomeBatismo() << " adicionada com sucesso." << std::endl;
			
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
			std::cout << "\nAve " << exotica->getNomeBatismo() << " adicionada com sucesso." << std::endl;	
			
		}
	}else {
		Ave* ave_domestica = new Ave(id_, "Ave", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_);
		
		this->map_animais.insert({id_, ave_domestica});
		std::cout << "\nAve " << ave_domestica->getNomeBatismo() << " adicionada com sucesso." << std::endl;
		
	}
}

void Petshop::cadastrarMamifero(int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {
	
	//criaçao dos veterinario e tratador só pra conseguir instanciar já que tá no construtor da classe animal
	Veterinario* vet1 = new Veterinario(2, "Pedro Burro", "011.257.789-30", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador(1, "Paulo Riscado", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);

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
			std::cout << "\nAnfibio " << nativo->getNomeCientifico() << " adicionado com sucesso." << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do mamífero silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			MamiferoExotico* exotico = new MamiferoExotico(id_, "MamiferoExotico", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, cor_pelo_, autorizacao_, pais_origem_);
			
			this->map_animais.insert({id_, exotico});
			std::cout << "\nMamífero " << exotico->getNomeBatismo() << " adicionado com sucesso." << std::endl;	
			
		}
	}else {
		Mamifero* mamifero_domestico = new Mamifero(id_, "Mamifero", nome_cientifico_, sexo_, tamanho_,
				dieta_, *vet1, *trat1, nome_batismo_, cor_pelo_);
		
		this->map_animais.insert({id_, mamifero_domestico});
		std::cout << "\nMamífero " << mamifero_domestico->getNomeBatismo() << " adicionado com sucesso." << std::endl;
		
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
			cadastrarMamifero(id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;
		case 4:
			cadastrarReptil(id_, nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_);
			break;

	}
}

void Petshop::listarAnimais() {
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
	}
}
/*
//Buscar solução para escolher qual atributo será editado para cada classe
void Petshop::editarAnimal() {
	std::cout << "\n********************************* EDITAR ANIMAIS ********************************" << std::endl;
	listarAnimais();

	int id_escolha;
	std::cout << "\n- Insira o ID do animal que deseja editar: ";
	std::cin >> id_escolha;

	std::map<int, Animal*>::iterator itr_t;
	for(itr_t = map_animais.begin(); itr_t != map_animais.end(); itr_t++){	
		if(itr_t->first == id_escolha) {
			std::cout << typeid(itr_t->second).name() << std::endl;
		}
	}
}	
*/
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

	 if (escolha_consulta == 1) {
		std::map<int, Animal*>::iterator it;
		int id_animal;
		bool match = false;

		do {
			std::cout << "Id do animal: ";
			std::cin >> id_animal;

			it = map_animais.find(id_animal);
			if(it != map_animais.end()){
				//std::cout << it; 
				std::cout << "Animal Encontrado" << std::endl;
			}else{
				std::cout << "Id inexistente. Tente novamente!" << std::endl;
			}

		}while(match == false);
		
		
	} else if (escolha_consulta == 2) {

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

		Veterinario* vet = new Veterinario(id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_, crmv_);
		
		map_funcionarios.insert({id_,vet});
		std::cout << "Veterinário "<< vet->getNome() <<" cadastrado com sucesso.\n" << std::endl;
		//std::cout << *(dynamic_cast<Veterinario*>(map_funcionarios.at(id_))); //FUNCIONANDO
	}else{
		int nivel_de_seguranca_;
		std::cout << "- Nível de segurança: ";
		std::cin >> nivel_de_seguranca_;	

		Tratador* trat = new Tratador(id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_, nivel_de_seguranca_);
		
		map_funcionarios.insert({id_,trat});
		std::cout << "Tratador "<< trat->getNome() <<" cadastrado com sucesso.\n" << std::endl;
		//std::cout << *(dynamic_cast<Tratador*>(map_funcionarios.at(id_)));  //FUNCIONANDO
	}
}
void Petshop::listarFuncionarios(){ // FALTA IF PRA VET E TRAT
	std::map<int, Funcionario*>::iterator it;
	std::cout << "\n---------Funcionários cadastrados--------\n" << std::endl;
	for(it = map_funcionarios.begin(); it != map_funcionarios.end(); it++){
		std::cout << *(dynamic_cast<Veterinario*>(it->second)) << "\n" << std::endl;
	}
}
/*
void Petshop::listarVeterinarios(){
	std::map<int, Veterinario>::iterator itr_v;
	std::cout << "\nVeterinários cadastrados:\n" << std::endl;
	for(itr_v = map_veterinarios.begin(); itr_v != map_veterinarios.end(); itr_v++){
		std::cout << itr_v->second << "\n" << std::endl;
	}
}

void Petshop::listarTratadores(){
	std::map<int, Tratador>::iterator itr_t;
	std::cout << "Tratadores cadastrados:\n" << std::endl;
	for(itr_t = map_tratadores.begin(); itr_t != map_tratadores.end(); itr_t++){
		std::cout << itr_t->second << "\n" << std::endl;
	}
}

void Petshop::removerVeterinario(){
	int id_vet;
	bool match = false;
	std::map<int,Veterinario>::iterator it;

	do{
		std::cout << "Id do veterinário: ";
		std::cin >> id_vet;

		it = map_veterinarios.find(id_vet);
		if(it != map_veterinarios.end()){
			map_veterinarios.erase(id_vet);
			match = true;
		}else{
			std::cout << "Id inexistente. Tente novamente!" << std::endl;
		}

	}while(match == false);

	std::cout << "Veterinário " << it->second.getNome() << " removido.\n" << std::endl;
}

void Petshop::removerTratador(){
	int id_tra;
	bool match = false;
	std::map<int,Tratador>::iterator it;

	do{
		std::cout << "Id do tratador: ";
		std::cin >> id_tra;

		it = map_tratadores.find(id_tra);
		if(it != map_tratadores.end()){
			map_tratadores.erase(id_tra);
			match = true;
		}else{
			std::cout << "Id inexistente. Tente novamente!" << std::endl;
		}

	}while(match == false);

	std::cout << "Tratador " << it->second.getNome() << " removido.\n" << std::endl;
}
*/

void Petshop::removerFuncionario(){
	//int remocao;
	std::cout << "\n**************************** REMOÇÃO DE FUNCIONÁRIOS ****************************\n\n";
	listarFuncionarios();
	/*
	do{
		std::cout << "Para remover Veterinário - 1, para Tratador - 2" << std::endl;
		std::cin >> remocao;
	}while(remocao < 1 || remocao > 2);

	if(remocao == 1){
		removerVeterinario();
	}else{
		removerTratador();
	}
	*/
}