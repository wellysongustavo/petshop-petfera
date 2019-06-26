/**
 * @file reptil_exotico.h
 * @brief Estrutura de dados da classe de Réptil Exótico
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#include "reptil.h"
#include "animal_exotico.h"

#ifndef _REPTIL_EXOTICO_H_
#define _REPTIL_EXOTICO_H_

/**
 * Classe de Réptil Exótico. Herda atributos e membros da
 * classe Reptil e AnimalExotico.
 */

class ReptilExotico: public Reptil, AnimalExotico {
	public:

		/**
		 * Construtor de Réptil Exótico. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados da classe Reptil e 
		 * AnimalExotico.
		 */

		ReptilExotico(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string pais_origem);
		
		/**
		 * Destrutor de Réptil Exótico.
		 */

		~ReptilExotico();

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
		 * para imprimir todos dados de uma referência de Réptil Exótico.
		 */

		friend std::ostream& operator << (std::ostream& os, ReptilExotico& r);	

};

#endif