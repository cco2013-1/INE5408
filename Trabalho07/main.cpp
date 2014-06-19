/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 07 - Busca e Balanceamento em Árvores
 *
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * main.cpp
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <ctime>
#include "AVLTree.h"
#include "BSTree.h"
#include "RBTree.h"

void printTree(node *subTreeRoot);
int obterInteiro();
string obterString();

int main() {
    BSTree *tree;
    string inputFile;
    string outputFileInsertion = "results_";
    string outpuFileDeletion;

    cout << "Bem vindo." << endl;

    while (true) {
        cout << "Escolha o arquivo de dados de CEP a ser processado: " << endl;
        cout << "1 - DF" << endl;
        cout << "2 - SC" << endl;
        cout << "3 - SP" << endl;
        cout << "4 - Todos concatenados" << endl;
        int opt = obterInteiro();
        if (opt == 1) {
            inputFile = "df.cep";
            outputFileInsertion += "DF_";
            break;
        }
        if (opt == 2) {
            inputFile = "sc.cep";
            outputFileInsertion += "SC_";
            break;
        }
        if (opt == 3) {
            inputFile = "sp.cep";
            outputFileInsertion += "SP_";
            break;
        }
        if (opt == 4) {
            inputFile = "todos.cep";
            outputFileInsertion += "todos_";
            break;
        }
        cout << "errou feio, errou rude." << endl;
    }

    while (true) {
        cout << "Escolha a árvore. 1 para AVL, 2 para RedBlack." << endl;
        int opt = obterInteiro();
        if (opt == 1) {
            tree = new AVLTree();
            outputFileInsertion += "AVLTree.dat";
            break;
        }
        if (opt == 2) {
            tree = new RBTree();
            outputFileInsertion += "RedBlackTree.dat";
            break;
        }
        cout << "errou feio, errou rude." << endl;
    }

    outpuFileDeletion = "deletion_" + outputFileInsertion;
    outputFileInsertion = "insertion_" + outputFileInsertion;

    FILE * cepFile = fopen(inputFile.c_str(), "r");
    FILE * resultsFileInsertion = fopen(outputFileInsertion.c_str(), "w");

    if (!cepFile) {
        cout << "Erro ao ler arquivo de CEPs." << endl;
        cout << "Encerrando o programa." << endl;
        exit(EXIT_FAILURE);
    }

    char line[100];

    while (true) {
        if (!fgets(line, 100, cepFile)) {
            break;
        }

        string readLine = string(line);
        int indexOfSep = readLine.find_first_of("|");
        string streetName = readLine.substr(0, indexOfSep);
        int cep = atoi(readLine.substr(indexOfSep + 1, readLine.size() - indexOfSep).c_str());

        clock_t start, finish;
        double timeToInsert;

        start = clock();
        tree->insert(cep, streetName);
        finish = clock();

        timeToInsert = ((double)(finish - start));//CLOCKS_PER_SEC * 1000;

        cout << "num elements: " << tree->getSize() << "\ttime to insert: " << timeToInsert << endl;

        string output = to_string(tree->getSize()) + "\t" + to_string(timeToInsert) + "\n";
        fputs(output.c_str(), resultsFileInsertion);
    }

    cout << "root: " << tree->getRoot()->key << endl;
    cout << "root successor: " << tree->successor(tree->getRoot())->key << endl;
    cout << "root height: " << tree->getRoot()->height << endl;

    while (true) {
        cout << "busca de cep. insira o cep a buscar: ";
        int cep = obterInteiro();
        if (cep <= 0) break;
        node *result = tree->find(cep);
        if (result) {
            cout << "o cep " << cep << " refere-se à rua " << result->value << endl;
        } else {
            cout << "cep não encontrado" << endl;
        }
    }
}

void printTree(node *subTreeRoot) {
    if (!subTreeRoot) {
        cout << "empty tree" << endl;
        return;
    }
    cout << subTreeRoot->key << "\t" << subTreeRoot->height << "\t"
        << (subTreeRoot->color == RED ? "red" : "black") << endl;
    if (subTreeRoot->leftChild) {
        printTree(subTreeRoot->leftChild);
    } else {
        cout << " NULL left" << endl;
    }
    if (subTreeRoot->rightChild) {
        printTree(subTreeRoot->rightChild);
    } else {
        cout << " NULL right " << endl;
    }

}

int obterInteiro() {
    string input = "";
    int inteiro = 0;

    getline(cin, input);

    stringstream myStream(input);
    myStream >> inteiro;

    return inteiro;
}

string obterString() {
    string input = "";
    getline(cin, input);
    return input;
}
