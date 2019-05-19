#include "animal.h"
#include "reptil.h"

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

std::ostream& operator << (std::ostream& os, Reptil& r) {
	os << "Id: " << r.m_id << "\nClasse: " << r.m_classe << "\nNome científico: " << r.m_nome_cientifico
	<< "\nSexo: " << r.m_sexo << "\nTamanho: " << r.m_tamanho << "\nDieta: " << r.m_dieta << "\nId do veterinario: " 
	<< r.m_veterinario.getId() << "\nId do tratador: " << r.m_tratador.getId() << "\nNome de batismo: " << r.m_nome_batismo 
	<< "\nVenenoso: " << r.m_venenoso << "\nTipo venenoso: " << r.m_tipo_venenoso << "\n_____________________________________"
	<< std::endl;
	
	return os;	
}
