/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho de Implementação 2 - Pesquisa de ManPages
 *
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
    void adiciona(T elemento);
    void adicionaNoInicio(T elemento);
    void adicionaNaPosicao(T elemento, int posicao);
    T elementoNaPosicao(int posicao);
    T retira();
    T retiraDaPosicao(int posicao);
    void retiraEspecifico(T elemento);
    bool estaCheia();
    bool estaVazia();
    int posicao(T elemento);
    bool contem(T elemento);
    int tamanho();
private:
    T *dados;
    int ultimo;
    int capacidade;
    void aumentaCapacidade();
    void deslocarEsquerda(int posicao);
    void deslocarDireita(int posicao);
 };

/**
 * Construtor da Lista
 * Aloca espaço para TAMANHO_INICIAL elementos.
 */
template <typename T>
Lista<T>::Lista() {
    dados = new T[TAMANHO_INICIAL];
    capacidade = TAMANHO_INICIAL;
    ultimo = -1;
}

/**
 * Destrutor da Lista
 * Libera o espaço utilizado pelos dados
 */
template <typename T>
Lista<T>::~Lista() {
    delete [] dados;
}

/**
 * Método estaCheia
 * Verifica se a capacidade atual da lista foi atingida.
 * @return verdadeiro se a lista estiver cheia, falso caso contrário.
 */
template <typename T>
bool Lista<T>::estaCheia() {
    return ultimo == capacidade - 1;
}

/**
 * Método estaVazia
 * Verifica se a lista está vazia.
 * @return verdadeiro se a lista estiver vazia, falso caso contrário.
 */
template <typename T>
bool Lista<T>::estaVazia() {
    if (ultimo == -1) {
        return true;
    }
    return false;
}

/**
 * Método adiciona
 * Insere o elemento passado no fim da lista.
 * @param elemento elemento a ser adicionado
 */
template <typename T>
void Lista<T>::adiciona(T elemento) {
    if (estaCheia()) {
        aumentaCapacidade();
    }

    dados[++ultimo]=elemento;
}

/**
 * Método aumentaCapacidade
 * Dobra a capacidade de armazenamento da lista.
  */
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

/**
 * Método retira
 * Remove o último elemento da lista e o retorna;
 * @return último elemento da lista
 */
template <typename T>
T Lista<T>::retira() {
    if (!estaVazia()) {
        return dados[ultimo--];
    }
    throw (ERRO_LISTA_CHEIA);
}

/**
 * Método adicionaNoInicio
 * Insere o elemento fornecido no início da lista
 * @param elemento elemento a ser adicionado no início da lista
 */
template <typename T>
void Lista<T>::adicionaNoInicio(T elemento) {
    adicionaNaPosicao(elemento, 0);
}

/**
 * Método elementoNaPosicao
 * Retorna o elemento armazenado na posição informada.
 * @param posicao a posição a ser consultada
 * @return elemento armazenado na posição informada.
 */
template <typename T>
T Lista<T>::elementoNaPosicao(int posicao) {
    return dados[posicao];
}

/**
 * Método retira da posição
 * Remove o elemento armazenado na posição informada, retornando
 * este elemento.
 * @param posicao posição da qual um elemento será removido
 * @return elemento removido
 */
template <typename T>
T Lista<T>::retiraDaPosicao(int posicao) {
    if (estaVazia()) {
        throw (ERRO_LISTA_VAZIA);
    }
    T elementoRetirado = dados[posicao];
    deslocarEsquerda(posicao);
    return elementoRetirado;
}

/**
 * Método adicionaNaPosicao
 * Adiciona o elemento passado na posição informada
 * @param elemento elemento a ser adicionado à lista
 * @param posicao posição na qual o elemento será inserido
 */
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

/**
 * Método retiraEspecifico
 * Caso a lista contenha o elemento informado, remove este elemento da lista.
 * @param elemento elemento a ser removido da lista
 */
template <typename T>
void Lista<T>::retiraEspecifico(T elemento) {
    if (contem(elemento)) {
    	retiraDaPosicao(posicao(elemento));
    	return;
    }
    throw (ERRO_ELEMENTO_INEXISTENTE);
}

/**
 * Método contem
 * Verifica se a lista contém determinado elemento.
 * @return verdadeiro se o elemento estiver contido na lista, falso caso contrário
 */
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

/**
 * Método posicao
 * Encontra a posição do elemento fornecido na lista
 * Caso o elemento não esteja contido na lista, retorna -1
 * @param elemento elemento cuja posição será buscada
 * @return posicao do elemento ou -1 se o elemento não for encontrado
 */
template <typename T>
int Lista<T>::posicao(T elemento) {
    if (!estaVazia()) {
        for (int i = 0 ; i <= ultimo ; i++) {
            if (elemento == dados[i]) {
                return i;
            }
        }
        return -1;
    }
    throw(ERRO_LISTA_VAZIA);
}

/**
 * Método deslocarDireita
 * Desloca todos os elementos à direita de posicao uma posição para a direita
 * @param posicao posição de início do deslocamento à direita
 */
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

/**
 * Método deslocarEsquerda
 * Desloca todos os elementos à direita de posicao uma posição para a esquerda.
 * @param posicao posição de início do deslocamento à esquerda
 */
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
