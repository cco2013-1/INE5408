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
string defineInputFile(string &inputFile);
string defineTree(BSTree* &tree);
void readAndInsertCeps(const string &inputFile, const string &outputFileInsertion,
                       BSTree* tree);
void showCepSearch(BSTree *tree);
void removeCepsFromTree(const string &outpuFileDeletion, BSTree *tree);
void generateGraphs(const string &outputFileInsertion, const string &outpuFileDeletion,
                    const string &graphOutputFileInsertion, const string &graphOutputFileDeletion);

int main() {
    BSTree *tree = NULL;
    string inputFile;
    string outputFileInsertion = "results_";
    string outpuFileDeletion;
    string graphOutputFileInsertion = "graph_";
    string graphOutputFileDeletion;

    cout << "Bem vindo." << endl;

    string cepsChosen = defineInputFile(inputFile);
    outputFileInsertion += cepsChosen;
    graphOutputFileInsertion += cepsChosen;

    string treeChosen = defineTree(tree);
    outputFileInsertion += treeChosen + ".dat";
    graphOutputFileInsertion += treeChosen + ".png";

    outpuFileDeletion = "deletion_" + outputFileInsertion;
    outputFileInsertion = "insertion_" + outputFileInsertion;

    graphOutputFileDeletion = "deletion_" + graphOutputFileInsertion;
    graphOutputFileInsertion = "insertion_" + graphOutputFileInsertion;

    readAndInsertCeps(inputFile, outputFileInsertion, tree);

    showCepSearch(tree);

    removeCepsFromTree(outpuFileDeletion, tree);

    generateGraphs(outputFileInsertion, outpuFileDeletion, graphOutputFileInsertion,
                   graphOutputFileDeletion);
}

/**
 * Function getInteger
 * gets an integer from user input
 * @returns integer inputed by user
 */
int getInteger() {
    string input = "";
    int integer = 0;

    getline(cin, input);

    stringstream myStream(input);
    myStream >> integer;

    return integer;
}

/**
 * Function defineInputFile
 * Shows a menu with possible input files.
 * After the user selection, sets the name of the input file
 * to the appropriate name and return a string representing the selection
 * @param inputFile string were the input file name will be saved
 * @return string representing the choice of the user
 */
string defineInputFile(string &inputFile) {
    while (true) {
        cout << "Escolha o arquivo de dados de CEP a ser processado: " << endl;
        cout << "1 - DF" << endl;
        cout << "2 - SC" << endl;
        cout << "3 - SP" << endl;
        cout << "4 - Todos concatenados" << endl;
        int opt = getInteger();
        if (opt == 1) {
            inputFile = "df.cep";
            return "DF_";
        }
        if (opt == 2) {
            inputFile = "sc.cep";
            return "SC_";
        }
        if (opt == 3) {
            inputFile = "sp.cep";
            return "SP_";
        }
        if (opt == 4) {
            inputFile = "todos.cep";
            return "todos_";
        }
        cout << "errou feio, errou rude." << endl;
    }
}

/**
 * Function defineTree
 * Defines the type of the tree used to store data
 * Shows a menu for seleciton and sets the passed tree pointer reference to a newly
 * created tree of the chosen type.
 * Returns a string representing the selected tree.
 * @param tree a reference to a BSTree pointer
 * @return a string that represents the chosen tree
 */
string defineTree(BSTree* &tree) {
    while (true) {
        cout << "Escolha a árvore. 1 para AVL, 2 para RedBlack." << endl;
        int opt = getInteger();
        if (opt == 1) {
            tree = new AVLTree();
            return "AVLTree";
        }
        if (opt == 2) {
            tree = new RBTreeV2();
            return "RedBlackTree";
        }
        cout << "errou feio, errou rude." << endl;
    }
}

/**
 * Function readAndInsertCeps
 * Reads the ceps from the input file, insert them in the tree and records the time
 * taken to store each cep in the outputFileInsertion file.
 * @param inputFile the name of the input file containing the ceps
 * @param outputFileInsertion name of the output file where the time taken to insert
 *      each element in the tree
 * @param tree the tree where the ceps will be inserted
 */
void readAndInsertCeps(const string &inputFile, const string &outputFileInsertion,
                        BSTree* tree) {
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
}

void showCepSearch(BSTree *tree) {
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
}

void removeCepsFromTree(const string &outpuFileDeletion, BSTree *tree) {
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
}

void generateGraphs(const string &outputFileInsertion, const string &outpuFileDeletion,
                    const string &graphOutputFileInsertion, const string &graphOutputFileDeletion) {
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
