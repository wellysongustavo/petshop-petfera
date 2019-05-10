#ifndef _REPTIL_H_
#define _REPTIL_H_

#include <string>
#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

class Reptil : public Animal {
	protected:
		bool m_venenoso;
		std::string m_tipo_venenoso;

	public:
		Reptil(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso);
		~Reptil();

		void setVenenoso(bool venenoso);
		void setTipoVenenoso(std::string tipo_venenoso);
		bool getVenenoso();
		std::string getTipoVenenoso();	
};

#endif