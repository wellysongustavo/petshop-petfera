#include <string>
#include "animal_silvestre.h"

AnimalExotico::AnimalExotico(std::string autorizacao, std::string pais_origem):
							AnimalSilvestre(autorizacao),
							m_pais_origem(pais_origem)
{}

AnimalExotico::~AnimalExotico(){}