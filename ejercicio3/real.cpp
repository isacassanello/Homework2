#include "real.h"
#include <string>
#include <stdexcept>

Real::Real(double v) {valor = v;}

double Real::getValor() {return valor;}

Numero* Real::suma(const Numero* otro){
    const Real* r = static_cast<const Real*>(otro);
    return new Real(valor + r->valor);
}

Numero* Real::resta(const Numero* otro){
    const Real* r = static_cast<const Real*>(otro);
    return new Real(valor - r->valor);
}

Numero* Real::multiplicacion(const Numero* otro){
    const Real* r = static_cast<const Real*>(otro);
    return new Real(valor * r->valor);
}

Numero* Real::division(const Numero* otro){
    const Real* r = static_cast<const Real*>(otro);
    if (r->valor == 0.0) throw runtime_error("Division por cero");
    return new Real(valor / r->valor);
}

string Real::toString() {
    return to_string(valor);
}
