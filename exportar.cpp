#include <iostream>
#include <string.h>
#include <unistd.h> // Para o getopt()

int main(int argc, char** argv){
	int c = 0;
	std::string c_classe, v_veterinario, t_tratador, arquivo;

	while((c = getopt(argc, argv, "c:v:t:")) != -1){
		switch(c){
			case 'c':
				if(optarg)	c_classe = optarg;
				break;
			case 'v':
				if(optarg)	v_veterinario = optarg;
				break;
			case 't':
				if(optarg)	t_tratador = optarg;
				break;
		}
	}
	if(optind < argc) {
		do{
			arquivo = argv[optind];
		}while(++optind < argc);
	}

	/*
		std::cout << "Execute novamente informando: " << std::endl;
		std::cout << "-c <classe>: argumento opcional indica a classe de animais a serem exportados;" << std::endl;
		std::cout << "-v <veterinario>: argumento opcional indica que apenas animais sob a"
				  << " responsabilidade do veterinário informado devem ser exportados." << std::endl;
		std::cout << "-t <tratador>: argumento opcional indica que apenas animais tratados "
				  << "pelo tratador informado devem ser exportados."<< std::endl;
		std::cout << "<arquivo_saida>: este argumento obrigatório indica o nome do arquivo de saída, "
				  << "ou seja, do arquivo onde serão guardados os dados a serem exportados." << std::endl;
	
	*/
	return 0;
}