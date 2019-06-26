/**
 * @file animal_nativo.h
 * @brief Estrutura de dados da classe de Animal Nativo
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _ANIMAL_NATIVO_H_
#define _ANIMAL_NATIVO_H_

#include <string>
#include "animal_silvestre.h"

/**
 * Classe Animal Nativo. Herda atributos e membros de AnimalSilvestre
 * e características de um animal nativoo. 
 */

class AnimalNativo : public AnimalSilvestre {

	protected:
		
		/**
		 * Atributo protected com a região do animal silvestre
		 * nativo.
		 */
		
		std::string m_uf_origem;

	public:
		
		/**
		 * Construtor de Animal Nativo. Construtor da classe Animal Nativo 
		 * com lista de inicialização dos atributos da classe e herdados de
		 * Animal Silvestre.
		 */ 
		
		AnimalNativo(std::string autorizacao, std::string uf_origem);
		
		/**
		 * Destrutor de Animal Nativo.
		 */

		~AnimalNativo();
};

#endif