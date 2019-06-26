/**
 * @file funcionario.h
 * @brief Estrutura de dados da classe de Funcionário
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <string>
#include <iostream>

/**
 * Classe Funcionário. Superclasse que herdará atributos e membros
 * comuns a todos funcionários.
 */

class Funcionario {
	protected:

		/**
		 * Atributo string Classe. Verifica se funcionário é Veterinario
		 * ou Tratador.
		 */

		std::string m_classe;
		
		/**
		 * Atributo inteiro para ID do funcionário.
		 */

		int m_id;

		/**
		 * Atributo string para Nome do funcionário.
		 */

		std::string m_nome;

		/**
		 * Atributo string para CPF do funcionário.
		 */

		std::string m_cpf;

		/**
		 * Atributo inteiro para Idade do funcionário.
		 */

		int m_idade;

		/**
		 * Atributo string para Tipo Sanguíneo do funcionário.
		 */

		std::string m_tipo_sanguineo;
		
		/**
		 * Atributo char para Fator RH do Tipo Sanguíneo.
		 */

		char m_fator_rh;

		/**
		 * Atributo string para Especialidade do funcionário.
		 */

		std::string m_especialidade;

	public:

		/**
		 * Construtor de Funcionário. Sobrecarregado com lista de 
		 * inicialização dos atributos protegidos. 
		 */

		Funcionario(std::string classe, int id, std::string nome, std::string cpf,
		int idade, std::string tipo_sanguineo, char fator_rh, std::string especialidade);
		
		/**
		 * Destrutor de Funcionário.
		 */
		
		~Funcionario();

		/**
		 * Método virtual Dummy. Assinatura da função para ser
		 * redefinida nas classes filhas. 
		 */

		virtual void dummy() = 0;

		/**
		 * Métodos setters. Modificadores.
		 */
		
		void setClasse(std::string classe);
		void setId(int id);
		void setNome(std::string nome);
		void setCpf(std::string cpf);
		void setIdade(int idade);
		void setTipoSanguineo(std::string tipo_sanguineo);
		void setFatorRh(char fator_rh);
		void setEspecialidade(std::string especialidade);

		/**
		 * Métodos getters. Acessores.
		 */

		std::string getClasse();
		int getId();
		std::string getNome();
		std::string getCpf();
		int getIdade();
		std::string getTipoSanguineo();
		char getFatorRh();
		std::string getEspecialidade();
		
};
#endif