/**
 * @file anfibio_exotico.h
 * @brief Estrutura de dados da classe de Anfíbio Exótico
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
#include "animal_exotico.h"

#ifndef _ANFIBIO_EXOTICO_H_
#define _ANFIBIO_EXOTICO_H_

/**
 * Classe de Anfíbio Exótico. Herda atributos e membros da
 * classe Anfibio e AnimalExotico.
 */

class AnfibioExotico: public Anfibio, AnimalExotico{
	
	public:

		/**
		 * Construtor de Anfíbio Exótico. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados da classe Anfibio e 
		 * AnimalExotico.
		 */

		AnfibioExotico(int id, std::string classe, std::string nome_cientifico, 
					   char sexo, double tamanho, std::string dieta, int id_veterinario, 
					   int id_tratador, std::string nome_batismo, int total_de_mudas, 
					   date ultima_muda, std::string autorizacao, std::string pais_origem);
		
		/**
		 * Destrutor de Anfíbio Exótico.
		 */

		~AnfibioExotico();

		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Animal.
		 */

		void dummy();

		/**
		 * Métodos setters. Modificadores.
		 */
		void setPaisOrigem(std::string pais_origem);
		void setAutorizacao(std::string autorizacao);

		/**
		 * Métodos getters. Acessores.
		 */

		std::string getPaisOrigem();
		std::string getAutorizacao();

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Anfíbio Exótico.
		 */

		friend std::ostream& operator << (std::ostream& os, AnfibioExotico& a);
};

#endif