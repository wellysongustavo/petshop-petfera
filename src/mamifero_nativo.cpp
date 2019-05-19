#include "mamifero_nativo.h"

MamiferoNativo::MamiferoNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
            Tratador tratador, std::string nome_batismo, std::string cor_pelo, 
            std::string autorizacao, std::string uf_origem) :

            Mamifero(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario,
            tratador, nome_batismo, cor_pelo),
            AnimalNativo(autorizacao, uf_origem) { }

MamiferoNativo::~MamiferoNativo(){ }

std::ostream& operator << (std::ostream& os, MamiferoNativo& m) {
	os << "Id: " << m.m_id << "\nClasse: " << m.m_classe << "\nNome científico: " << m.m_nome_cientifico
	<< "\nSexo: " << m.m_sexo << "\nTamanho: " << m.m_tamanho << "\nDieta: " << m.m_dieta << "\nId do veterinario: " 
	<< m.m_veterinario.getId() << "\nId do tratador: " << m.m_tratador.getId() << "\nNome de batismo: " << m.m_nome_batismo 
	<< "\nCor do pelo: " << m.m_cor_pelo << "\nAutorização do IBAMA: " << m.m_autorizacao_ibama << "\nRegião de origem: " 
	<< m.m_uf_origem << "\n_____________________________________" << std::endl;
	
	return os;	
}