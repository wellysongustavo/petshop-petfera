/**
 * @file reptil_nativo.h
 * @brief Estrutura de dados da classe de Réptil Nativo
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#include "reptil.h"
#include "animal_nativo.h"

#ifndef _REPTIL_NATIVO_H_
#define _REPTIL_NATIVO_H_

/**
 * Classe de Réptil Nativo. Herda atributos e membros da
 * classe Reptil e AnimalNativo.
 */

class ReptilNativo : public Reptil, AnimalNativo {
	public:

		/**
		 * Construtor de Réptil Nativo. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados das classes Reptil e
		 * AnimalNativo.
		 */

		ReptilNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string uf_origem);
		
		/**
		 * Destrutor de Réptil Nativo.
		 */

		~ReptilNativo();

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
		 * para imprimir todos dados de uma referência de Réptil Nativo.
		 */

		friend std::ostream& operator << (std::ostream& os, ReptilNativo& r);	

};

#endif