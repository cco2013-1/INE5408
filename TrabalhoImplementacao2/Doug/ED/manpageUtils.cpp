#include <fstream>
#include "manpageUtils.h"
#include "ListaInvertida.h"
#include <iostream>

using namespace std;

Manpage ManpageUtils::leRegistros(char* registros, int index){
    ifstream input(registros, ios::in | ios::binary);

    Manpage manpage;
    input.seekg(sizeof(struct Manpage)*index);
    input.read((char *) &manpage, sizeof(struct Manpage));
    input.close();

    return manpage;
}

vector<Manpage> ManpageUtils::a(char* indexes, string palavra, char* registros){
	
	ifstream input(indexes, ios::in | ios::binary);

	Palavra p;
	int index = 0;
	bool achou = false;
	
	while(input.read((char *) &p, sizeof(struct Palavra))){
		//cout << p.chave << endl;
		if(p.chave == palavra){
			//cout << p.chave << endl;
			achou = true;
			break;
		}

	}

	// while(!achou){

	// 	// input.seekg(sizeof(struct Palavra)*index);
	//    	input.read((char *) &p, sizeof(struct Palavra));
	   	
	//    	cout << p.chave << " - " << palavra << " - " << sizeof(struct Palavra) <<endl;		
	// 	if(p.chave == palavra){
	// 		achou = true;
	// 	}
	// 	index++;
	// // }
	input.close();
	vector<Manpage> vetor;

	for(int i = 0; i < sizeof(p.indexes)/sizeof(p.indexes[0]); i++){
		//cout << p.indexes[i] << endl;
		if(p.indexes[i] == -1){
			break;
		}
	 	vetor.insert(vetor.begin()+i, leRegistros(registros,p.indexes[i]));
	}
	return vetor;
}


