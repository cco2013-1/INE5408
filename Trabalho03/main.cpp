#include <iostream>
#include "Lista.hpp"

using namespace std;

void imprimeLista();

Lista<int> l;

int main() {

    cout << "Testando adiciona()" << endl;
    l.adiciona(1);
    l.adiciona(2);
    imprimeLista();

    cout << "Testando adicionaNoInicio(0)" << endl;
    l.adicionaNoInicio(0);
    imprimeLista();

    cout << "Testando adicionaNaPosicao(10, 1)" << endl;
    l.adicionaNaPosicao(10, 1);
    imprimeLista();

    cout << "Testando retira()" << endl;
    cout << "Retirou " << l.retira() << endl;
    imprimeLista();

    cout << "Testando retiraDaPosicao(0)" << endl;
    cout << "Retirou " << l.retiraDaPosicao(0) << endl;
    imprimeLista();

    cout << "Testando retiraEspecifico(10)" << endl;
    l.retiraEspecifico(10);
    imprimeLista();

    return 0;
}

void imprimeLista() {
    for (int i = 0; i < l.tamanho(); i++) {
        printf("%8d\t%8d\n", i, l.elementoNaPosicao(i));
    }
}
