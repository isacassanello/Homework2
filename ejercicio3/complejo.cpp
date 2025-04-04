#include "complejo.h"
#include <string>
#include <stdexcept>
using namespace std;

// constructor
Complejo::Complejo(double re, double im) {
    real = re;
    imaginario = im;
}

// suma de complejos: (a + bi) + (c + di) = (a + c) + (b + d)i
shared_ptr<Numero> Complejo::suma(const Numero& otro){
    const Complejo& c = static_cast<const Complejo&>(otro);
    return make_shared<Complejo>(real + c.real, imaginario + c.imaginario);
}

// resta de complejos: (a + bi) - (c + di) = (a - c) + (b - d)i
shared_ptr<Numero> Complejo::resta(const Numero& otro){
    const Complejo& c = static_cast<const Complejo&>(otro);
    return make_shared<Complejo>(real - c.real, imaginario - c.imaginario);
}

// multiplicacion: (a + bi)(c + di) = (ac - bd) + (ad + bc)i
shared_ptr<Numero> Complejo::multiplicacion(const Numero& otro){
    const Complejo& c = static_cast<const Complejo&>(otro);
    // i^2 = -1
    double re = real * c.real - imaginario * c.imaginario; 
    double im = real * c.imaginario + imaginario * c.real;
    return make_shared<Complejo>(re, im);
}

// division: [(a + bi) / (c + di)] = [(ac + bd) + (bc - ad)i] / (c² + d²)
shared_ptr<Numero> Complejo::division(const Numero& otro){
    const Complejo& c = static_cast<const Complejo&>(otro);
    // division de dos numeros complejos -> mutliplico y divido por el conjugado del denominador. Entonces, el denominador se convierte en la muliplicacion del denominador y su conjugado
    double denominador = c.real * c.real + c.imaginario * c.imaginario;
    if (denominador == 0) throw runtime_error("Division por cero\n");
    double re = (real * c.real + imaginario * c.imaginario) / denominador;
    double im = (imaginario * c.real - real * c.imaginario) / denominador;
    return make_shared<Complejo>(re, im);
}

// convierte el valor entero a string para mostrarlo
string Complejo::toString() {
    string resultado;
    resultado += to_string(real); // parte real
    if (imaginario >= 0) resultado += "+";
    resultado += to_string(imaginario); // parte imaginaria
    resultado += "i";
    return resultado;
}

// getters
double Complejo::getReal() {return real;} // devuelve la parte real del numero complejo
double Complejo::getImaginario() {return imaginario;} // devuelve la parte imaginaria del numero complejo
