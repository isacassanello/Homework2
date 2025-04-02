#include "entero.h"
#include <string>
#include <stdexcept>

Entero::Entero(int v) {valor = v;}

int Entero::getValor() {return valor;}

Numero* Entero::suma(const Numero* otro){
    const Entero* e = static_cast<const Entero*>(otro);
    return new Entero(valor + e->valor);
}

Numero* Entero::resta(const Numero* otro){
    const Entero* e = static_cast<const Entero*>(otro);
    return new Entero(valor - e->valor);
}

Numero* Entero::multiplicacion(const Numero* otro){
    const Entero* e = static_cast<const Entero*>(otro);
    return new Entero(valor * e->valor);
}

Numero* Entero::division(const Numero* otro){
    const Entero* e = static_cast<const Entero*>(otro);
    if (e->valor == 0) throw runtime_error("\nDivision por cero");
    return new Entero(valor / e->valor);
}

string Entero::toString() {
    return to_string(valor);
}