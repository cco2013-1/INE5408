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
 * ListaContabil.cpp
 */

 #include "ListaContabil.h"

 
ListaContabil::ListaContabil() {
	this->Lista();
}

ListaContabil::~ListaContabil() {
	this->~Lista();
}

Lancamento ListaContabil::verTransicao(int posicao) {
	return this->elementoNaPosicao(posicao);
}

 
