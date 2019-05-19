#include "reptil.h"
#include "animal_nativo.h"

#ifndef _REPTIL_NATIVO_H_
#define _REPTIL_NATIVO_H_

class ReptilNativo : public Reptil, AnimalNativo {
	public:
		ReptilNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string uf_origem);
		~ReptilNativo();

		friend std::ostream& operator << (std::ostream& os, ReptilNativo& r);	

};

#endif