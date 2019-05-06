#include <string>
#include "animal.h"

Mamifero::Mamifero(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, std::string cor_pelo) : Animal(id, classe, 
			nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo),
			m_cor_pelo(cor_pelo) { /* void */ }

Mamifero::~Mamifero() { /* void */ }

void Mamifero::setCorPelo(std::string cor_pelo) { m_cor_pelo = cor_pelo; }
std::string Mamifero::getCorPelo() { return m_cor_pelo; }