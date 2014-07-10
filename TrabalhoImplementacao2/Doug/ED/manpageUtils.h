#ifndef MANPAGEUTILS_H
#define MANPAGEUTILS_H
#include <string>
#include <vector>

/**
* struct responsável por armazenar informações de uma manpage
* comando é o nome da manpage
* conteudo é o conteudo da manpage
* 
* OBS: a maior manpage disponibilizada possui aproximadamente 140000 bytes
* como os registros possuem tamanho fixo, é necessario alocar espaço para acomodar o maior arquivo
* mesmo que a maioria das manpages possuem ~5000 bytes.
*/
struct Manpage{
    char comando[100];
    char conteudo[140000];
};

class ManpageUtils{
public:
	/**
	* Método de acesso a um registro específico,
	* determinado por <tamanho do registro> * index
	* 
	* @param caminho para o arquivo de registros
	* @param identificador do registro desejado (posição do mesmo no arquivo de registros)
	* @return Manpage contendo o comando e o conteudo da manpage encontrada
	*/
	Manpage leRegistros(char* registros, int index);
	std::vector<Manpage> a(char* indexes, std::string palavra, char* registros);


};

#endif