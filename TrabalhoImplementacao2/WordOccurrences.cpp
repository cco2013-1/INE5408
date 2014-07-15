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

#include "WordOccurrences.h"

/**
 * Construtor WordOccurrences
 */
WordOccurrences::WordOccurrences() {
}

/**
 * Construtor WordOccurrences
 * Recebe a palavras para a qual serão registras as ocorrências
 */
WordOccurrences::WordOccurrences(string w) {
    word = w;
}

/**
 * Destrutor ~WordOccurrences
 */
WordOccurrences::~WordOccurrences() {

}

/**
 * Método registerOccurrences
 * Registra a ocorrência informada pelo indice index na lista
 * de ocorrencias da palavra.
 * @param index índice da ocorrencia que se deseja registrar
 */
void WordOccurrences::registerOccurence(int index) {
    occurrences.adiciona(index);
}

/**
 * Método getOccurrences
 * Retorna a lista de ocorrências da palavra
 * @return lista de ocorrências da palavra
 */
Lista<int> WordOccurrences::getOccurences() {
    return occurrences;
}

/**
 * Método getWord
 * Retorna a palavra que o objeto atual representa
 * @return palavra que o objeto atual representa
 */
string WordOccurrences::getWord() {
    return word;
}
