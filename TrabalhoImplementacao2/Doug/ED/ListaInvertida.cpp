#include "ListaInvertida.h"
#include <iostream>
#include <cstring>

using namespace std;

CabecaDeLista::CabecaDeLista(Palavra _palavra){
	palavra = _palavra;
	ocorrencias = 1;
	prox = 0;
}

ListaInvertida::ListaInvertida(){
	inicio = 0;
	ultima = inicio;
	numeroDeChaves = 0;
	iterator = inicio;
}

void ListaInvertida::add(std::string chave, short index){
	CabecaDeLista* aux = procura(chave);
	if(aux == 0){
		numeroDeChaves++;
		//Palavra* palavra = new Palavra(chave, index);
		Palavra palavra;
		strcpy(palavra.chave, chave.c_str());
		palavra.indexes[0] = index;
		palavra.indexes[1] = -1;
		
		CabecaDeLista* cabecaDeLista = new CabecaDeLista(palavra);	
		if(inicio == 0){
			inicio = cabecaDeLista;
		}
		if(ultima != 0){
			ultima->prox = cabecaDeLista;
		}
		ultima = cabecaDeLista;
	}else{
		if(!contemIndex(index, aux->palavra)){
			aux->palavra.indexes[aux->ocorrencias] = index;
			aux->palavra.indexes[aux->ocorrencias+1] = -1;
			aux->ocorrencias++;
		}
	}
	// delete aux;
}

bool ListaInvertida::contemIndex(int index, Palavra palavra){
	for(int i = 0; (i < sizeof(palavra.indexes) && palavra.indexes[i] != -1); i++){
		// cout << index << " - " << palavra.indexes[i] << endl;
		if(index == palavra.indexes[i]) return true;
	}
	return false;
}

CabecaDeLista* ListaInvertida::procura(std::string chave){
	CabecaDeLista* aux = inicio;
	while(aux != 0){
		
		if(aux->palavra.chave == chave) {
			//cout << aux->palavra.chave << " - " << chave << endl;
			//cout << aux->palavra.indexes[1];
			return aux;
		}
		aux = aux->prox;
	}
	delete aux;
	return 0;
}

CabecaDeLista* ListaInvertida::next(){
	CabecaDeLista* aux = iterator;
	if(iterator == 0){
		return 0;
	}
	if(iterator->prox == 0){
		iterator = 0;		
	} else {
		iterator = iterator->prox;
	}
	return aux;
}

void ListaInvertida::resetaIterator(){
	iterator = inicio;
}