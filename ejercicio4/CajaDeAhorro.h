#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H
#include "Banco.h"

class CajaDeAhorro : public CuentaDeBanco{
    private:
        mutable int contadorMostrar; // contador que lleva la cuenta de cuantas veces se llamo al metodo mostrarInfo()
        // con mutable permito que un miembro de una clase pueda ser modificado incluso si el objeto que lo contiene es declarado como 'const'

    public: 
        CajaDeAhorro(string titular, double saldoInicial = 0.0);
        void retirar(double cantidad) override;
        void mostrarInfo() const override;

        // esto le da permiso a CuentaCorriente para acceder a los atributos privados de CajaDeAhorro
        friend class CuentaCorriente; //  le permite a CuentaCorriente acceder directamente al atributo balance de la caja
};

#endif