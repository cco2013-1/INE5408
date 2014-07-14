#include "WordOccurrences.h"

WordOccurrences::WordOccurrences() {

}

WordOccurrences::WordOccurrences(string w) {
    word = w;
}

WordOccurrences::~WordOccurrences() {

}

void WordOccurrences::registerOccurence(int index) {
    occurrences.adiciona(index);
}

Lista<int> WordOccurrences::getOccurences() {
    return occurrences;
}

string WordOccurrences::getWord() {
    return word;
}
