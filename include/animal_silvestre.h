#ifndef _ANIMAL_SILVESTRE_H_
#define _ANIMAL_SILVESTRE_H_

#include <string>

class AnimalSilvestre {

	protected:
		std::string m_autorizacao_ibama;

	public:
		AnimalSilvestre(std::string m_autorizacao_ibama);
		~AnimalSilvestre();
};

#endif