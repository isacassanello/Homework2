#ifndef COMPLEJO_H
#define COMPLEJO_H
#include "numero.h"

/*
    - Clase Complejo es heredada de la interfaz Numero 
    - representa un numero complejo con parte real y parte imaginaria
*/
 
class Complejo : public Numero {
    private:
        double real; // parte real del numero complejo
        double imaginario; // parte imaginaria del numero complejo

    public:
        // constructor: recibe parte real e imaginaria
        Complejo(double re, double im); 
        
        // implementaciones de las operaciones definidas en la interfaz Numero
        shared_ptr<Numero> suma(const Numero& otro) override;
        shared_ptr<Numero> resta(const Numero& otro) override;
        shared_ptr<Numero> multiplicacion(const Numero& otro) override;
        shared_ptr<Numero> division(const Numero& otro) override;
        
        // devuelve el valor como string
        string toString() override;
        
        // getters
        double getReal();
        double getImaginario();
};

#endif