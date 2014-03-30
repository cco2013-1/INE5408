/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 01 - Implementação de pilhas com Vetor em C++
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * Fila.hpp
 */

#include "EstruturaLinear.hpp"

template<typename T>
class Fila: public EstruturaLinear<T> {
public:
	Fila();
	~Fila();
	T extrair();
};

template<typename T>
Fila<T>::Fila() {

}

template<typename T>
Fila<T>::~Fila() {

}

template<typename T>
T Fila<T>::extrair() {
	if(!this->estaVazia()) {
		T elemento = this->dados[0];
		for(int i = 0 ; i < this->posicaoAtual ; i++) {
			this->dados[i] = this->dados[i + 1];
		}
		this->posicaoAtual = --this->posicaoAtual;
		return elemento;
	}
	throw(ERRO_ESTRUTURA_VAZIA); 

}