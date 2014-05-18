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
 * Cliente.h
 */

#ifndef __cliente_h__
#define __cliente_h__

#include "GeradorAleatorio.h"

/**
 * Enum tipoCliente.
 * Define o tipo do cliente.
 */
enum tipoCliente {
    MENOR_FILA, /**<Cliente que escolhe a menor fila>*/
    FILA_COM_MENOS_PRODUTOS /**<Cliente que escolhe a fila com menor numero de
                             * produtos>
                             */
};

/**
 * Enum formaPagamento
 * Define a forma de Pagamento utilizada pelo cliente
 */
enum formaPagamento {
    CHEQUE, /**<Pagamento em Cheque.>*/
    DINHEIRO /**<Pagamento em Dinheiro>*/
};

/**
 * Classe Cliente.
 * Representa um cliente na simulação de supermercados.
 */
class Cliente {
private:
    tipoCliente tipo;
    formaPagamento pagamento;
    int quantidadeProdutos;
    double valorTotal;
    int horarioDeChegada;
    int horarioDeSaida;
    void defineTipoCliente();
    void defineFormaPagamento();
    void defineProdutos();
    GeradorAleatorio *ga;
    static int numClientes;
public:
    Cliente(int chegada);
    ~Cliente();
    double valorCompras();
    int quantidadeDeProdutos();
    int obtemHorarioChegada();
    int obtemHorarioSaida();
    void defineHorarioSaida(int saida);
    tipoCliente obtemTipoCliente();
    formaPagamento obtemFormaPagamento();
};

#endif
