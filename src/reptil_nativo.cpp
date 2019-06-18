#include "reptil_nativo.h"

ReptilNativo::ReptilNativo(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string uf_origem) : Reptil(id, 
			classe, nome_cientifico, sexo, tamanho, dieta, id_veterinario, id_tratador, nome_batismo, venenoso,  
			tipo_venenoso), AnimalNativo(autorizacao, uf_origem)  { /* void */ }

ReptilNativo::~ReptilNativo() { /* void */ }

void ReptilNativo::dummy() { /* void */ }

//Getters e setters
void ReptilNativo::setUfOrigem(std::string uf_origem) { m_uf_origem = uf_origem; }
void ReptilNativo::setAutorizacao(std::string autorizacao) { m_autorizacao_ibama = autorizacao; }
std::string ReptilNativo::getUfOrigem() { return m_uf_origem; }
std::string ReptilNativo::getAutorizacao() { return m_autorizacao_ibama; }

std::ostream& operator << (std::ostream& os, ReptilNativo& r) {
	os << "Id: " << r.m_id << "\nClasse: " << r.m_classe << "\nNome científico: " << r.m_nome_cientifico
	<< "\nSexo: " << r.m_sexo << "\nTamanho: " << r.m_tamanho << "\nDieta: " << r.m_dieta << "\nId do veterinario: " 
	<< r.m_id_veterinario << "\nId do tratador: " << r.m_id_tratador << "\nNome de batismo: " << r.m_nome_batismo 
	<< "\nVenenoso: " << std::boolalpha << r.m_venenoso << "\nTipo venenoso: " << r.m_tipo_venenoso << "\nAutorização do IBAMA: " 
	<< r.m_autorizacao_ibama << "\nRegião de origem: " << r.m_uf_origem 
	<< "\n________________________________________________________________________________" << std::endl;
	
	return os;	
}