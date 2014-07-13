#include "InvertedList.h"
#include "Lista.hpp"
#include "SortedList.hpp"

using namespace std;

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
	newOccurrence.word = words.retira(); 
	newOccurrence.occurrences.add(index);
	if(occurrences.isEmpty()) {
		occurrences.add(newOccurrence);
		insert(words, index);
	}
	if(occurrences.position(newOccurrence) == -1) {
		occurrences.add(newOccurrence);
		insert(words, index);
	}

	wordOccurrences occAux = occurrences.getInPosition(occurrences.position(newOccurrence));
	occAux.occurrences.add(index);
	insert(words, index);	
}

/*
*Funcao search
*recebe uma lista de palavras e retorna uma lista com as posições do texto na qual elas
*estão contidas.
*/
Lista<int> InvertedList::search(Lista<string> word) {
	//TODO
}

Lista<string> InvertedList::get() {
	int size = occurrences.size();
	Lista<string> lista;
	for(int i =0; i< size; i++) {
		lista.adiciona(occurrences.get().word);
	}
	return lista;
}

int InvertedList::size() {
	return occurrences.size();
}