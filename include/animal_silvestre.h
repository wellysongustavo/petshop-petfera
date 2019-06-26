/**
 * @file animal_silvestre.h
 * @brief Estrutura de dados da classe de Animal Silvestre
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _ANIMAL_SILVESTRE_H_
#define _ANIMAL_SILVESTRE_H_

#include <string>

/**
 * Classe Animal Silvestre. Herdará para classes filhas
 * uma string da autorização do IBAMA. 
 */

class AnimalSilvestre {

	protected:

		/**
		 * String protegida com autorização do IBAMA.
		 */
		
		std::string m_autorizacao_ibama;

	public:

		/**
		 * Construtor de Animal Silvestre. Sobrecarregado com lista 
		 * de inicialização de atributos protegidos.
		 */

		AnimalSilvestre(std::string m_autorizacao_ibama);
		
		/**
		 * Destrutor de Animal Silvestre. 
		 */

		~AnimalSilvestre();
};

#endif