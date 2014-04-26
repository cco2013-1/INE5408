/*
main para testar os métodos da Lista
*/

#include <iostream>
#include "ListaEncadeada.hpp"
#include "Elemento.hpp"

using namespace std;

int main(){
	ListaEncadeada<int> lista = ListaEncadeada<int>();
	int test = 7; 
	lista.adicionaNoInicio(test);
	cout << "lista encadeada " << lista.retiraDoInicio() << "\n";
}
