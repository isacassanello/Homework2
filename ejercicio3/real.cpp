#include "real.h"
#include <string>
#include <stdexcept>

// Uso static_cast para convertir un puntero de tipo base (Numero) a un tipo derivado (Real) para acceder a sus atributos y metodos

// constructor: inicializa el valor con el numero real recibido
Real::Real(double v) {valor = v;}

// implementacion de la suma entre Reales
shared_ptr<Numero> Real::suma(const Numero& otro){
    // asumo que otro es un numero real, hago cast para acceder a su valor
    const Real& r = static_cast<const Real&>(otro);
    return make_shared<Real>(valor + r.valor);
}

// implementacion de la resta entre Reales
shared_ptr<Numero> Real::resta(const Numero& otro){
    const Real& r = static_cast<const Real&>(otro);
    return make_shared<Real>(valor - r.valor);
}

// implementacion de la multiplicacion entre Reales
shared_ptr<Numero> Real::multiplicacion(const Numero& otro){
    const Real& r = static_cast<const Real&>(otro);
    return make_shared<Real>(valor * r.valor);
}

// implementacion de la divisiom entre Reales
shared_ptr<Numero> Real::division(const Numero& otro){
    const Real& r = static_cast<const Real&>(otro);
    if (r.valor == 0.0) throw runtime_error("Division por cero");
    return make_shared<Real>(valor / r.valor);
}

// convierte el valor entero a string para mostrarlo
string Real::toString() {
    return to_string(valor);
}

// getter
double Real::getValor() {return valor;}