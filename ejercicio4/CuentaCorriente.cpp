#include "CuentaCorriente.h"
#include <iostream>
using namespace std;

// constructor
CuentaCorriente::CuentaCorriente(string titular, double saldoInicial, CajaDeAhorro* caja)
    // llama al constructor de la clase base y asocia la caja vinculada
    : CuentaDeBanco(titular, saldoInicial), cajaVinculada(caja) {}

void CuentaCorriente::retirar(double cant){
    if (cant <= balance){
        // caso 1: saldo suficiente en la cuenta corriente -> se descuenta directamente
        balance -= cant;
        cout << "Dinero retirado desde Cuenta Corriente. Nuevo balance: $" << balance << endl;
    } else if (cajaVinculada && cant <= balance + cajaVinculada->balance){
        // caso 2: no alcanza el saldo de cuenta corriente, pero sumando el de la caja si alcanza
        double restante = cant - balance; // calculo cuanto falta
        balance = 0;
        cajaVinculada->balance -= restante;
        cout << "Dinero retirado. Se usaron fondos de la Caja de Ahorro" << endl;
        cout << "   - Balance en Cuenta Corriente: $0" << endl;
        cout << "   - Balance en Cuenta de Ahorro: $" << cajaVinculada->balance << endl;
    } else {
        // caso 3: ni con ambas cuentas alcanza -> no se realiza el retiro
        cout << "Fondos insuficientes en ambas cuentas" << endl;
    }
}

void CuentaCorriente::mostrarInfo() const{
    cout << "Mostrando informacion de la cuenta..." << endl;
    cout << "   -> Tipo de cuenta: CUENTA CORRIENTE" << endl;
    cout << "   -> Titular: " << titularCuenta << endl;
    cout << "   -> Balance: $" << balance << endl; 
}