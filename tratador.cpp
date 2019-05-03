#include "funcionario.h"

Tratador::Tratador(int id, std::string nome, std::string cpf, 
	int idade, short tipo_sanguineo, char fator_rh, std::string especialidade, 
	int nivel_de_seguranca) : Funcionario(id, nome, cpf, idade, tipo_sanguineo, fator_rh,
	especialidade), m_nivel_de_seguranca(nivel_de_seguranca) { /* void */ }

Tratador::~Tratador() { /* void */ }

void Tratador::setNivelSeguranca(int nivel_de_seguranca) { m_nivel_de_seguranca = nivel_de_seguranca; }
int Tratador::getNivelSeguranca() { return m_nivel_de_seguranca; }

std::ostream& operator << (std::ostream& os, const Tratador& t) {
	os << "ID: " << t.m_id << "\nNome: " << t.m_nome << "\nCPF: " << t.m_cpf 
	<< "\nIdade: " << t.m_idade << "\nTipo sanguíneo: " << t.m_tipo_sanguineo 
	<< "\nFator RH: " << t.m_fator_rh << "\nEspecialidade: " << t.m_especialidade 
	<< "\nNível de Segurança: " << t.m_nivel_de_seguranca << std::endl;	

	return os;
}