#ifndef __InvertedList_h__
#define __InvertedList_h__

using namespace std;

struct wordOccurrences {
    string word;
    Lista<int> occurrences;
};

class InvertedList {
public:
    InvertedList();
    ~InvertedList();
    void insert(Lista<string> words, int index);
    Lista<int> search(Lista<string> word);

private:
	Lista<wordOccurrences> occurrences; 
};


#endif
