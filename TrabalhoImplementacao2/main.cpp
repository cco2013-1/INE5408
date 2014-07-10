#include <iostream>
#include <string>
#include "Lista.hpp"

#define PATH_TO_MANPAGES "ManPages/"

using namespace std;

Lista<string> listManPages();
Lista<string> tokenizer(string str, string sep);
string exec(char* cmd);

int main() {
    Lista<string> tokens = tokenizer("Antonio Vinicius Gomes Teixeira", " ");
    for (int i = 0; i < tokens.tamanho(); i++) {
        cout << "elem " << i << " " << tokens.elementoNaPosicao(i) << endl;
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

    while (ls != "") {
        // string token =
    }
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

Lista<string> tokenizer(string str, string sep) {
    Lista<string> tokens;
    string token;
    while (str != "") {
        unsigned found = str.find_first_of(sep);
        token = str.substr(found);
        tokens.adiciona(token);
        str = str.substr(found, string::npos);
    }
    return tokens;
}
