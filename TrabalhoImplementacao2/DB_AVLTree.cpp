#include "DB_AVLTree.h"

DB_AVLTree::DB_AVLTree() {
    size = 0;
    root = NULL_RECORD_INDEX;
}

DB_AVLTree::~DB_AVLTree() {
    //TODO
}

void DB_AVLTree::insert(char * comando, char * conteudo) {
    manPage newManPage = createManPage(comando, conteudo);
    insert(newManPage);
    size += 1;
}

void DB_AVLTree::remove(char * comando) {
    //TODO
}

int DB_AVLTree::getSize() {
    return size;
}

int DB_AVLTree::minimum() {
    return minimum(root);
}

int DB_AVLTree::maximum() {
    return maximum(root);
}

int DB_AVLTree::successor(int manPageIndex) {

    manPage x = readRecord(manPageIndex);

    if (x.rightChild != NULL_RECORD_INDEX) {
        return minimum(x.rightChild);
    } else {
        manPage succ;
        while (x.parent != NULL_RECORD_INDEX) {
            succ = readRecord(x.parent);
            if (succ.leftChild == manPageIndex) {
                return x.parent;
            }
            manPageIndex = x.parent;
            x = succ;
        }
    }

    return NULL_RECORD_INDEX;
}

int DB_AVLTree::predecessor(int manPageIndex) {

    manPage x = readRecord(manPageIndex);

    if (x.leftChild != NULL_RECORD_INDEX) {
        return maximum(x.rightChild);
    } else {
        manPage pred;
        while (x.parent != NULL_RECORD_INDEX) {
            pred = readRecord(x.parent);
            if (pred.leftChild == manPageIndex) {
                return x.parent;
            }
            manPageIndex = x.parent;
            x = pred;
        }
    }
}

manPage DB_AVLTree::createManPage(char * comando, char * conteudo) {
    manPage newManPage;
    strcpy(newManPage.comando, comando);
    strcpy(newManPage.conteudo, conteudo);
    newManPage.leftChild = NULL_RECORD_INDEX;
    newManPage.rightChild = NULL_RECORD_INDEX;
    newManPage.parent = NULL_RECORD_INDEX;
    newManPage.height = 0;

    return newManPage;
}

void DB_AVLTree::insert(manPage newManPage) {


    int y = NULL_RECORD_INDEX;
    int x = root;

    //the newly inserted manPage will have index equal to size before insertion
    //as the size is incremented only after the insertion, we use it here directly
    //as the index of the new man page.
    //this may cause problems on deletions and subsequent insertions
    //TODO: decide whether we will treat this or not
    int newManPageIndex = size;

    manPage xManPage, yManPage;

    while (x != NULL_RECORD_INDEX) {
        y = x;
        xManPage = readRecord(x);
        if (strcmp(newManPage.comando, xManPage.comando) < 0) {
            x = xManPage.leftChild;
        } else {
            x = x.rightChild;
        }
    }

    newManPage.parent = y;

    if (y == NULL_RECORD_INDEX) {
        root = 0;
    } else {
        yManPage = readRecord(y);

        if (strcmp(newManPage.comando, yManPage.comando) < 0) {
            yManPage.leftChild = newManPageIndex;
        } else {
            yManPage.rightChild = newManPageIndex;
        }
        writeRecord(yManPage, y);
    }

    writeRecord(newManPage, newManPageIndex);
    rebalance(newManPageIndex);
}
