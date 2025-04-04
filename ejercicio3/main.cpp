#include <iostream>
#include "entero.h"
#include "real.h"
#include "complejo.h"
using namespace std;

int main(){
    // ENTEROS
    shared_ptr<Numero> e1 = make_shared<Entero>(5);
    shared_ptr<Numero> e2 = make_shared<Entero>(10);

    cout << "\n=========ENTEROS=========" << endl;
    cout << "e1 = " << e1->toString() << endl;
    cout << "e2 = " << e2->toString() << endl;
    cout << "Suma: " << e1->suma(*e2)->toString() << endl;
    cout << "Resta: " << e1->resta(*e2)->toString() << endl;
    cout << "Multiplicacion: " << e1->multiplicacion(*e2)->toString() << endl;
    cout << "Division: " << e1->division(*e2)->toString() << "\n" << endl;

    // REALES
    shared_ptr<Numero> r1 = make_shared<Real>(7.5);
    shared_ptr<Numero> r2 = make_shared<Real>(2.5); 

    cout << "\n=========REALES=========" << endl;
    cout << "r1 = " << r1->toString() << endl;
    cout << "r2 = " << r2->toString() << endl;
    cout << "Suma: " << r1->suma(*r2)->toString() << endl;
    cout << "Resta: " << r1->resta(*r2)->toString() << endl;
    cout << "Multiplicacion: " << r1->multiplicacion(*r2)->toString() << endl;
    cout << "Division: " << r1->division(*r2)->toString() << "\n" << endl;

    // COMPLEJOS
    shared_ptr<Numero> c1 = make_shared<Complejo>(4, 3);
    shared_ptr<Numero> c2 = make_shared<Complejo>(4, -2);

    cout << "\n=========COMPLEJOS=========" << endl;
    cout << "c1 = " << c1->toString() << endl;
    cout << "c2 = " << c2->toString() << endl;
    cout << "Suma: " << c1->suma(*c2)->toString() << endl;
    cout << "Resta: " << c1->resta(*c2)->toString() << endl;
    cout << "Multiplicacion: " << c1->multiplicacion(*c2)->toString() << endl;
    cout << "Division: " << c1->division(*c2)->toString() << "\n" << endl;

    // DIVISION POR CERO
    cout << "\n=========DIVISION POR CERO=========" << endl;

    cout << "ENTEROS" << endl;
    shared_ptr<Numero> e3 = make_shared<Entero>(8);
    shared_ptr<Numero> e4 = make_shared<Entero>(0);
    try {
        shared_ptr<Numero> resultado = e3->division(*e4);
        cout << "Division " << resultado->toString() << "\n" << endl;
    } catch (const exception& e) {
        cout << "Error al dividir enteros: " << e.what() << endl;
    }

    cout << "\nREALES" << endl;
    shared_ptr<Numero> r3 = make_shared<Real>(3.3);
    shared_ptr<Numero> r4 = make_shared<Real>(0.0);
    try {
        shared_ptr<Numero> resultado = r3->division(*r4);
        cout << "Division " << resultado->toString() << "\n" << endl;
    } catch (const exception& e) {
        cout << "Error al dividir reales: " << e.what() << endl;
    }

    cout << "\nCOMPLEJOS" << endl;
    shared_ptr<Numero> c3 = make_shared<Complejo>(1, 2);
    shared_ptr<Numero> c4 = make_shared<Complejo>(0, 0);
    try {
        shared_ptr<Numero> resultado = c3->division(*r4);
        cout << "Division " << resultado->toString() << "\n" << endl;
    } catch (const exception& e) {
        cout << "Error al dividir complejos: " << e.what() << endl;
    }

    return 0;
}