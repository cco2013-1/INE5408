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
 * Lancamento.cpp
 */

#include "Lancamento.h"
#include <cstring> 

Lancamento::Lancamento() {

}

Lancamento::Lancamento(char* nomeLancado, double valorLancado) {
 	nomeLancamento = new char[strlen(nomeLancado)+1];
 	strcpy(nomeLancamento, nomeLancado);
 	valorLancamento = valorLancado;
}

Lancamento::~Lancamento() {

}

char* Lancamento::nome() {
	return nomeLancamento;
}

double Lancamento::valor() {
	return valorLancamento;
}
