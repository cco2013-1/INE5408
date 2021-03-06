/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 04 - Implementação da Lista com um vetor de Ponteiros para Strings
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * ListaDeVetores.h
 */

 #include "Lista.hpp"
 

 class ListaDeVetores: public Lista<char*> {
 public:
 	ListaDeVetores();
 	virtual ~ListaDeVetores();
 	int posicao(char* elemento);
 	bool contem (char* elemento);
 };

