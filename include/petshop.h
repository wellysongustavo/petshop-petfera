#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <iterator>
#include <typeinfo>
#include <fstream>
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
#include "mamifero_nativo.h"
#include "mamifero_exotico.h"
#include "reptil.h"
#include "reptil_nativo.h"
#include "reptil_exotico.h"
#include "ave.h"
#include "ave_exotica.h"
#include "ave_nativa.h"
#include "date.h"

#ifndef _PETSHOP_H_
#define _PETSHOP_H_

class Petshop{
	private:
		std::map<int, Animal*> map_animais;
		std::map<int, Funcionario*> map_funcionarios;
	public:
		std::string m_nome;
		Petshop(std::string nome);
		~Petshop();

		std::fstream abrirArquivo(std::string tipo_map);
		
		void lerArquivoAnimal();
		void atualizaArquivoAnimal();
		void gravarArquivoFuncionario();
		void lerArquivoFuncionario();
		void desalocarObjetos();
		
		int buscarPorId(std::string tipo_map);
		int verificaId(std::string tipo_map);
		void imprimeAnimalEspecifico(Animal* animal);

		void cadastrarAnimal();
		void cadastrarAnfibio(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void cadastrarReptil(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void cadastrarAve(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void cadastrarMamifero(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void listarAnimais();	
		void removerAnimal();
		void editarAnimal();
		void consultarAnimal(); //pesquisar por animal, classe animal, veterinario e tratador 

		void cadastrarFuncionario();
		void listarFuncionarios();
		void removerFuncionario();
		void editarFuncionario();
		void consultarFuncionario();
};

#endif