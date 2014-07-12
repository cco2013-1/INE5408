#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "SortedList.hpp"
#include "Lista.hpp"

using namespace std;

SortedList<string> lista;

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
    char text[] = {"aa aa aa aa aa aa pp pp pp pp dd dd dd bb bb aa dddd dd pp aa ab bb bb bb bb bb acc cc cc cc"};
    char limiters[] = {" "};
    Lista<string> lista2;
    lista2 = tokenizer(text, limiters);
    int tamanho2 = lista2.tamanho();
    for(int i = 0; i <= 15 ; i++) {
        lista.add(lista2.retira());
    }
    int tamanho = lista.size();
    for(int i = 0; i < tamanho ; i++) {
        cout << lista.get() << endl;
    }

    return 0;
}