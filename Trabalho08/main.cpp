/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 08 - Método de Ordenação
 *
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * main.cpp
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include "Lista.hpp"

using namespace std;

Lista<int> readFile(string filename);
int integerCmp(const int & a, const int & b);

int main() {

    cout << "Iniciando leitura do arquivo de dados... ";
    Lista<int> listaAOrdenar = readFile("arquivo.dat");
    cout << "CONCLUÍDO!" << endl;

    cout << "Iniciando ordenação da lista de inteiros... ";
    clock_t begin = clock();
    listaAOrdenar.ordenar(integerCmp);
    clock_t end = clock();
    double elapsed_time = double(end-begin) / CLOCKS_PER_SEC;
    cout << "CONCLUÍDO!" << endl;
    cout << "Tempo necessário para ordenar a lista: " << elapsed_time << " s" << endl << endl;

    cout << "Pressione uma tecla para exibir a lista ordenada" << endl;
    getchar();

    for (int i = 0; i < listaAOrdenar.tamanho(); i++) {
        cout << i << ": " << listaAOrdenar.elementoNaPosicao(i) << endl;
    }

    return 0;
}

/**
 * Função readFile
 * Lê o arquivo de entrada de dados e retorna uma lista de inteiros
 * @param filename nome do arquivo de entrada
 * @return Lista de inteiros com os valores lidos
 */
Lista<int> readFile(string filename) {
    FILE *inputFile = fopen(filename.c_str(), "r");

    Lista<int> result;

    if (!inputFile) {
        cout << "Impossível abrir arquivo de dados" << endl;
        return result;
    }

    char line[100];

    while (true) {
        if (!fgets(line, 100, inputFile)) {
            break;
        }
        result.adiciona(atoi(line));
    }

    //Remove primeiro elemento, que representa a quantidade
    //de números e não deve ser considerado.
    result.retiraDaPosicao(0);

    return result;
}

/**
 * Função integerCmp
 * Função para comparação de inteiros.
 * É passada ao método de ordenação da lista para possibilitar a comparação
 * de inteiros.
 */
int integerCmp(const int & a, const int & b) {
    if(a < b) return -1;
    if(a == b) return 0;
    return 1;
}
