#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H
#include "Banco.h"

class CajaDeAhorro : public CuentaDeBanco{
    private:
        int contadorMostrar; // contador que lleva la cuenta de cuantas veces se llamo al metodo mostrarInfo()

    public: 
        CajaDeAhorro(string titular, double saldoInicial = 0.0);
        void retirar(double cantidad) override;
        void mostrarInfo() override;

        // esto le da permiso a CuentaCorriente para acceder a los atributos privados o protegidos de CajaDeAhorro
        friend class CuentaCorriente;
};

#endif