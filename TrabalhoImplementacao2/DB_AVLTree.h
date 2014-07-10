/*
 * @author max
 */

#ifndef __db_avl_tree_h__
#define __db_avl_tree_h__

#include <iostream> //cout
#include <fstream> //fstream
#include <cstring> //strcpy

#define NULL_RECORD_INDEX -1

using namespace std;

struct manPage {
    char comando[100];
    char conteudo[140000];
    int leftChild;
    int rightChild;
    int parent;
    int height;
};

class DB_AVLTree {
public:
    DB_AVLTree();
    ~DB_AVLTree();
    void insert(char * comando, char * conteudo);
    void remove(char * comando);
    int getSize();
    int minimum();
    int maximum();
    int successor(int manPageIndex);
    int predecessor(int manPageIndex);

private:
    int root;
    int size;
    manPage createManPage(char * comando, char * conteudo);
    void insert(manPage newManPage);
    void rebalance(int manPageIndex);
    bool balanced(int manPageIndex);
    void rotateRight(int manPageIndex);
    void rotateLeft(int manPageIndex);
    int height(int manPageIndex);
    int minimum(int manPageIndex);
    int maximum(int manPageIndex);
    void transplant(int manPageIndex_u, int manPageIndex_v);
    manPage readRecord(int recordIndex);
    void writeRecord(manPage mp, int index);
};

void escreve(const char * filename) {
  ofstream output(filename,
          //ios::out //abre arquivo para escrita.
          ios::app //abre arquivo para escrita, adicionando ao fim do arquivo (append).
          | ios::binary //arquivo binario.
         );
  if (!output) {
    cout << " -> Erro ao abrir arquivo." << endl;
    return;
  }

  MyRecord mr;
  strcpy(mr.nome, "AAA");
  mr.salario = 4000;
  mr.teste = 101;

  output.write((char *) &mr, sizeof(struct MyRecord));

  output.close();
}

void le(const char * filename) {
  ifstream input(filename,
         ios::in //abre arquivo para leitura.
         | ios::binary //arquivo binario.
        );
  if(!input) {
    cout << " -> Erro ao abrir arquivo." << endl;
    return;
  }

  MyRecord mr;
  input.read((char *) &mr, sizeof(struct MyRecord));
  input.close();

  cout << "Nome: " << mr.nome << endl;
  cout.precision(2);
  cout.setf(ios::fixed);
  cout << "Salario: " << mr.salario << endl;
  cout << "Teste: " << mr.teste << endl;
}

int main() {
  const char * file = "arquivo_test.txt";

  //Cria/Abre um arquivo e insere um registro no fim
  escreve(file);

  //Abre o arquivo criado e le o registro
  le(file);

  return 0;
}


#endif
