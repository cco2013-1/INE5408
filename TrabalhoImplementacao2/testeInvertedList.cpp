#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "SortedList.hpp"
#include "Lista.hpp"
#include "InvertedList.h"

using namespace std;

InvertedList lista;

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
   
    char text[] = {"ipsum adipiscing integer et leo"};
    char text1[] = {"ipsum adipiscing integer et leo"};
    ///amet consectetur adipiscing elit integer ut ligula et leo viverra egestas eu nec risus praesent blandit vel nisi quis sagittis nunc eget fermentum ipsum nullam sed sapien suscipit imperdiet neque a venenatis nibh ut facilisis aliquet dolor quis venenatis pellentesque vel tellus lorem nulla erat diam diam diam
    char limiters[] = {" "};
    Lista<string> lista2;
    Lista<string> lista3;
    lista2 = tokenizer(text, limiters);
    lista3 = tokenizer(text1, limiters);
    lista.insert(lista2, 0);
    lista.insert(lista3, 1);
    Lista<string> listaPega = lista.get();
    int tamanho = listaPega.tamanho();
    for(int i = 0; i < tamanho ; i++) {
        cout << listaPega.retira() << endl;
    }

    return 0;
}
