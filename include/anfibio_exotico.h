#include <iostream>
#include "anfibio.h"
#include "animal_exotico.h"

#ifndef _ANFIBIO_EXOTICO_H_
#define _ANFIBIO_EXOTICO_H_

class AnfibioExotico: public Anfibio, AnimalExotico{
	
	public:
		AnfibioExotico();
		~AnfibioExotico();
};

#endif