/**
 * @file mamifero.h
 * @brief Estrutura de dados da classe de Mamífero
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _MAMIFERO_H_
#define _MAMIFERO_H_

#include <string>
#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

/**
 * Classe Mamífero. Herda atributos e membros da
 * classe Animal.
 */

class Mamifero : public Animal {
	protected:

		/**
		 * Cor do Pelo. Atributo string com a cor do
		 * pelo do mamífero.
		 */

		std::string m_cor_pelo;

	public:

		/**
		 * Construtor de Mamífero. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados classe Animal e
		 * atributos protegidos de sua classe.
		 */

		Mamifero(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, std::string cor_pelo);
		
		/**
		 * Destrutor de Mamífero.
		 */

		~Mamifero();

		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Animal.
		 */

		void dummy();

		/**
		 * Métodos setters. Modificadores.
		 */

		void setCorPelo(std::string cor_pelo);
		
		/**
		 * Métodos getters. Acessores.
		 */

		std::string getCorPelo();

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Mamífero.
		 */

		friend std::ostream& operator << (std::ostream& os, Mamifero& m);
	
};

#endif