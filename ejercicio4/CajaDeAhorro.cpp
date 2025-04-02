#include "CajaDeAhorro.h"
#include <iostream>
using namespace std;

// constructor de la clase derivada CajaDeAhorro
CajaDeAhorro::CajaDeAhorro(string titular, double saldoInicial)
    // llamo al constructor de la clase base (CuentaDeBanco) con los parametros necesarios para inicializar sus atributos: titularCuenta y balance
    : CuentaDeBanco(titular, saldoInicial) {
    contadorMostrar = 0;
}
