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
 * BSTree.h
 */

#ifndef __bs_tree_h__
#define __bs_tree_h__

#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

enum Color { RED, BLACK };

class node {
public:
    node *leftChild;
    node *rightChild;
    node *parent;
    string key;
    string value;
    int height;
    Color color;
    int diskIndex;
};

struct diskNode {
    char key[100];
    char value[140000];
    int parent;
    int leftChild;
    int rightChild;
};

class BSTree {
public:
    BSTree();
    ~BSTree();
    virtual void insert(string key, string value);
    virtual void remove(string key);
    virtual int getSize();
    virtual node * minimum();
    virtual node * maximum();
    virtual node * successor(node *n);
    virtual node * predecessor(node *n);
    virtual node * find(string key);
    virtual node ** inOrder();
    virtual node * getRoot();
    virtual node * getNil();
    void saveToDisk(string filename);
    string findInDisk(string key, string filename);

protected:
    node *root;
    int size;
    virtual node * createNode(string key, string value);
    virtual void insert(node *newNode);
    virtual void rotateRight(node *n);
    virtual void rotateLeft(node *n);
    int height(node *n);
    virtual node * minimum(node *subTreeRoot);
    virtual node * maximum(node *subTreeRoot);
    virtual void transplant(node *u, node *v);
    void resolveDiskIndices(node *n);
    diskNode createDiskNode(node *n);
    void writeTreeToDisk(node *n, string filename);
    void writeNodeToDisk(node *n, string filename);
    diskNode findNodeInDisk(string key, int index, string filename);
    diskNode readNodeFromDisk(int index, string filename);

    int diskIndexCounter;
};

#endif
