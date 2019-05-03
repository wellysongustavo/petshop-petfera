#include <iostream>
#include <string>

#include "funcionario.h"

int main() {

	Funcionario func1(29, "Wellyson", "173.451.249-16", 22, 2, 'M', "Dormir");
	Veterinario vet1(29, "Veterano", "123.443.322-34", 29, 1, 'M', "Catioros", "Sei não o que é isso");
	Tratador trat1(58, "Trator", "324.324.223-32", 43, 3, 'M', "Tratados", 4);

	std::cout << vet1;
	std::cout << std::endl;
	std::cout << trat1;

	return 0;
}