#include "funcionario.h"

Funcionario::Funcionario(int id, std::string nome, std::string cpf, 
	int idade,std::string tipo_sanguineo, char fator_rh, std::string especialidade) : 
m_id(id), m_nome(nome), m_cpf(cpf), m_idade(idade), 
m_tipo_sanguineo(tipo_sanguineo), m_fator_rh(fator_rh), m_especialidade(especialidade) {
	/* void */
}

Funcionario::~Funcionario() { /* void */ }

//Métodos setters
void Funcionario::setId(int id) { m_id = id; }
void Funcionario::setNome(std::string nome) { m_nome = nome; }
void Funcionario::stCpf(std::string cpf) { m_cpf = cpf; }
void Funcionario::setIdade(int idade) { m_idade = idade; }
void Funcionario::setTipoSanguineo(std::string tipo_sanguineo) { m_tipo_sanguineo = tipo_sanguineo; }
void Funcionario::setFatorRh(char fator_rh) { m_fator_rh = fator_rh; }
void Funcionario::setEspecialidade(std::string especialidade) { m_especialidade = especialidade; }
//Métodos getters 
int Funcionario::getId() { return m_id; }
std::string Funcionario::getNome() { return m_nome; }
std::string Funcionario::getCpf() { return m_cpf; }
int Funcionario::getIdade() { return m_idade; }
std::string Funcionario::getTipoSanguineo() { return m_tipo_sanguineo; }
char Funcionario::getFatorRh() { return m_fator_rh; }
std::string Funcionario::getEspecialidade() { return m_especialidade; }