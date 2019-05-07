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
		Veterinario m_veterinario;
		Tratador m_tratador;
		std::string m_nome_batismo;

	public:
		Animal(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo);
		Animal();
		~Animal();

		void setId(int id);
		void setClasse(std::string classe);
		void setNomeCientifico(std::string nome_cientifico);
		void setSexo(char sexo);
		void setTamanho(double tamanho);
		void setDieta(std::string dieta);
		void setVeterinario(Veterinario veterinario);
		void setTratador(Tratador tratador);
		void setNomeBatismo(std::string nome_batismo);

		int getId();
		std::string getClasse();
		std::string getNomeCientifico();
		char getSexo();
		double getTamanho();
		std::string getDieta();
		Veterinario getVeterinario();
		Tratador getTratador();
		std::string getNomeBatismo();
	
};

#endif