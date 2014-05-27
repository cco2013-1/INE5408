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
 * FilaCliente.cpp
 */

#include "FilaCliente.h"

/**
 * Construtor da Fila de Clientes
 * Inicializa a Lista Encadeada responsável por
 * organizar os clientes
 */
FilaCliente::FilaCliente() {
    lista = new ListaEncadeada<Cliente>();
    numProdutos = 0;
}

/**
 * Destrutor da Fila de Clientes
 * Libera o espaço utilizado pela Lista Encadeada
 */
FilaCliente::~FilaCliente() {
    delete lista;
}

/**
 * Método adicionaCliente
 * Adiciona um cliente no final da Lista, dando o comportamento de fila
 * @param c Cliente que se deseja incluir na fila
 * @see retiraCliente()
 */
void FilaCliente::adicionaCliente(Cliente *c) {
    lista->adiciona(c);
    numProdutos += c->quantidadeDeProdutos();
}

/**
 * Método retiraCliente
 * Retira um cliente do inicio da Lista. Em conjunto com adicionaCliente,
 * dá o comportamento de Fila à Lista Encadeada utilizada.
 * @see adicionaCliente()
 */
void FilaCliente::retiraCliente() {
    numProdutos -= lista->elementoNaPosicao(0)->quantidadeDeProdutos();
    lista->retiraDaPosicao(0);
}

/**
 * Método proximoCliente
 * Mostra o primeiro cliente da fila, sem removê-lo
 * @return primeiro cliente da fila
 */
Cliente * FilaCliente::proximoCliente() {
    return lista->elementoNaPosicao(0);
}

/**
 * Método obtemNumClientes
 * Retorna o número de clientes atualmente na fila
 * @return numero de clientes na fila
 */
int FilaCliente::obtemNumClientes() {
    return lista->tamanho();
}

/**
 * Método obtemNumProdutos
 * Retorna a quantidade total de produtos dos clientes que estão na fila
 */
int FilaCliente::obtemNumProdutos() {
    return numProdutos;
}
