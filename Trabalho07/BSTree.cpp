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
 * BSTree.cpp
 */

#include "BSTree.h"
#include <stdlib.h>

BSTree::BSTree() {
    root = NULL;
    size = 0;
}

BSTree::~BSTree() {
    while (root) {
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
void BSTree::insert(int key, string value) {
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
 * Algorithms, 3rd Edition, page 298
 */
void BSTree::remove(int key) {
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
        //Case a: no left child
        if (!x->leftChild) {
            transplant(x, x->rightChild);
        }
        //Case b: no right child
        else if (!x->rightChild) {
            transplant(x, x->leftChild);
        }
        //Cases c and d:
        else {
            node *y = minimum(x->rightChild);
            //Case d specific:
            if (y->parent != x) {
                transplant(y, y->rightChild);
                y->rightChild = x->rightChild;
                y->rightChild->parent = y;
            }
            transplant(x, y);
            y->leftChild = x->leftChild;
            y->leftChild->parent = y;
        }

        delete x;
        size -= 1;
    }
}

/**
 * Method getSize
 * Returns the number of node in the tree
 * @return number of nodes in the tree
 */
int BSTree::getSize() {
    return size;
}

/**
 * Method minimum
 * Finds the node with the minimum key in the tree
 * @return node with minimum key
 */
node * BSTree::minimum() {
    return minimum(root);
}

/**
 * Method maximum
 * Finds the node with the maximum key in the tree
 * @return node with maximum key
 */
node * BSTree::maximum() {
    return maximum(root);
}

/**
 * Method successor
 * Finds the successor of the given node
 * @see http://stackoverflow.com/questions/3750929/find-inorder-successor-in-bst-without-using-any-extra-space
 * @param n node for which one wants to find a successor
 * @return node successor to the given node
 */
node * BSTree::successor(node *n) {
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
 * Method predecessor
 * Finds the predecessor node of the given node
 * @param n node for which one wants to find a predecessor
 * @return node successor to the given node
 */
node * BSTree::predecessor(node *n) {
    node *x = n;
    if (x->leftChild) {
        return maximum(x->leftChild);
    } else {
        node *pred;
        while((pred = x->parent)) {
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
node * BSTree::find(int key) {
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
        return x;
    }

    return NULL;
}

node * BSTree::getRoot() {
    return root;
}

node * BSTree::getNil() {
    return NULL;
}

/**
 * Protected method createNode
 * creates an empty node, with NULL pointers to children and to parent
 * and with 0 height
 * @param key
 * @param value
 * @return newly created node, without parent or children
 */
node * BSTree::createNode(int key, string value) {
    node *newNode = new node;
    newNode->key = key;
    newNode->value = value;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent = NULL;
    newNode->height = 0;
    newNode->color = RED;

    return newNode;
}

/**
 * Protected method insert
 * Protected method for inserting a given node in a given subtree
 * @param newNode the new node being inserted
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition
 * @see http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec06_orig.pdf
 */
void BSTree::insert(node *newNode) {

    node *y = NULL;
    node *x = root;

    //Find insertion position
    while (x) {
        y = x;
        if (newNode->key < x->key) {
            x = x->leftChild;
        } else {
            x = x->rightChild;
        }
    }

    //Set position node y as new node's parent
    newNode->parent = y;

    if (!y) {
        root = newNode;
    } else if (newNode->key < y->key) {
        y->leftChild = newNode;
    } else {
        y->rightChild = newNode;
    }

    x = newNode;
}

/**
 * Protected method rotateRight
 * Performs a right rotation of the given node
 * and updates nodes' heights
 * @param x the node being rotated to the right
 * @see http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec06_orig.pdf *
 */
void BSTree::rotateRight(node *x) {
    node *y = x->leftChild;
    node *b = y->rightChild;
    node *parent = x->parent;
    x->leftChild = b;
    if (b) {
        b->parent = x;
    }
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
 * Protected method rotateLeft
 * Performs a left rotation of the given node
 * and updates nodes' heights
 * @param x the node being rotated to de left
 * @see http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec06_orig.pdf *
 */
void BSTree::rotateLeft(node *x) {
    node *y = x->rightChild;
    node *b = y->leftChild;
    node *parent = x->parent;
    x->rightChild = b;
    if (b) {
        b->parent = x;
    }
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
 * Protected method height
 * Returns the height of a given node. If it is NULL, return -1.
 * @param n the node of which the height is being calculated
 * @return the node's height
 */
int BSTree::height(node *n) {
    if (n == NULL) {
        return -1;
    }
    else return n->height;
}

/**
 * Protected method minimum
 * returns the node with the mininum key in the
 * three rooted at subTreeRoot
 * @param subTreeRoot sub-tree's root
 * @return node with minimum key within the subtree
 */
node * BSTree::minimum(node *subTreeRoot) {
    if (!subTreeRoot) {
        return NULL;
    }

    node *min = subTreeRoot;

    while (min->leftChild) {
        min = min->leftChild;
    }

    return min;
}

/**
 * Protected method maximum
 * returns the node with the maximum key in the
 * three rooted at subTreeRoot
 * @param subTreeRoot sub-tree's root
 * @return node with maximum key within the subtree
 */
node * BSTree::maximum(node *subTreeRoot) {
    if (!subTreeRoot) {
        return NULL;
    }

    node *max = subTreeRoot;

    while (max->rightChild) {
        max = max->rightChild;
    }

    return max;
}

/**
 * Protected method transplant
 * Replaces one subtree as a child of its parent
 * with another subtree.
 * When TRANSPLANT replaces the subtree rooted at node u
 * with the subtree rooted at node v, node u’s parent becomes
 * node v’s parent, and u’s parent ends up having v as its
 * appropriate child.
 * @param u, v nodes to be transplanted
 * @see Cormen, Leiserson, Rivest and Stein - Introduction to
 * Algorithms, 3rd Edition, page 296
 */
void BSTree::transplant(node *u, node *v) {
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
