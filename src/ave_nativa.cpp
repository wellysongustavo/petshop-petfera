#include "ave_nativa.h"

AveNativa::AveNativa(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas, std::string autorizacao, std::string uf_origem):

            Ave(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario,
            tratador, nome_batismo, tamanho_do_bico_cm, envergadura_das_asas),
            AnimalNativo(autorizacao, uf_origem) { }
AveNativa::~AveNativa() { }

//Getters e setters
void AveNativa::setUfOrigem(std::string uf_origem) { m_uf_origem = uf_origem; }
void AveNativa::setAutorizacao(std::string autorizacao) { m_autorizacao_ibama = autorizacao; }
std::string AveNativa::getUfOrigem() { return m_uf_origem; }
std::string AveNativa::getAutorizacao() { return m_autorizacao_ibama; }

std::ostream& operator << (std::ostream& os, AveNativa& a) {
	os << "Id: " << a.m_id << "\nClasse: " << a.m_classe << "\nNome científico: " << a.m_nome_cientifico
	<< "\nSexo: " << a.m_sexo << "\nTamanho: " << a.m_tamanho << "\nDieta: " << a.m_dieta << "\nId do veterinario: " 
	<< a.m_veterinario.getId() << "\nId do tratador: " << a.m_tratador.getId() << "\nNome de batismo: " << a.m_nome_batismo 
	<< "\nTamanho do bico (em cm): " << a.m_tamanho_do_bico_cm  << "\nEnvergadura das asas (em cm): " << a.m_envergadura_das_asas
	<< "\nAutorização do IBAMA: " << a.m_autorizacao_ibama << "\nRegião de origem: " << a.m_uf_origem << 
	"\n________________________________________________________________________________" << std::endl;
	
	return os;	
}