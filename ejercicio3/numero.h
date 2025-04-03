#ifndef NUMERO_H
#define NUMERO_H
#include <string>
#include <memory>
using namespace std;
 
// Numero es una clase abstracta pura 
class Numero{
    public:
        virtual shared_ptr<Numero> suma(const Numero& otro) = 0;
        virtual shared_ptr<Numero> resta(const Numero& otro) = 0;
        virtual shared_ptr<Numero> multiplicacion(const Numero& otro) = 0; 
        virtual shared_ptr<Numero> division(const Numero& otro) = 0;
        virtual string toString() = 0;
        virtual ~Numero() = default; // default deshabilita los metodos
};

#endif
