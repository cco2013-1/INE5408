/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 03 - Implementação de filas de char com Vetores em C++
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
 	void adiciona(T elemento); //adiciona o elemento na ultima posicao livre
 	void adicionaNoInicio(T elemento); //adiciona o elemento no inicio da lista
 	void adicionaNaPosicao(T elemento, int posicao); //adiciona o elemento na posicao desejada
 	void adicionaEmOrdem(T elemento); //adiciona o elemento na ordem definida pelo programador
 	T retira(); //retira o ultimo elemento da lista
 	T retiraDoInicio(); 
 	T retiraDaPosicao(int posicao);
 	T retiraEspecifico(T elemento); 
 	bool listaCheia();
 	bool listaVazia();
 	int posicao(T elemento);
 	bool contem(T elemento);
 	bool igual(T elemento1, T elemento2);
 	bool maior(T elemento1, T elemento2); //retorna true caso o elemento 1 for maior que o elemento 2 (verificar necessidade)
 	bool menor(T elemento1, T elemento2); //retorna true caso o elemento 1 for menor que o elemento 2 (verificar necessidade)
private:
	T dados[TAMANHO_MAX];
	int ultimo; //valor da posição do ultimo elemento inserido na lista
	void deslocarEsquerda(int posicao); //desloca os elementos da lista para a esquerda a partir da posição passada por parâmetro
	void deslocarDireita(int posicao); //desloca os elementos da lista para a direita a partir da posição passada por parâmetro
 };

template typename<T>
Lista<T>::Lista() {
	ultimo = -1;
}

template typename<T>
Lista<T>::~Lista() {
	ultimo = -1;
}

template typename<T>
bool Lista<T>::estaCheia() {
	if(ultimo == TAMANHO_MAX - 1) {
		return true;
	}
	return false;
}

template typename<T>
bool Lista<T>::estaVazia() {
	if(ultimo == -1) {
		return true;
	}
	return false;
}

template typename<T>
void Lista<T>::adiciona(T elemento) {
	if(!estaCheia()) {
		dados[++ultimo]=elemento;	
		return;
	}
	throw (ERRO_LISTA_CHEIA);
}

template typename<T>
T Lista<T>::retira() {
	if(!estaCheia()) {
		return dados[ultimo--];
	}
	throw (ERRO_LISTA_CHEIA);
}


/* Os métodos abaixo servirão de base para implementar métodos instanciados acima*/



template typename<T>	
void Lista<T>::inserirNaPosicao(T elemento, int posicao) {
	if(!estaCheia()) {
		if(posicao =< TAMANHO_MAX & posicao >= 0) {
			deslocarDireita(posicao);
			dados[posicao] = elemento;
			return;
		}
		throw (ERRO_POSICAO_INEXISTENTE);
	}
	throw (ERRO_LISTA_CHEIA);
}

template typename<T>
void Lista<T>::retirarDaPosicao(int posicao) {
	if(!estaVazia()) {
		if(posicao =< TAMANHO_MAX & posicao >= 0) {
			deslocarEsquerda(posicao);
			return; 
		}
		throw(ERRO_POSICAO_INEXISTENTE);	
	}
	throw(ERRO_LISTA_VAZIA);
	
}

template typename<T>
void Lista<T>::retirarElemento(T elemento) {

}

template typename<T>
T Lista<T>::pegarElemento(T elemento) {

}

template typename<T>
T Lista<T>::pegarElementoEm(int posicao) {
	if(posicao =< TAMANHO_MAX & posicao >= 0) {
		return dados[posicao];
	}
	throw(ERRO_POSICAO_INEXISTENTE);
}

template typename<T>
bool Lista<T>::estaCheia() {
	if()
}
