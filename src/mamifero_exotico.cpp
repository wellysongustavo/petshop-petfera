#include "mamifero_exotico.h"

MamiferoExotico::MamiferoExotico(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
            Tratador tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string pais_origem) :

            Mamifero(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario,
            tratador, nome_batismo, cor_pelo),
            AnimalExotico(autorizacao, pais_origem) { }
MamiferoExotico::~MamiferoExotico(){ }