#include "CuentaCorriente.h"
#include <iostream>
using namespace std;

CuentaCorriente::CuentaCorriente(string titular, double saldoInicial, CajaDeAhorro* caja)
    : CuentaDeBanco(titular, saldoInicial), cajaVinculada(caja) {}

void CuentaCorriente::retirar(double cant){
    if (cant <= balance){
        balance -= cant;
        cout << "Dinero retirado desde Cuenta Corriente. Nuevo balance: $" << balance << endl;
    } else if (cajaVinculada && cant <= balance + cajaVinculada->balance){
        double restante = cant - balance;
        balance = 0;
        cajaVinculada->balance -= restante;
        cout << "Dinero retirado. Se usaron fondos de la Caja de Ahorro" << endl;
        cout << "   - Balance en Cuenta Corriente: $0" << endl;
        cout << "   - Balance en Cuenta de Ahorro: $" << cajaVinculada->balance << endl;
    } else {
        cout << "Fondos insuficientes en ambas cuentas" << endl;
    }
}

void CuentaCorriente::mostrarInfo() const{
    cout << "Mostrando informacion de la cuenta..." << endl;
    cout << "   -> Tipo de cuenta: CUENTA CORRIENTE" << endl;
    cout << "   -> Titular: " << titularCuenta << endl;
    cout << "   -> Balance: $" << balance << endl; 
}