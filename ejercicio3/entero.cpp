#include "entero.h"
#include <string>
#include <stdexcept>

Entero::Entero(int v) {valor = v;}

int Entero::getValor() {return valor;}

shared_ptr<Numero> Entero::suma(const Numero& otro){
    const Entero& e = static_cast<const Entero&>(otro);
    return make_shared<Entero>(valor + e.valor);
}

shared_ptr<Numero> Entero::resta(const Numero& otro){
    const Entero& e = static_cast<const Entero&>(otro);
    return make_shared<Entero>(valor - e.valor);
}

shared_ptr<Numero> Entero::multiplicacion(const Numero& otro){
    const Entero& e = static_cast<const Entero&>(otro);
    return make_shared<Entero>(valor & e.valor);
}

shared_ptr<Numero> Entero::division(const Numero& otro){
    const Entero& e = static_cast<const Entero&>(otro);
    if (e.valor == 0) throw runtime_error("Division por cero\n");
    return make_shared<Entero>(valor / e.valor);
}

string Entero::toString() {
    return to_string(valor);
}