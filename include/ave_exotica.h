/**
 * @file ave_exotica.h
 * @brief Estrutura de dados da classe de Ave Exótica
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#include "ave.h"
#include "animal_exotico.h"

#ifndef AVE_EXOTICA_H
#define AVE_EXOTICA_H

/**
 * Classe de Anfíbio Exótico. Herda atributos e membros da
 * classe Anfibio e AnimalExotico.
 */

class AveExotica: public Ave, AnimalExotico{
	public:

		/**
		 * Construtor de Ave Exotica. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados da classe Ave e AnimalExotico. 
		 */

		AveExotica(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas, std::string autorizacao, std::string pais_origem);
		
		/**
		 * Destrutor de Ave Exótica.
		 */

		~AveExotica();

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

		std::string getAutorizacao();
		std::string getPaisOrigem();

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Ave Exótica.
		 */

		friend std::ostream& operator << (std::ostream& os, AveExotica& a);
};

#endif