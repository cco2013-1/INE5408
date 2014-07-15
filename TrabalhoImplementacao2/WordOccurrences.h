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
 * WordOccurrences.cpp
 */

#ifndef __word_occurences_h__
#define __word_occurences_h__

#include <string>
#include "Lista.hpp"

using namespace std;

/**
 * Classe WordOccurrences
 * Estrutura utilizada para encapsular uma palavra e uma lista
 * de índices de arquivos onde esta palavra ocorre.
 */
class WordOccurrences {
public:
    WordOccurrences();
    WordOccurrences(string w);
    ~WordOccurrences();
    void registerOccurence(int index);
    Lista<int> getOccurences();
    string getWord();

    bool operator<(const WordOccurrences& rhs) const {
       if (word.compare(rhs.word) < 0) return true;
       return false;
    }

    bool operator>(const WordOccurrences& rhs) const {
       if (word.compare(rhs.word) > 0) return true;
       return false;
    }

    bool operator==(const WordOccurrences& rhs) const {
       if(word.compare(rhs.word) == 0) return true;
       return false;
    }

private:
    string word;
    Lista<int> occurrences;
};

#endif
