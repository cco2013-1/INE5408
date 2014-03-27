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
            cout << "Digite o elemento a ser empilhado" << endl;
            elem = obterInteiro();
            try {
                p.inserir(elem);
                cout << "Valor empilhado corretamente" << endl;
            } catch(int e) {
                cout << "Erro: pilha cheia" << endl;
            }
            cout << "\n\n\n";
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
    int count = 1;
    
    while (true) {
        
        try {
            int elem = p.extrair();
            pilhaAuxiliar.inserir(elem);
            printf("%7d %5d\n", count++, elem);
        } catch (int e) {
            break;
        }
    }

    while (!pilhaAuxiliar.estaVazia()) {
        p.inserir(pilhaAuxiliar.extrair());
    }
}
