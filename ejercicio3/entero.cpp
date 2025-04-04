#include "entero.h"
#include <string>
#include <stdexcept>

// Uso static_cast para convertir un puntero de tipo base (Numero) a un tipo derivado (Entero) para acceder a sus atributos y metodos

// constructor: inicializa el valor del entero
Entero::Entero(int v) {valor = v;}

// implementacion de la suma entre Enteros
shared_ptr<Numero> Entero::suma(const Numero& otro){
    // se hace un cast del parametro a Entero (supongo que otro es Entero)
    const Entero& e = static_cast<const Entero&>(otro);
    return make_shared<Entero>(valor + e.valor);
}

// implementacion de la resta entre Enteros
shared_ptr<Numero> Entero::resta(const Numero& otro){
    const Entero& e = static_cast<const Entero&>(otro);
    return make_shared<Entero>(valor - e.valor);
}

// implementacion de la multiplicacion entre Enteros
shared_ptr<Numero> Entero::multiplicacion(const Numero& otro){
    const Entero& e = static_cast<const Entero&>(otro);
    return make_shared<Entero>(valor * e.valor);
}

// implementacion de la division entre Enteros
shared_ptr<Numero> Entero::division(const Numero& otro){
    const Entero& e = static_cast<const Entero&>(otro);
    if (e.valor == 0) throw runtime_error("Division por cero\n"); // control de division por cero
    return make_shared<Entero>(valor / e.valor);
}

// convierte el valor entero a string para mostrarlo
string Entero::toString() {
    return to_string(valor);
}

// getter
int Entero::getValor() {return valor;}