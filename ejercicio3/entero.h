#ifndef ENTERO_H
#define ENTERO_H
#include "numero.h"

/*
    - Clase Entero es heredada de la interfaz Numero 
    - representa un numero entero de tipo int con operaciones basicas
*/

class Entero : public Numero {
    private:
        int valor;

    public:
        // constructor
        Entero(int v);

        // implementaciones de las operaciones definidas en la interfaz Numero
        shared_ptr<Numero> suma(const Numero& otro) override;
        shared_ptr<Numero> resta(const Numero& otro) override;
        shared_ptr<Numero> multiplicacion(const Numero& otro) override;
        shared_ptr<Numero> division(const Numero& otro) override;
        
        // devuelve el valor como string
        string toString() override;
        
        // getter
        int getValor();
};

#endif