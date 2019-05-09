#ifndef _ANIMAL_EXOTICO_H_
#define _ANIMAL_EXOTICO_H_

#include <string>
#include "animal_silvestre.h"

class AnimalExotico : public AnimalSilvestre {

	protected:
		string m_autorizacao;
		string m_pais_origem;

	public:
		AnimalExotico(std::string m_autorizacao, std::string m_uf_origem);
		~AnimalExotico();
};

#endif