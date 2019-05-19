#include "anfibio_exotico.h"

AnfibioExotico::AnfibioExotico(int id, std::string classe, std::string nome_cientifico, 
   		   char sexo, double tamanho, std::string dieta, Veterinario veterinario, 
   		   Tratador tratador, std::string nome_batismo, int total_de_mudas, 
   		   date ultima_muda, std::string autorizacao, std::string pais_origem) : 

		   Anfibio(id, classe, nome_cientifico, sexo, tamanho, dieta, veterinario,
		   		   tratador, nome_batismo, total_de_mudas, ultima_muda),
		   AnimalExotico(autorizacao, pais_origem) { }

AnfibioExotico::~AnfibioExotico(){ }

std::ostream& operator << (std::ostream& os, AnfibioExotico& a) {
	os << "Id: " << a.m_id << "\nClasse: " << a.m_classe << "\nNome científico: " << a.m_nome_cientifico
	<< "\nSexo: " << a.m_sexo << "\nTamanho: " << a.m_tamanho << "\nDieta: " << a.m_dieta << "\nId do veterinario: " 
	<< a.m_veterinario.getId() << "\nId do tratador: " << a.m_tratador.getId() << "\nNome de batismo: " << a.m_nome_batismo 
	<< "\nTotal de mudas: " << a.m_total_de_mudas  << "\nData da ultima muda: " << a.m_ultima_muda << "\nAutorização do IBAMA: " 
	<< a.m_autorizacao_ibama << "\nRegião de origem: " << a.m_pais_origem << "\n_____________________________________"
	<< std::endl;
	
	return os;	
}