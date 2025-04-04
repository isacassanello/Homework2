#ifndef NUMERO_H
#define NUMERO_H
#include <string>
#include <memory>
using namespace std;
 
/*
    - Numero es una clase abstracta pura 
    - Real, Entero y Complejo heredan y definen su propio comportamiento para las operaciones
    - Uso shared_ptr para manejar la memoria automaticamenteM
*/

class Numero{
    public:
        // operaciones -> metodos virtuales puros
        virtual shared_ptr<Numero> suma(const Numero& otro) = 0;
        virtual shared_ptr<Numero> resta(const Numero& otro) = 0;
        virtual shared_ptr<Numero> multiplicacion(const Numero& otro) = 0; 
        virtual shared_ptr<Numero> division(const Numero& otro) = 0;
        
        // devuelve el valor como string
        virtual string toString() = 0;
        
        // destructor para liberar memoria correctamente en clases derivadas
        virtual ~Numero() = default; // destructor vacio
};

#endif