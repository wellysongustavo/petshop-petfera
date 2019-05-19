#include <iostream>
#include <string>
#include "anfibio.h"
#include "animal_exotico.h"

#ifndef _ANFIBIO_EXOTICO_H_
#define _ANFIBIO_EXOTICO_H_

class AnfibioExotico: public Anfibio, AnimalExotico{
	
	public:
		AnfibioExotico(int id, std::string classe, std::string nome_cientifico, 
					   char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
					   Tratador tratador, std::string nome_batismo, int total_de_mudas, 
					   date ultima_muda, std::string autorizacao, std::string pais_origem);
		~AnfibioExotico();

		friend std::ostream& operator << (std::ostream& os, AnfibioExotico& a);
};

#endif