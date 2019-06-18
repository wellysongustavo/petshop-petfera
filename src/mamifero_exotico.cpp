#include "mamifero_exotico.h"

MamiferoExotico::MamiferoExotico(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string pais_origem) :

            Mamifero(id, classe, nome_cientifico, sexo, tamanho, dieta, id_veterinario,
            id_tratador, nome_batismo, cor_pelo),
            AnimalExotico(autorizacao, pais_origem) { }
MamiferoExotico::~MamiferoExotico(){ }

void MamiferoExotico::dummy() { /* void */ }

//Getters e setters
void MamiferoExotico::setPaisOrigem(std::string pais_origem) { m_pais_origem = pais_origem; }
void MamiferoExotico::setAutorizacao(std::string autorizacao) { m_autorizacao_ibama = autorizacao; }
std::string MamiferoExotico::getPaisOrigem() { return m_pais_origem; }
std::string MamiferoExotico::getAutorizacao() { return m_autorizacao_ibama; }

std::ostream& operator << (std::ostream& os, MamiferoExotico& m) {
	os << "Id: " << m.m_id << "\nClasse: " << m.m_classe << "\nNome científico: " << m.m_nome_cientifico
	<< "\nSexo: " << m.m_sexo << "\nTamanho: " << m.m_tamanho << "\nDieta: " << m.m_dieta << "\nId do veterinario: " 
	<< m.m_id_veterinario << "\nId do tratador: " << m.m_id_tratador << "\nNome de batismo: " << m.m_nome_batismo 
	<< "\nCor do pelo: " << m.m_cor_pelo << "\nAutorização do IBAMA: " << m.m_autorizacao_ibama << "\nRegião de origem: " 
	<< m.m_pais_origem << "\n________________________________________________________________________________" << std::endl;
	
	return os;	
}