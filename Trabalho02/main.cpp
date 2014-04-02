/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 02 - Implementação de filas de char com Vetores em C++
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * mainFila.cpp
 */

#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Fila.hpp"

using namespace std;

void run();
void mostrarOpcoes();
int obterOpcao();
int obterInteiro();
void obterChar(char * destino);
void esvaziarFila();
void mostrarFila();
void imprimirCaracteres(char *caracteres);

Fila<char*> f;

int main() {
    run();
    return 0;
}

void run() {
    mostrarOpcoes();
    int opt = obterOpcao();

    switch (opt) {
        case 1:
            cout << "Digite uma string (sem espaços) a ser enfileirada:" << endl;
            char elem[40];
            obterChar(elem);

            try {
                f.inserir(elem);
                cout << "String enfileirada corretamente." << endl;
            } catch(int e) {
                cout << "Erro: fila cheia" << endl;
            }
            run();
            break;
        case 2:
            cout << "Desenfileirando um valor" << endl;
            try {
                // char elem[40];
                // strcpy(elem, f.extrair());
                cout << "Valor desenfileirando: ";
                imprimirCaracteres(f.extrair());
                cout << endl;
            } catch (int e) {
                cout << "Erro: fila vazia" << endl;
            }
            run();
            break;
        case 3:
            esvaziarFila();
            cout << "Fila limpa" << endl;
            run();
            break;
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

void obterChar(char * destino) {
    string input = "";

    getline(cin, input);

    if (input.length() > 40) {
        input = input.substr(0, 40);
    }

    for (int i = 0; i < input.length(); i++) {
        destino[i] = input.at(i);
    }
}

void imprimirCaracteres(char *caracteres) {
    for (int i = 0; i < strlen(caracteres) - 1; i++) {
        cout << caracteres[i];
    }
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
    Fila<char*> filaAuxiliar;
    int count = 0;

    while (true) {

        try {
            char *elem = f.extrair();
            printf("%3d", count++);
            imprimirCaracteres(elem);
            cout << endl;
            filaAuxiliar.inserir(elem);
        } catch (int e) {
            break;
        }
    }

    while (!filaAuxiliar.estaVazia()) {
        char *elem = filaAuxiliar.extrair();
        f.inserir(elem);
    }
}
