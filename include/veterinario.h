/**
 * @file veterinario.h
 * @brief Estrutura de dados da classe de Veterinário
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

#include <string>
#include "funcionario.h"

/**
 * Classe Veterinário. Herda atributos e membros da classe
 * Funcionario.
 */

class Veterinario : public Funcionario {
	private:

		/**
		 * CRMV. Atributo string para guardar o
		 * CRMV do funcionário.
		 */

		std::string m_crmv;

	public:
		
		/**
		 * Construtor de Veterinário. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados classe Funcionario e
		 * atributos protegidos de sua classe.
		 */

		Veterinario(std::string classe, int id, std::string nome, std::string cpf,
		int idade, std::string tipo_sanguineo, char fator_rh, std::string especialidade,
		std::string crmv);
		
		/**
		 * Destrutor de Veterinário.
		 */

		~Veterinario();
		
		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Funcionário.
		 */

		void dummy();

		/**
		 * Métodos setters. Modificadores.
		 */

		void setCrmv(std::string crmv);
		
		/**
		 * Métodos getters. Acessores.
		 */

		std::string getCrmv();

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Veterinário.
		 */

		friend std::ostream& operator << (std::ostream& os, const Veterinario& v);
		
		/**
		 * Sobrecarga do operador de igualdade. Sobrecarrega operador ==
		 * para verificar se os veterinários passados por referência são iguais,
		 * retornando verdadeiro ou falso.
		 */
		
		friend bool operator == (const Veterinario& v1, const Veterinario& v2);
};
#endif