#include "reptil_exotico.h"

ReptilExotico::ReptilExotico(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso, std::string autorizacao, std::string pais_origem) : Reptil(id, 
			classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso,  
			tipo_venenoso), AnimalExotico(autorizacao, pais_origem)  { /* void */ }

ReptilExotico::~ReptilExotico() { /* void */ }

std::ostream& operator << (std::ostream& os, ReptilExotico& r) {
	os << "Id: " << r.m_id << "\nClasse: " << r.m_classe << "\nNome científico: " << r.m_nome_cientifico
	<< "\nSexo: " << r.m_sexo << "\nTamanho: " << r.m_tamanho << "\nDieta: " << r.m_dieta << "\nId do veterinario: " 
	<< r.m_veterinario.getId() << "\nId do tratador: " << r.m_tratador.getId() << "\nNome de batismo: " << r.m_nome_batismo 
	<< "\nVenenoso: " << r.m_venenoso << "\nTipo venenoso: " << r.m_tipo_venenoso << "\nAutorização do IBAMA: " 
	<< r.m_autorizacao_ibama << "\nRegião de origem: " << r.m_pais_origem << "\n_____________________________________"
	<< std::endl;
	
	return os;	
}