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

/**
 * Method createNode
 * creates an empty node, with NULL pointers to children and to parent
 * and with 0 height
 * @return newly created node, without parent or children
 */
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

/**
 * Method insert
 * Private method for inserting a given node in a given subtree
 * Using insights from:
 * Cormen, Leiserson, Rivest and Stein - Introduction to Algorithms, 3rd Edition
 * and
 * http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec06_orig.pdf
 */
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

    //update heights and ensuring balance
    //reusing x and y variables
    x = newNode;
    while (x->parent != NULL) {
        y = x->parent;
        if (x->height == y->height) {
            y->height += 1;
        }

        x = y;

        if (!balanced(x)) {
            if (height(x->rightChild) > height(x->leftChild)) {
                y = x->rightChild;
                if (height(y->rightChild) >= height(y->leftChild)) {
                    rotateLeft(x);
                } else {
                    rotateRight(y);
                    rotateLeft(x);
                }
            } else {
                y = x->leftChild;
                if (height(y->leftChild) >= height(y->rightChild)) {
                    rotateRight(x);
                } else {
                    rotateLeft(y);
                    rotateRight(x);
                }
            }
        }


    }
}

void AVLTree::rotateRight(node *n) {

}

void AVLTree::rotateLeft(node *n) {

}

/**
 * Method height
 * Returns the height of a given node. If it is NULL, return -1.
 */
int AVLTree::height(node *n) {
    if (n == NULL) {
        return -1;
    }
    else return n->height;
}

/**
 * Method balanced
 * Verifies whether a given subtree is balanced.
 */
bool AVLTree::balanced(node *n) {
    return abs(height(n->leftChild) - height(n->rightChild)) <= 1;
}


