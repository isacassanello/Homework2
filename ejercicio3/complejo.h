#ifndef COMPLEJO_H
#define COMPLEJO_H
#include "numero.h"
 
class Complejo : public Numero {
    private:
        double real;
        double imaginario;

    public:
        Complejo(double re, double im); // parte real y parte imaginaria
        Numero* suma(const Numero* otro) override;
        Numero* resta(const Numero* otro) override;
        Numero* multiplicacion(const Numero* otro) override;
        Numero* division(const Numero* otro) override;
        string toString() override;
        
        // getter
        double getReal();
        double getImaginario();
};

#endif