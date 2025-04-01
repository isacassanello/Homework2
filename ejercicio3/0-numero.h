#ifndef NUMERO_H
#define NUMERO_H
#include <string>
using namespace std;
 
class Numero{
    public:
        virtual Numero* suma(const Numero* otro);
        virtual Numero* resta(const Numero* otro);
        virtual Numero* multiplicacion(const Numero* otro); 
        virtual Numero* division(const Numero* otro);
        virtual string toString();
        virtual ~Numero();
};

#endif
