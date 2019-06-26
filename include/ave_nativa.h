/**
 * @file ave_nativa.h
 * @brief Estrutura de dados da classe de Ave Nativa
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#include "ave.h"
#include "animal_nativo.h"


#ifndef AVE_NATIVA_H
#define AVE_NATIVA_H

/**
 * Classe de Ave Nativa. Herda atributos e membros da
 * classe Ave e AnimalNativo.
 */

class AveNativa: public Ave, AnimalNativo{
	public:

		/**
		 * Construtor de Ave Nativa. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados das classes Ave e
		 * AnimalNativo.
		 */

		AveNativa(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas, std::string autorizacao, std::string uf_origem);
		
		/**
		 * Destrutor de Ave Nativa.
		 */	

		~AveNativa();

		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Animal.
		 */

		void dummy();

		/**
		 * Métodos setters. Modificadores.
		 */

		void setUfOrigem(std::string uf_origem);
		void setAutorizacao(std::string autorizacao);
		
		/**
		 * Métodos getters. Acessores.
		 */

		std::string getAutorizacao();
		std::string getUfOrigem();

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Ave Nativa.
		 */

		friend std::ostream& operator << (std::ostream& os, AveNativa& a);
};

#endif