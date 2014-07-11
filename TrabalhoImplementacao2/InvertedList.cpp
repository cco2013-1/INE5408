#include "InvertedList.h"
#include "Lista.hpp"


InvertedList::InvertedList() {
	//TODO
}

InvertedList::~InvertedList() {
	//TODO
}
/*
* Função insert	
* recebe uma lista de palavras e a posição desta lista e
* 
*/
void InvertedList::insert(Lista<string> words, int index) {
	if(words.estaVazia()) {
		return;
	}
	wordOccurrences newOccurrence;
	newOccurrence.word = words.retira(); 
	newOccurrence.occurrences.adiciona(index);
	if(occurrences.posicao(newOccurrence) == -1) {
		occurrences.adicionaEmOrdem(newOccurrence);
	}
	wordOccurrences occAux = occurrences.pegar(occurrences.posicao(newOccurrence));
	occAux.occurrences.adiciona(index);
	insert(words, index);	
}