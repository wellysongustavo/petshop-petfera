#include "funcionario.h"
#include "veterinario.h"

Veterinario::Veterinario(int id, std::string nome, std::string cpf, 
	int idade, std::string tipo_sanguineo, char fator_rh, std::string especialidade, 
	std::string crmv) : Funcionario(id, nome, cpf, idade, tipo_sanguineo, fator_rh,
	especialidade), m_crmv(crmv) { /* void */ }

Veterinario::~Veterinario() { /* void */ }

void Veterinario::setCrmv(std::string crmv) { m_crmv = crmv; }
std::string Veterinario::getCrmv() { return m_crmv; }

std::ostream& operator << (std::ostream& os, const Veterinario& v) {
	os << "ID: " << v.m_id << "\nNome: " << v.m_nome << "\nCPF: " << v.m_cpf 
	<< "\nIdade: " << v.m_idade << "\nTipo sanguíneo: " << v.m_tipo_sanguineo 
	<< "\nFator RH: " << v.m_fator_rh << "\nEspecialidade: " << v.m_especialidade 
	<< "\nCRMV: " << v.m_crmv << std::endl;	

	return os;
}