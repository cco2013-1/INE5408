/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 05 - Trabalho de Sistema de Contabilidade Mafioso
 * com Lista Encadeada Simples
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * Trabalho03.cpp
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "ListaContabil.h"
#include <sstream>
#include <cstring>

using namespace std;

string listaAtualTexto = "Débitos";
char opcao;
string mensagem = "";
ListaContabil listaCredito = ListaContabil();
ListaContabil listaDebito = ListaContabil();
ListaContabil *listaAtual = &listaDebito;

void listarTransacoes() {
    if (listaAtual->estaVazia()) {
        printf("Lista vazia! Impossível imprimir\n");
        return;
    }
    for (int i = 0; i < listaAtual->tamanho(); i++) {
        printf("(%i) %s %.2f\n", i, listaAtual->elementoNaPosicao(i)->nome(),
                listaAtual->elementoNaPosicao(i)->valor());
    }
}

void removerTransacoes() {
    string input = "";
    bool sair = false;
    int valor;
    while (!sair) {
        printf("Menu remover:\n\n"
                "(t) Remover todas as transações\n"
                "(r) Remover transação específica\n"
                "(s) Sair\n"
                "\nLista atual: %s \n", listaAtualTexto.c_str());
        listarTransacoes();
        opcao = getchar();
        getchar();
        switch (opcao) {
        case 't':
            listaAtual->~ListaContabil();
            printf("Lista destruída!");
           sair = true;
            break;
        case 'r':
            while (true) {
                printf("Entre com o número do lançamento:\n");
                getline(cin, input);
                stringstream myStream(input);
                if (myStream >> valor)
                    if (valor >= 0 && valor <= listaAtual->tamanho())
                        break;
                printf(
                        "Número inválido... Entre com um"
                                " número válido, inteiro, maior ou igual a 0 e menor ou igual a %i !\n",
                        listaAtual->tamanho());
            }
            try{
                listaAtual->retiraDaPosicao(valor);
                printf("Lancamento removido com sucesso!\n");
            }
            catch(int erro) {
                printf("Se você chegou aqui o progamador é um burro!");
            }


            sair = true;
            break;
        case 's':
            printf(
                    "Você saiu do menu de remoção.");
            sair = true;
            break;
        default:
            printf("Opção inválida");
        }
    }
}

void lancarTran() {
    string nome = "";
    double valor;
    string input = "";

    printf("Entre com o nome do lançamento:\n");
    getline(cin, nome);
    while (true) {

        printf("Entre com o valor do lançamento:\n");
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> valor)
            if (valor > 0)
                break;

        printf("Número inválido... Entre com um"
                " número válido, real, maior ou igual a 0 !\n");

    }
   /*
   ATENCAO: Voce tem que garantir que o char * recebido do string nome
   tem que ser tratado no construtor do lançamento para ocupar o menor
   espaço em memoria possivel. Isso vale 1 ponto na nota do trabalho!
   */
    Lancamento *lan;
    lan = new Lancamento((char *)nome.c_str(), valor);
    try {
        listaAtual->adiciona(lan);
        printf("Lancamento adicionado com sucesso!");
    } catch (int erro){
        printf("Impossível adicionar nova transação! Erro de lista cheia!");
    }
}

void mostraSaldo() {
    double tCredito = 0;
    double tDebito = 0;

    for (int i = 0; i < listaCredito.tamanho(); i++) {
        tCredito += listaCredito.verTransacao(i)->valor();
    }
    for (int i = 0; i < listaDebito.tamanho(); i++) {
        tDebito += listaDebito.verTransacao(i)->valor();
    }

    printf("\nTotal (Créditos - Débitos): \n     %.2f", tCredito - tDebito);
}
int main() {
    bool sair = false;

    while (!sair) {

        printf("\n Menu:\n"
                "(c) Seleciona Lista de Créditos\n"
                "(d) Seleciona Lista de Débitos\n"
                "(l) Lançar Transação\n"
                "(t) Listar Transações\n"
                "(r) Remover Transações\n"
                "(s) Mostar Saldo (total créditos - total de débitos)\n"
                "(q) Sair do Programa\n"
                "\nLista atual: %s \n%s", listaAtualTexto.c_str(),
                mensagem.c_str());

        opcao = getchar();
        getchar();
        switch (opcao) {
        case 'c':
            mensagem = "";
            listaAtualTexto = "Créditos";
            listaAtual = &listaCredito;
            break;
        case 'd':
            mensagem = "";
            listaAtualTexto = "Débitos";
            listaAtual = &listaDebito;
            break;
        case 'l':
            mensagem = "";
            lancarTran();
            break;
        case 't':
            listarTransacoes();
            break;
        case 'r':
            removerTransacoes();
            break;
        case 's':
            mostraSaldo();
            break;
        case 'q':
            sair = true;
            break;
        default:
            mensagem = "\nOpção inválida selecione uma"
                    " das opções listadas acima!";
        }
    }
}
