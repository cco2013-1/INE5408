#include <iostream>
#include <string>
#include <stdio.h>
#include "Lista.hpp"

#define PATH_TO_MANPAGES "ManPages/"

using namespace std;

Lista<string> listManPages();
Lista<string> tokenizer(string str, string sep);
string exec(char* cmd);
Lista<string> tokenizer(char text[], char limiters[]);
// Lista<string> tokenizer(string text, string limiters);

char limiters[] = {' ', '-', '/','.'};

int main() {
    Lista<string> ls = tokenizer("Antonio Vinicius Gomes Teixeira", limiters); //listManPages();
    for (int i = 0; i < ls.tamanho(); i++) {
        cout << i << " : " << ls.elementoNaPosicao(i) << endl;
    }
    return 0;
}

/**
 * Função listManPages
 * Executa comando `ls` e retorna uma lista com os resultados
 * utilizado para
 */
Lista<string> listManPages() {
    string cmd = string("ls ") + string(PATH_TO_MANPAGES);
    string ls = exec((char *)cmd.c_str());
    return tokenizer((char *)ls.c_str(), "\n");
}

/**
 * @see http://stackoverflow.com/questions/478898/how-to-execute-a-command-and-get-output-of-command-within-c
 */
string exec(char* cmd) {
    FILE* pipe = popen(cmd, "r");
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

// Lista<string> tokenizer(string text, string limiters) {
//     Lista<string> tokens;
//     string str = text;

//     while(true) {
//         size_t found = str.find_first_of(limiters);
//         string token = str.substr(0, found);
//         cout << token << endl;
//         tokens.adiciona(token);
//         str = str.substr(found + 1, string::npos);
//         if (found == string::npos) {
//             break;
//         }
//     }
//     return tokens;
// }
