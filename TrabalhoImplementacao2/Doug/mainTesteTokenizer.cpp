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
 * main.cpp
 */

#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Lista.hpp"


using namespace std;


Lista<string> lista;
char text[] = "Matheus Ben-Hur/de Melo.Leite";
char limiters[] = {' ', '-', '/','.'};

Lista<string> tokenizer(char text[], char limiters[]){
    Lista<string> words;
    char *word = strtok(text, limiters);
    for(int i = 0; word; i++) {
        words.adiciona(string(word));
        word = strtok(NULL, limiters);
    }
    return words;
}

int main() {
    lista = tokenizer(text, limiters);
    int tamanho = lista.tamanho();
    for(int i = 0; i < tamanho ; i++) {
        cout << lista.retira() << endl;
    }
    return 0;
}

