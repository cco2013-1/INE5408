/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 01 - Implementação de pilhas com Vetor em C++
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * main.cpp
 */

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include "Pilha.h"

using namespace std;

void run();
void mostrarOpcoes();
int obterOpcao();
int obterInteiro();
void esvaziarPilha();
void mostrarPilha();

Pilha p;

int main() {

    run();
    return 0;
}

void run() {

    mostrarOpcoes();
    int opt = obterOpcao();
    int elem;

    switch (opt) {
        case 1:
            cout << "Digite o elemento a ser empilhado" << endl;
            elem = obterInteiro();
            if (p.empilha(elem) >= 0) {
                cout << "Valor empilhado corretamente" << endl;
            } else {
                cout << "Erro: pilha cheia" << endl;
            }
            cout << "\n\n\n";
            run();
            break;
        case 2:
            cout << "Desempilhando um valor" << endl;
            elem = p.desempilha();

            if (elem != ERROPILHAVAZIA) {
                cout << "Valor desempilhado " << elem << endl;
            } else {
                cout << "Erro: pilha vazia" << endl;
            }
            cout << "\n\n\n";
            run();
            break;
        case 3:
            esvaziarPilha();
            cout << "Pilha limpa" << endl;
            cout << "\n\n\n";
            run();
            break;
        case 4:
            cout << "Posição Valor" << endl;
            mostrarPilha();
            cout << "\n\n\n";
            run();
            break;
        default:
            cout << "Encerrando o programa" << endl;
    }

}

void mostrarOpcoes() {
    cout << "Pilhas" << endl;
    cout << "Digite o número da opção desejada:" << endl;
    cout << "1) Empilhar elemento" << endl;
    cout << "2) Desempilhar elemento" << endl;
    cout << "3) Limpar pilha" << endl;
    cout << "4) Mostrar pilha" << endl;
    cout << "5) Sair do programa" << endl;
}

int obterOpcao() {
    int opt = 0;

    while (true) {
        opt = obterInteiro();
        if (opt > 0 && opt <= 5){
            break;
        }
        cout << "Opção inválida. Insira uma opção entre 1 e 5" << endl;
    }

    return opt;
}

int obterInteiro() {
    string input = "";
    int inteiro = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> inteiro) {
            break;
        }

        cout << "Formato inválido. Insira um inteiro" << endl;
    }

    return inteiro;
}

void esvaziarPilha() {
    while (!p.pilhaVazia()) {
        p.desempilha();
    }
}

void mostrarPilha() {
    Pilha pilhaAuxiliar;
    int count = 1;
    while (!p.pilhaVazia()) {
        int elem = p.desempilha();
        pilhaAuxiliar.empilha(elem);
        // cout << count++ << "  " << elem << endl;
        printf("%7d %5d\n", count++, elem);
    }

    while (!pilhaAuxiliar.pilhaVazia()) {
        p.empilha(pilhaAuxiliar.desempilha());
    }
}
