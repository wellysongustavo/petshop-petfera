/**
 * @file anfibio.h
 * @brief Estrutura de dados da classe de Anfíbio
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _ANFIBIO_H_
#define _ANFIBIO_H_

#include <string>
#include "animal.h"
#include "veterinario.h"
#include "tratador.h"
#include "date.h"

/**
 * Classe Anfíbio. Herda atributos e membros da
 * classe Animal.
 */

class Anfibio : public Animal {
	protected:

		/**
		 * Total de mudas. Um atributo inteiro protegido com
		 * a quantidade de mudas do Anfíbio.
		 */

		int m_total_de_mudas;
		
		/**
		 * Última Muda. Atributo date protegido
		 * com a data da última múda do Anfíbio.
		 */

		date m_ultima_muda;

	public:

		/**
		 * Construtor de Anfíbio. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados classe Animal e
		 * atributos protegidos de sua classe.
		 */

		Anfibio(int id, std::string classe, std::string nome_cientifico, 
				char sexo, double tamanho, std::string dieta, int id_veterinario, 
				int id_tratador, std::string nome_batismo, int total_de_mudas, date ultima_muda); 
		
		/**
		 * Destrutor de Anfíbio.
		 */

		~Anfibio();

		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Animal.
		 */

		void dummy();
		
		/**
		 * Métodos setters. Modificadores.
		 */

		void setTotalMudas(int total_de_mudas);
		void setUltimaMuda(date ultima_muda);
		
		/**
		 * Métodos getters. Acessores
		 */
		
		date getUltimaMuda();
		int getTotalMudas();

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Anfíbio.
		 */

		friend std::ostream& operator << (std::ostream& os, Anfibio& a);
};

#endif