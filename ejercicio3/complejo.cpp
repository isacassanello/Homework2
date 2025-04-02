#include "complejo.h"
#include <string>
#include <stdexcept>

Complejo::Complejo(double re, double im) {
    real = re;
    imaginario = im;
}

double Complejo::getReal() {return real;}
double Complejo::getImaginario() {return imaginario;}

Numero* Complejo::suma(const Numero* otro){
    const Complejo* c = static_cast<const Complejo*>(otro);
    return new Complejo(real + c->real, imaginario + c->imaginario);
}

Numero* Complejo::resta(const Numero* otro){
    const Complejo* c = static_cast<const Complejo*>(otro);
    return new Complejo(real - c->real, imaginario - c->imaginario);
}

Numero* Complejo::multiplicacion(const Numero* otro){
    const Complejo* c = static_cast<const Complejo*>(otro);
    // i^2 = -1
    double re = real * c->real - imaginario * c->imaginario; 
    double im = real * c->imaginario + imaginario * c->real;
    return new Complejo(re, im);
}

Numero* Complejo::division(const Numero* otro){
    const Complejo* c = static_cast<const Complejo*>(otro);
    // division de dos numeros complejos -> mutliplico y divido por el conjugado del denominador. Entonces, el denominador se convierte en la muliplicacion del denominador y su conjugado
    double denominador = c->real * c->real + c->imaginario * c->imaginario;
    if (denominador == 0) throw runtime_error("Division por cero\n");
    double re = (real * c->real + imaginario * c->imaginario) / denominador;
    double im = (imaginario * c->real - real * c->imaginario) / denominador;
    return new Complejo(re, im);
}

string Complejo::toString() {
    string resultado;
    resultado += to_string(real); // parte real
    
    if (imaginario >= 0) resultado += "+";

    resultado += to_string(imaginario); // parte imaginaria
    
    resultado += "i";

    return resultado;
}
