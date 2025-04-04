#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "Banco.h"
#include "CajaDeAhorro.h"

// Clase derivada
class CuentaCorriente : public CuentaDeBanco{
    private:
    /*
        - Puntero a una CajaDeAhorro vinculada:
        - se utiliza en caso de no hay suficiente saldo en la cuenta corriente, por lo tanto puede usar 
        dinero de una CajaDeAhorro vinculada
    */
        CajaDeAhorro* cajaVinculada; 

    public:
        // constructor: inicializa la cuenta con titular, saldo inicial (por defecto 0) y un puntero a una caja de ahorro asociada (por defecto nullptr si no se especifica)
        CuentaCorriente(string titular, double saldoInicial = 0.0, CajaDeAhorro* caja = nullptr);

        // sobrescribe el metodo abstracto 'retirar' de la clase base
        void retirar(double cantidad) override;   
        
        // sobrescribe el metodo abstracto 'mostrarInfo' de la clase base
        void mostrarInfo() const override; 
};

#endif