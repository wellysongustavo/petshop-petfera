#include "mamifero.h"
#include "animal_nativo.h"

#ifndef MAMIFERO_NATIVO_H
#define MAMIFERO_NATIVO_H

class MamiferoNativo: public Mamifero, AnimalNativo{
	public:
		MamiferoNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
            Tratador tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string uf_origem);
		~MamiferoNativo();
};

#endif