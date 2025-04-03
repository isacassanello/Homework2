#ifndef COMPLEJO_H
#define COMPLEJO_H
#include "numero.h"

/*
Se usa make_shared<Complejo>() en cada operación para evitar new y tener manejo automático de memoria
*/
 
class Complejo : public Numero {
    private:
        double real;
        double imaginario;

    public:
        Complejo(double re, double im); // parte real y parte imaginaria
        shared_ptr<Numero> suma(const Numero& otro) override;
        shared_ptr<Numero> resta(const Numero& otro) override;
        shared_ptr<Numero> multiplicacion(const Numero& otro) override;
        shared_ptr<Numero> division(const Numero& otro) override;
        string toString() override;
        
        // getter
        double getReal();
        double getImaginario();
};

#endif