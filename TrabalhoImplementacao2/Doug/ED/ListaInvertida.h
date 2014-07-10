#ifndef LISTAINVERTIDA_H
#define LISTAINVERTIDA_H

#include <string>
#include <cstring>

struct Palavra{
	// Palavra(std::string _chave, short indexInicial){
	// 	strcpy(chave, _chave.c_str());
	// 	indexes[0] = indexInicial;
	// }
	char chave[50];
	short indexes[6000];
};

class CabecaDeLista{
public:
	CabecaDeLista(Palavra _palavra);

	Palavra palavra;
	CabecaDeLista* prox;
	int ocorrencias;
};


class ListaInvertida{
public:
	ListaInvertida();
	void add(std::string chave, short index);
	CabecaDeLista* procura(std::string chave);

	CabecaDeLista* iterator;
	CabecaDeLista* next();
	void resetaIterator();
	CabecaDeLista* inicio;
	CabecaDeLista* ultima;
	int numeroDeChaves;
private:
	bool contemIndex(int index, Palavra palavra);
};

#endif