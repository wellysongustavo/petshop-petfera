#include <iostream>
#include "mamifero.h"
#include "animal_nativo.h"
#include "mamifero_nativo.h"
//#include "animal_silvestre.h"

MamiferoNativo::MamiferoNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
            Tratador tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string uf_origem) :

            Mamifero(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario,
            tratador, nome_batismo, cor_pelo),
            AnimalNativo(autorizacao, uf_origem) { }
MamiferoNativo::~MamiferoNativo(){ }