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
 * Caixa.cpp
 */

#include "Caixa.h"

/**
 * Construtor de Caixa
 * A fila de clientes é criada, o identificador e o salário do caixa
 * são definidos e, baseado em sua eficiência, o tempo para processar cada
 * produto e o tempo para processar cheques são definidos.
 */
Caixa::Caixa(string id, int eficiencia, double sal) {
    fila = new FilaCliente();
    identificador = id;
    switch (eficiencia) {
    case 1:
        tempoPorProduto = 1;
        tempoCheque = 10;
        break;
    case 2:
        tempoPorProduto = 2;
        tempoCheque = 25;
        break;
    default:
        tempoPorProduto = 4;
        tempoCheque = 60;
    }
    salario = sal;
    horarioAtendimentoProximoCliente = 0;
    faturamento = 0;
    clientesAtendidos = 0;
    tempoTotalClientesFila = 0;
}

/**
 * Destrutor Caixa
 * Libera o espaçao utilizado pela fila de clientes
 */
Caixa::~Caixa() {
    delete fila;
}

/**
 * Método adicionaCliente
 * Define o horário em que o cliente terminará de ser atendido
 * e o adiciona à fila de clientes.
 */
void Caixa::adicionaCliente(Cliente *c) {
    horarioAtendimentoProximoCliente = horarioAtendimentoProximoCliente <
        c->obtemHorarioChegada() ? c->obtemHorarioChegada() :
        horarioAtendimentoProximoCliente;
    horarioAtendimentoProximoCliente += tempoAtendimentoCliente(c);
    c->defineHorarioSaida(horarioAtendimentoProximoCliente);
    fila->adicionaCliente(c);
}

/**
 * Método tempoAtendimentoCliente
 * Calcula o tempo necessário para o caixa atual atender o cliente,
 * levando em conta a quantidade de produtos e a forma de pagamento.
 * @param c Cliente para o qual se deseja calcular o tempo de atendimento
 * @return tempo necessário para atender o cliente
 */
int Caixa::tempoAtendimentoCliente(Cliente *c) {
    return c->quantidadeDeProdutos() * tempoPorProduto +
        (c->obtemFormaPagamento() == CHEQUE ? tempoCheque : 0);
}

/**
 * Método atendeCliente
 * Retira o cliente da fila caso o tempo necessário para
 * processar suas compras já tenha passado.
 */
void Caixa::atendeCliente(int horario) {
    if (fila->obtemNumClientes() == 0) {
        return;
    }
    Cliente *c = fila->proximoCliente();
    if (horario >= c->obtemHorarioSaida()) {
        faturamento += c->valorCompras();
        clientesAtendidos += 1;
        tempoTotalClientesFila += (c->obtemHorarioSaida() - c->obtemHorarioChegada());
        fila->retiraCliente();
    }
}

/**
 * Método obtemIdentificador
 * Retorna o identificador do caixa
 * @return o identificador do caixa
 */
string Caixa::obtemIdentificador() {
    return identificador;
}

/**
 * Método obtemSalario
 * Retorna o salário do caixa
 * @return salario do caixa
 */
double Caixa::obtemSalario() {
    return salario;
}

/**
 * Método numeroClientesFila
 * Retorna o número de clientes na fila
 * @return numero de clientes na fila
 */
int Caixa::numeroClientesFila() {
    return fila->obtemNumClientes();
}

/**
 * Método quantidadeProdutosFila
 * Retorna a quantidade total de produtos na fila
 * @return quantidade total de produtos na fila
 */
int Caixa::quantidadeProdutosFila() {
    return fila->obtemNumProdutos();
}

/**
 * Método obtemFaturamento
 * Retorna o faturamento do caixa
 * @return faturamento do caixa
 */
double Caixa::obtemFaturamento() {
    return faturamento;
}

/**
 * Método obtemTempoPermanenciaFila
 * Retorna o tempo total que os clientes aguardaram neste caixa
 * @return tempo de permanencia em fila
 */
int Caixa::tempoPermanenciaFila() {
    return tempoTotalClientesFila;
}

/**
 * Método numeroClientesAtendidos
 * Retorna o número de clientes atendidos pelo caixa
 * @return numero de clientes atendidos pelo caixa
 */
int Caixa::numeroClientesAtendidos() {
    return clientesAtendidos;
}
