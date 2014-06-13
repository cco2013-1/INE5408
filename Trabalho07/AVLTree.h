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

#ifndef __avl_tree_hpp__
#define __avl_tree_hpp__

#import <string>

using namespace std;

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int key, string value);
    void remove(int key);
// private:
    struct node {
        node *leftChild;
        node *rightChild;
        node *parent;
        int key;
        string value;
        int height;
    };
    node *root;
    int size;
    node * createNode(int key, string value);
    void insert(node *newNode, node *subTreeRoot);
    void rotateRight(node *n);
    void rotateLeft(node *n);
    bool balanced(node *n);
    int height(node *n);
};

#endif
