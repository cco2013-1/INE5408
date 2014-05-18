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
 * SuperMercado.h
 */

#ifndef __supermercado_h__
#define __supermercado_h__

#include "GeradorAleatorio.h"
#include "ListaCaixa.h"
#include "Caixa.h"
#include "Cliente.h"

/**
 * Classe SuperMercado
 * Representa o Mercado na Simulação
 */
class SuperMercado {
private:
    string nome;
    int horario;
    int horarioTerminoSimulacao;
    int horasSimulacao;
    int tempoMedioChegadaNovoCliente;
    int varianciaChegadaNovoCliente;
    int numeroCaixas;
    int horarioChegadaProximoCliente;
    GeradorAleatorio *ga;
    ListaCaixa *caixas;
    int numeroClientesDesistiram;
    double valorComprasClientesDesistiram;
    double faturamentoTotal;
    double faturamentoMedio;
    double tempoMedioPermanenciaFila;
    void obterParametrosSimulacao();
    void apresentarRelatorio();
    bool encontrarCaixa(Cliente *c);
    void calcularDados();
public:
    SuperMercado();
    ~SuperMercado();
    void simular();
};

#endif
