#ifndef NUMERO_H
#define NUMERO_H
#include <string>
using namespace std;
 
// Numero es una clase abstracta pura o una interfaz
class Numero{
    public:
        virtual Numero* suma(const Numero* otro) = 0;
        virtual Numero* resta(const Numero* otro) = 0;
        virtual Numero* multiplicacion(const Numero* otro) = 0; 
        virtual Numero* division(const Numero* otro) = 0;
        virtual string toString() = 0;
        virtual ~Numero() = default; // default deshabilita los metodos
};

#endif
