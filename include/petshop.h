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
<<<<<<< HEAD
		Petshop(int nome);
		~Petshop();
=======
>>>>>>> d18804d7f892a23f23b2e82232c216c4d1b7939f

		Petshop(std::string nome);
		~Petshop();
		
		void cadastrarAnimal();
		void removerAnimal();
		void editarAnimal();
		void consultarAnimal(); //pesquisar por animal, classe animal, veterinario e tratador 

		void cadastrarAnfibio(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);

		void cadastrarVeterinario();
		void removerVeterinario();
		void editarVeterinario();
		void consultarVeterinario();

		void cadastrarTratador();
		void removerTratador();
		void editarTratador();
		void consultarTratador();
};

#endif