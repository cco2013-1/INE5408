#include <iostream>
#include "Cliente.h"
#include "GeradorAleatorio.h"

using namespace std;

int main() {
    GeradorAleatorio *ga = new GeradorAleatorio();

    for (int i = 0; i < 10; i++) {
        cout << "Cliente " << i << endl;
        Cliente *c = new Cliente(0);
        c->defineHorarioSaida(ga->obtemInteiroNoIntervalo(i, i + 10));
        cout << "Valor compras " << c->valorCompras() << endl;
        cout << "Tipo Cliente " << c->obtemTipoCliente() << endl;
        cout << "Forma pagamento " << c->obtemFormaPagamento() << endl;
        cout << "Horário de saída " << c->obtemHorarioSaida() << endl;
        cout << "=======================================" << endl << endl;
    }
}
