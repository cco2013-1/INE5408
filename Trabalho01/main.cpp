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
#include <stdlib.h>
#include "Pilha.hpp"

using namespace std;

void run();
void mostrarOpcoes();
int obterOpcao();
int obterInteiro();
void esvaziarPilha();
void mostrarPilha();

Pilha<int> p;

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
            cout << "Digite o elemento a ser empilhado:" << endl;
            elem = obterInteiro();
            try {
                p.inserir(elem);
                cout << "Valor empilhado corretamente." << endl;
            } catch(int e) {
                cout << "Erro: pilha cheia" << endl;
            }
            run();
            break;
        case 2:
            cout << "Desempilhando um valor" << endl;
            try {
                elem = p.extrair();
                cout << "Valor desempilhado " << elem << endl;
            } catch (int e) {
                cout << "Erro: pilha vazia" << endl;
            }
            run();
            break;
        case 3:
            esvaziarPilha();
            cout << "Pilha limpa" << endl;
            exit(0);
        case 4:
            cout << "Posição  Valor" << endl;
            if (p.estaVazia()) {
                cout << "Erro: pilha vazia" << endl;
            } else {
                mostrarPilha();
            }
            run();
            break;
        default:
            exit(0);
    }

}

void mostrarOpcoes() {
    cout << "Pilhas:" << endl;
    cout << "Digite o numero da opção desejada:" << endl;
    cout << "1) Empilhar Elemento" << endl;
    cout << "2) Desempilhar Elemento" << endl;
    cout << "3) Limpar Pilha" << endl;
    cout << "4) Mostrar Pilha" << endl;
    cout << "5) Sair do programa" << endl;
}

int obterOpcao() {
    int opt = 0;

    opt = obterInteiro();

    return opt;
}

int obterInteiro() {
    string input = "";
    int inteiro = 0;

    getline(cin, input);

    stringstream myStream(input);
    myStream >> inteiro;

    return inteiro;
}

void esvaziarPilha() {
    while (true) {
        try {
            p.extrair();
        } catch (int e) {
            break;
        }
    }
}

void mostrarPilha() {
    Pilha<int> pilhaAuxiliar;
    int count = 0;

    while (true) {

        try {
            int elem = p.extrair();
            pilhaAuxiliar.inserir(elem);
        } catch (int e) {
            break;
        }
    }

    while (!pilhaAuxiliar.estaVazia()) {
        int elem = pilhaAuxiliar.extrair();
        p.inserir(elem);
        printf("%3d %11d\n", count++, elem);
    }
}
