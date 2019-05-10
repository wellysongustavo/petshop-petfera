#include <iostream>
#include <string>
#include "anfibio.h"
#include "animal_nativo.h"
#include "anfibio_nativo.h"

AnfibioNativo::AnfibioNativo(int id, std::string classe, std::string nome_cientifico, char sexo, 
			  				 double tamanho, std::string dieta, Veterinario veterinario, 
			  				 Tratador tratador, std::string nome_batismo, int total_de_mudas, date ultima_muda
			  				 std::string autorizacao, std::string uf_origem):
								
							 Anfibio(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario,
							   		 tratador, nome_batismo, total_de_mudas, ultima_muda),
							 AnimalNativo(autorizacao, uf_origem)
{}
AnfibioNativo::~AnfibioNativo(){}