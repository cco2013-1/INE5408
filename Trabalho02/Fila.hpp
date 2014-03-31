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
	if (!this->estaVazia()) {
		T elemento = this->dados[0];
		for (int i = 0 ; i < this->posicaoAtual - 1 ; i++) {
			this->dados[i] = this->dados[i + 1];
		}
		this->posicaoAtual--;
		return elemento;
	}
	throw(ERRO_ESTRUTURA_VAZIA);

}
