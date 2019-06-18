#include "ave.h"
#include "animal_nativo.h"


#ifndef AVE_NATIVA_H
#define AVE_NATIVA_H

class AveNativa: public Ave, AnimalNativo{
	public:
		AveNativa(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas, std::string autorizacao, std::string uf_origem);
		~AveNativa();

		void dummy();

		void setUfOrigem(std::string uf_origem);
		std::string getUfOrigem();
		void setAutorizacao(std::string autorizacao);
		std::string getAutorizacao();
		
		friend std::ostream& operator << (std::ostream& os, AveNativa& a);
};

#endif