/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 03 - Implementação de um programa com número variável
 * de Listas com vetores usando a Classe lista com vetor
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * Lista.hpp
 */

#ifndef __lista_hpp__
#define __lista_hpp__

#define TAMANHO_INICIAL 10
#define ERRO_LISTA_CHEIA -1
#define ERRO_LISTA_VAZIA -2
#define ERRO_POSICAO_INEXISTENTE -3
#define ERRO_ELEMENTO_INEXISTENTE -4

template <typename T>
class Lista {
public:
    Lista();
    ~Lista();
    void adiciona(T elemento); //adiciona o elemento na ultima posicao livre
    void adicionaNoInicio(T elemento); //adiciona o elemento no inicio da lista
    void adicionaNaPosicao(T elemento, int posicao); //adiciona o elemento na posicao desejada
    T elementoNaPosicao(int posicao);
    T retira(); //retira o ultimo elemento da lista
    T retiraDaPosicao(int posicao);
    void retiraEspecifico(T elemento);
    bool estaCheia();
    bool estaVazia();
    int posicao(T elemento);
    bool contem(T elemento);
    int tamanho();
private:
    T *dados;
    int ultimo; //valor da posição do ultimo elemento inserido na lista
    int capacidade;
    void aumentaCapacidade();
    void deslocarEsquerda(int posicao); //desloca os elementos da lista para a esquerda a partir da posição passada por parâmetro
    void deslocarDireita(int posicao); //desloca os elementos da lista para a direita a partir da posição passada por parâmetro
 };

template <typename T>
Lista<T>::Lista() {
    dados = new T[TAMANHO_INICIAL];
    capacidade = TAMANHO_INICIAL;
    ultimo = -1;
}

template <typename T>
Lista<T>::~Lista() {
    ultimo = -1;
}

template <typename T>
bool Lista<T>::estaCheia() {
    return ultimo == capacidade - 1;
}

template <typename T>
bool Lista<T>::estaVazia() {
    if (ultimo == -1) {
        return true;
    }
    return false;
}

template <typename T>
void Lista<T>::adiciona(T elemento) {
    if (estaCheia()) {
        aumentaCapacidade();
    }

    dados[++ultimo]=elemento;
}

template <typename T>
void Lista<T>::aumentaCapacidade() {
    capacidade = 2 * capacidade;
    T * novosDados = new T[capacidade];
    for (int i = 0; i < tamanho(); i ++) {
        novosDados[i] = dados[i];
    }
    delete [] dados;
    dados = novosDados;
}

template <typename T>
T Lista<T>::retira() {
    if (!estaVazia()) {
        return dados[ultimo--];
    }
    throw (ERRO_LISTA_CHEIA);
}

template <typename T>
void Lista<T>::adicionaNoInicio(T elemento) {
    adicionaNaPosicao(elemento, 0);
}

template <typename T>
T Lista<T>::elementoNaPosicao(int posicao) {
    return dados[posicao];
}

template <typename T>
T Lista<T>::retiraDaPosicao(int posicao) {
    if (estaVazia()) {
        throw (ERRO_LISTA_VAZIA);
    }
    T elementoRetirado = dados[posicao];
    deslocarEsquerda(posicao);
    return elementoRetirado;
}

template <typename T>
void Lista<T>::adicionaNaPosicao(T elemento, int posicao) {
    if (estaCheia()) {
        aumentaCapacidade();
    }
    if (posicao <= ultimo + 1 && posicao >= 0) {
        deslocarDireita(posicao);
        dados[posicao] = elemento;
        return;
    }
    throw (ERRO_LISTA_CHEIA);
}

template <typename T>
void Lista<T>::retiraEspecifico(T elemento) {
    if (contem(elemento)) {
    	retiraDaPosicao(posicao(elemento));
    	return;
    }
    throw (ERRO_ELEMENTO_INEXISTENTE);
}

template <typename T>
bool Lista<T>::contem(T elemento) {
    if (!estaVazia()) {
        for (int i = 0 ; i <= ultimo ; i++) {
            if (elemento == dados[i]) {
                return true;
            }
        }
    }
    return false;
}

template <typename T>
int Lista<T>::posicao(T elemento) {
    if (!estaVazia()) {
        for (int i = 0 ; i <= ultimo ; i++) {
            if (elemento == dados[i]) {
                return i;
            }
            throw(ERRO_ELEMENTO_INEXISTENTE);
        }
    }
    throw(ERRO_LISTA_VAZIA);
}

template <typename T>
void Lista<T>::deslocarDireita(int posicao) {
    if (estaCheia()) {
        aumentaCapacidade();
    }

    ultimo++;
    for (int i = ultimo ; i > posicao ; i--){
        dados[i] = dados[i-1];
    }
}

template <typename T>
void Lista<T>::deslocarEsquerda(int posicao) {
	if (estaVazia()) {
	    throw (ERRO_LISTA_VAZIA);
	}

    for (int i = posicao ; i < ultimo ; i++){
        dados[i] = dados[i+1];
    }
    ultimo--;
}

template <typename T>
int Lista<T>::tamanho() {
    return ultimo + 1;
}

#endif
