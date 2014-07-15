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
 * InvertedList.cpp
 */

#include "InvertedList.h"

using namespace std;

/**
 * Construtor InvertedList
 * Lê o arquivo de conjunções
 */
InvertedList::InvertedList() {
    conjunctions = readConjunctions();
}

/**
 * Destrutor ~InvertedList
 */
InvertedList::~InvertedList() {
}

/**
 * Método proccess
 * Recebe uma lista contendo as palavras de um texto e
 * o índice deste texto.
 * Processa o texto, filtrando conjunções e registrando a
 * ocorrencia das palavras.
 * @param text lista de palavras a ser processada
 * @param index índice do texto sendo processado
 */
void InvertedList::proccess(Lista<string> text, int index) {

    unordered_set<string> wordsSeenThisTime;

    for (int i = 0; i < text.tamanho(); i++) {
        string word = text.elementoNaPosicao(i);

        //if word is a conjunction, just ignore it
        unordered_set<string>::const_iterator found = conjunctions.find(word);
        if (found != conjunctions.end()) {
            continue;
        }

        //if word has already been seen in this text, ignore it
        found = wordsSeenThisTime.find(word);
        if (found != wordsSeenThisTime.end()) {
            continue;
        }

        wordsSeenThisTime.insert(word);

        //if word has already been seen, but in other text,
        //append the current text index to the occurrences of
        //this particular word
        found = words.find(word);
        if (found != words.end()) {
            int pos = occurrences.position(word);
            WordOccurrences * wo = occurrences.get(pos);
            wo->registerOccurence(index);
            continue;
        }

        //if word was not seen, add it to the list of occurrences
        words.insert(word);
        WordOccurrences * wo = new WordOccurrences(word);
        wo->registerOccurence(index);
        occurrences.add(wo);
    }
}

/**
 * Método search
 * Recebe uma lista de palavras a serem buscadas e retorna uma lista
 * de índices dos arquivos nos quais estas palavras estão contidas.
 * @param searchParams palavras a serem buscadas
 * @return lista de índices de arquivos nos quais as palavras foram
 * encontradas
 */
Lista<int> InvertedList::search(Lista<string> searchParams) {
    Lista<int> result;
    bool resultInitialized = false;

    for (int i = 0; i < searchParams.tamanho(); i++) {
        string word = searchParams.elementoNaPosicao(i);

        //Se palavra não existe no índice
        if (words.find(word) == words.end()) {
            Lista<int> emptyList;
            return emptyList;
        }

        Lista<int> partialResult = occurrences.get(occurrences.position(word))->getOccurences();

        if (!resultInitialized) {
            result = partialResult;
            resultInitialized = true;
            continue;
        }

        Lista<int> newResult;

        for (int i = 0; i < result.tamanho(); i++) {
            int occ = result.elementoNaPosicao(i);
            for (int j = 0; j < partialResult.tamanho(); j++) {
                if (partialResult.elementoNaPosicao(j) == occ) {
                    newResult.adiciona(occ);
                    break;
                }
            }
        }

        result = newResult;
    }

    return result;
}

/**
 * Método size
 * Retorna o número de palavras no índice da lista invertida
 * @return número de palavras na lista invertida
 */
int InvertedList::size() {
    return occurrences.size();
}

/**
 * Método saveToDisk
 * Salva a lista invertida em disco
 * @param filename nome do arquivo no qual a lista será salva
 */
void InvertedList::saveToDisk(string filename) {
    for (int i = 0; i < size(); i++) {
        saveElementToDisk(occurrences.get(i), filename);
    }
}

/**
 * Método searchInDisk
 * Realiza busca por chave secundária em arquivo de lista invertida salvo em disco.
 * @param searchPrams lista de palavras a serem buscadas
 * @param filename nome do arquivo contendo a lista invertida em disco
 * @return lista de inteiros contendo os índices dos arquivos
 */
Lista<int> InvertedList::searchInDisk(Lista<string> searchParams, string filename) {
    Lista<int> result;
    bool resultInitialized = false;

    for (int i = 0; i < searchParams.tamanho(); i++) {
        string word = searchParams.elementoNaPosicao(i);

        int indexOfWord = findWordInDisk(word, filename);
        //Se palavra não existe no índice
        if (indexOfWord == -1) {
            Lista<int> emptyList;
            return emptyList;
        }

        diskElement de = readElementFromDisk(indexOfWord, filename);
        Lista<int> partialResult;
        for (int i = 0; i < de.numberOfOccurrences; i++) {
            partialResult.adiciona(de.occurrences[i]);
        }

        if (!resultInitialized) {
            result = partialResult;
            resultInitialized = true;
            continue;
        }

        Lista<int> newResult;

        for (int i = 0; i < result.tamanho(); i++) {
            int occ = result.elementoNaPosicao(i);
            for (int j = 0; j < partialResult.tamanho(); j++) {
                if (partialResult.elementoNaPosicao(j) == occ) {
                    newResult.adiciona(occ);
                    break;
                }
            }
        }

        result = newResult;
    }

    return result;
}

/**
 * Método readConjunctions
 * Lê arquivo com lista de conjunções e conectores, que serão filtradas dos textos
 * e não farão parte do índice de palavras.
 * @return conjunto de palavras a serem ignoradas nos textos processados
 */
unordered_set<string> InvertedList::readConjunctions() {
    FILE *conjunctionsFile = fopen("conjunctions.txt", "r");

    unordered_set<string> result;

    if (!conjunctionsFile) {
        cout << "Não foi encontrado arquivo de conectores. Nada será filtrado." << endl;
        return result;
    }

    char line[100];

    while (true) {
        if (!fgets(line, 100, conjunctionsFile)) {
            break;
        }
        result.insert(string(line));
    }
    return result;
}

/**
 * Método saveElementToDisk
 * Grava em disco um único elemento da lista invertida, composto por uma palavra
 * e suas ocorrências.
 * @param element objeto do tipo WordOccurrences contendo a palavra e suas
 * ocorrencias
 * @param filename nome do arquivo no qual será gravado o elemento
 */
void InvertedList::saveElementToDisk(WordOccurrences *element, string filename) {
    ofstream output(filename.c_str(), ios::app | ios::binary);

    if (!output) {
        cout << "Erro ao gravar índice de palavras em disco" << endl;
        return;
    }

    diskElement de = createDiskElement(element);

    output.write((char *) &de, sizeof(struct diskElement));
    output.close();
}

/**
 * Método createDiskElement
 * Cria um struct do tipo diskElement a partir de um objeto
 * do tipo WordOccurrences.
 * @parameter wo objeto do tipo WordOccurrences
 * @return um struct correspondente ao objeto passado
 */
diskElement InvertedList::createDiskElement(WordOccurrences *wo) {
    diskElement de;

    strcpy(de.word, wo->getWord().c_str());
    Lista<int> occurrences = wo->getOccurences();
    for (int i = 0; i < occurrences.tamanho(); i++) {
        de.occurrences[i] = occurrences.elementoNaPosicao(i);
    }
    de.numberOfOccurrences = wo->getOccurences().tamanho();

    return de;
}

/**
 * Método findWordInDisk
 * Determina o índice do registro que contém uma determinada palavra.
 * Wrapper para o algoritmo de busca binária, que é responsável pela
 * pesquisa. Retorna o índice da palavra no arquivo.
 * @param word palavra a ser pesquisada no arquivo de registros
 * @param filename nome do arquivo de registros a ser pesquisado
 * @return índice do registro que contém a palavra passada
 */
int InvertedList::findWordInDisk(string word, string filename) {
    return binarySearch(0, numberOfElementsInDisk(filename) - 1, word, filename);
}

/**
 * Método binarySearch
 * Realiza uma busca binária no arquivo de registros pela palavra passada.
 * Retorna o índice do registro que contém a palavra ou -1 caso a palavra
 * não seja encontrada.
 * @param begin ponteiro para o início da região de busca no algoritmo
 * recursivo de busca
 * @param end ponteiro para o fim da região de busca no algoritmo recursivo
 * @param word palavra sendo buscada
 * @param filename nome do arquivo de registros
 * @return índidice da palavra buscada no arquivo de registros ou -1 caso
 * a palavra não seja encontrada
 */
int InvertedList::binarySearch(int begin, int end, string word, string filename) {
    if (begin > end) {
        return -1;
    }

    int average = (end - begin)/2 + begin;
    diskElement de = readElementFromDisk(average, filename);

    if (string(de.word) < word) {
        return binarySearch(average + 1, end, word, filename);
    } else if (string(de.word) > word) {
        return binarySearch(begin, average - 1, word, filename);
    } else {
        return average;
    }
}

/**
 * Método numberOfElementsInDisk
 * Verifica quantos elementos estão salvos no arquivo de registros.
 * @param filename nome do arquivo de registros
 * @return número de registros no arquivo passado
 */
int InvertedList::numberOfElementsInDisk(string filename) {
    ifstream input(filename.c_str(), ios::in | ios::binary);

    if (!input) {
        return 0;
    }

    input.seekg(0, input.end);
    return input.tellg() / sizeof(struct diskElement);
}

/**
 * Método readElementFromDisk
 * Lê um registro específico no arquivo de registros, de acordo com o
 * índice passado.
 * @param index índice do registro a ser lido
 * @param filename nome do arquivo de registros
 * @return struct diskElement contendo o registro lido
 */
diskElement InvertedList::readElementFromDisk(int index, string filename) {
    ifstream input(filename.c_str(), ios::in | ios::binary);

    if (!input) {
        cout << "Não foi possível ler arquivo de índices das palavras. ";
        cout << "Nome do arquivo fornecido: " << filename << endl;
        throw "Erro ao ler arquivo de indice de palavras";
    }

    diskElement de;

    input.seekg(streampos(index * sizeof(struct diskElement)));
    input.read((char *) &de, sizeof(struct diskElement));
    input.close();

    return de;
}
