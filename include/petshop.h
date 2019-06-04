#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>

#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

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

		std::fstream abrirArquivo();

		void cadastrarAnimal();
		void cadastrarAnfibio(std::fstream& arquivo, int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void cadastrarReptil(std::fstream& arquivo, int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void cadastrarAve(std::fstream& arquivo, int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void cadastrarMamifero(std::fstream& arquivo, int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void listarAnimais();	
		void removerAnimal();
		void editarAnimal();
		void consultarAnimal(); //pesquisar por animal, classe animal, veterinario e tratador 

		//void listarVeterinarios();
		//void removerVeterinario();
		void editarVeterinario();
		void consultarVeterinario();

		//void listarTratadores();
		//void removerTratador();
		void editarTratador();
		void consultarTratador();

		void cadastrarFuncionario();
		void listarFuncionarios();
		void removerFuncionario();
};

#endif