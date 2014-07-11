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
* recebe uma lista de palavras e a posição desta lista e cria um objeto que contém uma palavra e uma lista de ocorrências
* desta palavra.
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
	occAux.occurrences.adicionaEmOrdem(index);
	insert(words, index);	
}