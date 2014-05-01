/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 06 - Assistência Técnica de computadores da marca HAL
 *
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * FilaEncadeada.hpp
 */

#ifndef __fila_encadeada_hpp__
#define __fila_encadeada_hpp__

#define TAMANHO_MAX 10
#define ERRO_FILA_VAZIA -2

#include <iostream>

using namespace std;

template <typename T>
class FilaEncadeada {
public:
    FilaEncadeada();
    ~FilaEncadeada();
    void adiciona(const T& elemento); //adiciona o elemento na ultima posicao livre
    T retira();
    T elementoEm(int posicao);
    bool estaVazia();
    int tamanho();
private:
    struct Capsula {
        Capsula *proxima;
        T informacao;
    };
    Capsula *primeira;
    Capsula *ultima;
    int _tamanho;
 };

template <typename T>
FilaEncadeada<T>::FilaEncadeada() {
    _tamanho = 0;
    primeira = 0; //Null
    ultima = 0;
}

template <typename T>
FilaEncadeada<T>::~FilaEncadeada() {
    Capsula *atual = primeira;

    while(_tamanho > 0) {
        retira();
    }
}

template <typename T>
bool FilaEncadeada<T>::estaVazia() {
    return _tamanho == 0;
}

template <typename T>
void FilaEncadeada<T>::adiciona(const T& elemento) {
    Capsula *nova = new Capsula();
    nova->informacao = elemento;
    nova->proxima = 0;
    if (_tamanho == 0) {
        primeira = nova;
        ultima = nova;
        ++_tamanho;
    }
    else {
    ultima->proxima = nova;
    ultima = nova;
    _tamanho++;
    }
}

template <typename T>
int FilaEncadeada<T>::tamanho() {
    return _tamanho;
}

template <typename T>
T FilaEncadeada<T>::retira() {
    if (estaVazia()) {
        throw(ERRO_FILA_VAZIA);
    }

    Capsula *retirada = primeira;
    T informacao = primeira->informacao;
    primeira = primeira->proxima;
    delete retirada;
    _tamanho--;
    return informacao;
}
#endif
