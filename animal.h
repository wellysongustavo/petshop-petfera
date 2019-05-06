#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>
#include "funcionario.h"

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

/* Criar .h separado para próximas classes */

#ifndef _ANFIBIO_H_
#define _ANFIBIO_H_

class Anfibio : public Animal {
	protected:
		int m_total_de_mudas;
		//date m_ultima_muda; 	/* Implemetar tipo date */

	public:
		Anfibio(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, int total_de_mudas); /* Falta date ultima_muda */ 
		~Anfibio();
		
		void setTotalMudas(int total_de_mudas);
		int getTotalMudas();
		/*
		void setUltimaMuda(date ultima_muda);
		date getUltimaMuda();
		*/	
};

#endif

#ifndef _MAMIFERO_H_
#define _MAMIFERO_H_

class Mamifero : public Animal {
	protected:
		std::string m_cor_pelo;

	public:
		Mamifero(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, std::string cor_pelo);
		~Mamifero();

		void setCorPelo(std::string cor_pelo);
		std::string getCorPelo();
	
};

#endif

#ifndef _REPTIL_H_
#define _REPTIL_H_

class Reptil : public Animal {
	protected:
		bool m_venenoso;
		std::string m_tipo_venenoso;

	public:
		Reptil(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, bool venenoso, 
			std::string tipo_venenoso);
		~Reptil();

		void setVenenoso(bool venenoso);
		void setTipoVenenoso(std::string tipo_venenoso);
		bool getVenenoso();
		std::string getTipoVenenoso();	
};

#endif

#ifndef _AVE_H_
#define _AVE_H_

class Ave : public Animal {
	protected:
		double m_tamanho_do_bico_cm;
		double m_envergadura_das_asas;

	public:
		Ave(int id, std::string classe, std::string nome_cientifico, 
			char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
			Tratador tratador, std::string nome_batismo, double tamanho_do_bico_cm,
			double envergadura_das_asas);
		~Ave();

		void setTamanhoBico(double tamanho_do_bico_cm);
		void setEnvergaduraAsas(double envergadura_das_asas);
		double getTamanhoBico();
		double getEnvergaduraAsas();
	
};

#endif