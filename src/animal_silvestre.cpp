#ifndef _ANIMAL_SILVESTRE_H_
#define _ANIMAL_SILVESTRE_H_

#include <string>

class AnimalSilvestre {

	protected:
		string m_autorizacao_ibama;

	public:
		AnimalSilvestre(string m_autorizacao_ibama);
		AnimalSilvestre();
};

#endif