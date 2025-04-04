#include "Banco.h"
#include <iostream>
using namespace std;

// constructor: inicializa los atributos con los valores recibidos
CuentaDeBanco::CuentaDeBanco(string titular, double saldoInicial) {
    titularCuenta = titular;
    balance = saldoInicial;
}

// destructor: al ser virtual, asegura destruccion correcta en jerarquias de herencia
CuentaDeBanco::~CuentaDeBanco() {}

// metodo para depositar una cantidad de dinero en la cuenta
void CuentaDeBanco::depositar(double cant){
    if (cant >= 0) {
        balance += cant;
        cout << "Deposito exitoso. Nuevo balance: $" << balance << endl;
    } else {
        cout << "Cantidad invalida para depositar" << endl;
    }
}