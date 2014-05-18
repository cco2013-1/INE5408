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
 * Caixa.h
 */

#ifndef __caixa_h__
#define __caixa_h__

#include <string>
#include "FilaCliente.h"

/**
 * Classe Caixa
 * Representa um caixa na simulação de supermercados
 */
class Caixa {
private:
    string identificador;
    double salario;
    FilaCliente *fila;
    int tempoPorProduto;
    int tempoCheque;
    int horarioAtendimentoProximoCliente;
    int tempoAtendimentoCliente(Cliente *c);
    double faturamento;
    int clientesAtendidos;
    int tempoTotalClientesFila;
public:
    Caixa(string id, int eficiencia, double salario);
    ~Caixa();
    void adicionaCliente(Cliente *c);
    void atendeCliente(int horario);
    string obtemIdentificador();
    double obtemSalario();
    int numeroClientesFila();
    int quantidadeProdutosFila();
    double obtemFaturamento();
    int tempoPermanenciaFila();
    int numeroClientesAtendidos();
};

#endif
