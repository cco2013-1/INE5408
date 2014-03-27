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
 * Pilha.hpp
 */

#include "EstruturaLinear.hpp"

template<typename T>
class Pilha: public EstruturaLinear<T> {
public:
	Pilha();
	~Pilha();
	T extrair();
};

template<typename T>
Pilha<T>::Pilha() {

}

template<typename T>
Pilha<T>::~Pilha() {

}

template<typename T>
T Pilha<T>::extrair(){
	if(!this->estaVazia()) {
		return this->dados[this->posicaoAtual--];
	}
	throw(ERRO_ESTRUTURA_VAZIA);

}
