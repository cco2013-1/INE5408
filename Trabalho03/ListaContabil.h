/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 03 - Implementação de um programa com número variável
 * de Listas com vetores usando a Classe lista com vetor
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * ListaContabil.h
 */

 #include "Lista.hpp"
 #include "Lancamento.h"

class ListaContabil: public Lista<Lancamento> {
public:
    ListaContabil();
    ~ListaContabil();
     Lancamento verTransacao(int posicao);
};
