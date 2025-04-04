#ifndef REAL_H
#define REAL_H
#include "numero.h"
 
/*
    - Clase Real es heredada de la interfaz Numero
    - representa un numero real de tipo double con operaciones basicas
*/

class Real : public Numero {
    private:
        double valor;

    public:
        // constructor
        Real(double v);

        // implementaciones de las operaciones definidas en la interfaz Numero
        shared_ptr<Numero> suma(const Numero& otro) override;
        shared_ptr<Numero> resta(const Numero& otro) override;
        shared_ptr<Numero> multiplicacion(const Numero& otro) override;
        shared_ptr<Numero> division(const Numero& otro) override;
        
        // devuelve el valor como string
        string toString() override;
        
        // getter
        double getValor();
};

#endif