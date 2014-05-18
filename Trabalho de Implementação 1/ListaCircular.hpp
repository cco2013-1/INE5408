/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho de Implementação 1 - Simulação de Supermercado
 *
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * ListaCircular.hpp
 */

#ifndef __lista_circular_hpp__
#define __lista_circular_hpp__

#define ERRO_LISTA_VAZIA -2
#define ERRO_POSICAO_INEXISTENTE -3
#define ERRO_ELEMENTO_INEXISTENTE -4

#include <iostream>

using namespace std;

template <typename T>
class ListaCircular {
public:
    ListaCircular();
    ~ListaCircular();
    void adiciona(T *elemento); //adiciona o elemento na ultima posicao livre
    void adicionaNoInicio(T *elemento); //adiciona o elemento no inicio da lista
    void adicionaNaPosicao(T *elemento, int posicao); //adiciona o elemento na posicao desejada
    T * elementoNaPosicao(int posicao);
    void retiraDaPosicao(int posicao);
    bool estaVazia();
    int tamanho();
protected:
    struct Capsula {
        Capsula *proxima;
        Capsula *anterior;
        T *informacao;
    };
    Capsula *primeira;
    int _tamanho;
 };

template <typename T>
ListaCircular<T>::ListaCircular() {
    _tamanho = 0;
    primeira = 0; //Null
}

template <typename T>
ListaCircular<T>::~ListaCircular() {
    Capsula *atual = primeira;

    while(_tamanho > 0) {
        retiraDaPosicao(0);
    }
}

template <typename T>
bool ListaCircular<T>::estaVazia() {
    return _tamanho == 0;
}

template <typename T>
void ListaCircular<T>::adiciona(T *elemento) {
    Capsula *nova = new Capsula;

    nova->informacao = elemento;
    if (_tamanho == 0) {
        primeira = nova;
        primeira->proxima = primeira;
        primeira->anterior = primeira;
    } else {
        nova->anterior = primeira->anterior;
        nova->anterior->proxima = nova;
        nova->proxima = primeira;
        primeira->anterior = nova;
    }
    _tamanho += 1;
}

template <typename T>
T * ListaCircular<T>::elementoNaPosicao(int posicao) {
    if (posicao < _tamanho && posicao >= 0) {
        Capsula *atual = primeira;
        int cont = 0;

        while (true) {
            if (cont == posicao) {
                break;
            }
            atual = atual->proxima;
            cont += 1;
        }

        return atual->informacao;
    }
    throw(ERRO_POSICAO_INEXISTENTE);
}

template <typename T>
int ListaCircular<T>::tamanho() {
    return _tamanho;
}

template <typename T>
void ListaCircular<T>::retiraDaPosicao(int posicao) {
    if (posicao < _tamanho && posicao > 0) {

        Capsula *atual = primeira;
        int cont = 0;

        while (true) {
            if (++cont == posicao) {
                Capsula *proxima = atual->proxima;
                atual->proxima = proxima->proxima;
                proxima->proxima->anterior = atual;
                delete proxima;
                _tamanho -= 1;
                return;
            }
            atual = atual->proxima;
        }

    }
    if (posicao == 0) {
        Capsula *auxiliar = primeira;
        primeira = primeira->proxima;
        primeira->anterior = auxiliar->anterior;
        auxiliar->anterior->proxima = primeira;
        delete auxiliar;
        _tamanho -= 1;
        return;
    }
    throw(ERRO_POSICAO_INEXISTENTE);
}

#endif
