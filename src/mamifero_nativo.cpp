#include "mamifero_nativo.h"

MamiferoNativo::MamiferoNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string uf_origem) :

            Mamifero(id, classe, nome_cientifico, sexo, tamanho, dieta, id_veterinario,
            id_tratador, nome_batismo, cor_pelo),
            AnimalNativo(autorizacao, uf_origem) { }

MamiferoNativo::~MamiferoNativo(){ }

void MamiferoNativo::dummy() { /* void */ }

//Getters e setters
void MamiferoNativo::setUfOrigem(std::string uf_origem) { m_uf_origem = uf_origem; }
void MamiferoNativo::setAutorizacao(std::string autorizacao) { m_autorizacao_ibama = autorizacao; }
std::string MamiferoNativo::getUfOrigem() { return m_uf_origem; }
std::string MamiferoNativo::getAutorizacao() { return m_autorizacao_ibama; }

std::ostream& operator << (std::ostream& os, MamiferoNativo& m) {
	os << "Id: " << m.m_id << "\nClasse: " << m.m_classe << "\nNome científico: " << m.m_nome_cientifico
	<< "\nSexo: " << m.m_sexo << "\nTamanho: " << m.m_tamanho << "\nDieta: " << m.m_dieta << "\nId do veterinario: " 
	<< m.m_id_veterinario << "\nId do tratador: " << m.m_id_tratador << "\nNome de batismo: " << m.m_nome_batismo 
	<< "\nCor do pelo: " << m.m_cor_pelo << "\nAutorização do IBAMA: " << m.m_autorizacao_ibama << "\nRegião de origem: " 
	<< m.m_uf_origem << "\n________________________________________________________________________________" << std::endl;
	
	return os;	
}