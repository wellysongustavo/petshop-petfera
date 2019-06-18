#include "ave_exotica.h"

AveExotica::AveExotica(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas, std::string autorizacao, std::string pais_origem):

            Ave(id, classe, nome_cientifico, sexo, tamanho, dieta, id_veterinario,
            id_tratador, nome_batismo, tamanho_do_bico_cm, envergadura_das_asas),
            AnimalExotico(autorizacao, pais_origem) { }
AveExotica::~AveExotica() { }

void AveExotica::dummy() { /* void */ }

void AveExotica::setPaisOrigem(std::string pais_origem) { m_pais_origem = pais_origem; }
void AveExotica::setAutorizacao(std::string autorizacao) { m_autorizacao_ibama = autorizacao; }
std::string AveExotica::getPaisOrigem() { return m_pais_origem; }
std::string AveExotica::getAutorizacao() { return m_autorizacao_ibama; }

std::ostream& operator << (std::ostream& os, AveExotica& a) {
	os << "Id: " << a.m_id << "\nClasse: " << a.m_classe << "\nNome científico: " << a.m_nome_cientifico
	<< "\nSexo: " << a.m_sexo << "\nTamanho: " << a.m_tamanho << "\nDieta: " << a.m_dieta << "\nId do veterinario: " 
	<< a.m_id_veterinario << "\nId do tratador: " << a.m_id_tratador << "\nNome de batismo: " << a.m_nome_batismo 
	<< "\nTamanho do bico (em cm): " << a.m_tamanho_do_bico_cm  << "\nEnvergadura das asas (em cm): " << a.m_envergadura_das_asas
	<< "\nAutorização do IBAMA: " << a.m_autorizacao_ibama << "\nRegião de origem: " << a.m_pais_origem << 
	"\n________________________________________________________________________________" << std::endl;
	
	return os;	
}
