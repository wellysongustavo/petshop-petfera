#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

#include <string>
#include "funcionario.h"

class Veterinario : public Funcionario {
	private:
		std::string m_crmv;

	public:
		Veterinario(std::string classe, int id, std::string nome, std::string cpf,
		int idade, std::string tipo_sanguineo, char fator_rh, std::string especialidade,
		std::string crmv);
		~Veterinario();
		void dummy();

		void setCrmv(std::string crmv);
		std::string getCrmv();

		friend std::ostream& operator << (std::ostream& os, const Veterinario& v);
};
#endif