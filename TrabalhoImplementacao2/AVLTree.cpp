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

//////// Public methods:

AVLTree::AVLTree() {
    root = NULL;
    size = 0;
}

AVLTree::~AVLTree() {
    //empty
}

/**
 * Method remove
 * Removes a node based in the provided key,
 * and rebalances the tree if necessary.
 * @parameter key
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition, page 298
 */
void AVLTree::remove(string key) {
    node *x = root;
    while (x) {
        if (key < x->key) {
            x = x->leftChild;
        } else if (key > x->key) {
            x = x->rightChild;
        } else {
            break;
        }
    }

    if (x && x->key == key) {
        node *toRebalance;

        //Case a: no left child
        if (!x->leftChild) {
            transplant(x, x->rightChild);
            if (x->rightChild) {
                toRebalance = x->rightChild;
            } else {
                //hack! since the rebalance method immediately
                //points to the parent of the given node, this works
                //well, particularly when the unbalanced node is the
                //root (x parent)
                toRebalance = x;
            }
        }
        //Case b: no right child
        else if (!x->rightChild) {
            transplant(x, x->leftChild);
            if (x->leftChild) {
                toRebalance = x->leftChild;
            } else {
                //hack! since the rebalance method immediately
                //points to the parent of the given node, this works
                //well, particularly when the unbalanced node is the
                //root (x parent)
                toRebalance = x;
            }
        }
        //Cases c and d:
        else {
            node *y = minimum(x->rightChild);
            //Case d specific:
            if (y->parent != x) {
                transplant(y, y->rightChild);
                y->rightChild = x->rightChild;
                y->rightChild->parent = y;
                toRebalance = minimum(y->rightChild);
            } else {
                toRebalance = x->leftChild;
            }
            transplant(x, y);
            y->leftChild = x->leftChild;
            y->leftChild->parent = y;
        }

        delete x;
        rebalance(toRebalance);
        size -= 1;
    }
}

/////// Private methods:

/**
 * Private method insert
 * Private method for inserting a given node in a given subtree
 * @param newNode the new node being inserted
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition
 * @see http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec06_orig.pdf
 */
void AVLTree::insert(node *newNode) {

    node *y = NULL;
    node *x = root;

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

    x = newNode;
    rebalance(x);
}

/**
 * Private method rebalance
 * Update heights and rebalances the tree
 * in order to mantain AVL property
 * @param n the node being rebalanced
 */
void AVLTree::rebalance(node *n) {
    if (!n) {
        return;
    }
    node *x = n;
    node *y = NULL;
    while (x->parent != NULL) {
        y = x->parent;
        y->height = max(height(y->leftChild), height(y->rightChild)) + 1;

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

/**
 * Private method balanced
 * Verifies whether a given subtree is balanced.
 * @param n root of the subtree that is being checked for balance
 * @return true if subtree is balanced, false otherwise
 */
bool AVLTree::balanced(node *n) {
    return abs(height(n->leftChild) - height(n->rightChild)) <= 1;
}
