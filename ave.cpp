#include <string>
#include "animal.h"

Ave::Ave(int id, std::string classe, std::string nome_cientifico,  
		char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
		Tratador tratador, std::string nome_batismo, double tamanho_do_bico_cm,
		double envergadura_das_asas) : Animal(id, classe, nome_cientifico, sexo, 
		tamanho, dieta, veterinario, tratador, nome_batismo), m_tamanho_do_bico_cm(
		tamanho_do_bico_cm), m_envergadura_das_asas(envergadura_das_asas) { /* void */ }

Ave::~Ave() { /* void */ }

void Ave::setTamanhoBico(double tamanho_do_bico_cm) { m_tamanho_do_bico_cm = tamanho_do_bico_cm; }
void Ave::setEnvergaduraAsas(double envergadura_das_asas) { m_envergadura_das_asas = envergadura_das_asas; }
double Ave::getTamanhoBico() { return m_tamanho_do_bico_cm; }
double Ave::getEnvergaduraAsas() { return m_envergadura_das_asas; }