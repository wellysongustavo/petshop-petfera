#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>
#include "funcionario.h"
#include "veterinario.h"
#include "tratador.h"

class Animal {
	protected:
		int m_id;
		std::string m_classe;
		std::string m_nome_cientifico;
		char m_sexo;
		double m_tamanho;
		std::string m_dieta;
		int m_id_veterinario;
		int m_id_tratador;
		std::string m_nome_batismo;

	public:
		Animal(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, int id_veterinario, 
			int id_tratador, std::string nome_batismo);
		Animal();
		~Animal();

		virtual void dummy() = 0;

		void setId(int id);
		void setClasse(std::string classe);
		void setNomeCientifico(std::string nome_cientifico);
		void setSexo(char sexo);
		void setTamanho(double tamanho);
		void setDieta(std::string dieta);
		void setIdVeterinario(int id_veterinario);
		void setIdTratador(int id_tratador);
		void setNomeBatismo(std::string nome_batismo);

		int getId();
		std::string getClasse();
		std::string getNomeCientifico();
		char getSexo();
		double getTamanho();
		std::string getDieta();
		int getIdVeterinario();
		int getIdTratador();
		std::string getNomeBatismo();
	
};

#endif