/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho de Implementação 1 - Simulação de Supermercado
 *
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * SuperMercado.cpp
 */

#include "SuperMercado.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define HORAS_TRABALHO_MES 180
#define FILA_MAXIMA 10
#define ARQUIVO_CONFIGURACOES "parametros.config"

using namespace std;

SuperMercado::SuperMercado() {
    caixas = new ListaCaixa();
    obterParametrosSimulacao();
    ga = new GeradorAleatorio();
    horario = 0;
    varianciaChegadaNovoCliente = (int)(tempoMedioChegadaNovoCliente / 4.);
    horarioChegadaProximoCliente = (int) ga->obtemDoubleDeDistribuicaoNormal(tempoMedioChegadaNovoCliente, varianciaChegadaNovoCliente);
}

SuperMercado::~SuperMercado() {
    delete caixas;
}

/**
 * Método simular
 * Roda a simulação do supermercado com os parâmetros fornecidos e
 * mostra o relatório da simulação
 */
void SuperMercado::simular() {
    while (horario < horarioTerminoSimulacao) {
        printf("\rhorario: %d\t Horario de Chegada do próximo cliente: %d", horario, horarioChegadaProximoCliente);
        if (horario == horarioChegadaProximoCliente) {
            Cliente *c = new Cliente(horario);
            if (!encontrarCaixa(c)) {
                numeroClientesDesistiram += 1;
                valorComprasClientesDesistiram += c->valorCompras();
            }
            horarioChegadaProximoCliente = horario +
                (int) ga->obtemDoubleDeDistribuicaoNormal(tempoMedioChegadaNovoCliente,
                        varianciaChegadaNovoCliente);
        }

        while (true) {
            Caixa *cx = caixas->proximoCaixa();
            cx->atendeCliente(horario);

            if (caixas->estaNoInicio()) {
                break;
            }
        }

        horario += 1;
    }
    apresentarRelatorio();
}

/**
 * Método obterParametrosSimulacao
 * Lê os parâmetros definidos no arquivo ARQUIVO_CONFIGURACOES
 * e inicializa as variáveis do SuperMercado de acordo com eses parametros.
 */
void SuperMercado::obterParametrosSimulacao() {
    FILE * pArquivoConfig = fopen(ARQUIVO_CONFIGURACOES, "r");
    if (pArquivoConfig == NULL) {
        cout << "Erro ao ler arquivo de configurações." << endl;
        cout << "Encerrando programa" << endl;
        exit(EXIT_FAILURE);
    }
    char linha[100];
    int linhasProcessadas = 0;
    int caixasProcessados = 0;
    while (true) {
        if(fgets(linha, 100, pArquivoConfig) == NULL) {
            break;
        }
        if (linha[0] == '#' || linha[0] == ' ' || linha[0] == '\n') {
            continue;
        }
        switch (linhasProcessadas) {
        case 0:
            nome = string(linha);
            break;
        case 1:
            horasSimulacao = atoi(linha);
            horarioTerminoSimulacao = horasSimulacao * 60 * 60;
            break;
        case 2:
            tempoMedioChegadaNovoCliente = atoi(linha);
            break;
        case 3:
            numeroCaixas = atoi(linha);
            break;
        default:
            char nomeCaixa[50];
            int eficiencia;
            double salario;
            sscanf(linha, "%s %d %lf", nomeCaixa, &eficiencia, &salario);
            Caixa *cx = new Caixa(string(nomeCaixa), eficiencia, salario);
            caixas->adicionaCaixa(cx);
            caixasProcessados += 1;
            if (caixasProcessados == numeroCaixas) {
                break;
            }
        }
        linhasProcessadas += 1;
    }

    cout << "Nome Supermercado: " << nome << endl;
    cout << "Horas simulação: " << horasSimulacao << endl;
    cout << "Tempo médio de chegada de novo cliente: " << tempoMedioChegadaNovoCliente << endl;
    cout << "Numero de caixas: " << numeroCaixas << endl;
    while (true) {
        Caixa *cx = caixas->proximoCaixa();

        cout << "Caixa: " << cx->obtemIdentificador() << endl;

        if (caixas->estaNoInicio()) {
            break;
        }
    }

    cout << "Pressione uma tecla para iniciar a simulação" << endl;
    getchar();
}

/**
 * Método encontarCaixa
 * Encontra um caixa com menor fila ou menor número de produtos,
 * de acordo com o tipo do cliente.
 * @param c cliente para o qual se deseja encontrar um caixa
 * @return true se foi possível encontrar o caixa, false caso contrário
 */
bool SuperMercado::encontrarCaixa(Cliente *c) {
    if (caixas->caixaComMenorFila()->numeroClientesFila() >= FILA_MAXIMA) {
        return false;
    }
    if (c->obtemTipoCliente() == MENOR_FILA) {
        caixas->caixaComMenorFila()->adicionaCliente(c);
    } else {
        caixas->caixaComMenosProdutos()->adicionaCliente(c);
    }
    return true;
}

/**
 * Método calcularDados
 * Calcula o faturamento total, faturamento médio e tempo médio de
 * permanencia na fila.
 */
void SuperMercado::calcularDados() {
    faturamentoTotal = 0;
    int totalClientesAtendidos = 0;
    int tempoTotalPermanenciaFila = 0;
    while (true) {
        Caixa *cx = caixas->proximoCaixa();

        faturamentoTotal += cx->obtemFaturamento();
        totalClientesAtendidos += cx->numeroClientesAtendidos();
        tempoTotalPermanenciaFila += cx->tempoPermanenciaFila();

        if (caixas->estaNoInicio()) {
            break;
        }
    }
    faturamentoMedio = faturamentoTotal/caixas->tamanho();
    tempoMedioPermanenciaFila = tempoTotalPermanenciaFila/totalClientesAtendidos;
}

/**
 * Método apresentarRelatorio
 * Apresenta o relatório com os dados da simulação
 */
void SuperMercado::apresentarRelatorio() {
    calcularDados();
    cout << endl << endl;
    cout << "Supermercado " << nome << endl;
    cout << "Simulação de operação" << endl;
    cout << "================================================================================" << endl;
    printf("Faturamento Total: R$ %.2f\n", faturamentoTotal);
    printf("Faturamento médio por caixa: R$ %.2f\n", faturamentoMedio);
    cout << "================================================================================" << endl;

    while (true) {
        Caixa *cx = caixas->proximoCaixa();

        cout << "Caixa: " << cx->obtemIdentificador() << endl;
        printf("Faturamento: R$ %.2f\n", cx->obtemFaturamento() );
        printf("Faturamento Líquido: R$ %.2f\n", cx->obtemFaturamento() -
            cx->obtemSalario() / double(HORAS_TRABALHO_MES) * horasSimulacao);
        cout << "================================================================================" << endl;

        if (caixas->estaNoInicio()) {
            break;
        }
    }

    cout << "Tempo médio de permência em fila: " << tempoMedioPermanenciaFila << endl;
    cout << "Número de clientes que desistiram: " << numeroClientesDesistiram << endl;
    printf("Faturamento que deixou de ser realizado: R$ %.2f\n", valorComprasClientesDesistiram);
}

