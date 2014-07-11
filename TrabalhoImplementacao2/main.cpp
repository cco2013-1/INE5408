#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Lista.hpp"

#define PATH_TO_MANPAGES "ManPages/"

using namespace std;

Lista<string> listManPages();
Lista<string> tokenizer(string str, string sep);
string exec(string cmd);
Lista<string> tokenizer(char text[], char limiters[]);
void readManPageFile(string filename, char * conteudo);

int main() {
    Lista<string> ls = listManPages();
    for (int i = 0; i < ls.tamanho(); i++) {
        cout << i << " : " << ls.elementoNaPosicao(i) << endl;
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

Lista<string> tokenizer(char text[], char limiters[]){
    Lista<string> words;
    char *word = strtok(text, limiters);
    for(int i = 0; word; i++) {
        words.adiciona(string(word));
        word = strtok(NULL, limiters);
    }
    return words;
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
