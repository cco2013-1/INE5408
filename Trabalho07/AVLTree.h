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
 * AVLTree.h
 */

#ifndef __avl_tree_h__
#define __avl_tree_h__

#include <string>

using namespace std;

class AVLTree {
public:
    AVLTree();
    ~AVLTree();

    struct node {
        node *leftChild;
        node *rightChild;
        node *parent;
        int key;
        string value;
        int height;
    };

    void insert(int key, string value);
    void remove(int key);
    node * minimum();
    node * maximum();
    node * successor(node *n);
    node * predecessor(node *n);
    node * find(int key);

private:
    node *root;
    int size;
    node * createNode(int key, string value);
    void insert(node *newNode);
    void rebalance(node *x);
    bool balanced(node *n);
    void rotateRight(node *x);
    void rotateLeft(node *x);
    int height(node *n);
    node * minimum(node *subTreeRoot);
    node * maximum(node *subTreeRoot);
    void transplant(node *u, node *v);
};

#endif
