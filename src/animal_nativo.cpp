#ifndef _ANIMAL_NATIVO_H_
#define _ANIMAL_NATIVO_H_

#include <string>
#include "animal_silvestre.h"

class AnimalNativo : public AnimalSilvestre {

	protected:
		string m_autorizacao;
		string m_uf_origem;

	public:
		AnimalNativo(std::string m_autorizacao, std::string m_uf_origem);
		~AnimalNativo();
};

#endif