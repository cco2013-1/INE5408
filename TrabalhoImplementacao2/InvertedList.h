#ifndef __InvertedList_h__
#define __InvertedList_h__

#include <string.h>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include "Lista.hpp"
#include "ListOfOccurrences.h"
#include "WordOccurrences.h"

using namespace std;

struct diskElement {
    char word[65];
    int occurrences[5642];
};

class InvertedList {
public:
    InvertedList();
    ~InvertedList();
    void proccess(Lista<string> text, int index);
    Lista<int> search(Lista<string> searchParams);
    int size();
    void saveToDisk(string filename);
    Lista<int> searchInDisk(Lista<string> searchParams, string filename);
    string findBiggestWord();
    WordOccurrences * findMostFrequentWord();

private:
    ListOfOccurrences occurrences;
    unordered_set<string> words;
    unordered_set<string> conjunctions;
    unordered_set<string> readConjunctions();
    diskElement createDiskElement(WordOccurrences *wo);
    void saveElementToDisk(WordOccurrences *element, string filename);
    int findWordInDisk(string word, string filename);
    int binarySearch(int begin, int end, string word, string filename);
    int numberOfElementsInDisk(string filename);
    diskElement readElementFromDisk(int index, string filename);
};

#endif
