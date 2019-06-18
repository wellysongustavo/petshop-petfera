#include "animal.h"
#include "mamifero.h"

Mamifero::Mamifero(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, std::string cor_pelo) : Animal(id, classe, 
			nome_cientifico, sexo, tamanho, dieta, id_veterinario, id_tratador, nome_batismo),
			m_cor_pelo(cor_pelo) { /* void */ }

Mamifero::~Mamifero() { /* void */ }

void Mamifero::dummy() { /* void */ }

void Mamifero::setCorPelo(std::string cor_pelo) { m_cor_pelo = cor_pelo; }
std::string Mamifero::getCorPelo() { return m_cor_pelo; }

std::ostream& operator << (std::ostream& os, Mamifero& m) {
	os << "Id: " << m.m_id << "\nClasse: " << m.m_classe << "\nNome científico: " << m.m_nome_cientifico
	<< "\nSexo: " << m.m_sexo << "\nTamanho: " << m.m_tamanho << "\nDieta: " << m.m_dieta << "\nId do veterinario: " 
	<< m.m_id_veterinario << "\nId do tratador: " << m.m_id_tratador << "\nNome de batismo: " << m.m_nome_batismo 
	<< "\nCor do pelo: " << m.m_cor_pelo << "\n________________________________________________________________________________"
	<< std::endl;
	
	return os;	
}