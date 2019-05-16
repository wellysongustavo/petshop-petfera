#include <iostream>
#include <string>

#include "funcionario.h"
#include "tratador.h"
#include "veterinario.h"
#include "animal.h"
#include "animal_silvestre.h"
#include "animal_nativo.h"
#include "animal_exotico.h"
#include "anfibio.h"
#include "anfibio_nativo.h"
#include "anfibio_exotico.h"
#include "mamifero.h"
#include "reptil.h"
#include "reptil_nativo.h"
#include "ave.h"
#include "date.h"
#include "petshop.h"

int main() {

	/*Veterinario* vet1 = new Veterinario(2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador(1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);
	std::cout << *vet1 << "\n" << *trat1 << std::endl;

	Animal* a1 = new Animal(1, "Mammalia", "Panthera leo", 'M', 2.05, "Carne", *vet1, *trat1, "Leão");
	std::cout << a1->getClasse() << std::endl;

	//Testando implementação da classe date
	date d(29,11,1998);
	AnfibioExotico* anfE = new AnfibioExotico(29, "Anfibio", "Anfibio Cientista", 'M', 3.23, "Só guaraná da amazonia", *vet1, *trat1, "Anfibiozin", 20, d, 
		"Num tem", "China");
	std::cout << "\n" << anfE->getUltimaMuda() << std::endl;*/

	//Teste instancia petshop
	Petshop* pet = new Petshop("PetGarrafa");

	//pet->cadastrarFuncionario();
	pet->cadastrarAnimal();



	return 0;
}