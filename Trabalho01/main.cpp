/**
 * Universidade Federal de Santa Catarina
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

using namespace std;

void run();
void mostrarOpcoes();
int obterOpcao();

int main() {
    run();
    return 0;
}

void run() {

    mostrarOpcoes();
    int opt = obterOpcao();

    switch (opt) {
        case 1:
            cout << "Digite o elemento a ser empilhado" << endl;

            run();
            break;
        case 2:
            cout << "Desempilhando um valor" << endl;

            run();
            break;
        case 3:
            cout << "Pilha limpa" << endl;

            run();
            break;
        case 4:
            cout << "Posição Valor" << endl;

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

int obterOpcao (){
    string input = "";
    int opt = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> opt && opt > 0 && opt <= 5) {
            break;
        }

        cout << "Opção inválida. Insira um número entre 1 e 5." << endl;
    }

    return opt;
}
