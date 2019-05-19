#include "ave.h"
#include "animal_nativo.h"


#ifndef AVE_NATIVA_H
#define AVE_NATIVA_H

class AveNativa: public Ave, AnimalNativo{
	public:
		AveNativa(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas, std::string autorizacao, std::string uf_origem);
		~AveNativa();

		friend std::ostream& operator << (std::ostream& os, AveNativa& a);
};

#endif