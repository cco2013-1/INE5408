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
 * ListaCaixa.h
 */

#ifndef __lista_caixa_h__
#define __lista_caixa_h__

#include "ListaCircular.hpp"
#include "Caixa.h"

class ListaCaixa: public ListaCircular<Caixa> {
private:
    Capsula *atual;
public:
    ListaCaixa();
    ~ListaCaixa();
    bool estaNoInicio();
    void adicionaCaixa(Caixa *c);
    Caixa* proximoCaixa();
    Caixa* caixaComMenorFila();
    Caixa* caixaComMenosProdutos();
};

#endif
