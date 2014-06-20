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
#include "RBTreeV2.h"
#include "gnuplot_i.hpp"

void printTree(node *subTreeRoot);
int getInteger();

int main() {
    BSTree *tree;
    string inputFile;
    string outputFileInsertion = "results_";
    string outpuFileDeletion;
    string graphOutputFileInsertion = "graph_";
    string graphOutputFileDeletion;

    cout << "Bem vindo." << endl;

    while (true) {
        cout << "Escolha o arquivo de dados de CEP a ser processado: " << endl;
        cout << "1 - DF" << endl;
        cout << "2 - SC" << endl;
        cout << "3 - SP" << endl;
        cout << "4 - Todos concatenados" << endl;
        int opt = getInteger();
        if (opt == 1) {
            inputFile = "df.cep";
            outputFileInsertion += "DF_";
            graphOutputFileInsertion += "DF_";
            break;
        }
        if (opt == 2) {
            inputFile = "sc.cep";
            outputFileInsertion += "SC_";
            graphOutputFileInsertion += "SC_";
            break;
        }
        if (opt == 3) {
            inputFile = "sp.cep";
            outputFileInsertion += "SP_";
            graphOutputFileInsertion += "SP_";
            break;
        }
        if (opt == 4) {
            inputFile = "todos.cep";
            outputFileInsertion += "todos_";
            graphOutputFileInsertion += "todos_";
            break;
        }
        cout << "errou feio, errou rude." << endl;
    }

    while (true) {
        cout << "Escolha a árvore. 1 para AVL, 2 para RedBlack." << endl;
        int opt = getInteger();
        if (opt == 1) {
            tree = new AVLTree();
            outputFileInsertion += "AVLTree.dat";
            graphOutputFileInsertion += "AVLTree.png";
            break;
        }
        if (opt == 2) {
            tree = new RBTreeV2();
            outputFileInsertion += "RedBlackTree.dat";
            graphOutputFileInsertion += "RedBlackTree.png";
            break;
        }
        cout << "errou feio, errou rude." << endl;
    }

    outpuFileDeletion = "deletion_" + outputFileInsertion;
    outputFileInsertion = "insertion_" + outputFileInsertion;

    graphOutputFileDeletion = "deletion_" + graphOutputFileInsertion;
    graphOutputFileInsertion = "insertion_" + graphOutputFileInsertion;

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

    fclose(resultsFileInsertion);

    while (true) {
        cout << "busca de cep. insira o cep a buscar (0 para sair): ";
        int cep = getInteger();
        if (cep <= 0) break;
        node *result = tree->find(cep);
        if (result) {
            cout << "o cep " << cep << " refere-se à rua " << result->value << endl;
        } else {
            cout << "cep não encontrado" << endl;
        }
    }

    cout << "Removendo entradas da árvore:" << endl;
    FILE * resultsFileDeletion = fopen(outpuFileDeletion.c_str(), "w");

    while (tree->getRoot() != tree->getNil()) {
        clock_t start, finish;
        double timeToRemove;

        start = clock();
        tree->remove(tree->minimum()->key);
        finish = clock();

        timeToRemove = ((double)(finish - start));//CLOCKS_PER_SEC * 1000;

        cout << "num elements: " << tree->getSize() << "\ttime to remove: " << timeToRemove << endl;

        string output = to_string(tree->getSize()) + "\t" + to_string(timeToRemove) + "\n";
        fputs(output.c_str(), resultsFileDeletion);
    }

    fclose(resultsFileDeletion);

    cout << "Gerando graficos." << endl;
    Gnuplot gp;
    string cmd = "set term png";
    gp.cmd(cmd);
    cmd = "set output '" + graphOutputFileInsertion + "'";
    gp.cmd(cmd);
    cmd = "plot '" + outputFileInsertion + "'";
    gp.cmd(cmd);
    cmd = "set output '" + graphOutputFileDeletion + "'";
    gp.cmd(cmd);
    cmd = "plot '" + outpuFileDeletion + "'";
    gp.cmd(cmd);
}

int getInteger() {
    string input = "";
    int integer = 0;

    getline(cin, input);

    stringstream myStream(input);
    myStream >> integer;

    return integer;
}
