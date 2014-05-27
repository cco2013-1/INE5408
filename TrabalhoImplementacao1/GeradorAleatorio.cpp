/**
 * Biblioteca para geração de números aleatórios
 *
 * @author Vinicius Teixeira
 * @date may-2014
 */

#include "GeradorAleatorio.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>

#define TWO_PI 6.2831853071795864769252866

GeradorAleatorio::GeradorAleatorio() {
    defineSemente(time(NULL));
    hasSpare = false;
}

GeradorAleatorio::~GeradorAleatorio() {
}

/**
 * Método defineSemente
 * Define a semente para o gerador de números aleatórios.
 * @param semente nova semente a ser utilizada
 */
void GeradorAleatorio::defineSemente(long semente) {
    srand(semente);
}

/**
 * Método obtemBoolean
 * Retorna true ou false com 50% de chance para cada.
 * @return true ou false
 */
bool GeradorAleatorio::obtemBoolean() {
    return obtemBoolean(0.5);
}

/**
 * Método obtemBoolean
 * Retorna true ou false, com chanceVerdadeiro * 100% chance de ser
 * true.
 * @param chanceVerdadeiro valor entre [0, 1] que define a probabilidade
 *        de ser true.
 * @return true ou false
 */
bool GeradorAleatorio::obtemBoolean(double chanceVerdadeiro) {
    int aleatorio = rand();
    return (aleatorio < RAND_MAX * chanceVerdadeiro);
}

/**
 * Método obtemInteiro
 * Retorna um número inteiro no intervalo [0, max).
 * @param max limite superior para o inteiro retornado
 *        (não incluido no intervalo)
 * @return inteiro entre 0 e max, sempre < max.
 */
int GeradorAleatorio::obtemInteiro(int max) {
    return rand()%max;
}

/**
 * Método obtemInteiroNoIntervalo
 * Retorna um número inteiro no intervalo fornecido [inicio, fim).
 * @param inicio Limite inferior do intervalo
 * @param fim Limite superior do intervalo
 * @return inteiro entre inicio e fim, sempre menor que fim e possivelmente
 *         igual a inicio.
 */
int GeradorAleatorio::obtemInteiroNoIntervalo(int inicio, int fim) {
    return obtemInteiro(fim - inicio) + inicio;
}

/**
 * Método obtemDouble
 * Retorna um valor entre [0.0, 1.0).
 * @return double entre [0.0 1.0)
 */
double GeradorAleatorio::obtemDouble() {
    return double(rand())/RAND_MAX;
}

/**
 * Método obtemDoubleNoIntervalo
 * Retorna um valor entre [inicio, fim).
 * @return double entre [inicio, fim).
 */
double GeradorAleatorio::obtemDoubleNoIntervalo(double inicio, double fim) {
    return obtemDouble() * (fim - inicio) + inicio;
}

/**
 * Método obtemDoubleDeDistribuicaoNormal
 * Retorna um número aleatório distribuido ao redor da média conforme
 * a distribuição normal, com a variancia especificada.
 * Adaptado de: http://en.wikipedia.org/wiki/Box-Muller_transform
 * @param media valor médio da distribuição desejada
 * @param variancai variancia desejada para a distribuição normal
 * @return valor aleatório distriuído de acordo com a Normal
 */
double GeradorAleatorio::obtemDoubleDeDistribuicaoNormal(double media, double variancia) {
    if (hasSpare) {
        hasSpare = false;
        return sqrt(variancia * aleatorio1) * sin(aleatorio2) + media;
    }

    hasSpare = true;

    aleatorio1 = rand() / ((double) RAND_MAX);
    if (aleatorio1 < 1e-100) {
        aleatorio1 = 1e-100;
    }
    aleatorio1 = -2 * log(aleatorio1);
    aleatorio2 = (rand() / ((double) RAND_MAX)) * TWO_PI;

    return sqrt(variancia * aleatorio1) * cos(aleatorio2) + media;
}
