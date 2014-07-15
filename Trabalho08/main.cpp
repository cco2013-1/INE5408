#include <iostream>
#include <fstream>
#include "Lista.hpp"

using namespace std;

Lista<int> readFile(string filename);
int integerCmp(const int & a, const int & b);

int main() {

    Lista<int> listaAOrdenar = readFile("arquivo.dat");

    listaAOrdenar.ordenar(integerCmp);

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
