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
 * RBTree.h
 */

#ifndef __rb_tree_h__
#define __rb_tree_h__

#include "BSTree.h"

class RBTree: public BSTree {
public:
    RBTree();
    ~RBTree();
    void remove(int key);

private:
    void insert(node *n);
    void rebalanceInsertion(node *z);
    void rebalanceDeletion(node *x);
};

#endif
