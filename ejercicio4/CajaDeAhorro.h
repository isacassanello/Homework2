#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H
#include "Banco.h"

// Clase derivada
class CajaDeAhorro : public CuentaDeBanco{
    private:
    /*
        - contadorMostrar -> contador que lleva la cuenta de cuantas veces se llamo al metodo mostrarInfo()
        - con mutable permito que un miembro de una clase pueda ser modificado incluso si el objeto que lo contiene es declarado como 'const'
        - Esto es necesario porque mostrarInfo() está declarado como const
    */
        mutable int contadorMostrar; 

    public: 
        // constructor: recibe nombre del titular y saldo inicial (por defecto 0.0)
        CajaDeAhorro(string titular, double saldoInicial = 0.0);

        // implementacion del metodo abstracto 'retirar' heredado de CuentaDeBanco
        void retirar(double cantidad) override;

        // implementacion del metodo abstracto 'mostrarInfo'
        void mostrarInfo() const override;

        /*
            - declaro a CuentaCorriente como clase friend para que pueda acceder a atributos privados de CajaDeAhorro ('balance')
            - Esto es necesario para que CuentaCorriente pueda retirar dinero desde CajaDeAhorro cuando no tenga fondos propios
        */
        friend class CuentaCorriente; 
};

#endif