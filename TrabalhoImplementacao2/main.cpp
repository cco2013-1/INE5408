#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <ctime>
#include "Lista.hpp"
#include "AVLTree.h"
#include "BSTree.h"


#define PATH_TO_MANPAGES "ManPages/"
#define MANPAGES_FILE "manpages.dat"

using namespace std;

Lista<string> listManPages();
Lista<string> tokenizer(string str, string sep);
string exec(string cmd);
Lista<string> tokenizer(char text[], char limiters[]);
void readManPageFile(string filename, char * conteudo);
void createIndices(Lista<string> manPageList);
string getString();

int main() {
    Lista<string> mpList = listManPages();
    createIndices(mpList);

    BSTree *tree = new AVLTree();
    while (true) {
        cout << "Pesquisa de manpages. Insira o nome da manpage a procurar. Vazio para sair" << endl;
        string comando = getString();
        if (comando == "") {
            break;
        }
        string result = tree->findInDisk(comando, MANPAGES_FILE);
        if (result == "") {
            cout << "comando nao encontrado" << endl;
        } else {
            cout << "comando: " << comando << endl;
            cout << "conteúdo da manpage:" << endl;
            cout << result << endl;
        }
    }

    return 0;
}

/**
 * Função listManPages
 * Executa comando `ls` e retorna uma lista com os resultados
 * utilizado para gerar lista com os arquivos de manpages a serem
 * processados
 * @return Lista contendo o título das manpages encontradas
 */
Lista<string> listManPages() {
    string cmd = string("ls ") + string(PATH_TO_MANPAGES);
    string ls = exec((char *)cmd.c_str());
    return tokenizer((char *)ls.c_str(), "\n");
}

/**
 * Função exec
 * Executa o comando passado como parâmetro na shell
 * @param comando a ser executado
 * @return stdout gerado pelo comando executado
 * @see http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c
 */
string exec(string cmd) {
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}

/**
 * Função tokenizer
 * Separa o texto passado em tokens (palavras), de acordo com os
 * separadores definidos no parametro limiters, retornando uma
 * lista com as palavras encontradas.
 * @param text o texto a ser separado em palavras
 * @param limiters os separadores que limitam as palavras
 * @return lista de strings com as palavras encontradas
 */
Lista<string> tokenizer(char text[], char limiters[]){
    Lista<string> words;
    char *word = strtok(text, limiters);
    for(int i = 0; word; i++) {
        words.adiciona(string(word));
        word = strtok(NULL, limiters);
    }
    return words;
}

void createIndices(Lista<string> manPageList) {
    ifstream input(MANPAGES_FILE, ios::in | ios::binary);

    if (!input) {
        cout << "Arquivo de registro de manpages não encontrado." << endl;
        cout << "Realizando leitura dos arquivos e criando arquivo de registros " << MANPAGES_FILE << endl;

        BSTree *tree = new AVLTree();
        for (int i = 0; i < manPageList.tamanho(); i++) {
            char conteudo[140000];
            string filename = manPageList.elementoNaPosicao(i);
            readManPageFile(filename, conteudo);
            string comando = filename.substr(0, filename.find_last_of("."));
            tree->insert(comando, string(conteudo));
        }

        clock_t begin = clock();
        tree->saveToDisk(MANPAGES_FILE);
        clock_t end = clock();

        double elapsedSecs = double(end - begin) / CLOCKS_PER_SEC;

        cout << "Tempo necessário para salvar árvore de busca em disco: " << elapsedSecs << " s" << endl;
    }

    input.close();
}

/**
 * Função readManPageFile
 * Dado um nome de arquivo de manpage, esta função lê o seu conteúdo
 * e o escreve no parametro conteudo.
 * @param filename o nome do arquivo a ser lido
 * @param conteudo local onde será escrito o conteúdo do mapage lido
 * @see http://stackoverflow.com/questions/3747086/reading-the-whole-text-file-into-a-char-array-in-c
 */
void readManPageFile(string filename, char * conteudo) {
    string completeFilename = "ManPages/" + filename;

    FILE *fp;
    long lSize;
    char *buffer;

    fp = fopen (completeFilename.c_str(), "rb");
    if(!fp) {
        cout << "Erro ao abrir arquivo" << endl;
    }

    fseek(fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind(fp);

    /* allocate memory for entire content */
    buffer = new char[lSize + 1];
    if (!buffer){
        fclose(fp);
        fputs("memory alloc fails",stderr);
        exit(1);
    }

    /* copy the file into the buffer */
    if (!fread(buffer, lSize, 1, fp)) {
        fclose(fp);
        free(buffer);
        fputs("entire read fails",stderr);
        exit(1);
    }
    fclose(fp);

    strcpy(conteudo, buffer);

    free(buffer);
}

int getInt() {
    string input = "";
    int inteiro = 0;

    while (true) {
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> inteiro) {
            break;
        }
        cout << "Formato inválido. Insira um inteiro" << endl;
    }

    return inteiro;
}

string getString() {
    string input = "";
    getline(cin, input);
    return input;
}
