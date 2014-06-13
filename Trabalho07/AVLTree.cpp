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
 * AVLTree.cpp
 */

#include "AVLTree.h"
#include <stdlib.h>

AVLTree::AVLTree() {
    root = NULL;
    size = 0;
}

AVLTree::~AVLTree() {
    // TODO
}

void AVLTree::insert(int key, string value) {
    node *newNode = createNode(key, value);
    insert(newNode, root);
}

void AVLTree::remove(int key) {
    // TODO
}

AVLTree::node * AVLTree::createNode(int key, string value) {
    node *newNode = new node;
    newNode->key = key;
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = NULL;
    newNode->height = 0;

    return newNode;
}

void AVLTree::insert(node *newNode, node *subTreeRoot) {

    node *y = NULL;
    node *x = subTreeRoot;

    //Find insertion position
    while (x != NULL) {
        y = x;
        if (newNode->key < x->key) {
            x = x->leftChild;
        } else {
            x = x->rightChild;
        }
    }

    //Set position node y as new node's parent
    newNode->parent = y;

    if (y == NULL) {
        root = newNode;
    } else if (newNode->key < y->key) {
        y->leftChild = newNode;
    } else {
        y->rightChild = newNode;
    }

    //update heights
    //reusing x and y variables

    x = newNode;
    while (x->parent != NULL) {
        y = x->parent;
        if (x->height == y->height) {
            y->height += 1;
        }



        x = y;
    }
}

int AVLTree::height(node *n) {
    if (n == NULL) {
        return -1;
    }
    else return n->height;
}

bool AVLTree::balanced(node *n) {
    return abs(height(n->leftChild) - height(n->rightChild)) <= 1;
}


