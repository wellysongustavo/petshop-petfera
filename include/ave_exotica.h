#include "ave.h"
#include "animal_exotico.h"

#ifndef AVE_EXOTICA_H
#define AVE_EXOTICA_H

class AveExotica: public Ave, AnimalExotico{
	public:
		AveExotica(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas, std::string autorizacao, std::string pais_origem);
		~AveExotica();

		void dummy();
		
		void setPaisOrigem(std::string pais_origem);
		std::string getPaisOrigem();
		void setAutorizacao(std::string autorizacao);
		std::string getAutorizacao();

		friend std::ostream& operator << (std::ostream& os, AveExotica& a);
};

#endif