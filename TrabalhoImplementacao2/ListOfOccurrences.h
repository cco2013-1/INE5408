#include "Lista.hpp"
#include "WordOccurrences.h"

#ifndef __list_of_occurrences_h__
#define __list_of_occurrences_h__

class ListOfOccurrences {
public:
    ListOfOccurrences();
    ~ListOfOccurrences();
    void add(WordOccurrences * wo);
    WordOccurrences * get(int position);
    int position(string w);
    int size();
    bool isEmpty();
private:
    Lista<WordOccurrences *> sortedList;
    int findPosition(WordOccurrences * wo);
    int binarySearch(int begin, int end, WordOccurrences * wo);
    int binaryFind(int begin, int end, WordOccurrences * wo);
};

#endif
