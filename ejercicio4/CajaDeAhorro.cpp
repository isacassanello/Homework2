#include "CajaDeAhorro.h"
#include <iostream>
using namespace std;

// constructor de la clase derivada CajaDeAhorro
CajaDeAhorro::CajaDeAhorro(string titular, double saldoInicial)
    // llamo al constructor de la clase base (CuentaDeBanco) con los parametros necesarios para inicializar sus atributos: titularCuenta y balance
    : CuentaDeBanco(titular, saldoInicial) {
    // inicio el contador de visualizaciones en 0
    contadorMostrar = 0;
}

// implementacion del metodo 'retirar'
void CajaDeAhorro::retirar(double cant){
    if (cant > balance){
        cout << "Fondo insuficiente en Caja de Ahorro" << endl;
    } else {
        balance -= cant;
        cout << "Dinero retirado desde Caja de Ahorro. Nuevo balance: $" << balance << endl;
    }
}

// implementacion del metodo 'mostrarInfo'
void CajaDeAhorro::mostrarInfo() const{
    if (contadorMostrar > 2){
        // si se llama mas de dos veces, se descuenta $20 del balance
        const_cast<CajaDeAhorro*>(this)->balance -= 20; // const_cast para modificar dentro de un metodo const
        cout << "Se descontaron $20 por exceder el limite de consultas" << endl;
    } 

    cout << "Mostrando informacion de la cuenta..." << endl;
    cout << "   -> Tipo de cuenta: CAJA DE AHORRO" << endl;
    cout << "   -> Titular: " << titularCuenta << endl;
    cout << "   -> Balance: $" << balance << endl;

    // se incrementa el contador de visualizaciones
    contadorMostrar++; // es mutable int
}
