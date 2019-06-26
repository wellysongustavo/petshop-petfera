/**
 * @file reptil.h
 * @brief Estrutura de dados da classe de Réptil
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _REPTIL_H_
#define _REPTIL_H_

#include <string>
#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

/**
 * Classe Réptil. Herda atributos e membros da
 * classe Animal.
 */

class Reptil : public Animal {
	protected:
		/**
		 * Bool Venenoso. Verifica se réptil é venenoso e 
		 * retorna verdadeiro ou falso.
		 */

		bool m_venenoso;
		
		/**
		 * Tipo Venenoso. String para o tipo do veneno do
		 * réptil venososo.
		 */

		std::string m_tipo_venenoso;

	public:

		/**
		 * Construtor de Réptil. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados classe Animal e
		 * atributos protegidos de sua classe.
		 */

		Reptil(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso = "Não venenoso");
		
		/**
		 * Destrutor de Réptil.
		 */

		~Reptil();

		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Animal.
		 */

		void dummy();

		/**
		 * Métodos setters. Modificadores.
		 */
		
		void setVenenoso(bool venenoso);
		void setTipoVenenoso(std::string tipo_venenoso);
		
		/**
		 * Métodos getters. Acessores.
		 */

		bool getVenenoso();
		std::string getTipoVenenoso();

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Réptil.
		 */

		friend std::ostream& operator << (std::ostream& os, Reptil& r);	
};

#endif