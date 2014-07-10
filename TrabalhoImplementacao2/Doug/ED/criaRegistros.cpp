#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "manpageUtils.h"
#include "ListaInvertida.h"

using namespace std;

/**
* Método responsável por contar o numero de ocorrencias de um caracter em uma string
* 
* @param texto onde será realizada a contagem
* @param caracter desejado
* @return numero de ocorrencias do caracter no texto
*/
int count(char text[], char ocurrence[]){
    int n = 0;
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == ocurrence[0]) n++;
    }
    return n;
}

/**
* Método responsavel por dividir o texto ao encontrar um determinado delimitador
*
* @param texto a ser dividido
* @param delimitador para dividir o texto
* @return texto dividido
*/
vector<char*> split(char text[], char delimiter[]){
    vector<char*> result;
    char *p = strtok(text, delimiter);
    for(int i = 0; p; i++) {
        result.insert(result.begin()+i, p);
        p = strtok(NULL, delimiter);
    }
    return result;
}

 /**
 * Método responsável por ler as manpages uma por uma e criar os registros de cada uma
 *
 * @param nome da manpage
 * @param local onde serão armazenados os registros
 */
void criaRegistros(char* filename, char* destino){
    ifstream input(filename, ios::in | ios::binary);

    /*
     * Tirar a extensão ".txt"
     * separar a string por "/" e pegar a ultima ocorrencia
     */
    string aux = filename;
    aux = aux.substr(0, aux.size()-4);
    char* comando = new char[aux.size()+1];
    copy(aux.begin(), aux.end(), comando);
    comando[aux.size()] = '\0';
    vector<char*> caminho_split = split(comando, "/");
    comando = caminho_split.at(caminho_split.size()-1);

    /*
     * Descobrir o length do conteudo da manpage
     */
    input.seekg(0, input.end);
    int length = input.tellg();
    input.seekg(0, input.beg);

    /*
     * Alocar espaço na memória e copiar o conteudo da manpage para a variavel "conteudo"
     */
    char* conteudo = new char[length];
    input.read(conteudo, length);
    
    input.close();


      // ----------------------- \\
     // Fim da leitura da manpage \\
    // --------------------------- \\


    ofstream output(destino, ios::app | ios::binary);
    if(!output){
        cout << "Erro ao abrir arquivo." << endl;
        return;
    }

    Manpage manpage;
    strcpy(manpage.comando, comando);
    strcpy(manpage.conteudo, conteudo);

    /*
     * Processo de gravação da struct (registro) em disco
     * sizeof retorna o tamanho da struct, definida pelo tamanho de seus atributos
     * nesse caso o tamanho é
     * 140000 + 100 = 140100 bytes para cada registro
     */
    output.write((char *) &manpage, sizeof(struct Manpage));
    output.close();
}

void criaIndexSecundario(char* registros, char* destino){
    ifstream input(registros, ios::in | ios::binary);
    Manpage manpage;
    ListaInvertida* lista = new ListaInvertida();
    vector<char*> palavras;
    for(int i = 0; input.read((char *) &manpage, sizeof(struct Manpage)) && i < 500; i++){
        palavras = split(manpage.conteudo, " ");
        for(int j = 0; j < palavras.size(); j++){
            lista->add(palavras.at(j), i);
        }
        cout << i << " - " << manpage.comando << " - " << palavras.size() << " - " << lista->numeroDeChaves << endl;
    }
    input.close();

    ofstream output(destino, ios::app | ios::binary);
    if(!output){
        cout << "Erro ao abrir arquivo." << endl;
        return;
    }
    
    CabecaDeLista* aux;
    Palavra p;
    lista->resetaIterator();
    while((aux = lista->next()) != 0){
        p = aux->palavra;
        output.write((char *) &p, sizeof(struct Palavra));
    }

    output.close();
}


 /**
  * Como utilizar o gerador de manpages:
  * ./meuPrograma pastaOndeEstaoAsManpages/*.txt
  * IMPORTANTE: não pode ter nenhum outro .txt na pasta que nao seja uma manpage.



    Manual: Compila, dps carrega o manpages.dat com o comando $./teste -l Manpages/*.txt.
            Para pesquisar apenas com o index use ./teste -r <index>
            Para criar a lista invertida, a partir do manpages.dat use ./teste -lis
            Para procurar na lista invertida ./teste -rr <palavra> (tem bugs)


  */
  int main(int argc, char* argv[]){
    if(argc > 1){
        string param = argv[1];
        if(param == "-l"){
            for(int i = 2; i < argc; i++){
                criaRegistros(argv[i], "manpages.dat");
            }       
        }else if(param == "-r"){
            ManpageUtils* m = new ManpageUtils();
            int index = atoi(argv[2]);
            Manpage manpage = m->leRegistros("manpages.dat", index);
            cout << manpage.comando << endl;
            cout << manpage.conteudo << endl;
        }else if(param == "-lis"){
            criaIndexSecundario("manpages.dat", "index_secundario.dat");
        }else if(param == "-rr"){
            vector<Manpage> vetor;
            ManpageUtils* m = new ManpageUtils();
            string str = argv[2];
            vetor = m->a("index_secundario.dat", str,"manpages.dat");

            for(int i = 0; i < vetor.size(); i++){
                 cout << vetor.at(i).comando << endl;
            }
        }
    }else{ 
                cout << sizeof(struct Palavra) << endl;
    }
    return 0;
}