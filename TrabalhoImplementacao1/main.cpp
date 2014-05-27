#include <iostream>
#include <string>
#include <sstream>
#include "SuperMercado.h"
#include "ListaCaixa.h"
#include "Caixa.h"

using namespace std;

void run();
void mostraOpcoes();
int obterOpcao();
int obterInteiro();
double obterDouble();
string obterString();
SuperMercado * obterDadosECriarSuperMercado();

int main() {
    run();
}

void run() {
    mostraOpcoes();
    int opcao = obterOpcao();
    SuperMercado *sm = NULL;

    switch(opcao) {
        case 1:
            sm = new SuperMercado();
            sm->simular();
            run();
            break;
        case 2:
            sm = obterDadosECriarSuperMercado();
            sm->simular();
            run();
            break;
        default:
            exit(0);
    }
}

void mostraOpcoes() {
    cout << "Bem vindo ao Simulador de SuperMercados" << endl;
    cout << "Para simular com arquivo de configurações digite 1" << endl;
    cout << "Para simular com entrada explícita de dados digite 2" << endl;
    cout << "Para sair, insira qualquer outro valor" << endl;
}

int obterOpcao() {
    int opt = 0;
    opt = obterInteiro();
    return opt;
}

int obterInteiro() {
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

double obterDouble() {
    string input = "";
    double valor = 0;

    while (true) {
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> valor && valor > 0) {
            break;
        }
        cout << "Formato inválido. Insira um valor válido" << endl;
    }
    return valor;
}

string obterString() {
    string input = "";
    getline(cin, input);
    return input;
}

SuperMercado * obterDadosECriarSuperMercado() {
    string nomeSuperMercado;
    int horasSimulacao;
    int tempoEntreChegadaClientes;
    int numeroCaixas;
    ListaCaixa *lc = new ListaCaixa();

    cout << "Insira o nome do SuperMercado" << endl;
    nomeSuperMercado = obterString();
    cout << "Insira o número de horas de simulação" << endl;
    horasSimulacao = obterInteiro();
    cout << "Insira o tempo médio de chegada de novos clientes, em segundos" << endl;
    tempoEntreChegadaClientes = obterInteiro();
    cout << "Insira o número de caixas" << endl;
    numeroCaixas = obterInteiro();

    for (int i = 0; i < numeroCaixas; i++) {
        string identificadorCaixa;
        int eficiencia;
        double salario;

        cout << "Insira o identificador do caixa " << i + 1 << endl;
        identificadorCaixa = obterString();
        cout << "Insira a eficiencia do caixa " << i + 1 << " com 1 para eficiente, 2 para médio e 3 para ineficiente" << endl;
        eficiencia = obterInteiro();
        if (eficiencia < 1 || eficiencia > 3) {
            eficiencia = 2;
        }
        cout << "Insira o salário do caixa " << i + 1 << endl;
        salario = obterDouble();

        Caixa *cx = new Caixa(identificadorCaixa, eficiencia, salario);
        lc->adicionaCaixa(cx);
    }

    return new SuperMercado(nomeSuperMercado, horasSimulacao,
        tempoEntreChegadaClientes, lc);
}
