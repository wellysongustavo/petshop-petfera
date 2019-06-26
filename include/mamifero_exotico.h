/**
 * @file mamifero_exotico.h
 * @brief Estrutura de dados da classe de Mamífero Exótico
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#include "mamifero.h"
#include "animal_exotico.h"

#ifndef MAMIFERO_EXOTICO_H
#define MAMIFERO_EXOTICO_H

/**
 * Classe de Mamífero Exótico. Herda atributos e membros da
 * classe Mamifero e AnimalExotico.
 */

class MamiferoExotico: public Mamifero, AnimalExotico{
	public:

		/**
		 * Construtor de Mamífero Exótico. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados da classe Mamifero e 
		 * AnimalExotico.
		 */

		MamiferoExotico(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
            int id_tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string pais_origem);	

		/**
		 * Destrutor de Mamífero Exótico.
		 */

		~MamiferoExotico();

		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Animal.
		 */

		void dummy();
		
		/**
		 * Métodos getters. Acessores.
		 */

		std::string getAutorizacao();
		std::string getPaisOrigem();
		
		/**
		 * Métodos setters. Modificadores.
		 */

		void setAutorizacao(std::string autorizacao);
		void setPaisOrigem(std::string pais_origem);

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Mamífero Exótico.
		 */

		friend std::ostream& operator << (std::ostream& os, MamiferoExotico& m);
};

#endif