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
 * FilaCliente.h
 */

#ifndef __fila_cliente_h__
#define __fila_cliente_h__

#include "Cliente.h"
#include "ListaEncadeada.hpp"

class FilaCliente {
private:
    ListaEncadeada<Cliente> *lista;
    int numProdutos;
public:
    FilaCliente();
    ~FilaCliente();
    void adicionaCliente(Cliente *c);
    void retiraCliente();
    Cliente* proximoCliente();
    int obtemNumClientes();
    int obtemNumProdutos();
};

#endif
