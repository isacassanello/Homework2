#ifndef ENTERO_H
#define ENTERO_H
#include "numero.h"

class Entero : public Numero {
    private:
        int valor;

    public:
        // constructor
        Entero(int v);

        Numero* suma(const Numero* otro) override;
        Numero* resta(const Numero* otro) override;
        Numero* multiplicacion(const Numero* otro) override;
        Numero* division(const Numero* otro) override;
        string toString() override;
        
        // getter
        int getValor();
};

#endif