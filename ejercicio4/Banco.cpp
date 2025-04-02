#include "Banco.h"
#include <iostream>
using namespace std;

CuentaDeBanco::CuentaDeBanco(string titular, double saldoInicial) {
    titularCuenta = titular;
    balance = saldoInicial;
}

CuentaDeBanco::~CuentaDeBanco() {}

void CuentaDeBanco::depositar(double cant){
    if (cant >= 0) {
        balance += cant;
        cout << "Deposito exitoso. Nuevo balance: $" << balance << endl;
    } else {
        cout << "Cantidad invalida para depositar" << endl;
    }
}



