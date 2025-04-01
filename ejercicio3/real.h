#ifndef REAL_H
#define REAL_H
#include "numero.h"
 
class Real : public Numero {
    private:
        double valor;

    public:
        Real(double v);
        Numero* suma(const Numero* otro) override;
        Numero* resta(const Numero* otro) override;
        Numero* multiplicacion(const Numero* otro) override;
        Numero* division(const Numero* otro) override;
        string toString() override;
        
        // getter
        double getValor();
};

#endif