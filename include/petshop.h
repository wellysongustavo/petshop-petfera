/**
 * @file petshop.h
 * @brief Estrutura de dados e assinaturas da classe controladora Petshop
 * @authors
   Fernanda Laís Pereira de Souza 
   Pedro Hugo da Silva Freire
   Wellyson Gustavo Silva Oliveira
 * @since 03/05/2019
 * @date 26/06/2019
 */

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <iterator>
#include <typeinfo>
#include <fstream>
#include <vector>

#include "funcionario.h"
#include "tratador.h"
#include "veterinario.h"
#include "animal.h"
#include "animal_silvestre.h"
#include "animal_nativo.h"
#include "animal_exotico.h"
#include "anfibio.h"
#include "anfibio_nativo.h"
#include "anfibio_exotico.h"
#include "mamifero.h"
#include "mamifero_nativo.h"
#include "mamifero_exotico.h"
#include "reptil.h"
#include "reptil_nativo.h"
#include "reptil_exotico.h"
#include "ave.h"
#include "ave_exotica.h"
#include "ave_nativa.h"
#include "date.h"

#ifndef _PETSHOP_H_
#define _PETSHOP_H_

/**
 * Classe Petshop. Para controle do PetFera
 */

class Petshop{
	private:

		/**
		 * Map map_animais. Para guardar animais cadastrados e seus id's
		 */
		
		std::map<int, Animal*> map_animais;
		
		/**
		 * Map map_funcionarios. Para guardar funcionários cadastrados e seus id's
		 */		
		
		std::map<int, Funcionario*> map_funcionarios;
	
	public:
		std::string m_nome;
		
		/**
		 * Construtor. Construtor da classe controladora que 
		 * recebe uma string que será seu nome.
		 */ 
		
		Petshop(std::string nome);
		
		/**
		 * Destrutor.
		 */
		
		~Petshop();

		/**
		 * Função para abertura de arquivo. Recebe uma string com
		 * o nome do arquivo para abertura e retorna um objeto fstream.
		 */

		std::fstream abrirArquivo(std::string tipo_map);
		
		/**
		 * Função para leitura do arquivo de controle de animais. Percorre
		 * o csv controle_animais e faz leitura para o map_animais
		 * da classe.
		 */

		void lerArquivoAnimal();

		/**
		 * Função para atualizar o arquivo de controle de animais. Escreve no arquivo
		 * os atributos dos animais presentes no map_animais da classe.
		 */

		void atualizaArquivoAnimal();
		
		/**
		 * Função para atualizar o arquivo de controle de funcionários. Escreve no arquivo
		 * os atributos dos funcionários presentes no map_funcionario da classe.
		 */

		void gravarArquivoFuncionario();
		
		/**
		 * Função para leitura do arquivo de controle de funcionários. Percorre
		 * o csv controle_funcionários e faz leitura para o map_funcionarios
		 * da classe.
		 */
		
		void lerArquivoFuncionario();
		
		/**
		 * Função para desalocar memória. Limpa a memória que
		 * foi alocada para objetos anteriormente com o destrutor. 
		 */

		void desalocarObjetos();
		
		/**
		 * Função para busca por id. Recebe uma string para identificar em qual
		 * map fazer busca e em caso de encontrar, esse id é retornado.
		 */
		
		int buscarPorId(std::string tipo_map);
		
		/**
		 * Função para verificar id. Recebe uma string para identificar em qual
		 * map fazer verificação, retornando o id apenas se não houver sido
		 * cadastrado anteriormente.
		 */

		int verificaId(std::string tipo_map);

		/**
		 * Função para imprimir animal. Recebe um objeto de animal e imprime
		 * seus atributos no prompt de comando.
		 */
		void imprimeAnimalEspecifico(Animal* animal);

		/**
		 * Função para cadastrar animal. Coleta os atributos da classe animal
		 * e envia para o cadastro da classe específica do animal. 
		 */

		void cadastrarAnimal();
		
		/**
		 * Função para cadastrar animal da classe anfíbio. Recebe parâmetros da função de
		 * cadastro de animal e coleta os atributos específicos da classe
		 * anfíbio para criar objeto. 
		 */\
		
		void cadastrarAnfibio(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		
		/**
		 * Função para cadastrar animal da classe réptil. Recebe parâmetros da função de
		 * cadastro de animal e coleta os atributos específicos da classe
		 * anfíbio para criar objeto. 
		 */

		void cadastrarReptil(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		
		/**
		 * Função para cadastrar animal da classe ave. Recebe parâmetros da função de
		 * cadastro de animal e coleta os atributos específicos da classe
		 * anfíbio para criar objeto. 
		 */

		void cadastrarAve(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);
		
		/**
		 * Função para cadastrar animal da classe mamífero. Recebe parâmetros da função de
		 * cadastro de animal e coleta os atributos específicos da classe
		 * anfíbio para criar objeto. 
		 */

		void cadastrarMamifero(int id, std::string nome_cientifico, char sexo, 
			double tamanho, std::string dieta, int id_veterinario, int id_tratador, 
			std::string nome_batismo);

		/**
		 * Função para listar animais. Imprime na tela o catálogo de animais
		 * cadastrados no Petshop Petfera.
		 */

		void listarAnimais();	

		/**
		 * Função para remover animal. Procura pelo id no map de controle de
		 * animais e o remove ao encontrá-lo.
		 */		

		void removerAnimal();

		/**
		 * Função para editar animais cadastrados. Com um iterador do map, percorre
		 * até encontrar animal a ser editado e coleta os novos dados.
		 */
		
		void editarAnimal();

		/**
		 * Função para consultar animal. Pesquisa por id do animal, classe do animal,
		 * por veterinário responsável e tratador.
		 */

		void consultarAnimal();

		/**
		 * Função para cadastrar funcionários. Coleta os atributos da classe funcionário
		 * e envia para o cadastro da classe específica do funcionário. 
		 */

		void cadastrarFuncionario();
		
		/**
		 * Função para listar funcionários. Lista os veterinários e tratadores cadastrados
		 * no map de controle de funcionários. 
		 */

		void listarFuncionarios();

		/**
		 * Função para remover funcionário. Procura pelo id no map de controle de
		 * funcionário e o remove ao encontrá-lo.
		 */		

		void removerFuncionario();
		
		/**
		 * Função para editar funcionários cadastrados. Com um iterador do map, percorre
		 * até encontrar funcionários a ser editado e coleta os novos dados.
		 */

		void editarFuncionario();
		
		/**
		 * Função para consultar funcionários. Pesquisa por id do funcionários,
		 * lista todos veterinários e lista todos tratadores cadastrados. 
		 */

		void consultarFuncionario();
};

#endif