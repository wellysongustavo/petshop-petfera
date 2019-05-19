#include <iostream>
#include <string>
#include <map>

#include "animal.h"
#include "veterinario.h"
#include "tratador.h"

#ifndef _PETSHOP_H_
#define _PETSHOP_H_

class Petshop{
	private:
		std::map<int, Animal*> map_animais;
		std::map<int,Veterinario> map_veterinarios;
		std::map<int,Tratador> map_tratadores;
	public:
		std::string m_nome;
		Petshop(std::string nome);
		~Petshop();

		void cadastrarAnimal();
		void cadastrarAnfibio(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void cadastrarReptil(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void cadastrarAve(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void cadastrarMamifero(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		void listarAnimais();	
		void removerAnimal();
		void editarAnimal();
		void consultarAnimal(); //pesquisar por animal, classe animal, veterinario e tratador 

		void cadastrarVeterinario(int id_, std::string nome_, std::string cpf_, int idade_, std::string tipo_sanguineo_, char fator_rh_, 			std::string especialidade_);
		void listarVeterinarios();
		void removerVeterinario();
		void editarVeterinario();
		void consultarVeterinario();

		void cadastrarTratador(int id_, std::string nome_, std::string cpf_, int idade_, std::string tipo_sanguineo_, char fator_rh_, 			std::string especialidade_);
		void listarTratadores();
		void removerTratador();
		void editarTratador();
		void consultarTratador();

		void cadastrarFuncionario();
		void removerFuncionario();
};

#endif
/*
std::ostream& operator << (std::ostream& os, AnfibioNativo& a) {
	os << "Id: " << a.m_id << "\nClasse: " << a.m_classe << "\nNome científico: " << a.m_nome_cientifico
	<< "\nSexo: " << a.m_sexo << "\nTamanho: " << a.m_tamanho << "\nDieta: " << a.m_dieta << "\nId do veterinario: " 
	<< a.m_veterinario.getId() << "\nId do tratador: " << a.m_tratador.getId() << "\nNome de batismo: " << a.m_nome_batismo 
	<< "\nTotal de mudas: " << a.m_total_de_mudas  << "\nData da ultima muda: " << a.m_ultima_muda << "\nAutorização do IBAMA: " 
	<< a.m_autorizacao_ibama << "\nRegião de origem: " << a.m_uf_origem << "\n_____________________________________"
	<< std::endl;
	
	return os;	
}*/