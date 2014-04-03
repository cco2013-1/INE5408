/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 02 - Implementação de filas de char com Vetores em C++
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * Lista.hpp
 */

#define TAMANHO_MAX = 100
#define ERRO_LISTA_CHEIA = -1;
#define ERRO_LISTA_VAZIA = -2; 
#define ERRO_POSICAO_INEXISTENTE = -3;

template typename<T>
 class Lista {
 public:
 	Lista();
 	~Lista();
 	void inserir(T elemento);
 	void inserirNaPosicao(T elemento, int posicao);
 	void retirarDaPosicao(int posicao);
 	void retirarElemento(T elemento);
 	T pegarElemento(T elemento);
 	T pegarElementoEm(int posicao);
 	bool estaCheia();
 	bool estaVazia();
 	int posicaoDo(T elemento);
 	bool contem(T elemento);

private:
	T dados[TAMANHO_MAX];
	int tamanho;

 };

template typename<T>
Lista<T>::Lista() {
	tamanho = -1;
}

template typename<T>
Lista<T>::~Lista() {

}

template typename<T>
void Lista<T>::inserir(T elemento) {
	if(!estaCheia()) {
		dados[tamanho++]=elemento;	
		return;
	}
	throw (ERRO_LISTA_CHEIA);
}

template typename<T>	
Lista<T>::inserirNaPosicao(T elemento, int posicao) {
	if(posicao =< TAMANHO_MAX & posicao >= 0) {
		dados[posicao] = elemento;
		return;
	}
	throw (ERRO_POSICAO_INEXISTENTE);
}

template typename<T>
Lista<T>::retirarDaPosicao(int posicao) {
	if(posicao =< TAMANHO_MAX & posicao >= 0) {
		dados[posicao] = NULL;
		return; 
	}
	throw(ERRO_POSICAO_INEXISTENTE);
}