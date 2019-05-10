#include "animal.h"
#include "reptil.h"
#include "reptil_nativo.h"
#include "animal_nativo.h"

Reptil::Reptil(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso) : Animal(id, classe, nome_cientifico, sexo, 
			tamanho, dieta, veterinario, tratador, nome_batismo), m_venenoso(venenoso),
			m_tipo_venenoso(tipo_venenoso) { /*void */	}

Reptil::~Reptil() { /* void */ }

void Reptil::setVenenoso(bool venenoso) { m_venenoso = venenoso; }
void Reptil::setTipoVenenoso(std::string tipo_venenoso) { m_tipo_venenoso = tipo_venenoso; }
bool Reptil::getVenenoso() { return m_venenoso; }
std::string Reptil::getTipoVenenoso() { return m_tipo_venenoso; }

//Reptil nativo

ReptilNativo::ReptilNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string uf_origem) : Animal(id, classe, nome_cientifico, sexo, 
			tamanho, dieta, veterinario, tratador, nome_batismo), m_venenoso(venenoso),
			Reptil(tipo_venenoso), AnimalNativo(autorizacao, uf_origem)  { /* void */ }

ReptilNativo::~ReptilNativo() { /* void */ }