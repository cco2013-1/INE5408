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

#include <string>

using namespace std;

enum Color { RED, BLACK };

class node {
public:
    node *leftChild;
    node *rightChild;
    node *parent;
    int key;
    string value;
    int height;
    Color color;
};

class BSTree {
public:
    BSTree();
    ~BSTree();
    void insert(int key, string value);
    virtual void remove(int key);
    int getSize();
    node * minimum();
    node * maximum();
    node * successor(node *n);
    node * predecessor(node *n);
    node * find(int key);
    node * getRoot();

protected:
    node *root;
    int size;
    node * createNode(int key, string value);
    virtual void insert(node *newNode);
    void rotateRight(node *n);
    void rotateLeft(node *n);
    int height(node *n);
    node * minimum(node *subTreeRoot);
    node * maximum(node *subTreeRoot);
    void transplant(node *u, node *v);
};

#endif
