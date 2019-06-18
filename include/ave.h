#ifndef _AVE_H_
#define _AVE_H_

#include <string>
#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

class Ave : public Animal {
	protected:
		double m_tamanho_do_bico_cm;
		double m_envergadura_das_asas;

	public:
		Ave(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas);
		~Ave();

		void dummy();

		void setTamanhoBico(double tamanho_do_bico_cm);
		void setEnvergaduraAsas(double envergadura_das_asas);
		double getTamanhoBico();
		double getEnvergaduraAsas();
		
		friend std::ostream& operator << (std::ostream& os, Ave& a);
};

#endif