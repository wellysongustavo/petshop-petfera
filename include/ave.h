/**
 * @file ave.h
 * @brief Estrutura de dados da classe de Ave
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _AVE_H_
#define _AVE_H_

#include <string>
#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

/**
 * Classe Ave. Herda atributos e membros da
 * classe Animal.
 */

class Ave : public Animal {
	protected:
		
		/**
		 * Tamanho do bico. Atributo double protegido do
		 * tamanho do bico da Ave.
		 */

		double m_tamanho_do_bico_cm;
		
		/**
		 * Envergadura das asas. Atributo double protegido do
		 * tamanho da envergadura das asas da Ave.
		 */

		double m_envergadura_das_asas;

	public:

		/**
		 * Construtor de Ave. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados classe Animal e
		 * atributos protegidos de sua classe.
		 */

		Ave(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas);
		
		/**
		 * Destrutor de Ave.
		 */

		~Ave();

		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Animal.
		 */

		void dummy();

		/**
		 * Métodos setters. Modificadores.
		 */

		void setTamanhoBico(double tamanho_do_bico_cm);
		void setEnvergaduraAsas(double envergadura_das_asas);
		
		/**
		 * Métodos getters. Acessores.
		 */
		
		double getTamanhoBico();
		double getEnvergaduraAsas();
		
		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Anfíbio.
		 */

		friend std::ostream& operator << (std::ostream& os, Ave& a);
};

#endif