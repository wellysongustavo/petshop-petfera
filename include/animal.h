/**
 * @file animal.h
 * @brief Estrutura de dados da classe de Animal
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>
#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"

/**
 * Classe Animal. Superclasse que herdará atributos e membros
 * comuns a todos animais.
 */

class Animal {
	protected:

		/**
		 * Atributo inteiro com ID do animal. 
		 */

		int m_id;
		
		/**
		 * Atributo string com Classe do animal. 
		 */

		std::string m_classe;
		
		/**
		 * Atributo string com Nome Científico do animal. 
		 */

		std::string m_nome_cientifico;
		
		/**
		 * Atributo char com o Sexo do animal.
		 */
		
		char m_sexo;

		/**
		 * Atributo double com o Tamanho do animal.
		 */

		double m_tamanho;
		
		/**
		 * Atributo string com a Dieta do animal. 
		 */
		
		std::string m_dieta;

		/**
		 * Atributo inteiro do ID do veterinário responsável. 
		 */

		int m_id_veterinario;
		
		/**
		 * Atributo inteiro do ID do tratador responsável. 
		 */

		int m_id_tratador;

		/**
		 * Atributo string com o Nome de Batismo do animal. 
		 */

		std::string m_nome_batismo;

	public:

		/**
		 * Construtor de Animal. Sobrecarregado com lista de 
		 * inicialização dos atributos protegidos. 
		 */

		Animal(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo);
		
		/**
		 * Construtor Padrão de Animal.
		 */
		
		Animal();

		/**
		 * Destrutor de Animal.
		 */

		~Animal();

		/**
		 * Método virtual Dummy. Assinatura da função para ser
		 * redefinida nas classes filhas. 
		 */

		virtual void dummy() = 0;

		/**
		 * Métodos setters. Modificadores.
		 */

		void setId(int id);
		void setClasse(std::string classe);
		void setNomeCientifico(std::string nome_cientifico);
		void setSexo(char sexo);
		void setTamanho(double tamanho);
		void setDieta(std::string dieta);
		void setIdVeterinario(int id_veterinario);
		void setIdTratador(int id_tratador);
		void setNomeBatismo(std::string nome_batismo);

		/**
		 * Métodos getters. Acessores.
		 */

		int getId();
		std::string getClasse();
		std::string getNomeCientifico();
		char getSexo();
		double getTamanho();
		std::string getDieta();
		int getIdVeterinario();
		int getIdTratador();
		std::string getNomeBatismo();
	
};

#endif