#include <string>
#include "animal_silvestre.h"
#include "animal_nativo.h"

AnimalNativo::AnimalNativo(std::string autorizacao, std::string uf_origem) : AnimalSilvestre(autorizacao),
		m_uf_origem(uf_origem) { /* void */ }

AnimalNativo::~AnimalNativo() { /* void */ }