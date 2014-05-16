/**
 * Biblioteca para geração de números aleatórios
 *
 * @author Vinicius Teixeira
 * @date may-2014
 */

#include "GeradorAleatorio.h"
#include <stdlib.h>
#include <time.h>

GeradorAleatorio::GeradorAleatorio() {
    defineSemente(time(NULL));
}

GeradorAleatorio::~GeradorAleatorio() {
}

/**
 * Método defineSemente
 * Define a semente para o gerador de números aleatórios
 * @param semente nova semente a ser utilizada
 */
void GeradorAleatorio::defineSemente(long semente) {
    srand(semente);
}

/**
 * Método obtemBoolean
 * Retorna true ou false com 50% de chance para cada
 */
bool GeradorAleatorio::obtemBoolean() {
    return obtemBoolean(0.5);
}

bool GeradorAleatorio::obtemBoolean(double chanceVerdadeiro) {
    int aleatorio = rand();
    return (aleatorio < RAND_MAX * chanceVerdadeiro)
}

// int GeradorAleatorio::obtemInteiro(int max)
