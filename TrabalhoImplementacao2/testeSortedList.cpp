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
    char text[] = {"lorem ipsum dolor sit amet consectetur adipiscing elit integer ut ligula et leo viverra egestas eu nec risus praesent blandit vel nisi quis sagittis nunc eget fermentum ipsum nullam sed sapien suscipit imperdiet neque a venenatis nibh ut facilisis aliquet dolor quis venenatis pellentesque vel tellus lorem nulla erat diam"};
    char limiters[] = {" "};
    Lista<string> lista2;
    lista2 = tokenizer(text, limiters);
    int tamanho2 = lista2.tamanho();
    for(int i = 0; i <= 49 ; i++) {
        lista.add(lista2.retira());
    }
    int tamanho = lista.size();
    for(int i = 0; i < tamanho ; i++) {
        cout << lista.get() << endl;
    }

    return 0;
}