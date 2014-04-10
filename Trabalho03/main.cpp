#include <iostream>
#include "Lista.hpp"

using namespace std;

void imprimeLista();

Lista<int> l;

int main() {
    l.adiciona(1);
    l.adiciona(2);

    imprimeLista();

    return 0;
}

void imprimeLista() {
    for (int i = 0; i < l.tamanho(); i++) {
        printf("%8d\t%8d\n", i, l.elementoNaPosicao(i));
    }
}
