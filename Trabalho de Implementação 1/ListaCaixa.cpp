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
 * ListaCaixa.cpp
 */

#include "ListaCaixa.h"

ListaCaixa::ListaCaixa():ListaCircular<Caixa>() {
    //TODO
}

/**
 * Destrutor ListaCaixa
 * Vazio pois o destrutor da super classe já faz a limpeza necessária.
 */
ListaCaixa::~ListaCaixa() {
}

/**
 * Método estaNoInicio
 * Verifica so ponteiro atual da lista circular está apontando para o
 * início da lista. Utilizado para verificar o momento em que se completa
 * uma volta na lista circular.
 * @return verdadeiro caso a lista esteja no inicio, falso caso contrario
 */
bool ListaCaixa::estaNoInicio() {
    return atual == primeira;
}

/**
 * Método adicionaCaixa
 * Adiciona um caixa à lista circular e aponta o ponteiro atual para
 * este caixa, caso seja o primeiro caixa inserido na lista.
 * @param c caixa a ser adicionado
 */
void ListaCaixa::adicionaCaixa(Caixa *c) {
    ListaCircular::adiciona(c);
    if (_tamanho == 1) {
        atual = primeira;
    }
}

/**
 * Método proximoCaixa
 * Retorna o proximo caixa na lista circular
 * @return proximo caixa
 */
Caixa * ListaCaixa::proximoCaixa() {
    Capsula * auxiliar = atual;
    atual = atual->proxima;
    return auxiliar->informacao;
}

/**
 * Método caixaComMenorFila
 * Retorna o caixa com a menor fila
 * @return caixa com a menor fila
 */
Caixa * ListaCaixa::caixaComMenorFila() {
    Caixa *caixaMenorFila = primeira->informacao;
    Capsula * atualAuxiliar = primeira;
    while (true) {
        Caixa *cx = atualAuxiliar->informacao;
        atualAuxiliar = atualAuxiliar->proxima;

        if (cx->numeroClientesFila() < caixaMenorFila->numeroClientesFila()) {
            caixaMenorFila = cx;
        }

        if (atualAuxiliar == primeira) {
            break;
        }
    }
    return caixaMenorFila;
}

/**
 * Método caixaComMenosProdutos
 * Retorna o caixa com a menor quantidade de produtos na fila
 * @return caixa com menor quantidade de produtos
 */
Caixa * ListaCaixa::caixaComMenosProdutos() {
    Caixa *caixaMenosProdutos = primeira->informacao;
    Capsula *atualAuxiliar = primeira;
    while (true) {
        Caixa *cx = atualAuxiliar->informacao;
        atualAuxiliar = atualAuxiliar->proxima;

        if (cx->quantidadeProdutosFila() < caixaMenosProdutos->quantidadeProdutosFila()) {
            caixaMenosProdutos = cx;
        }

        if (atualAuxiliar == primeira) {
            break;
        }
    }
    return caixaMenosProdutos;
}
