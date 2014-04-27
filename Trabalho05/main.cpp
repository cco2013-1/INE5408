#include <iostream>
#include "ListaEncadeada.hpp"

using namespace std;

void imprimeLista();

ListaEncadeada<int> l;

int main() {

    cout << "Testando adiciona()" << endl;
    int *a, *b;
    a = new int;
    b = new int;
    *a = 1;
    *b = 2;
    l.adiciona(a);
    l.adiciona(b);
    imprimeLista();

    cout << "Testando adicionaNoInicio(0)" << endl;
    int *c;
    c = new int;
    *c = 65;
    l.adicionaNoInicio(c);
    imprimeLista();

    cout << "Testando adicionaNaPosicao(10, 1)" << endl;
    int *d = new int;
    *d = 10;
    l.adicionaNaPosicao(d, 1);
    imprimeLista();

    cout << "Testando retiraDaPosicao(1)" << endl;
    l.retiraDaPosicao(1);
    imprimeLista();

    cout << "Testando adicionar após ter retirado" << endl;
    int *e = new int;
    *e = 29;
    l.adiciona(e);
    imprimeLista();

    cout << "Removendo do inicio" << endl;
    l.retiraDaPosicao(0);
    imprimeLista();

    cout << "Removendo do fim" << endl;
    l.retiraDaPosicao(2);
    imprimeLista();


    // cout << "Testando retiraEspecifico(10)" << endl;
    // l.retiraEspecifico(10);
    // imprimeLista();

    // printf("%s\n", "dasdfa");

    return 0;
}

void imprimeLista() {
    for (int i = 0; i < l.tamanho(); i++) {
        printf("%8d\t%8d\n", i, *(l.elementoNaPosicao(i)));
    }
}
