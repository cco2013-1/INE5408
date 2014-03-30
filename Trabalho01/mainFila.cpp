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
 * mainFila.cpp
 */

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Fila.hpp"

using namespace std;

void run();
void mostrarOpcoes();
int obterOpcao();
int obterInteiro();
char obterChar();
void esvaziarFila();
void mostrarFila();

Fila<char> f;

int main() {
    run();
    return 0;
}

void run() {
    mostrarOpcoes();
    int opt = obterOpcao();
    char elem;

    switch (opt) {
        case 1:
            cout << "Digite o elemento a ser enfileirado:" << endl;
            elem = obterChar();
            try {
                f.inserir(elem);
                cout << "Valor enfileirado corretamente." << endl;
            } catch(int e) {
                cout << "Erro: fila cheia" << endl;
            }
            run();
            break;
        case 2:
            cout << "Desenfileirando um valor" << endl;
            try {
                elem = f.extrair();
                cout << "Valor desenfileirado " << elem << endl;
            } catch (int e) {
                cout << "Erro: fila vazia" << endl;
            }
            run();
            break;
        case 3:
            esvaziarFila();
            cout << "Fila limpa" << endl;
            exit(0);
        case 4:
            cout << "Posição  Valor" << endl;
            if (f.estaVazia()) {
                cout << "Erro: fila vazia" << endl;
            } else {
                mostrarFila();
            }
            run();
            break;    
        default:
            exit(0);
    }

}

void mostrarOpcoes() {
    cout << "Filas:" << endl;
    cout << "Digite o numero da opção desejada:" << endl;
    cout << "1) Enfileirar Elemento" << endl;
    cout << "2) Desenfileirar Elemento" << endl;
    cout << "3) Limpar Fila" << endl;
    cout << "4) Mostrar Fila" << endl;
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

char obterChar() {
    string input = "";
    char caractere = ' ';

    getline(cin, input);

    stringstream myStream(input);
    myStream >> caractere;

    return caractere;
}

void esvaziarFila() {
    while (true) {
        try {
            f.extrair();
        } catch (int e) {
            break;
        }
    }
}

void mostrarFila() {
    Fila<char> filaAuxiliar;
    int count = 0;

    while (true) {

        try {
            char elem = f.extrair();
            filaAuxiliar.inserir(elem);
        } catch (int e) {
            break;
        }
    }

    while (!filaAuxiliar.estaVazia()) {
        char elem = filaAuxiliar.extrair();
        f.inserir(elem);
        printf("%3d %11d\n", count++, elem);
    }
}
