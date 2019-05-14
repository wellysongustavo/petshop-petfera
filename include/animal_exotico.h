#ifndef _ANIMAL_EXOTICO_H_
#define _ANIMAL_EXOTICO_H_

#include <string>
#include "animal_silvestre.h"

class AnimalExotico : public AnimalSilvestre {

	protected:
		std::string m_pais_origem;

	public:
		AnimalExotico(std::string autorizacao, std::string pais_origem);
		~AnimalExotico();
};

#endif