/**
 * @file date.h
 * @brief Estrutura de dados da classe de date
 * @authors Bernt A Oedegaard
 * @date 26/06/2019
 */

#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <string>

using namespace std;

/**
 * Classe date. Classe para manipulação de datas.
 */

class date {
protected:

	/**
	 * Atributo inteiro que guarda o valor do dia.
	 */
	
	int day_;

	/**
	 * Atributo inteiro que guarda o valor do mês.
	 */
	
	int month_;
	
	/**
	 * Atributo inteiro que guarda o valor do ano.
	 */
	
	int year_;
	
public:

	/**
	 * Construtor Padrão da Classe date.
	 */

	date();

	/**
	 * Construtor de date. Sobrecarregado com lista de 
	 * inicialização dos atributos protegidos.
	 */

	date(const int& d, const int& m, const int& y);
	
	/**
	 * Função valid. Verifica se os valores de dia,
	 * mês e ano são validos retornando verdadeiro ou
	 * falso.
	 */

	bool valid(void) const;

	/**
	 * Métodos getters. Acessores.
	 */
	
	int day() const;
	int month() const;
	int year() const;

	/**
	 * Métodos setters. Modificadores.
	 */
	
	void set_day(const int& day);
	void set_month(const int& month);
	void set_year(const int& year);

	/**
	 * Função Converte String. Recebe uma data do tipo
	 * string e faz conversão para o tipo date.
	 */

	date converte_string(std::string string_data);
};

/**
 * Sobrecarga do operador de inserção. Sobrecarrega operador <<
 * para imprimir data no formato dia/mês/ano.
 */

ostream& operator << ( ostream& os, const date& d); //output operator

#endif