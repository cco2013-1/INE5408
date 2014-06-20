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
 * RBTreeV2.cpp
 */

#include "RBTreeV2.h"
#include <stdlib.h>

RBTreeV2::RBTreeV2() {
    nilNode = new node;
    nilNode->color = BLACK;
    root = nilNode;
    size = 0;
}

RBTreeV2::~RBTreeV2() {
    while (root && root != nilNode) {
        remove(root->key);
    }
}

/**
 * Method insert
 * Creates a new node with the given key and value
 * and inserts it in the tree.
 * @param key the key to the new value
 * @param value the new value
 */
void RBTreeV2::insert(int key, string value) {
    node *newNode = createNode(key, value);
    insert(newNode);
    size += 1;
}

/**
 * Method remove
 * Removes a node based in the provided key,
 * and rebalances the tree if necessary.
 * @parameter key
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition, page 324
 */
void RBTreeV2::remove(int key) {
    node *z = root;
    while (z != nilNode) {
        if (key < z->key) {
            z = z->leftChild;
        } else if (key > z->key) {
            z = z->rightChild;
        } else {
            break;
        }
    }

    if (z != nilNode && z->key == key) {
        node * y = z;
        node * x;
        Color yOriginalColor = y->color;
        if (z->leftChild == nilNode) {
            x = z->rightChild;
            transplant(z, z->rightChild);
        } else if (z->rightChild == nilNode) {
            x = z->leftChild;
            transplant(z, z->leftChild);
        } else {
            y = minimum(z->rightChild);
            yOriginalColor = y->color;
            x = y->rightChild;
            if (y->parent == z) {
                x->parent = y;
            } else {
                transplant(y, y->rightChild);
                y->rightChild = z->rightChild;
                y->rightChild->parent = y;
            }
            transplant(z, y);
            y->leftChild = z->leftChild;
            y->leftChild->parent = y;
            y->color = z->color;
        }
        if (yOriginalColor == BLACK) {
            rebalanceDeletion(x);
        }
    }

    delete z;
    size -= 1;
}

/**
 * Method getSize
 * Returns the number of node in the tree
 * @return number of nodes in the tree
 */
int RBTreeV2::getSize() {
    return size;
}

/**
 * Method minimum
 * Finds the node with the minimum key in the tree
 * @return node with minimum key
 */
node * RBTreeV2::minimum() {
    return minimum(root);
}

/**
 * Method maximum
 * Finds the node with the maximum key in the tree
 * @return node with maximum key
 */
node * RBTreeV2::maximum() {
    return maximum(root);
}

/**
 * Method successor
 * Finds the successor of the given node
 * @see http://stackoverflow.com/questions/3750929/find-inorder-successor-in-bst-without-using-any-extra-space
 * @param n node for which one wants to find a successor
 * @return node successor to the given node
 */
node * RBTreeV2::successor(node *x) {
    if (x->rightChild != nilNode) {
        return minimum(x->rightChild);
    } else {
        node *succ;
        while (x->parent && x->parent != nilNode) {
            succ = x->parent;
            if (succ->leftChild == x) {
                return succ;
            }
            x = succ;
        }
    }
    return NULL;
}

/**
 * Method predecessor
 * Finds the predecessor node of the given node
 * @param n node for which one wants to find a predecessor
 * @return node successor to the given node
 */
node * RBTreeV2::predecessor(node *x) {
    if (x->leftChild != nilNode) {
        return maximum(x->leftChild);
    } else {
        node *pred;
        while (x->parent && x->parent != nilNode) {
            pred = x->parent;
            if (pred->rightChild == x) {
                return pred;
            }
            x = pred;
        }
    }
    return NULL;
}

/**
 * Method find
 * Returns the node that has the given key
 * @param key the key to be found
 * @return node that has the given key
 */
node * RBTreeV2::find(int key) {
    node *x = root;
    while (x != nilNode) {
        if (key < x->key) {
            x = x->leftChild;
        } else if (key > x->key) {
            x = x->rightChild;
        } else {
            break;
        }
    }

    if (x != nilNode && x->key == key) {
        return x;
    }

    return NULL;
}

/**
 * Method inOrder
 * returns a pointer to an array of pointers to nodes
 * with nodes ordered by key
 * @return pointer to array of pointers to nodes, with nodes in order
 */
node ** RBTreeV2::inOrder() {
    node ** arrayInOrder = new node *[getSize()];
    node * next = minimum();
    int index = 0;
    while (true) {
        arrayInOrder[index] = next;
        next = successor(next);
        index += 1;
        if (!next) {
            break;
        }
    }
    return arrayInOrder;
}

node * RBTreeV2::getRoot() {
    return root;
}

node * RBTreeV2::getNil() {
    return nilNode;
}

////////////////Private Methods

/**
 * Private method createNode
 * creates an empty node, with NULL pointers to children and to parent
 * and with 0 height
 * @param key
 * @param value
 * @return newly created node, without parent or children
 */
node * RBTreeV2::createNode(int key, string value) {
    node *newNode = new node;
    newNode->key = key;
    newNode->value = value;
    newNode->leftChild = nilNode;
    newNode->rightChild = nilNode;
    newNode->parent = nilNode;
    newNode->color = RED;

    return newNode;
}

void RBTreeV2::insert(node *z) {
    node * y = nilNode;
    node * x = root;

    while (x != nilNode) {
        y = x;
        if (z->key < x->key) {
            x = x->leftChild;
        } else {
            x = x->rightChild;
        }
    }

    z->parent = y;

    if (y == nilNode) {
        root = z;
    } else if (z->key < y->key) {
        y->leftChild = z;
    } else {
        y->rightChild = z;
    }

    rebalanceInsertion(z);
}

/**
 * Private method rebalanceInsertion
 * Restores Reb-Black properties after an insertion
 * @param z node that has been inserted
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition - page 316
 */
void RBTreeV2::rebalanceInsertion(node *z) {
    node * y;
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->leftChild) {
            y = z->parent->parent->rightChild;
            if (y->color == RED) {
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
            if (y->color == RED) {
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
                rotateLeft(z->parent->parent);
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
void RBTreeV2::rebalanceDeletion(node *x) {
    node * w;
    while (x != root && x->color == BLACK) {
        if (x == x->parent->leftChild) {
            w = x->parent->rightChild;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                w = x->parent->rightChild;
            }
            if (w->leftChild->color == BLACK && w->rightChild->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->rightChild->color == BLACK) {
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
            if (w->leftChild->color == BLACK && w->rightChild->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->leftChild->color == BLACK) {
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

/**
 * Private method rotateRight
 * Performs a right rotation of the given node
 * and updates nodes' heights
 * @param x the node being rotated to the right
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition, page 313
 */
void RBTreeV2::rotateRight(node *x) {
    node *y = x->leftChild;
    node *b = y->rightChild;
    node *parent = x->parent;
    x->leftChild = b;
    if (b != nilNode) {
        b->parent = x;
    }
    y->rightChild = x;
    x->parent = y;
    y->parent = parent;
    if (parent != nilNode && parent->rightChild == x) {
        parent->rightChild = y;
    } else if (parent != nilNode) {
        parent->leftChild = y;
    } else {
        root = y;
    }
}

/**
 * Private method rotateLeft
 * Performs a left rotation of the given node
 * and updates nodes' heights
 * @param x the node being rotated to de left
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition, page 313
 */
void RBTreeV2::rotateLeft(node *x) {
    node *y = x->rightChild;
    node *b = y->leftChild;
    node *parent = x->parent;
    x->rightChild = b;
    if (b != nilNode) {
        b->parent = x;
    }
    y->leftChild = x;
    x->parent = y;
    y->parent = parent;
    if (parent != nilNode && parent->rightChild == x) {
        parent->rightChild = y;
    } else if (parent != nilNode) {
        parent->leftChild = y;
    } else {
        root = y;
    }
}

/**
 * Private method minimum
 * returns the node with the mininum key in the
 * three rooted at subTreeRoot
 * @param subTreeRoot sub-tree's root
 * @return node with minimum key within the subtree
 */
node * RBTreeV2::minimum(node *subTreeRoot) {
    if (!subTreeRoot) {
        return NULL;
    }

    node *min = subTreeRoot;

    while (min->leftChild != nilNode) {
        min = min->leftChild;
    }

    return min;
}

/**
 * Private method maximum
 * returns the node with the maximum key in the
 * three rooted at subTreeRoot
 * @param subTreeRoot sub-tree's root
 * @return node with maximum key within the subtree
 */
node * RBTreeV2::maximum(node *subTreeRoot) {
    if (!subTreeRoot) {
        return NULL;
    }

    node *max = subTreeRoot;

    while (max->rightChild != nilNode) {
        max = max->rightChild;
    }

    return max;
}

/**
 * Private method transplant
 * Replaces one subtree as a child of its parent
 * with another subtree.
 * When TRANSPLANT replaces the subtree rooted at node u
 * with the subtree rooted at node v, node u’s parent becomes
 * node v’s parent, and u’s parent ends up having v as its
 * appropriate child.
 * @param u, v nodes to be transplanted
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition, page 323
 */
void RBTreeV2::transplant(node *u, node *v) {
    if (u->parent == nilNode) {
        root = v;
    } else if (u == u->parent->leftChild) {
        u->parent->leftChild = v;
    } else {
        u->parent->rightChild = v;
    }
    v->parent = u->parent;
}
