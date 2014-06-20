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
 * RBTreeV2.h
 */

#ifndef __rb_tree_v2_h__
#define __rb_tree_v2_h__

#include <string>
#include "BSTree.h"

using namespace std;

class RBTreeV2 : public BSTree {
public:
    RBTreeV2();
    ~RBTreeV2();
    void insert(int key, string value);
    void remove(int key);
    int getSize();
    node * minimum();
    node * maximum();
    node * successor(node *x);
    node * predecessor(node *x);
    node * find(int key);
    node * getRoot();
    node * getNil();

private:
    node *root;
    node *nilNode;
    int size;
    node * createNode(int key, string value);
    void insert(node *z);
    void rebalanceInsertion(node *z);
    void rebalanceDeletion(node *x);
    void rotateRight(node *x);
    void rotateLeft(node *x);
    node *minimum(node *subTreeRoot);
    node *maximum(node *subTreeRoot);
    void transplant(node *u, node *v);
};

#endif
