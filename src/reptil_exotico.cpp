#include "animal.h"
#include "reptil.h"
#include "reptil_exotico.h"
#include "animal_exotico.h"

ReptilExotico::ReptilExotico(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string pais_origem) : Reptil(id, 
			classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso,  
			tipo_venenoso), AnimalExotico(autorizacao, pais_origem)  { /* void */ }

ReptilExotico::~ReptilExotico() { /* void */ }