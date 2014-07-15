/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho de Implementação 2 - Pesquisa de ManPages
 *
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * InvertedList.h
 */

#ifndef __InvertedList_h__
#define __InvertedList_h__

#include <string.h>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include "Lista.hpp"
#include "ListOfOccurrences.h"
#include "WordOccurrences.h"

using namespace std;

/**
 * struct diskElement
 * Estrutura utilizada para representar em disco objetos do
 * tipo WordOccurrence.
 */
struct diskElement {
    char word[65];
    int occurrences[5642];
    int numberOfOccurrences;
};

/**
 * Classe InvertedList
 * Representa uma lista invertida de ocorrencia de palavras,
 * possibilitando busca por chave secundária. A lista deve
 * ser montada em memória podendo posteriormente ser salva
 * e consultada em disco.
 */
class InvertedList {
public:
    InvertedList();
    ~InvertedList();
    void proccess(Lista<string> text, int index);
    Lista<int> search(Lista<string> searchParams);
    int size();
    void saveToDisk(string filename);
    Lista<int> searchInDisk(Lista<string> searchParams, string filename);

private:
    ListOfOccurrences occurrences;
    unordered_set<string> words;
    unordered_set<string> conjunctions;
    unordered_set<string> readConjunctions();
    diskElement createDiskElement(WordOccurrences *wo);
    void saveElementToDisk(WordOccurrences *element, string filename);
    int findWordInDisk(string word, string filename);
    int binarySearch(int begin, int end, string word, string filename);
    int numberOfElementsInDisk(string filename);
    diskElement readElementFromDisk(int index, string filename);
};

#endif
