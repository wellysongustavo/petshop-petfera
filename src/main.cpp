#include <iostream>
#include <string>

#include "funcionario.h"
#include "tratador.h"
#include "veterinario.h"
#include "animal.h"
#include "anfibio.h"
#include "mamifero.h"
#include "reptil.h"
#include "ave.h"
#include "date.h"

int main() {

	Veterinario* vet1 = new Veterinario(2, "Daniel Oscar", "123.456.789-10", 30, "O", '+', "Felinos", "CRMV-GO 0406");
	Tratador* trat1 = new Tratador(1, "João Alberto", "007.404.200-98", 45, "AB", '-', "Répteis e Aves", 1);
	std::cout << *vet1 << "\n" << *trat1 << std::endl;

	Animal* a1 = new Animal(1, "Mammalia", "Panthera leo", 'M', 2.05, "Carne", *vet1, *trat1, "Leão");
	std::cout << a1->getClasse() << std::endl;

	//Testando implementação da classe date
	date d(29,11,1998);
	Anfibio* anf = new Anfibio(29, "Anfibio", "Anfibio Cientista", 'M', 3.23, "Só guaraná da amazonia", *vet1, *trat1, "Anfibiozin", 20, d);
	std::cout << "\n" << anf->getUltimaMuda() << std::endl;



	return 0;
}