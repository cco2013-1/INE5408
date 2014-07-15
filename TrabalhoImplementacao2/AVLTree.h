/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho de Implementação 2 - Pesquisa de ManPages
 *
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * AVLTree.h
 */

#ifndef __avl_tree_h__
#define __avl_tree_h__

#include "BSTree.h"

/**
 * Classe AVLTree
 * Estrutura de dados de Árvore de Busca Binária Semi-Balanceada
 * Armazena os elementos em ordem em uma estrutura de árvore binária,
 * permitindo consultas, inserções e deleções. Garante o semi-balanceamento
 * da árvore, realizando rebalanceamentos na inserção ou na deleção, conforme
 * necessidade. Garante complexidade O(log n) para consultas, inserções e
 * deleções.
 */
class AVLTree: public BSTree {
public:
    AVLTree();
    ~AVLTree();
    void remove(string key);

private:
    void insert(node *newNode);
    void rebalance(node *x);
    bool balanced(node *n);
};

#endif
