#ifndef __word_occurences_h__
#define __word_occurences_h__

#include <string>
#include "Lista.hpp"

using namespace std;

class WordOccurrences {

public:

    WordOccurrences();
    WordOccurrences(string w);
    ~WordOccurrences();
    void registerOccurence(int index);
    Lista<int> getOccurences();
    string getWord();

    bool operator<(const WordOccurrences& rhs) const {
       if (word.compare(rhs.word) < 0) return true;
       return false;
    }

    bool operator>(const WordOccurrences& rhs) const {
       if (word.compare(rhs.word) > 0) return true;
       return false;
    }

    bool operator==(const WordOccurrences& rhs) const {
       if(word.compare(rhs.word) == 0) return true;
       return false;
    }

private:
    string word;
    Lista<int> occurrences;
};

#endif
