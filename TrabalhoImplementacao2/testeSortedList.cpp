#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "SortedList.hpp"


using namespace std;


SortedList<int> lista;

int main() {
    for(int i = 0 ; i< 100 ; i++) {
        lista.add(rand()%100);
    }
    int tamanho = lista.size();
    for(int i = 0; i < tamanho ; i++) {
        cout << lista.get() << endl;
    }
    return 0;
}
