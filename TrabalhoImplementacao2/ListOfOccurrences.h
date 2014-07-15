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
 * ListOfOccurrences.h
 */

#include "Lista.hpp"
#include "WordOccurrences.h"

#ifndef __list_of_occurrences_h__
#define __list_of_occurrences_h__

/**
 * Classe ListOfOccurrences
 * Estrutura de dados de Lista Ordenada especializada para armazenamento
 * de objetos do tipo WordOccurrences. Utiliza estrutura de dados de lista
 * simples e garante o ordenamento na inserção. Suporta as operações de
 * inserção e consulta. A complexidade da inserção é de O(log n). A consulta
 * tem complexidade O(1) (consulta por índice). Para descobrir o índice de uma
 * palavra específica, a complexidade é O(log n).
 */
class ListOfOccurrences {
public:
    ListOfOccurrences();
    ~ListOfOccurrences();
    void add(WordOccurrences * wo);
    WordOccurrences * get(int position);
    int position(string w);
    int size();
    bool isEmpty();
private:
    Lista<WordOccurrences *> sortedList;
    int findPosition(WordOccurrences * wo);
    int binarySearch(int begin, int end, WordOccurrences * wo);
    int binaryFind(int begin, int end, WordOccurrences * wo);
};

#endif
