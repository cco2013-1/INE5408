/**
 * Biblioteca para geração de números aleatórios
 *
 * @author Vinicius Teixeira
 * @date may-2014
 */

#ifndef __gerador_aleatorio_h__
#define __gerador_aleatorio_h__

/**
 * Classe GeradorAleatorio
 * Gera números aleatórios de diversas maneiras.
 */
class GeradorAleatorio {
private:
    bool hasSpare; /**<utilizado pelo método obtemDoubleDeDistribuicaoNormal>*/
    double aleatorio1, aleatorio2; /**<utilizado pelo método obtemDoubleDeDistribuicaoNormal>*/
public:
    GeradorAleatorio();
    ~GeradorAleatorio();
    void defineSemente(long semente);
    bool obtemBoolean();
    bool obtemBoolean(double chanceVerdadeiro);
    int obtemInteiro(int max);
    int obtemInteiroNoIntervalo(int inicio, int fim);
    double obtemDouble();
    double obtemDoubleNoIntervalo(double inicio, double fim);
    double obtemDoubleDeDistribuicaoNormal(double media, double variancia);
};

#endif
