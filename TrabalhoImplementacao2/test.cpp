#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#define FILE_NAME "manpages.dat"
#define ERRO_ABRIR_ARQUIVO -1;

#include "AVLTree.h"
#include "BSTree.h"
#include "Lista.hpp"

using namespace std;

struct manPage {
    char comando[100];
    char conteudo[140000];
    int leftChild;
    int rightChild;
    int parent;
    int height;
};

void processManPageFile(char *filename);
manPage readRecord(int recordIndex);
void writeRecord(manPage mp, int index = -1);
void readManPageFile(const char *filename, char * conteudo);
string getFilename (const string& str);
string getString();
int getInt();
int getNumberOfRecords();
string exec(char* cmd);
void imprimeArvore(node * n);

Lista<string> tokenizer(char text[], char limiters[]){
    Lista<string> words;
    char *word = strtok(text, limiters);
    for(int i = 0; word; i++) {
        words.adiciona(string(word));
        word = strtok(NULL, limiters);
    }
    return words;
}

int main() {

    BSTree *tree = new AVLTree();

    char mussuzins[500] = "Mussum ipsum cacilds, vidis litro abertis. Consetis adipiscings elitis. Pra lá , depois divoltis porris, paradis. Paisis, filhis, espiritis santis. Mé faiz elementum girarzis, nisi eros vermeio, in elementis mé pra quem é amistosis quis leo. Manduma pindureta quium dia nois paga. Sapien in monti palavris qui num significa nadis i pareci latim. Interessantiss quisso pudia ce receita de bolis, mais bolis eu num gostis.";

    Lista<string> palavras = tokenizer(mussuzins, " ");

    cout << "numero de palavras " << palavras.tamanho() << endl;
    for (int i = 0; i < palavras.tamanho(); i++) {
        tree->insert(palavras.elementoNaPosicao(i), string(mussuzins));
    }

    tree->resolveDiskIndices(tree->getRoot());

    diskNode dn = tree->createDiskNode(tree->getRoot()->leftChild);

    cout << "key " << dn.key << endl;
    cout << "value " << dn.value << endl;
    cout << "parent " << dn.parent << endl;
    cout << "leftChild " << dn.leftChild << endl;
    cout << "rightChild " << dn.rightChild << endl;



    // string ls = exec("ls ManPages");
    // cout << "ls result:" << endl;
    // cout << ls << endl;

    // while (true) {
    //     cout << "insira arquivo a processar" << endl;
    //     string fileToProcess = getString();
    //     if (fileToProcess == "") {
    //         break;
    //     }
    //     processManPageFile((char *)fileToProcess.c_str());
    // }


    // int numRecords = getNumberOfRecords();

    // cout << "Número de manPages: " << numRecords;

    // while (true) {
    //     cout << "Insira num registro a mostrar. -1 para sair" << endl;
    //     int index = getInt();
    //     if (index < 0) {
    //         break;
    //     }

    //     manPage mp = readRecord(index);
    //     cout << "comando " << mp.comando << endl;
    //     cout << "conteudo:" << endl;
    //     cout << mp.conteudo << endl;
    // }



    return 0;
}

void imprimeArvore(node * n) {
    cout << "key: " << n->key << "\tdiskIndex: " << n->diskIndex << endl;
    if (n->leftChild) {
        imprimeArvore(n->leftChild);
    } else {
        cout << "null" << endl;
    }
    if (n->rightChild) {
        imprimeArvore(n->rightChild);
    } else {
        cout << "null" << endl;
    }
}

int getNumberOfRecords() {
    ifstream input(FILE_NAME, ios::in | ios::binary);

    if (!input) {
        cout << "Não existe arquivo de registros" << endl;
    }

    input.seekg(0, input.end);
    int lenght = input.tellg();
    return lenght/(sizeof(struct manPage));
}

void processManPageFile(char *filename) {

    manPage mp;
    string comando = string(filename);
    comando = comando.substr(0, comando.find_last_of("."));
    char conteudo[140000];

    readManPageFile(filename, conteudo);
    strcpy(mp.comando, comando.c_str());
    strcpy(mp.conteudo, conteudo);
    mp.leftChild = 0;
    mp.rightChild = 0;
    mp.parent = 0;
    mp.height = 0;

    writeRecord(mp);
}

void writeRecord(manPage mp, int index) {
    ofstream output(FILE_NAME, ios::app | ios::binary);

    if (!output) {
        cout << "Erro ao abrir arquivo." << endl;
        return;
    }

    if (index != -1) {
        output.seekp(streampos(index * sizeof(struct manPage)));
    }

    output.write((char *) &mp, sizeof(struct manPage));
    output.close();
}

manPage readRecord(int recordIndex) {
    ifstream input(FILE_NAME, ios::in | ios::binary);

    if (!input) {
        cout << "Erro ao abrir arquivo" << endl;
        throw ERRO_ABRIR_ARQUIVO;
    }

    input.seekg(streampos(recordIndex * sizeof(struct manPage)));

    manPage mp;
    input.read((char *) &mp, sizeof(struct manPage));
    input.close();

    return mp;
}

/**
 * @see http://stackoverflow.com/questions/3747086/reading-the-whole-text-file-into-a-char-array-in-c
 */
void readManPageFile(const char *filename, char * conteudo){
    string completeFilename = "ManPages/" + string(filename);

    FILE *fp;
    long lSize;
    char *buffer;

    fp = fopen ( completeFilename.c_str(), "rb" );
    if( !fp ) {
        cout << "Erro ao abrir arquivo" << endl;
    }

    fseek( fp , 0L , SEEK_END);
    lSize = ftell( fp );
    rewind( fp );

    /* allocate memory for entire content */
    buffer = new char[lSize + 1];
    if (!buffer){
        fclose(fp),fputs("memory alloc fails",stderr),exit(1);
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

string getFilename (const string& str) {
  unsigned found = str.find_last_of("/\\");
  return str.substr(found+1);
}

string getString() {
    string input = "";
    getline(cin, input);
    return input;
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
