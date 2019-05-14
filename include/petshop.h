#include <iostream>
#include <string>
#include <vector>

#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

#ifndef _PETSHOP_H_
#define _PETSHOP_H_

class Petshop{
	private:
		std::vector<Animal> vector_animais;
		std::vector<Veterinario> vector_veterinarios;
		std::vector<Tratador> vector_tratadores;
	public:
		std::string m_nome;
		Petshop(std::string nome);
		~Petshop();

		void cadastrarAnimal();
		void removerAnimal();
		void editarAnimal();
		void consultarAnimal(); //pesquisar por animal, classe animal, veterinario e tratador 

		void cadastrarAnfibio(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		
		void cadastrarReptil(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);

		void cadastrarVeterinario(int id_, std::string nome_, std::string cpf_, int idade_, std::string tipo_sanguineo_, char fator_rh_, std::string especialidade_);
		void removerVeterinario();
		void editarVeterinario();
		void consultarVeterinario();

		void cadastrarTratador(int id_, std::string nome_, std::string cpf_, int idade_, std::string tipo_sanguineo_, char fator_rh_, std::string especialidade_);
		void removerTratador();
		void editarTratador();
		void consultarTratador();

		void cadastrarFuncionario();
};

#endif