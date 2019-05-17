#include "reptil_nativo.h"

ReptilNativo::ReptilNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string uf_origem) : Reptil(id, 
			classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso,  
			tipo_venenoso), AnimalNativo(autorizacao, uf_origem)  { /* void */ }

ReptilNativo::~ReptilNativo() { /* void */ }