#include <iostream>
#include <stdio.h>
#include "FilaEncadeada.hpp"

using namespace std;

void imprimeLista();

FilaEncadeada<int> f;

int main() {

    cout << "Testando adiciona()" << endl;
    int a, b, c;
    a = 1;
    b = 2;
    c = 3;
    f.adiciona(a);
    f.adiciona(b);
    f.adiciona(c);
    printf("O tamanho da fila é %d\n", f.tamanho());
    

    cout << "Testando retira()" << endl;
    int retirado = f.retira();
    printf("O elemento retirado foi %d\n", retirado);
    retirado = f.retira();
    printf("O elemento retirado foi %d\n", retirado);
    retirado = f.retira();
    printf("O elemento retirado foi %d\n", retirado);

    cout<<"Testando retira com fila vazia \n"<<"\0";
    try{
        f.retira();
    }
    catch(int erro) {
        cout<<"A fila ta vazia, seu trabalho por enquanto está funcionando \n"<<"\0";
    }

    cout<<"Testando adicionar mais um elemento após a fila estar vazia \n"<<"\0";
    f.adiciona(172);
    printf("Elemento adicionado com sucesso!  O tamanho da fila é %d\n", f.tamanho());
    cout<<"Retirando o último elemento para a fila tornar-se vazia novamente \n"<<"\0";
    retirado = f.retira();
    printf("O elemento retirado foi %d\n", retirado);
    printf("O tamanho da fila é %d\n", f.tamanho());

    return 0;
}