#include "petshop.h"

//criaçao dos veterinario e tratador só pra conseguir instanciar já que tá no construtor da classe animal
Veterinario* vet1 = new Veterinario("Veterinario", 2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
Tratador* trat1 = new Tratador("Tratador", 1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);

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

int Petshop::verificaId(std::string tipo_map){
	bool match = true;
	int id;
	do{
		std::cout << "Id: ";
		std::cin >> id;

		if(tipo_map == "Animal"){

			std::map<int,Animal*>::iterator it;
			it = map_animais.find(id);
			if(it != map_animais.end()){
				std::cout << "Id existente. Tente novamente!" << std::endl;
			}else{
				match = false;
			}

		}else if(tipo_map == "Funcionario"){

			std::map<int,Funcionario*>::iterator it;
			it = map_funcionarios.find(id);
			if(it != map_funcionarios.end()){
				std::cout << "Id existente. Tente novamente!" << std::endl;
			}else{
				match = false;
			}
		}
	}while(match == true);
	return id;
}

void Petshop::imprimeAnimalEspecifico(Animal* animal){
	
	if(animal->getClasse() == "Anfibio"){
		std::cout << *(dynamic_cast<Anfibio*>(animal)) << std::endl;
	}
	else if(animal->getClasse() == "AnfibioNativo"){
		std::cout << *(dynamic_cast<AnfibioNativo*>(animal)) << std::endl;
	}
	else if(animal->getClasse() == "AnfibioExotico"){
		std::cout << *(dynamic_cast<AnfibioExotico*>(animal)) << std::endl;
	}
	//Verificação para aves
	else if(animal->getClasse() == "Ave"){
		std::cout << *(dynamic_cast<Ave*>(animal)) << std::endl;
	}
	else if(animal->getClasse() == "AveNativa"){
		std::cout << *(dynamic_cast<AveNativa*>(animal)) << std::endl;
	}
	else if(animal->getClasse() == "AveExotica"){
		std::cout << *(dynamic_cast<AveExotica*>(animal)) << std::endl;
	}
	//Verificação para mamíferos
	else if(animal->getClasse() == "Mamifero"){
		std::cout << *(dynamic_cast<Mamifero*>(animal)) << std::endl;
	}
	else if(animal->getClasse() == "MamiferoNativo"){
		std::cout << *(dynamic_cast<MamiferoNativo*>(animal)) << std::endl;
	}
	else if(animal->getClasse() == "MamiferoExotico"){
		std::cout << *(dynamic_cast<MamiferoExotico*>(animal)) << std::endl;
	}
	//Verificação para répteis
	else if(animal->getClasse() == "Reptil"){
		std::cout << *(dynamic_cast<Reptil*>(animal)) << std::endl;
	}
	else if(animal->getClasse() == "ReptilNativo"){
		std::cout << *(dynamic_cast<ReptilNativo*>(animal)) << std::endl;
	}
	else if(animal->getClasse() == "ReptilExotico"){
		std::cout << *(dynamic_cast<ReptilExotico*>(animal)) << std::endl;
	}
}

std::fstream Petshop::abrirArquivo(std::string tipo_map) {
	std::fstream arquivo;
	if(tipo_map == "Animal") {
		arquivo.open("controle_animais.csv", std::ios::in | std::ios::out | std::ios::app);
	}else if(tipo_map == "Funcionario") {
		arquivo.open("controle_funcionarios.csv", std::ios::in | std::ios::out | std::ios::app);
	}
	if(!(arquivo.is_open())) { 
		std::cerr << "ERRO! Abertura de arquivo inválida." << std::endl; 
		exit(1);
	}
	arquivo.seekg(0);

	return arquivo;
}

void Petshop::lerArquivoAnimal() {
	std::fstream arquivo = abrirArquivo("Animal");

	arquivo.seekg (0, ios::end);
	int length = arquivo.tellg();
	arquivo.seekg (0, ios::beg);

	//criando as variáveis
	std::string aux, linha, classe, cientifico, sexo, dieta, batismo, autorizacao, uf, pais, tipo_venenoso, cor_do_pelo;
	bool venenoso; 
	double tam, tam_bico_cm, envergadura;
	int id, id_v, id_t_, total_de_mudas;
	date data_ultima_muda;
	
	std::vector<std::string> v;
	if(length > 0) {
		while(!arquivo.eof()){
			v.clear(); //necessário para inserir e manipular cada linha
			getline(arquivo, linha); //lê uma linha e salva como string na variável "linha"
	
			stringstream ss(linha); //usado para quebrar string em palavras
			while(getline(ss, aux, ';')){
				v.push_back(aux);
			}
			
			//Salvando os valores lidos do csv
			id = std::stoi(v[0]);
			classe = v[1];
			cientifico = v[2];
			sexo = v[3];
			tam = std::stod(v[4]);
			dieta = v[5];
			id_v = std::stoi(v[6]);
			id_t_ = std::stoi(v[7]);
			batismo = v[8];
	
			char* s = new char[sexo.length()+1];
			std::strcpy(s, sexo.c_str());
	
			std::size_t found = classe.find("Anfibio");
			if(found!=std::string::npos) {
				total_de_mudas = std::stoi(v[9]);
	
				if(v[10] != "Não informado") {
				data_ultima_muda = data_ultima_muda.converte_string(v[10]);
				}else {
					data_ultima_muda.set_day(00); data_ultima_muda.set_month(00); data_ultima_muda.set_year(0000);
				}
	
				if(classe.compare("Anfibio") > 0) {
					autorizacao = v[11];
	
					if(classe == "AnfibioNativo") {
						uf = v[12];
	
						AnfibioNativo* anfibio_nativo = new AnfibioNativo(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
							total_de_mudas, data_ultima_muda, autorizacao, uf);
	
						this->map_animais.insert({id, anfibio_nativo});
					}
					if(classe == "AnfibioExotico") {
						pais = v[12];
	
						AnfibioExotico* anfibio_exotico = new AnfibioExotico(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
							total_de_mudas, data_ultima_muda, autorizacao, pais);
	
						this->map_animais.insert({id, anfibio_exotico});
					}
				}else{
					Anfibio* anfibio_domestico = new Anfibio(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
						total_de_mudas, data_ultima_muda);
		
					this->map_animais.insert({id, anfibio_domestico});
				}
				v.clear();
			}
	
			std::size_t found2= classe.find("Ave");
			if(found2!=std::string::npos) {
				tam_bico_cm = std::stod(v[9]);
				envergadura = std::stod(v[10]);
	
				if(classe.compare("Ave") > 0) {
					autorizacao = v[11];
	
					if(classe == "AveNativa") {
						uf = v[12];
	
						AveNativa* ave_nativa = new AveNativa(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
							tam_bico_cm, envergadura, autorizacao, uf);
	
						this->map_animais.insert({id, ave_nativa});
					}
					if(classe == "AveExotica") {
						pais = v[12];
	
						AveExotica* ave_exotica = new AveExotica(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
							tam_bico_cm, envergadura, autorizacao, pais);
	
						this->map_animais.insert({id, ave_exotica});
					}
				}else{
					Ave* ave_domestica = new Ave(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
						tam_bico_cm, envergadura);
		
					this->map_animais.insert({id, ave_domestica});
				}
				v.clear();
			}
	
			std::size_t found3 = classe.find("Reptil");
			if(found3!=std::string::npos) {
				venenoso = (v[9] == "1") ? true : false;
				tipo_venenoso = (venenoso == true) ? v[10] : "Não venenoso";
	
				if(classe.compare("Reptil") > 0) {
					autorizacao = v[11];
	
					if(classe == "ReptilNativo") {
						uf = v[12];
	
						ReptilNativo* reptil_nativo = new ReptilNativo(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
							venenoso, tipo_venenoso, autorizacao, uf);
	
						this->map_animais.insert({id, reptil_nativo});
					}
					if(classe == "ReptilExotico") {
						pais = v[12];
	
						ReptilExotico* reptil_exotico = new ReptilExotico(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
							venenoso, tipo_venenoso, autorizacao, pais);
	
						this->map_animais.insert({id, reptil_exotico});
					}
				}else{
					Reptil* reptil_domestico = new Reptil(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
						venenoso, tipo_venenoso);
		
					this->map_animais.insert({id, reptil_domestico});
				}
				v.clear();
			}
	
			std::size_t found4 = classe.find("Mamifero");
			if(found4!=std::string::npos) {
				cor_do_pelo = v[9];
	
				if(classe.compare("Mamifero") > 0) {
					autorizacao = v[10];
	
					if(classe == "MamiferoNativo") {
						uf = v[11];
	
						MamiferoNativo* mamifero_nativo = new MamiferoNativo(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
							cor_do_pelo, autorizacao, uf);
	
						this->map_animais.insert({id, mamifero_nativo});
					}
					if(classe == "MamiferoExotico") {
						pais = v[11];
	
						MamiferoExotico* mamifero_exotico = new MamiferoExotico(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
							cor_do_pelo, autorizacao, pais);
	
						this->map_animais.insert({id, mamifero_exotico});
					}
				}else{
					Mamifero* mamifero_domestico = new Mamifero(id, classe, cientifico, *s, tam, dieta, id_v, id_t_, batismo, 
							cor_do_pelo);
	
					this->map_animais.insert({id, mamifero_domestico});
				}
				v.clear();
			}
		}
	}
	arquivo.close();		
}

void Petshop::atualizaArquivoAnimal() {
	remove("controle_animais.csv");
	std::fstream arquivo = abrirArquivo("Animal");

	std::map<int, Animal*>::iterator itr_t;
	for(itr_t = map_animais.begin(); itr_t != map_animais.end(); itr_t++){
		
		arquivo << itr_t->second->getId() << ";" << itr_t->second->getClasse() << ";" << itr_t->second->getNomeCientifico()
		<< ";" << itr_t->second->getSexo() << ";" << itr_t->second->getTamanho() << ";" << itr_t->second->getDieta()
		<< ";" << (itr_t->second->getIdVeterinario()) << ";" << (itr_t->second->getIdTratador()) << ";"
		<< itr_t->second->getNomeBatismo();

		std::string classe = (itr_t->second)->getClasse();
		
		std::size_t found = classe.find("Anfibio");
		if(found!=std::string::npos) {
			arquivo << ";" << dynamic_cast<Anfibio*>(itr_t->second)->getTotalMudas() << ";" << dynamic_cast<Anfibio*>(itr_t->second)->getUltimaMuda();

			if(classe.compare("Anfibio") > 0) { arquivo << ";" << reinterpret_cast<AnfibioNativo*>(itr_t->second)->getAutorizacao() << ";"; }

			if(classe == "AnfibioNativo") { arquivo << dynamic_cast<AnfibioNativo*>(itr_t->second)->getUfOrigem(); }

			if(classe == "AnfibioExotico") { arquivo << dynamic_cast<AnfibioExotico*>(itr_t->second)->getPaisOrigem(); }
		}

		std::size_t found2 = classe.find("Ave");
		if(found2!=std::string::npos) {
			arquivo << ";" << dynamic_cast<Ave*>(itr_t->second)->getTamanhoBico() << ";" << dynamic_cast<Ave*>(itr_t->second)->getEnvergaduraAsas();

			if(classe.compare("Ave") > 0) { arquivo << ";" << reinterpret_cast<AveNativa*>(itr_t->second)->getAutorizacao() << ";"; }

			if(classe == "AveNativa") { arquivo << dynamic_cast<AveNativa*>(itr_t->second)->getUfOrigem(); }

			if(classe == "AveExotica") { arquivo << dynamic_cast<AveExotica*>(itr_t->second)->getPaisOrigem(); }
		}

		std::size_t found3 = classe.find("Mamifero");
		if(found3!=std::string::npos) {
			arquivo << ";" << dynamic_cast<Mamifero*>(itr_t->second)->getCorPelo();

			if(classe.compare("Mamifero") > 0) { arquivo << ";" << reinterpret_cast<MamiferoNativo*>(itr_t->second)->getAutorizacao() << ";"; }

			if(classe == "MamiferoNativo") { arquivo << dynamic_cast<MamiferoNativo*>(itr_t->second)->getUfOrigem() ; }

			if(classe == "MamiferoExotico") { arquivo << dynamic_cast<MamiferoExotico*>(itr_t->second)->getPaisOrigem() ; }
		}

		std::size_t found4 = classe.find("Reptil");
		if(found4!=std::string::npos) {
			arquivo << ";" << dynamic_cast<Reptil*>(itr_t->second)->getVenenoso() << ";" << dynamic_cast<Reptil*>(itr_t->second)->getTipoVenenoso();

			if(classe.compare("Reptil") > 0) { arquivo << ";" << reinterpret_cast<ReptilNativo*>(itr_t->second)->getAutorizacao() << ";"; }

			if(classe == "ReptilNativo") { arquivo << dynamic_cast<ReptilNativo*>(itr_t->second)->getUfOrigem(); }

			if(classe == "ReptilExotico") { arquivo << dynamic_cast<ReptilExotico*>(itr_t->second)->getPaisOrigem(); }	
		}
		arquivo << std::endl;
	}
	arquivo.close();
}

void Petshop::cadastrarAnfibio(int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {
	
	int total_de_mudas_;
	std::cout << "- Total de mudas do anfíbio: ";
	std::cin >> total_de_mudas_;

	int dia_, mes_, ano_;
	if(total_de_mudas_ > 0) {
		std::cout << "- Data da última muda do anfíbio (dia mês ano): ";
		std::cin >> dia_; std::cin >> mes_; std::cin >> ano_;
	}else {
		dia_ = 00; mes_ = 00; ano_ = 0000;
	}

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

			AnfibioNativo* anfibio_nativo = new AnfibioNativo(id_, "AnfibioNativo", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, total_de_mudas_, data_, autorizacao_, uf_origem_);
			map_animais.insert({id_,anfibio_nativo});
			std::cout << "\nAnfibio " << nome_batismo_ << " adicionado com sucesso." << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do anfíbio silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			AnfibioExotico* anfibio_exotico = new AnfibioExotico(id_, "AnfibioExotico", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, total_de_mudas_, data_, autorizacao_, pais_origem_);
			map_animais.insert({id_,anfibio_exotico});
			std::cout << "\nAnfibio " << nome_batismo_ << " adicionado com sucesso." << std::endl;
		}
	}else {
		
		Anfibio* anfibio = new Anfibio(id_, "Anfibio", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, total_de_mudas_, data_);
		map_animais.insert({id_,anfibio});
		std::cout << "\nAnfibio " << nome_batismo_ << " adicionado com sucesso." << std::endl;
	}
}

void Petshop::cadastrarReptil(int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {

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

			ReptilNativo* reptil_nativo = new ReptilNativo(id_, "ReptilNativo", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, venenoso_, tipo_venenoso_, autorizacao_, uf_origem_);
			map_animais.insert({id_,reptil_nativo});
			std::cout << "\nRéptil " << nome_batismo_ << " adicionado com sucesso." << std::endl;
			
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do réptil silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			ReptilExotico* reptil_exotico = new ReptilExotico(id_, "ReptilExotico", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, venenoso_, tipo_venenoso_, autorizacao_, pais_origem_);
			map_animais.insert({id_,reptil_exotico});

			std::cout << "\nRéptil " << nome_batismo_ << " adicionado com sucesso." << std::endl;
		}
	}else {	

		Reptil* reptil = new Reptil(id_, "Reptil", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, venenoso_, tipo_venenoso_);
		map_animais.insert({id_,reptil});
		std::cout << "\nRéptil " << nome_batismo_ << " adicionado com sucesso." << std::endl;
	}
}

void Petshop::cadastrarAve(int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {

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

			AveNativa* ave_nativa = new AveNativa(id_, "AveNativa", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_, autorizacao_, uf_origem_);
			map_animais.insert({id_,ave_nativa});
			std::cout << "\nAve " << nome_batismo_ << " adicionada com sucesso." << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do ave silvestre exótica: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			AveExotica* ave_exotica = new AveExotica(id_, "AveExotica", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_, autorizacao_, pais_origem_);
			map_animais.insert({id_,ave_exotica});
			std::cout << "\nAve " << nome_batismo_ << " adicionada com sucesso." << std::endl;	
		}
	}else {
		
		Ave* ave = new Ave(id_, "Ave", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, tamanho_do_bico_cm_, envergadura_das_asas_);
		map_animais.insert({id_,ave});
		std::cout << "\nAve " << nome_batismo_ << " adicionada com sucesso." << std::endl;
		
	}
}

void Petshop::cadastrarMamifero(int id_, std::string nome_cientifico_, char sexo_, 
	double tamanho_, std::string dieta_, int id_veterinario_, int id_tratador_, 
	std::string nome_batismo_) {
	
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

			MamiferoNativo* mamifero_nativo = new MamiferoNativo(id_, "MamiferoNativo", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, cor_pelo_, autorizacao_, uf_origem_);
			map_animais.insert({id_,mamifero_nativo});
			std::cout << "\nMamífero " << nome_batismo_ << " adicionada com sucesso." << std::endl;
		}
		else if(area == 2) {
			std::string pais_origem_;
			std::cout << "- País de origem do mamífero silvestre exótico: ";
			std::cin.ignore();
			std::getline( cin, pais_origem_);

			MamiferoExotico* mamifero_exotico = new MamiferoExotico(id_, "MamiferoExotico", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, cor_pelo_, autorizacao_, pais_origem_);
			map_animais.insert({id_,mamifero_exotico});
			std::cout << "\nMamífero " << nome_batismo_ << " adicionada com sucesso." << std::endl;
		}
	}else {
			
			Mamifero* mamifero = new Mamifero(id_, "Mamifero", nome_cientifico_, sexo_, tamanho_, dieta_, id_veterinario_, id_tratador_, nome_batismo_, cor_pelo_);
			map_animais.insert({id_,mamifero});
			std::cout << "\nMamífero " << nome_batismo_ << " adicionada com sucesso." << std::endl;
	}
}

void Petshop::cadastrarAnimal() { 
	int escolha_classe;

	std::cout << "\n****************************** CADASTRO DE ANIMAIS ******************************\n\n- Insira da classe do animal (1- Anfíbio | 2- Ave | 3- Mamífero | 4- Réptil): ";
	do{
		std::cin >> escolha_classe;
	}while(escolha_classe < 1 || escolha_classe > 4);

	int id_ = verificaId("Animal");

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
	std::cout << "- Veterinário -> ";
	id_veterinario_ = buscarPorId("Funcionario");
	//std::cin >> id_veterinario_;

	int id_tratador_;
	std::cout << "- Tratador -> ";
	id_tratador_ = buscarPorId("Funcionario");

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
		imprimeAnimalEspecifico(itr_t->second);
	}
}

void Petshop::editarAnimal() {
	lerArquivoAnimal(); //atualizar o map

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
			std::string classe = it->second->getClasse();
			std::size_t found = classe.find("Anfibio");
			if(found!=std::string::npos){
				std::string total_de_mudas, dia, mes, ano;

				std::cout << "- Total de mudas [" << dynamic_cast<Anfibio*>(it->second)->getTotalMudas() << "]: ";
				std::cin >> total_de_mudas;
				if(total_de_mudas != "*") { dynamic_cast<Anfibio*>(it->second)->setTotalMudas(std::stoi(total_de_mudas)); }

				if(dynamic_cast<Anfibio*>(it->second)->getTotalMudas() > 0) {
					std::cout << "- Data da última muda [" << dynamic_cast<Anfibio*>(it->second)->getUltimaMuda() << "] (dia mes ano): ";
					std::cin >> dia; std::cin >> mes; std::cin >> ano;
					if(dia != "*" && mes != "*" && ano != "*") { 
						date ultima_muda(std::stoi(dia), std::stoi(mes), std::stoi(ano));
						dynamic_cast<Anfibio*>(it->second)->setUltimaMuda(ultima_muda); }
				}else {
					date ultima_muda(00, 00, 0000);
						dynamic_cast<Anfibio*>(it->second)->setUltimaMuda(ultima_muda);
				}

				if((it->second->getClasse()).compare("Anfibio") > 0) {
					std::string autorizacao_silvestre;

					std::cout << "- Autorização [" << reinterpret_cast<AnfibioNativo*>(it->second)->getAutorizacao() << "]: ";
					std::cin >> autorizacao_silvestre;
					if(autorizacao_silvestre != "*") { reinterpret_cast<AnfibioNativo*>(it->second)->setAutorizacao(autorizacao_silvestre); }

					if(it->second->getClasse() == "AnfibioNativo"){
						std::string uf_origem_nativo;

						std::cout << "- UF de origem [" << dynamic_cast<AnfibioNativo*>(it->second)->getUfOrigem() << "]: ";
						std::cin >> uf_origem_nativo;
						if(uf_origem_nativo != "*") { dynamic_cast<AnfibioNativo*>(it->second)->setUfOrigem(uf_origem_nativo); }
					}
					if(it->second->getClasse() == "AnfibioExotico"){
						std::string pais_origem_exotico;

						std::cout << "- País de origem [" << dynamic_cast<AnfibioExotico*>(it->second)->getPaisOrigem() << "]: ";
						std::cin >> pais_origem_exotico;
						if(pais_origem_exotico != "*") { dynamic_cast<AnfibioExotico*>(it->second)->setPaisOrigem(pais_origem_exotico); }
					}
				}
			}			
			//Verificação para aves
			std::size_t found2 = classe.find("Ave");
			if(found2!=std::string::npos){
				std::string tamanho_do_bico_cm, envergadura_das_asas;

				std::cout << "- Tamanho do bico em cm [" << dynamic_cast<Ave*>(it->second)->getTamanhoBico() << "]: ";
				std::cin >> tamanho_do_bico_cm;
				if(tamanho_do_bico_cm != "*") { dynamic_cast<Ave*>(it->second)->setTamanhoBico(std::stod(tamanho_do_bico_cm)); }

				std::cout << "- Envergadura das asas em cm [" << dynamic_cast<Ave*>(it->second)->getEnvergaduraAsas() << "]: ";
				std::cin >> envergadura_das_asas;
				if(envergadura_das_asas != "*") { dynamic_cast<Ave*>(it->second)->setEnvergaduraAsas(std::stod(envergadura_das_asas)); }
				
				if((it->second->getClasse()).compare("Ave") > 0) {
					std::string autorizacao_silvestre;

					std::cout << "- Autorização [" << reinterpret_cast<AveNativa*>(it->second)->getAutorizacao() << "]: ";
					std::cin >> autorizacao_silvestre;
					if(autorizacao_silvestre != "*") { reinterpret_cast<AveNativa*>(it->second)->setAutorizacao(autorizacao_silvestre); }
				
					if(it->second->getClasse() == "AveNativa"){
						std::string uf_origem_nativa;

						std::cout << "- UF de origem [" << dynamic_cast<AveNativa*>(it->second)->getUfOrigem() << "]: ";
						std::cin >> uf_origem_nativa;
						if(uf_origem_nativa != "*") { dynamic_cast<AveNativa*>(it->second)->setUfOrigem(uf_origem_nativa); }			
					}
					if(it->second->getClasse() == "AveExotica"){
						std::string pais_origem_exotica;
					
						std::cout << "- País de origem [" << dynamic_cast<AveExotica*>(it->second)->getPaisOrigem() << "]: ";
						std::cin >> pais_origem_exotica;
						if(pais_origem_exotica != "*") { dynamic_cast<AveExotica*>(it->second)->setPaisOrigem(pais_origem_exotica); }				
					}
				}
			}
			//Verificação para mamíferos
			std::size_t found3 = classe.find("Mamifero");
			if(found3!=std::string::npos){
				std::string cor_pelo;

				std::cout << "- Cor do pelo [" << dynamic_cast<Mamifero*>(it->second)->getCorPelo() << "]: ";
				std::cin >> cor_pelo;
				if(cor_pelo != "*") { dynamic_cast<Mamifero*>(it->second)->setCorPelo(cor_pelo); }	
				
				if((it->second->getClasse()).compare("Mamifero") > 0) {
					std::string autorizacao_mamifero_silvestre;

					std::cout << "- Autorização [" << reinterpret_cast<MamiferoNativo*>(it->second)->getAutorizacao() << "]: ";
					std::cin >> autorizacao_mamifero_silvestre;
					if(autorizacao_mamifero_silvestre != "*") { reinterpret_cast<MamiferoNativo*>(it->second)->setAutorizacao(autorizacao_mamifero_silvestre); }

					if(it->second->getClasse() == "MamiferoNativo"){				
						std::string uf_origem_mamifero_nativo;						

						std::cout << "- UF de origem [" << dynamic_cast<MamiferoNativo*>(it->second)->getUfOrigem() << "]: ";
						std::cin >> uf_origem_mamifero_nativo;
						if(uf_origem_mamifero_nativo != "*") { dynamic_cast<MamiferoNativo*>(it->second)->setUfOrigem(uf_origem_mamifero_nativo); }			
					}
					if(it->second->getClasse() == "MamiferoExotico"){				
						std::string pais_origem_mamifero_exotico;

						std::cout << "- UF de origem [" << dynamic_cast<MamiferoExotico*>(it->second)->getPaisOrigem() << "]: ";
						std::cin >> pais_origem_mamifero_exotico;
						if(pais_origem_mamifero_exotico != "*") { dynamic_cast<MamiferoExotico*>(it->second)->setPaisOrigem(pais_origem_mamifero_exotico); }			
					}
				}
			}
			//Verificação para répteis
			std::size_t found4 = classe.find("Reptil");
			if(found4!=std::string::npos){
				std::string venenoso, tipo_venenoso;
				
				std::cout << "- Venenoso [" << dynamic_cast<Reptil*>(it->second)->getVenenoso() << "] (1 para verdadeiro, 0 para falso): ";
				std::cin >> venenoso;
				bool bool_venenoso = (venenoso == "1") ? true : false;
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
				if((it->second->getClasse()).compare("Reptil") > 0) {
					std::string autorizacao_reptil_silvestre;

					std::cout << "- Autorização [" << reinterpret_cast<ReptilNativo*>(it->second)->getAutorizacao() << "]: ";
					std::cin >> autorizacao_reptil_silvestre;
					if(autorizacao_reptil_silvestre != "*") { reinterpret_cast<ReptilNativo*>(it->second)->setAutorizacao(autorizacao_reptil_silvestre); }

					if(it->second->getClasse() == "ReptilNativo"){
						std::string uf_origem_reptil_nativo;	

						std::cout << "- UF de origem [" << dynamic_cast<ReptilNativo*>(it->second)->getUfOrigem() << "]: ";
						std::cin >> uf_origem_reptil_nativo;
						if(uf_origem_reptil_nativo != "*") { dynamic_cast<ReptilNativo*>(it->second)->setUfOrigem(uf_origem_reptil_nativo); }						
					}
					if(it->second->getClasse() == "ReptilExotico"){
						std::string pais_origem_reptil_exotico;
						
						std::cout << "- País de origem [" << dynamic_cast<ReptilExotico*>(it->second)->getPaisOrigem() << "]: ";
						std::cin >> pais_origem_reptil_exotico;
						if(pais_origem_reptil_exotico != "*") { dynamic_cast<ReptilExotico*>(it->second)->setPaisOrigem(pais_origem_reptil_exotico); }				
					}
				}
			}
			std::cout << "\nAnimal atualizado com sucesso!" << std::endl;
		}else{
			std::cout << "Id inexistente. Tente novamente!" << std::endl;
		}
	}while(match == false);
}	

void Petshop::removerAnimal(){
	listarAnimais();
	int id_animal;
	id_animal = buscarPorId("Animal");
	map_animais.erase(id_animal);
	
	std::cout << "Animal removido.\n" << std::endl; 
}

void Petshop::consultarAnimal(){
	int escolha_consulta;

	std::cout << "1 - Pesquisar por id" << std::endl;
	std::cout << "2 - Pesquisar por classe" << std::endl;
	std::cout << "3 - Pesquisar por tratador" << std::endl;
	std::cout << "4 - Pesquisar por veterinário" << std::endl;
	std::cout << "Opção: ";
	std::cin >> escolha_consulta;
	while(escolha_consulta < 1 || escolha_consulta > 4){
		std::cout << "A opção digitada não existe. Digite a opção desejada: ";
		std::cin >> escolha_consulta;
	}

	std::map<int, Animal*>::iterator itr_animal;
	std::map<int, Funcionario*>::iterator itr_func;

	/////Variáveis usadas no switch////////////////
	int id_animal, id_tratador, id_veterinario;
	int classe_animal;
	std::string classe_animal_;
	int nativo_ou_exotico;
	std::string nativo_ou_exotico_;
	std::string pesquisa;
	//////////////////////////////////////////////

	switch(escolha_consulta){
		case 1:
			
			id_animal = buscarPorId("Animal");
			itr_animal = map_animais.find(id_animal);
			std::cout << "\n";

			imprimeAnimalEspecifico(itr_animal->second);
			break;
		case 2:
			
			std::cout << "Insira a classe do animal (1- Anfíbio | 2- Ave | 3- Mamífero | 4- Réptil): ";
			do {
				std::cin >> classe_animal;

				if(classe_animal == 1) {
					classe_animal_ = "Anfibio";
				} else if (classe_animal == 2) {
					classe_animal_ = "Ave";
				} else if (classe_animal == 3) {
					classe_animal_ = "Mamifero";
				} else {
					classe_animal_ = "Reptil";
				}
			} while (classe_animal < 1 || classe_animal > 4);

			std::cout << "Insira da classe do animal (1- Nativo | 2- Exotico | 3-Doméstico): ";
			do {
				std::cin >> nativo_ou_exotico;

				if(nativo_ou_exotico == 1) {
					if(classe_animal == 2) {
						nativo_ou_exotico_ = "Nativa";
					} else {
						nativo_ou_exotico_ = "Nativo";
					}	
				} else if (nativo_ou_exotico == 2) {
					nativo_ou_exotico_ = "Exotico";
				} else {
					nativo_ou_exotico_ = "";
				}
			} while (nativo_ou_exotico < 1 || nativo_ou_exotico > 3);

			std::cout << "\n";
			
			pesquisa = classe_animal_ +nativo_ou_exotico_;

			for(itr_animal = map_animais.begin(); itr_animal != map_animais.end(); itr_animal++){

				if(pesquisa == itr_animal->second->getClasse()){
					imprimeAnimalEspecifico(itr_animal->second);
				}
			}
			break;
		case 3:
			
			id_tratador = buscarPorId("Funcionario");
			//itr_func = map_funcionarios.find(id_tratador);
			std::cout << "\n";

			// sobrecarregar objetos
			for(itr_animal = map_animais.begin(); itr_animal != map_animais.end(); itr_animal++){

				if(itr_animal->second->getIdTratador() == id_tratador ){
					imprimeAnimalEspecifico(itr_animal->second);
				}
			}	
			break;
		case 4:
			id_veterinario = buscarPorId("Funcionario");
			//itr_func = map_funcionarios.find(id_veterinario);
			std::cout << "\n";

			// sobrecarregar objetos
			for(itr_animal = map_animais.begin(); itr_animal != map_animais.end(); itr_animal++){

				if(itr_animal->second->getIdVeterinario() == id_veterinario ){
					imprimeAnimalEspecifico(itr_animal->second);
				}
			}	
			break;
	}
}

void Petshop::gravarArquivoFuncionario(){
	remove("controle_funcionarios.csv");
	
	std::fstream arquivo = abrirArquivo("Funcionario");

	std::map<int, Funcionario*>::iterator it;

	for(it = map_funcionarios.begin(); it != map_funcionarios.end(); it++){
		arquivo << it->second->getClasse() << ";"
				<< it->second->getId() << ";"
				<< it->second->getNome() << ";"
				<< it->second->getCpf() << ";"
				<< it->second->getIdade() << ";"
				<< it->second->getTipoSanguineo() << ";"
				<< it->second->getFatorRh() << ";"
				<< it->second->getEspecialidade() << ";";

		if(it->second->getClasse() == "Veterinario"){
			arquivo << dynamic_cast<Veterinario*>(it->second)->getCrmv() << "\n";
		}else if(it->second->getClasse() == "Tratador"){
			arquivo << dynamic_cast<Tratador*>(it->second)->getNivelSeguranca() << "\n";
		}			
	}

	arquivo.close();
}

void Petshop::lerArquivoFuncionario(){

	std::fstream arquivo = abrirArquivo("Funcionario");

	arquivo.seekg (0, ios::end);
	int length = arquivo.tellg();
	arquivo.seekg (0, ios::beg);

	std::vector<std::string> funcionario;
	std::string linha, palavra;
	if(length > 0) {
		while(!arquivo.eof()){
			funcionario.clear(); //necessário para inserir e manipular cada linha
			getline(arquivo, linha); //lê uma linha e salva como string na variável "linha"
	
			stringstream s(linha); //usado para quebrar string em palavras
			while(getline(s, palavra, ';')){
				funcionario.push_back(palavra);
			}
	
			//Transformando string de funcionario[6] em char------------
			char * funcionario_6 = new char [funcionario[6].length()+1];
			std::strcpy (funcionario_6, funcionario[6].c_str());
			//----------------------------------------------------------
	
			if(funcionario[0] == "Veterinario"){
				
				Veterinario* vet = new Veterinario(funcionario[0], stoi(funcionario[1]), funcionario[2], funcionario[3], stoi(funcionario[4]), funcionario[5], *funcionario_6, funcionario[7], funcionario[8]);
				map_funcionarios.insert({stoi(funcionario[1]),vet});
	
			}else if(funcionario[0] == "Tratador"){
	
				Tratador* trat = new Tratador(funcionario[0], stoi(funcionario[1]), funcionario[2], funcionario[3], stoi(funcionario[4]), funcionario[5], *funcionario_6, funcionario[7], stoi(funcionario[8]));
				map_funcionarios.insert({stoi(funcionario[1]),trat});
			}
		}
	}
	arquivo.close();
}

void Petshop::cadastrarFuncionario(){
	int tipo_funcionario;
	std::cout << "\n**************************** CADASTRO DE FUNCIONÁRIOS ****************************\n\n- Insira (1- Veterinário | 2- Tratador ): ";
	do{
		std::cin >> tipo_funcionario;
	}while(tipo_funcionario < 1 || tipo_funcionario > 2);

	int id_ = verificaId("Funcionario");

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
	}else{
		int nivel_de_seguranca_;
		std::cout << "- Nível de segurança: ";
		std::cin >> nivel_de_seguranca_;	

		Tratador* trat = new Tratador("Tratador", id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_, nivel_de_seguranca_);
		
		map_funcionarios.insert({id_,trat});
		std::cout << "Tratador "<< trat->getNome() <<" cadastrado com sucesso.\n" << std::endl;
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
	std::cout << "\n**************************** EDIÇÃO DE FUNCIONÁRIOS ****************************\n\n";
	bool edicao_opcao = false;
	int opcao;
	int id_edicao;
	std::map<int,Funcionario*>::iterator it;
	listarFuncionarios();

	do{
		id_edicao = buscarPorId("Funcionario");
		it = map_funcionarios.find(id_edicao);

		std::string novo_id, novo_nome, novo_cpf, nova_idade, novo_tipo_sanguineo, novo_fator_rh, nova_especialidade, novo_crmv, novo_nivel_de_seguranca;

		std::cout << "\n- Preencha com o novo valor caso deseje alterar ou '*' para manter o antigo:\n\n- Nome [" << it->second->getNome() << "]: ";
		std::cin >> novo_nome;
		if(novo_nome != "*"){ it->second->setNome(novo_nome); }

		std::cout << "- CPF [" << it->second->getCpf() << "]: ";
		std::cin >> novo_cpf;
		if(novo_cpf != "*"){ it->second->setCpf(novo_cpf); }

		std::cout << "- Idade [" << it->second->getIdade() << "]: ";
		std::cin >> nova_idade;
		if(nova_idade != "*"){ it->second->setIdade(stoi(nova_idade)); }

		std::cout << "- Tipo sanguíneo [" << it->second->getTipoSanguineo() << "]: ";
		std::cin >> novo_tipo_sanguineo;
		if(novo_tipo_sanguineo != "*"){ it->second->setTipoSanguineo(novo_tipo_sanguineo); }

		std::cout << "- Fator RH [" << it->second->getFatorRh() << "]: ";
		std::cin >> novo_fator_rh;
		char * aux = new char [novo_fator_rh.length()+1];
		std::strcpy (aux, novo_fator_rh.c_str());
		if(novo_fator_rh != "*"){ it->second->setFatorRh(*aux); }

		std::cout << "- Especialidade [" << it->second->getEspecialidade() << "]: ";
		std::cin >> nova_especialidade;
		if(nova_especialidade != "*"){ it->second->setEspecialidade(nova_especialidade); }

		if(it->second->getClasse() == "Veterinario"){

			std::cout << "- CRMV [" << dynamic_cast<Veterinario*>(it->second)->getCrmv() << "]: ";
			std::cin >> novo_crmv;
			if(novo_crmv != "*"){ dynamic_cast<Veterinario*>(it->second)->setCrmv(novo_crmv); }

		}else if(it->second->getClasse() == "Tratador"){

			std::cout << "- Nível de segurança [" << dynamic_cast<Tratador*>(it->second)->getNivelSeguranca() << "]: ";
			std::cin >> novo_nivel_de_seguranca;
			if(novo_nivel_de_seguranca != "*"){ dynamic_cast<Tratador*>(it->second)->setNivelSeguranca(stoi(novo_nivel_de_seguranca)); }

		}

		std::cout << "Funcionário " << it->second->getNome() << "atualizado com sucesso!\nPara editar outro funcionário: (1-Sim | 2-Não)\n";
		std::cin >> opcao;
		edicao_opcao = (opcao == 1)?true:false;
	}while(edicao_opcao == true);
}

void Petshop::consultarFuncionario(){
	int escolha_consulta, nova_consulta_int;
	bool nova_consulta_bool = false;
	//Variáveis necessárias aos cases
	int id_pesquisa;
	std::map<int,Funcionario*>::iterator it;
	int contador_de_funcionarios;

	std::cout << "\n**************************** CONSULTA DE FUNCIONÁRIOS ****************************\n\n";
	do{
		std::cout << "1 - Pesquisar por id" << std::endl;
		std::cout << "2 - Pesquisar Veterinários" << std::endl;
		std::cout << "3 - Pesquisar Tratadores" << std::endl;
		std::cout << "Escolha: ";
		std::cin >> escolha_consulta;

		contador_de_funcionarios = 0;
		switch(escolha_consulta){
			case 1:
					id_pesquisa = buscarPorId("Funcionario");
					it = map_funcionarios.find(id_pesquisa);
					std::cout << "\n";

					if(it->second->getClasse() == "Veterinario"){
						std::cout << *(dynamic_cast<Veterinario*>(it->second)) << "\n" << std::endl;

					}else if(it->second->getClasse() == "Tratador"){
						std::cout << *(dynamic_cast<Tratador*>(it->second)) << "\n" << std::endl;	
					}
				break;
			case 2:
					std::cout << "\n";
					for(it = map_funcionarios.begin(); it != map_funcionarios.end(); it++){

						if(it->second->getClasse() == "Veterinario"){
							std::cout << *(dynamic_cast<Veterinario*>(it->second)) << "\n" << std::endl;
							contador_de_funcionarios++;
						}
					}
					if(contador_de_funcionarios == 0){ 
						std::cout << "Não há veterinários cadastrados.\n"; 
					}
				break;
			case 3:
					std::cout << "\n";
					for(it = map_funcionarios.begin(); it != map_funcionarios.end(); it++){
							
						if(it->second->getClasse() == "Tratador"){
							std::cout << *(dynamic_cast<Tratador*>(it->second)) << "\n" << std::endl;
							contador_de_funcionarios++;
						}
					}
					if(contador_de_funcionarios == 0){ 
						std::cout << "Não há tratadores cadastrados.\n"; 
					}
				break;
		}

		std::cout << "Para consultar outro funcionário: (1-Sim | 2-Não)\n";
		std::cin >> nova_consulta_int;
		nova_consulta_bool = (nova_consulta_int == 1)?true:false;
	}while(nova_consulta_bool == true);
}
