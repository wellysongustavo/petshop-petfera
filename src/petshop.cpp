#include <iostream>
#include <string>
#include <vector>

#include "petshop.h"
#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

Petshop::Petshop(int nome): m_nome(nome){}
Petshop::~Petshop(){}

void Petshop::cadastrarAnimal(){
	
}

void Petshop::removerAnimal(){}
void Petshop::editarAnimal(){}
void Petshop::consultarAnimal(){} //pesquisar por animal, classe animal, veterinario e tratador 

void Petshop::cadastrarVeterinario(){}
void Petshop::removerVeterinario(){}
void Petshop::editarVeterinario(){}
void Petshop::consultarVeterinario(){}

void Petshop::cadastrarTratador(){}
void Petshop::removerTratador(){}
void Petshop::editarTratador(){}
void Petshop::consultarTratador(){}