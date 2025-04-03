#include <iostream>
#include "CajaDeAhorro.h"
#include "CuentaCorriente.h"
using namespace std;

int main() {
    CajaDeAhorro caja("Juan", 100);
    CuentaCorriente corriente("Juan", 40, &caja);

    cout << "\n=====MOSTRAR BALANCES INICIALES=====" << endl;
    cout << "Caja de Ahorro:" << endl;
    caja.mostrarInfo();
    cout << "\nCuente Corriente:" << endl;
    corriente.mostrarInfo();

    // depositar
    cout << "\n=====PRUEBA DEPOSITAR DINERO=====" << endl;
    caja.depositar(50);  // esperado: balance = 150
    caja.depositar(-2);  // esperado: cantidad invalida

    // mostrar info varias veces
    cout << "\n=====PRUEBA MOSTRAR LA INFORMACION HASTA EL DESCUENTO=====" << endl;
    cout << "Llamado 1:" << endl;
    caja.mostrarInfo();
    cout << "\nLlamado 2:" << endl;
    caja.mostrarInfo();
    cout << "\nLlamado 3:" << endl;
    caja.mostrarInfo();  // a partir de aca se descuenta $20 

    // probar retiro
    cout << "\n=====PRUEBA RETIRAR DINERO=====" << endl;
    cout << "1) De la Caja de Ahorro:" << endl;
    caja.retirar(200);  // esperado: "Fondo insuficiente en Caja de Ahorro"
    caja.retirar(50);   // esperado: que retire bien el dinero -> nuevo balance = 80

    cout << "\n2) De la Cuenta Corriente:" << endl;
    corriente.retirar(10); // esperado: tiene 40 en cuenta corriente -> nuevo balance = 30
    corriente.retirar(70);  // esperado: tiene 30 en cuenta corriente, usa 40 de caja de ahorro
    corriente.retirar(500); // no hay dinero suficiente en ambas

    // mostrar balances finales
    cout << "\n=====MOSTRAR BALANCES FINALES=====" << endl;
    cout << "Caja de Ahorro:" << endl;
    caja.mostrarInfo();
    cout << "\nCuente Corriente:" << endl;
    corriente.mostrarInfo();

    return 0;
}
