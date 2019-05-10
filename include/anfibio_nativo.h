#include <iostream>
#include <string>
#include "anfibio.h"
#include "animal_nativo.h"

#ifndef _ANFIBIO_NATIVO_H_
#define _ANFIBIO_NATIVO_H_

class AnfibioNativo: public Anfibio, AnimalNativo{
	public:
		AnfibioNativo(int id, std::string classe, std::string nome_cientifico, char sexo, 
					  double tamanho, std::string dieta, Veterinario veterinario, 
					  Tratador tratador, std::string nome_batismo, int total_de_mudas, date ultima_muda
					  std::string autorizacao, std::string uf_origem);
		~AnfibioNativo();
};

#endif