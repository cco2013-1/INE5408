#ifndef __InvertedList_h__
#define __InvertedList_h__

#include "Lista.hpp"
#include "SortedList.hpp"
#include <string>


using namespace std;

struct wordOccurrences {
    string word;
    SortedList<int> occurrences;

    bool operator<(const wordOccurrences& rhs) const
{
	if (strcmp(word,rhs.word) < 0) return true;
	return false;
}

bool operator>(const wordOccurrences& rhs) const
{
	if (strcmp(word,rhs.word) > 0) return true;
	return false;

bool operator==(const wordOccurrences& rhs) const
{
	if(strcmp(word, rhs.word) == 0) return true;
	return false;
}
};

class InvertedList {
public:
    InvertedList();
    ~InvertedList();
    void insert(Lista<string> words, int index);
    Lista<int> search(Lista<string> word);
    Lista<string> get(); //somente para efeito de teste
    int size();

private:
	SortedList<wordOccurrences> occurrences; 
};


#endif
