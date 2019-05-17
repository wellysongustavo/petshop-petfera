#include <iostream>
#include "animal.h"
#include "anfibio.h"

Anfibio::Anfibio(int id, std::string classe, std::string nome_cientifico, 
				char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
				Tratador tratador, std::string nome_batismo, int total_de_mudas, date ultima_muda) : 

				Animal(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo), 

				m_total_de_mudas(total_de_mudas), m_ultima_muda(ultima_muda) {}

Anfibio::~Anfibio() { /* void */ }

void Anfibio::setTotalMudas(int total_de_mudas) { m_total_de_mudas = total_de_mudas; }
void Anfibio::setUltimaMuda(date ultima_muda) { m_ultima_muda = ultima_muda; }
int Anfibio::getTotalMudas() { return m_total_de_mudas; }
date Anfibio::getUltimaMuda() { return m_ultima_muda; }