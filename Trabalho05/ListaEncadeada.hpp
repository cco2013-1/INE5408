/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 05 - Trabalho de Sistema de Contabilidade Mafioso com Lista Encadeada Simples
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * ListaEncadeada.hpp
 */

#ifndef _ListaEncadeada_hpp_
#define _ListaEncadeada_hpp_
#include "Elemento.hpp"

#include <stdexcept>

#define ERRO_POSICAO_INVALIDA -2;

template <typename T>
class ListaEncadeada {
public:
	ListaEncadeada();
	~ListaEncadeada();
	void adiciona(const T& informacao);
	void adicionaNoInicio(const T& informacao);
	void adicionaNaPosicao(const T& informacao, int posicao);
	void adicionaEmOrdem(const T& informacao);
	T retira();
	T retiraDoInicio();
	T retiraDaPosicao(int posicao);
	void retiraEspecifico(const T& informacao);
	bool estaVazia();
	int posicao(const T& informacao);
	bool contem(const T& informacao);
private:
	Elemento<T> *dados;
	int tamanho;
};

 
template <typename T>
ListaEncadeada<T>::ListaEncadeada():
	tamanho(0),
	dados(0)
{}

template <typename T>
ListaEncadeada<T>::~ListaEncadeada() {
	Elemento<T> *elemento = dados;
	for (int i = 0; i < tamanho; ++i) {
		Elemento<T> *proximo = elemento->pegarProximoElemento();
		delete elemento;
		elemento = proximo;
	}	
}

template <typename T>
bool ListaEncadeada<T>::estaVazia() {
	return tamanho == 0;
}

template <typename T>
void ListaEncadeada<T>::adicionaNoInicio(const T& informacao) {
	try {
		Elemento<T> *novoElemento = new Elemento<T>(informacao, dados);
		dados = novoElemento;
		++tamanho;
	} catch (std::bad_alloc&) {
		throw;
	}
}

template <typename T>
T ListaEncadeada<T>::retiraDoInicio() {
	if (this->tamanho == 0) {
		throw std::range_error("Lista vazia!");
	}

	T informacao(*this->dados->pegarInformacao());
	Elemento<T> *elementoRetirado = dados;
	dados = elementoRetirado->pegarProximoElemento();
	delete elementoRetirado;
	--tamanho;
	return informacao;
}

template <typename T>
void ListaEncadeada<T>::adicionaNaPosicao(const T& informacao, int posicao) {
	if (posicao == 0){
		adicionaNoInicio(informacao);
		return 0;
	}

	if (posicao <= tamanho) {
		Elemento<T> *ultimoElemento = dados;

		for(int i = 0; i < (posicao - 1); i++) {
			ultimoElemento = ultimoElemento->pegarProximoElemento();
		}

		Elemento<T> *novoElemento = new Elemento<T>(informacao, ultimoElemento->pegarProximoElemento());

		ultimoElemento->adicionarProximoElemento(novoElemento);
		++tamanho;
	}
	
	throw std::range_error("Posição inválida!");
}

#endif