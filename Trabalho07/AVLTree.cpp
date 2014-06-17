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


/**
 * Method remove
 * Removes a node based in the provided key,
 * and rebalances the tree if necessary.
 * @parameter key
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to Algorithms, 3rd Edition, page 297
 * TODO refactor!!!!!
 */
void AVLTree::remove(int key) {
    node *x = root;
    while (x != NULL) {
        if (key < x->key) {
            x = x->leftChild;
        } else if (key > x->key) {
            x = x->rightChild;
        } else {
            break;
        }
    }

    if (x && x->key == key) {

        //Case a: no left child
        if (!x->leftChild) {
            node *rightChild = x->rightChild;
            if (x->parent && x->parent->leftChild == x) {
                x->parent->leftChild = rightChild;
            } else if (x->parent) {
                x->parent->rightChild = rightChild;
            } else {
                root = rightChild;
            }

            //right child might be null
            //if it is not null, then update its parent to point
            //to the parent of the removed node
            if (x->rightChild) {
                x->rightChild->parent = x->parent;
            }

            delete x;

            rebalance(rightChild);

            return;
        }

        /*
         * Case b: no right child
         */
        if (!x->rightChild) {
            node *leftChild = x->leftChild;
            if (x->parent && x->parent->leftChild == x) {
                x->parent->leftChild = leftChild;
            } else if (x->parent) {
                x->parent->rightChild = leftChild;
            } else {
                root = leftChild;
            }

            //left child might be null
            //if it is not null, then update its parent to point
            //to the parent of the removed node
            if (x->leftChild) {
                x->leftChild->parent = x->parent;
            }

            delete x;

            rebalance(leftChild);

            return;
        }

        /*
         * Case c: Node has two children and its right child
         * has no left child. This means that node's right child
         * is the node's successor.
         */
        if (!x->rightChild->leftChild) {
            node *rightChild = x->rightChild;
            if (x->parent && x->parent->leftChild == x) {
                x->parent->leftChild = rightChild;
            } else if (x->parent) {
                x->parent->rightChild = rightChild;
            }
            rightChild->parent = x->parent;
            rightChild->leftChild = x->leftChild;
            x->leftChild->parent = rightChild;

            delete x;

            rebalance(rightChild);

            return;
        }

        /*
         * Case d: Node to be deleted ́ has two children
         * (left child l and right child r), and its
         * successor y != r lies within the subtree
         * rooted at r
         */

        node * x_successor = successor(x);

        //move y (x_successor) right child to y position
        x_successor->parent->leftChild = x_successor->rightChild;
        if (x_successor->rightChild) {
            x_successor->rightChild->parent = x_successor->parent;
        }

        //make x_successor be x right child's parent
        x_successor->rightChild = x->rightChild;
        if (x_successor->rightChild) {
            x->rightChild->parent = x_successor;
        }

        //move x_successor to x position
        if (x->parent && x->parent->leftChild == x) {
            x->parent->leftChild = x_successor;
        } else if (x->parent) {
            x->parent->rightChild = x_successor;
        } else {
            root = x_successor;
        }
        x_successor->parent = x->parent;

        x_successor->leftChild = x->leftChild;
        x->leftChild->parent = x_successor;

        delete x;

        rebalance(x_successor->rightChild);

        return;
    }
}

/**
 * Method successor
 * Finds the element that the key that is successor to
 * the given key
 * @param key reference key of which the successor will be located
 * @return node successor to the given key
 */
AVLTree::node * AVLTree::successor(node *n) {
    node *x = n;
    if (x->rightChild) {
        return minimum(x->rightChild);
    } else {
        node *succ;
        while ((succ = x->parent)) {
            if (succ->leftChild == x) {
                return succ;
            }
            x = succ;
        }
    }
    return NULL;
}

/**
 * Method minimum
 * Finds the node with the minimum key in the tree
 * @return node with minimum key
 */
AVLTree::node * AVLTree::minimum() {
    return minimum(root);
}

/**
 * Private method minimum
 * returns the node with the mininum key in the
 * three rooted at subTreeRoot
 * @param subTreeRoot sub-tree's root
 * @return node with minimum key within the subtree
 */
AVLTree::node * AVLTree::minimum(node *subTreeRoot) {
    node *min = subTreeRoot;

    while (min->leftChild) {
        min = min->leftChild;
    }

    return min;
}

/**
 * Method createNode
 * creates an empty node, with NULL pointers to children and to parent
 * and with 0 height
 * @param key
 * @param value
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
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to Algorithms, 3rd Edition
 * @see http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec06_orig.pdf
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

    x = newNode;
    rebalance(x);
}

/**
 * Method rabalance
 * Update heights and rebalances the tree
 * as to mantain AVL property
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
 * Method rotateRight
 * Performs a right rotation of the given node
 * and updates nodes' heights
 * See:
 * http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec06_orig.pdf *
 */
void AVLTree::rotateRight(node *x) {
    node *y = x->leftChild;
    node *b = y->rightChild;
    node *parent = x->parent;
    x->leftChild = b;
    y->rightChild = x;
    x->parent = y;
    y->parent = parent;
    if (parent && parent->rightChild == x) {
        parent->rightChild = y;
    } else if (parent) {
        parent->leftChild = y;
    } else {
        root = y;
    }
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = x->height + 1;
}

/**
 * Method rotateLeft
 * Performs a left rotation of the given node
 * and updates nodes' heights
 * See:
 * http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec06_orig.pdf *
 */
void AVLTree::rotateLeft(node *x) {
    node *y = x->rightChild;
    node *b = y->leftChild;
    node *parent = x->parent;
    x->rightChild = b;
    y->leftChild = x;
    x->parent = y;
    y->parent = parent;
    if (parent && parent->rightChild == x) {
        parent->rightChild = y;
    } else if (parent) {
        parent->leftChild = y;
    } else {
        root = y;
    }
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = x->height + 1;
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

void AVLTree::transplant(node *u, node *v) {
    if (!u->parent) {
        root = v;
    } else if (u->parent->leftChild == u) {
        u->parent->leftChild = v;
    } else {
        u->parent->rightChild = v;
    }
    if (v) {
        v->parent = u->parent;
    }
}
