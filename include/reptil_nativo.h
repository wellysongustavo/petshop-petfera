#include "reptil.h"
#include "animal_nativo.h"

#ifndef _REPTIL_NATIVO_H_
#define _REPTIL_NATIVO_H_

class ReptilNativo : public Reptil, AnimalNativo {
	public:
		ReptilNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string uf_origem);
		~ReptilNativo();

		void dummy();

		std::string getAutorizacao();
		std::string getUfOrigem();
		void setAutorizacao(std::string autorizacao);
		void setUfOrigem(std::string uf_origem);
		
		friend std::ostream& operator << (std::ostream& os, ReptilNativo& r);	

};

#endif