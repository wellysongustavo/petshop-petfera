#include <iostream>
#include "reptil.h"
#include "animal_nativo.h"

#ifndef _REPTIL_NATIVO_H_
#define _REPTIL_NATIVO_H_

class ReptilNativo : public Reptil, AnimalNativo {
	public:
		ReptilNativo();
		~ReptilNativo();
};

#endif