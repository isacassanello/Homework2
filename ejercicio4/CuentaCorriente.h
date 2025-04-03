#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "Banco.h"
#include "CajaDeAhorro.h"

class CuentaCorriente : public CuentaDeBanco{
    private:
        // caso: no hay suficiente saldo en la cuenta corriente, puede usar dinero de una CajaDeAhorro vinculada
        CajaDeAhorro* cajaVinculada; 

    public:
        CuentaCorriente(string titular, double saldoInicial = 0.0, CajaDeAhorro* caja = nullptr);

        void retirar(double cantidad) override;    
        void mostrarInfo() const override; 
};

#endif