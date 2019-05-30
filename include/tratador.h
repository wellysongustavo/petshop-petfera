#ifndef _TRATADOR_H_
#define _TRATADOR_H_

#include <string>
#include "funcionario.h"

class Tratador : public Funcionario {
	private:
		int m_nivel_de_seguranca;

	public:
		Tratador(std::string classe, int id, std::string nome, std::string cpf,
		int idade, std::string tipo_sanguineo, char fator_rh, std::string especialidade, 
		int nivel_de_seguranca);
		~Tratador();

		void setNivelSeguranca(int nivel_de_seguranca);
		int getNivelSeguranca();

		friend std::ostream& operator << (std::ostream& os, const Tratador& t);

};
#endif