#include "anfibio_nativo.h"

AnfibioNativo::AnfibioNativo(int id, std::string classe, std::string nome_cientifico, char sexo, 
			  				 double tamanho, std::string dieta, int id_veterinario, 
							 int id_tratador, std::string nome_batismo, int total_de_mudas, date ultima_muda,
			  				 std::string autorizacao, std::string uf_origem):
								
							 Anfibio(id, classe, nome_cientifico, sexo, tamanho, dieta, id_veterinario,
							   		 id_tratador, nome_batismo, total_de_mudas, ultima_muda),
							 AnimalNativo(autorizacao, uf_origem)
{}
AnfibioNativo::~AnfibioNativo(){}

void AnfibioNativo::dummy() { /* void */ }

//Getters e setters
void AnfibioNativo::setUfOrigem(std::string uf_origem) { m_uf_origem = uf_origem; }
void AnfibioNativo::setAutorizacao(std::string autorizacao) { m_autorizacao_ibama = autorizacao; }
std::string AnfibioNativo::getUfOrigem() { return m_uf_origem; }
std::string AnfibioNativo::getAutorizacao() { return m_autorizacao_ibama; }

std::ostream& operator << (std::ostream& os, AnfibioNativo& a) {
	os << "Id: " << a.m_id << "\nClasse: " << a.m_classe << "\nNome científico: " << a.m_nome_cientifico
	<< "\nSexo: " << a.m_sexo << "\nTamanho: " << a.m_tamanho << "\nDieta: " << a.m_dieta << "\nId do veterinario: " 
	<< a.m_id_veterinario << "\nId do tratador: " << a.m_id_tratador << "\nNome de batismo: " << a.m_nome_batismo 
	<< "\nTotal de mudas: " << a.m_total_de_mudas  << "\nData da ultima muda: " << a.m_ultima_muda << "\nAutorização do IBAMA: " 
	<< a.m_autorizacao_ibama << "\nRegião de origem: " << a.m_uf_origem 
	<< "\n________________________________________________________________________________" << std::endl;
	
	return os;	
}