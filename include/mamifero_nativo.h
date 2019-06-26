/**
 * @file mamifero_nativo.h
 * @brief Estrutura de dados da classe de Mamífero Nativo
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#include "mamifero.h"
#include "animal_nativo.h"

#ifndef MAMIFERO_NATIVO_H
#define MAMIFERO_NATIVO_H

/**
 * Classe de Mamífero Nativo. Herda atributos e membros da
 * classe Mamifero e AnimalNativo.
 */

class MamiferoNativo: public Mamifero, AnimalNativo{
	public:

		/**
		 * Construtor de Mamífero Nativo. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados das classes Mamifero e
		 * AnimalNativo.
		 */

		MamiferoNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
            int id_tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string uf_origem);
		
		/**
		 * Destrutor de Mamífero Nativo.
		 */

		~MamiferoNativo();

		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Animal.
		 */

		void dummy();

		/**
		 * Métodos getters. Acessores.
		 */

		std::string getAutorizacao();
		std::string getUfOrigem();

		/**
		 * Métodos setters. Modificadores.
		 */

		void setAutorizacao(std::string autorizacao);
		void setUfOrigem(std::string uf_origem);

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Mamífero Nativo.
		 */
		
		friend std::ostream& operator << (std::ostream& os, MamiferoNativo& m);
};

#endif