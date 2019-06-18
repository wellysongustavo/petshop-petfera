#include "animal.h"
#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"

Animal::Animal(int id, std::string classe, std::string nome_cientifico, 
	char sexo, double tamanho, std::string dieta, int id_veterinario, 
	int id_tratador, std::string nome_batismo) : m_id(id), m_classe(classe),
	m_nome_cientifico(nome_cientifico), m_sexo(sexo), m_tamanho(tamanho),
	m_dieta(dieta), m_id_veterinario(id_veterinario), m_id_tratador(id_tratador), 
	m_nome_batismo(nome_batismo) { /* void */ }

Animal::~Animal() { /* void */ }

//Métodos setters
void Animal::setId(int id) { m_id = id; }
void Animal::setClasse(std::string classe) { m_classe = classe; }
void Animal::setNomeCientifico(std::string nome_cientifico) { m_nome_cientifico = nome_cientifico; }
void Animal::setSexo(char sexo) { m_sexo = sexo; }
void Animal::setTamanho(double tamanho) { m_tamanho = tamanho; }
void Animal::setDieta(std::string dieta) { m_dieta = dieta; }
void Animal::setIdVeterinario(int id_veterinario) { m_id_veterinario = id_veterinario; }
void Animal::setIdTratador(int id_tratador) { m_id_tratador = id_tratador; }
void Animal::setNomeBatismo(std::string nome_batismo) { m_nome_batismo = nome_batismo; }
//Métodos getters
int Animal::getId() { return m_id; }
std::string Animal::getClasse() { return m_classe; }
std::string Animal::getNomeCientifico() { return m_nome_cientifico; }
char Animal::getSexo() { return m_sexo; }
double Animal::getTamanho() { return m_tamanho; }
std::string Animal::getDieta() { return m_dieta; }
int Animal::getIdVeterinario() { return m_id_veterinario; }
int Animal::getIdTratador() { return m_id_tratador; }
std::string Animal::getNomeBatismo() { return m_nome_batismo; }