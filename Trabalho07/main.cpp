#include <iostream>

using std::cout;

#include "ArvoreAVL.h"

int main (){
    ArvoreAVL<char> arvore;
    arvore.inserir('a');
    arvore.inserir('c');
    arvore.inserir('b');
    cout << arvore.toString();
}
