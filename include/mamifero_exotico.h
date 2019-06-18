#include "mamifero.h"
#include "animal_exotico.h"

#ifndef MAMIFERO_EXOTICO_H
#define MAMIFERO_EXOTICO_H

class MamiferoExotico: public Mamifero, AnimalExotico{
	public:
		MamiferoExotico(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
            int id_tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string pais_origem);		
		~MamiferoExotico();

		void dummy();
		
		std::string getAutorizacao();
		std::string getPaisOrigem();
		void setAutorizacao(std::string autorizacao);
		void setPaisOrigem(std::string pais_origem);

		friend std::ostream& operator << (std::ostream& os, MamiferoExotico& m);
};

#endif