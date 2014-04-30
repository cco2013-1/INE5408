#include <iostream>
#include <stdio.h>
#include "FilaEncadeada.hpp"

using namespace std;

void imprimeLista();

FilaEncadeada<int> f;

int main() {

    cout << "Testando adiciona()" << endl;
    int a, b;
    a = 1;
    b = 2;
    f.adiciona(a);
    f.adiciona(b);
    imprimeLista();

    cout << "Testando retira()" << endl;
    f.retira();
    imprimeLista();

    cout << "Testando adicionar após ter retirado" << endl;
    int e = 29;
    f.adiciona(e);
    imprimeLista();

    return 0;
}

void imprimeLista() {
    for (int i = 0; i < f.tamanho(); i++) {
        int asd = f.retira();
        printf("%8d\t%8d\n", i, asd);
        f.adiciona(asd);
    }
} 