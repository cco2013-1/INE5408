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
 * Lancamento.h
 */

#ifndef __lancamento_h__
#define __lancamento_h__

class Lancamento {
public:
	Lancamento();
	~Lancamento();
private:
 	char *nome;
 	double valor;
 };

#endif
