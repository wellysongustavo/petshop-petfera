#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <string>
#include <iostream>

class Funcionario {
	protected:
		int m_id;
		std::string m_nome;
		std::string m_cpf;
		int m_idade;
		short m_tipo_sanguineo;
		char m_fator_rh;
		std::string m_especialidade;

	public:
		Funcionario(int id, std::string nome, std::string cpf,
		int idade, short tipo_sanguineo, char fator_rh, std::string especialidade);
		~Funcionario();

		void setId(int id);
		std::string setNome(std::string nome);
		std::string stCpf(std::string cpf);
		int setIdade(int idade);
		short setTipoSanguineo(short tipo_sanguineo);
		char setFatorRh(char fator_rh);
		std::string setEspecialidade(std::string especialidade);

		int getId();
		std::string getNome();
		std::string getCpf();
		int getIdade();
		short getTipoSanguineo();
		char getFatorRh();
		std::string getEspecialidade();
	
};
#endif


#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

class Veterinario : public Funcionario {
	private:
		std::string m_crmv;

	public:
		Veterinario(int id, std::string nome, std::string cpf,
		int idade, short tipo_sanguineo, char fator_rh, std::string especialidade,
		std::string crmv);
		~Veterinario();

		void setCrmv(std::string crmv);
		std::string getCrmv();

		friend std::ostream& operator << (std::ostream& os, const Veterinario& v);
};
#endif


#ifndef _TRATADOR_H_
#define _TRATADOR_H_

class Tratador : public Funcionario {
	private:
		int m_nivel_de_seguranca;

	public:
		Tratador(int id, std::string nome, std::string cpf,
		int idade, short tipo_sanguineo, char fator_rh, std::string especialidade, 
		int nivel_de_seguranca);
		~Tratador();

		void setNivelSeguranca(int nivel_de_seguranca);
		int getNivelSeguranca();

		friend std::ostream& operator << (std::ostream& os, const Tratador& t);

};
#endif