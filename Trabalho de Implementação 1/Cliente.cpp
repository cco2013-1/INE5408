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
 * Cliente.cpp
 */

#include <stdlib.h>
#include <time.h>
#include "Cliente.h"


#define ERRO_HORARIO_SAIDA 1
#define PROBABILIDADE_MENOR_FILA 0.5
#define PROBABILIDADE_CHEQUE 0.2
#define QUANTIDADE_MIN_PROD 2
#define QUANTIDADE_MAX_PROD 100
#define VALOR_MIN_PROD 1.00
#define VALOR_MAX_PROD 90.00

int Cliente::numClientes = 0;

/**
 * Construtor do Cliente.
 * Cria um novo Cliente no horario de chegada, definindo o tipo de cliente
 * (buscaMenorFila ou buscaFilaComMenosProdutos), a forma de pagamento (chegue
 * ou dinheiro) e a quantidade e o valor total dos produtos.
 * @param chegada Horário de chegada do Cliente.
 */
Cliente::Cliente(int chegada) {
    ga = new GeradorAleatorio;
    ///Define a semente do gerador aletório
    ///baseado no número de clientes, para evitar
    ///que os clientes gerados em sequencia tenham
    ///os mesmos valores
    ga->defineSemente(long(time(NULL)/float(numClientes)));
    horarioDeChegada = chegada;
    defineTipoCliente();
    defineFormaPagamento();
    defineProdutos();
    numClientes += 1;
}

/**
 * Destrutor do Cliente
 * Vazio pois não há nada a destruir.
 */
Cliente::~Cliente() {
}

/**
 * Método valorCompras.
 * Retorna o valor total das compras do cliente
 * @return valorTotal o valor total das compras do cliente
 */
double Cliente::valorCompras() {
    return valorTotal;
}

/**
 * Método numProdutos
 * Retorna a quantidade de produtos comprada pelo cliente
 * @return quantidade de produtos
 */
int Cliente::quantidadeDeProdutos() {
    return quantidadeProdutos;
}

/**
 * Método obtemHorarioChegada
 * Retorna o horário de chegada do cliente
 * @return horário de chegada do cliente
 */
int Cliente::obtemHorarioChegada() {
    return horarioDeChegada;
}

/**
 * Método obtemHorarioSaida
 * Retorna o horário de saída previamente definido para este cliente.
 * @return horarioDeSaida o horário de saída do cliente
 * @see defineHoarioSaida()
 */
int Cliente::obtemHorarioSaida() {
    return horarioDeSaida;
}

/**
 * Método defineHorarioSaida
 * Define o horário de saída do cliente, após este ser
 * inserido em alguma fila do caixa.
 * @param saida horário de saída do cliente
 */
void Cliente::defineHorarioSaida(int saida) {
    if (saida > horarioDeChegada) {
        horarioDeSaida = saida;
    } else throw (ERRO_HORARIO_SAIDA);
}

/**
 * Método obtemTipoCliente
 * Retorna o tipo do cliente.
 * @return tipoCliente o valor do enumerado do tipoCliente
 */
tipoCliente Cliente::obtemTipoCliente() {
    return tipo;
}

/**
 * Método obtemFormaPagamento
 * Retorna a forma de pagamento do cliente.
 * @return formaPagamento a forma de pagamento que o cliente utilizará
 */
formaPagamento Cliente::obtemFormaPagamento() {
    return pagamento;
}

/**
 * Método defineTipoCliente
 * Define o tipo do cliente. Este método é privado e é chamado apenas
 * na construção do Cliente. A probabilidade de um cliente ser menorFila
 * ou menosProdutos é igual, portanto 50% para cada tipo, conforme definido
 * na constante PROBABILIDADE_MENOR_FILA.
 */
void Cliente::defineTipoCliente() {
    if (ga->obtemBoolean(PROBABILIDADE_MENOR_FILA)) {
        tipo = MENOR_FILA;
    } else {
        tipo = FILA_COM_MENOS_PRODUTOS;
    }
}

/**
 * Método defineFormaPagamento
 * Define a forma de pagamento a ser utilizada pelo cliente.
 * A probabilidade de um cliente pagar com cheque é dada pela constante
 * PROBABILIDADE_CHEQUE.
 */
void Cliente::defineFormaPagamento() {
    if (ga->obtemBoolean(PROBABILIDADE_CHEQUE)) {
        pagamento = CHEQUE;
    } else {
        pagamento = DINHEIRO;
    }
}

/**
 * Método defineProdutos
 * Define a quantidade de produtos e o valor total dos produtos.
 * A quantidade de produtos é definida pelas constantes QUANTIDADE_MIN_PROD
 * e QUANTIDADE_MAX_PROD e a faixa de valores de cada produto é definida pelas
 * constantes VALOR_MIN_PROD e VALOR_MAX_PROD.
 */
void Cliente::defineProdutos() {
    quantidadeProdutos = ga->obtemInteiroNoIntervalo(QUANTIDADE_MIN_PROD, QUANTIDADE_MAX_PROD + 1);
    valorTotal = 0.;
    for (int i = 0; i < quantidadeProdutos; i++) {
        valorTotal += ga->obtemDoubleNoIntervalo(VALOR_MIN_PROD, VALOR_MAX_PROD);
    }
}
