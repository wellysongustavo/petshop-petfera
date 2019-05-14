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
		Petshop(int nome);
		~Petshop();

		void cadastrarAnimal();
		void removerAnimal();
		void editarAnimal();
		void consultarAnimal(); //pesquisar por animal, classe animal, veterinario e tratador 

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