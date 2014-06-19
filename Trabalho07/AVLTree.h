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

#include "BSTree.h"

class AVLTree: public BSTree {
public:
    AVLTree();
    ~AVLTree();
    void remove(int key);

private:
    void insert(node *newNode);
    void rebalance(node *x);
    bool balanced(node *n);
};

#endif
