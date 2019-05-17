#include "mamifero.h"
#include "animal_exotico.h"

#ifndef MAMIFERO_EXOTICO_H
#define MAMIFERO_EXOTICO_H

class MamiferoExotico: public Mamifero, AnimalExotico{
	public:
		MamiferoExotico(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
            Tratador tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string pais_origem);
		
		~MamiferoExotico();
};

#endif