#include "CajaDeAhorro.h"
#include <iostream>
using namespace std;

// constructor de la clase derivada CajaDeAhorro
CajaDeAhorro::CajaDeAhorro(string titular, double saldoInicial)
    // llamo al constructor de la clase base (CuentaDeBanco) con los parametros necesarios para inicializar sus atributos: titularCuenta y balance
    : CuentaDeBanco(titular, saldoInicial) {
    contadorMostrar = 0;
}

void CajaDeAhorro::retirar(double cant){
    if (cant > balance){
        cout << "Fondo insuficiente en Caja de Ahorro" << endl;
    } else {
        balance -= cant;
        cout << "Dinero retirado desde Caja de Ahorro. Nuevo balance: $" << balance << endl;
    }
}

void CajaDeAhorro::mostrarInfo() const{
    // const_cast para modificar dentro de un método const
    if (contadorMostrar > 2){
        const_cast<CajaDeAhorro*>(this)->balance -= 20;
        // const_cast elimina la cualidad de 'const de un objeto
        cout << "Se descontaron $20 por exceder el limite de consultas" << endl;
    } 

    cout << "Mostrando informacion de la cuenta..." << endl;
    cout << "   -> Tipo de cuenta: CAJA DE AHORRO" << endl;
    cout << "   -> Titular: " << titularCuenta << endl;
    cout << "   -> Balance: $" << balance << endl;

    contadorMostrar++; // es mutable int
}
