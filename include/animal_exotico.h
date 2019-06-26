/**
 * @file animal_exotico.h
 * @brief Estrutura de dados da classe de Animal Exótico
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _ANIMAL_EXOTICO_H_
#define _ANIMAL_EXOTICO_H_

#include <string>
#include "animal_silvestre.h"

/**
 * Classe Animal Exotico. Herda atributos e membros de AnimalSilvestre
 * e características de um animal exótico. 
 */

class AnimalExotico : public AnimalSilvestre {

	protected:

		/**
		 * Atributo protected com o país de origem.
		 * do animal silvestre exótico.
		 */

		std::string m_pais_origem;

	public:

		/**
		 * Construtor de Animal Exótico. Construtor da classe Animal Exótico 
		 * com lista de inicialização dos atributos da classe e herdados de
		 * Animal Silvestre.
		 */ 

		AnimalExotico(std::string autorizacao, std::string pais_origem);
		
		/**
		 * Destrutor de Animal Exótico.
		 */

		~AnimalExotico();
};

#endif