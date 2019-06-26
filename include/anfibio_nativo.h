/**
 * @file anfibio_nativo.h
 * @brief Estrutura de dados da classe de Anfíbio Nativo
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#include <iostream>
#include <string>
#include "anfibio.h"
#include "animal_nativo.h"
#include "animal_silvestre.h"

#ifndef _ANFIBIO_NATIVO_H_
#define _ANFIBIO_NATIVO_H_

/**
 * Classe de Anfíbio Nativo. Herda atributos e membros da
 * classe Anfibio e AnimalNativo.
 */

class AnfibioNativo: public Anfibio, AnimalNativo {
	public:

		/**
		 * Construtor de Anfíbio Nativo. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados das classes Anfibio e
		 * AnimalNativo.
		 */

		AnfibioNativo(int id, std::string classe, std::string nome_cientifico, char sexo, 
					  double tamanho, std::string dieta, int id_veterinario, 
					  int id_tratador, std::string nome_batismo, int total_de_mudas, date ultima_muda,
					  std::string autorizacao, std::string uf_origem);
		/**
		 * Destrutor de Anfíbio Nativo.
		 */

		~AnfibioNativo();

		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Animal.
		 */

		void dummy();

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Anfíbio Nativo.
		 */
		
		friend std::ostream& operator << (std::ostream& os, AnfibioNativo& a);

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
};

#endif