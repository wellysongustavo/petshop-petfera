#include <iostream>
#include "mamifero.h"
#include "animal_exotico.h"

#ifndef _MAMIFERO_EXOTICO_H_
#define _MAMIFERO_EXOTICO_H_

class MamiferoExotico: public AnimalExotico{
	
	public:
		MamiferoExotico();
		~MamiferoExotico();
};

#endif