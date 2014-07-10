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
#include <unordered_set> 
#include "Lista.hpp"


using namespace std;


Lista<string> lista;
Lista<string> lista2;
char text[] = "Vinicius and gay but when dá o cú";
char limiters[] = {' ', '-', '/','.'};
unordered_set<string> conjunctions = {"and", "that", "but", "or", "as", "if", "when","than", "because", "while", "where", 
"after", "so", "though", "since", "until", "whether", "before", "although", "nor", "like", "once", "unless", 
"now", "except"};

Lista<string> tokenizer(char text[], char limiters[]){
    Lista<string> words;
    char *word = strtok(text, limiters);
    for(int i = 0; word; i++) {
        words.adiciona(string(word));    
        word = strtok(NULL, limiters);
    }
    return words;
}

Lista<string> filterConjunction(Lista<string> words, unordered_set<string> conjunctions) {
    Lista<string> filtered;
    int size = words.tamanho();
    for(int i = 0; i < size; i++) {
        string removed = words.retira();
        unordered_set<string>::const_iterator got = conjunctions.find(removed);    
        if(got == conjunctions.end()) {
            filtered.adiciona(removed);
        }
    }
    return filtered;
}

int main() {
    lista = tokenizer(text, limiters);
    lista2 = filterConjunction(lista, conjunctions);
    int tamanho = lista2.tamanho();
    for(int i = 0; i < tamanho ; i++) {
        cout << lista2.retira() << endl;
    }
    return 0;
}

