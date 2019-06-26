/**
 * @file tratador.h
 * @brief Estrutura de dados da classe de Tratador
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _TRATADOR_H_
#define _TRATADOR_H_

#include <string>
#include "funcionario.h"

/**
 * Classe Tratador. Herda atributos e membros da classe
 * Funcionario.
 */

class Tratador : public Funcionario {
	private:
		
		/**
		 * Nível de Segurança. Atributo inteiro para o 
		 * sinalizar o nível de segurança do Tratador.
		 */

		int m_nivel_de_seguranca;

	public:

		/**
		 * Construtor de Tratador. Sobrecarregado com lista de 
		 * inicialização dos atributos herdados classe Funcionario e
		 * atributos protegidos de sua classe.
		 */

		Tratador(std::string classe, int id, std::string nome, std::string cpf,
		int idade, std::string tipo_sanguineo, char fator_rh, std::string especialidade, 
		int nivel_de_seguranca);
		
		/**
		 * Destrutor de Tratador.
		 */

		~Tratador();
		
		/**
		 * Função Dummy. Implementação da função para 
		 * método virtual da superclasse Funcionário.
		 */

		void dummy();
		
		/**
		 * Métodos setters. Modificadores.
		 */

		void setNivelSeguranca(int nivel_de_seguranca);
		
		/**
		 * Métodos getters. Acessores.
		 */

		int getNivelSeguranca();

		/**
		 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
		 * para imprimir todos dados de uma referência de Tratador.
		 */

		friend std::ostream& operator << (std::ostream& os, const Tratador& t);
		
		/**
		 * Sobrecarga do operador de igualdade. Sobrecarrega operador ==
		 * para verificar se os tratadores passados por referência são iguais,
		 * retornando verdadeiro ou falso.
		 */

		friend bool operator == (const Tratador& t1, const Tratador& t2);
};
#endif