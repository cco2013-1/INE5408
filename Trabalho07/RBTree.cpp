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
 * RBTree.cpp
 */

#include "RBTree.h"
#include <stdlib.h>

RBTree::RBTree() {
    root = NULL;
    size = 0;
}

RBTree::~RBTree() {
    //empty
}

/**
 * Method remove
 * Removes from the tree the node that has the given key.
 * @param key The key of the node one wants to be removed.
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition - page 324
 */
void RBTree::remove(int key) {
    node *z = root;
    while (z) {
        if (key < z->key){
            z = z->leftChild;
        } else if (key > z->key) {
            z = z->rightChild;
        } else {
            break;
        }
    }

    if (z && z->key == key) {
        node * y = z;
        node * x;
        Color yOriginalColor = y->color;

        if (z->leftChild == NULL) {
            x = z->rightChild;
            bool flag = false;
            if (z == z->parent->leftChild) {
                flag = true;
            }
            transplant(z, z->rightChild);
            if (!x && root) {
                x = new node;
                x->parent = y->parent;
                x->color = BLACK;
                if (flag) {
                    x->value = "__left_hack__";
                }
            }
        } else if (z->rightChild == NULL) {
            x = z->leftChild;
            transplant(z, z->leftChild);
        } else {
            bool flag = false;
            y = minimum(z->rightChild);
            yOriginalColor = y->color;
            x = y->rightChild;
            if (y->parent == z) {
                if (x) x->parent = y;
            } else {
                flag = true;
                transplant(y, y->rightChild);
                y->rightChild = z->rightChild;
                y->rightChild->parent = y;
            }
            transplant(z, y);
            y->leftChild = z->leftChild;
            y->leftChild->parent = y;
            y->color = z->color;
            if (!x) {
                x = new node;
                x->parent = y->rightChild;
                x->color = BLACK;
                if (flag) {
                    x->value = "__left_hack__";
                }
            }
        }

        if (yOriginalColor == BLACK) {
            rebalanceDeletion(x);
        }

        delete z;
        size -= 1;
    }
}

/**
 * Private method insert
 * Inserts the given node in the tree
 * @param newNode the node to be inserted
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition - page 315
 */
void RBTree::insert(node *newNode) {

    node *y = NULL;
    node *x = root;

    while (x) {
        y = x;
        if (newNode->key < x->key) {
            x = x->leftChild;
        } else {
            x = x->rightChild;
        }
    }

    newNode->parent = y;

    if (!y) {
        root = newNode;
        //makes the root black
        newNode->color = BLACK;
        return; //so that no rebalance is made,
                //since there is only one node in the tree.
    } else if (newNode->key < y->key) {
        y->leftChild = newNode;
    } else {
        y->rightChild = newNode;
    }

    rebalanceInsertion(newNode);
}

/**
 * Private method rebalanceInsertion
 * Restores Reb-Black properties after an insertion
 * @param z node that has been inserted
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition - page 316
 */
void RBTree::rebalanceInsertion(node *z) {
    node *y = NULL;
    while (z->parent && z->parent->color == RED) {
        if (z->parent == z->parent->parent->leftChild) {
            y = z->parent->parent->rightChild;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->rightChild) {
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z->parent->parent);
            }
        } else {
            y = z->parent->parent->leftChild;
            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->leftChild) {
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z);
            }
        }
    }
    root->color = BLACK;
}

/**
 * Private method rebalanceDeletion
 * Restores Red-Black properties after a deletion
 * @param x node that has to be rebalanced.
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition - page 326
 */
void RBTree::rebalanceDeletion(node *x) {
    node * w;

    while (x != root && x->color == BLACK) {
        if (x == x->parent->leftChild || x->value == "__left_hack__") {
            w = x->parent->rightChild;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                w = x->parent->rightChild;
            }
            if ((w->leftChild && w->leftChild->color == BLACK && w->rightChild && w->rightChild->color == BLACK) || (!w->leftChild && !w->rightChild)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (!w->rightChild || w->rightChild->color == BLACK) {
                    w->leftChild->color = BLACK;
                    w->color = RED;
                    rotateRight(w);
                    w = x->parent->rightChild;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->rightChild->color = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        } else {
            w = x->parent->leftChild;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(x->parent);
                w = x->parent->leftChild;
            }
            if ((w->leftChild && w->leftChild->color == BLACK && w->rightChild && w->rightChild->color == BLACK) || (!w->leftChild && !w->rightChild)) {
                w->color = RED;
                x = x->parent;
            } else {
                if (!w->leftChild || w->leftChild->color == BLACK) {
                    w->rightChild->color = BLACK;
                    w->color = RED;
                    rotateLeft(w);
                    w = x->parent->leftChild;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->leftChild->color = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}
