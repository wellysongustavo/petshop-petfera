#include "anfibio_exotico.h"

AnfibioExotico::AnfibioExotico(int id, std::string classe, std::string nome_cientifico, 
   		   char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
   		   Tratador tratador, std::string nome_batismo, int total_de_mudas, 
   		   date ultima_muda, std::string autorizacao, std::string pais_origem) : 

		   Anfibio(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario,
		   		   tratador, nome_batismo, total_de_mudas, ultima_muda),
		   AnimalExotico(autorizacao, pais_origem) { }

AnfibioExotico::~AnfibioExotico(){ }