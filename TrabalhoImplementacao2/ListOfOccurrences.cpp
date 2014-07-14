#include "ListOfOccurrences.h"

ListOfOccurrences::ListOfOccurrences() {

}

ListOfOccurrences::~ListOfOccurrences() {

}

void ListOfOccurrences::add(WordOccurrences * wo) {
    int position = findPosition(wo);
    sortedList.adicionaNaPosicao(wo, position);
}

WordOccurrences * ListOfOccurrences::get(int position) {
    return sortedList.elementoNaPosicao(position);
}

/**
 * Método position
 * Wrapper para binaryFind, este método cria um falso objeto de
 * WordOccurrences a ser encontrado na lista e o procura na lista.
 * @param w palavra a ser encontrada na lista
 * @return posicao do objeto WordOcurrences na lista, para a palavra
 * fornecida
 */
int ListOfOccurrences::position(string w) {
    WordOccurrences * wo = new WordOccurrences(w);
    return binaryFind(0, size() - 1, wo);
}

/**
 * Método binaryFind
 * Este método encontra a posição em que um dado objeto está armazenado
 * na lista ordenada. Caso o objeto não seja encontrado, retorna -1.
 */
int ListOfOccurrences::binaryFind(int begin, int end, WordOccurrences *wo) {
    if (begin > end) {
        return -1;
    }

    int average = (end - begin)/2 + begin;

    if (*(sortedList.elementoNaPosicao(average)) < *wo) {
        return binaryFind(average + 1, end, wo);
    } else if (*(sortedList.elementoNaPosicao(average)) > *wo) {
        return binaryFind(begin, average - 1, wo);
    } else {
        return average;
    }
}

/**
 * Método size
 * Retorna a quantidade de palavras com ocorrencias armazenadas
 * @return quantidade de palavras com ocorrencias armazenadas
 */
int ListOfOccurrences::size() {
    return sortedList.tamanho();
}

/**
 * Método isEmpty
 * Checa se a lista de ocorrencias de palavras está vazia
 * @return verdadeiro se a lista estiver vazia, falso caso contrário
 */
bool ListOfOccurrences::isEmpty() {
    return sortedList.estaVazia();
}

/**
 * Method findPosition
 * Wrapper method for binarySearch, this method returns the
 * insertion position for a new WordOccurrences object so that
 * the order in the list is mantained.
 */
int ListOfOccurrences::findPosition(WordOccurrences * wo) {
    return binarySearch(0, size() - 1, wo);
}

/**
 * Method binarySearch
 * This method searches a position of insertion for a new WordOccurrences
 * object. It is very similar to binaryFind, but it allways returns a valid
 * position for insertion, never returning -1 or creating an error.
 */
int ListOfOccurrences::binarySearch(int begin, int end, WordOccurrences * wo) {
    if (isEmpty()) {
        return 0;
    }

    if (begin >= end) {
        if (*(sortedList.elementoNaPosicao(begin)) < *wo) {
            return ++begin;
        }
        return begin;
    }

    int average = (end - begin)/2 + begin;

    if (*(sortedList.elementoNaPosicao(average)) < *wo) {
        return binarySearch(average + 1, end, wo);
    } else if (*(sortedList.elementoNaPosicao(average)) > *wo) {
        return binarySearch(begin, average - 1, wo);
    } else {
        return average;
    }
}
