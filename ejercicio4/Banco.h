#ifndef BANCO_H
#define BANCO_H
#include <iostream>
#include <string>
using namespace std;
 
class CuentaDeBanco{
    protected:
    /*
    estan protected para que las subclases (CajaDeAhorro y CuentaCorriente) puedan acceder directamente sin usar getters/setters
    */
        double balance; // total de la cuenta
        string titularCuenta;

    public:
        // constructor
        CuentaDeBanco(string titular, double saldoInicial = 0.0);

        // destructor virtual
        virtual ~CuentaDeBanco();

        // metodo para depositar dinero
        void depositar(double cant); // es publico para que pueda usarse desde cualquier parte

        // metodo virtual puro para retirar dinero
        virtual void retirar(double cantidad) = 0; // virtuales puros -> obligando a las subclases a implementarlos

        // metodo virtual puro para mostrar informacion
        virtual void mostrarInfo() const = 0; // virtuales puros -> obligando a las subclases a implementarlos
};

#endif
