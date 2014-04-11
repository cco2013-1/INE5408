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
 * ListaDeVetores.cpp
 */

 #include "ListaDeVetores.h"
 #include <cstring>


ListaDeVetores::ListaDeVetores() : Lista<char*>(){
}

ListaDeVetores::~ListaDeVetores() {
}

int ListaDeVetores::posicao(char* elemento) {
    for (int i = 0 ; i <= ultimo ; i++) {
       	if (strcmp(elemento, dados[i]) == 0) {
               return i;
      	    }
      	}
            
    
}

bool ListaDeVetores::contem(char* elemento) {
	for (int i = 0 ; i <= ultimo ; i++) {
       	if (strcmp(elemento, dados[i]) == 0) {
               return true;
      	    }
    }

    return false;
}

