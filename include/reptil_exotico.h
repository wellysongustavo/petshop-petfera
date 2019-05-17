#include "reptil.h"
#include "animal_exotico.h"

#ifndef _REPTIL_EXOTICO_H_
#define _REPTIL_EXOTICO_H_

class ReptilExotico: public Reptil, AnimalExotico {
	public:
		ReptilExotico(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string pais_origem);
		~ReptilExotico();
};

#endif