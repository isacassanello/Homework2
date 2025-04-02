#include <iostream>
#include "entero.h"
#include "real.h"
#include "complejo.h"
using namespace std;

int main(){
    // ENTEROS
    Entero* e1 = new Entero(5);
    Entero* e2 = new Entero(10);

    cout << "\n=========ENTEROS=========" << endl;
    cout << "e1 = " << e1->toString() << endl;
    cout << "e2 = " << e2->toString() << endl;
    cout << "Suma: " << e1->suma(e2)->toString() << endl;
    cout << "Resta: " << e1->resta(e2)->toString() << endl;
    cout << "Multiplicacion: " << e1->multiplicacion(e2)->toString() << endl;
    cout << "Division: " << e1->division(e2)->toString() << "\n" << endl;

    // REALES
    Real* r1 = new Real(7.5);
    Real* r2 = new Real(2.5); 

    cout << "\n=========REALES=========" << endl;
    cout << "r1 = " << r1->toString() << endl;
    cout << "r2 = " << r2->toString() << endl;
    cout << "Suma: " << r1->suma(r2)->toString() << endl;
    cout << "Resta: " << r1->resta(r2)->toString() << endl;
    cout << "Multiplicacion: " << r1->multiplicacion(r2)->toString() << endl;
    cout << "Division: " << r1->division(r2)->toString() << "\n" << endl;

    // COMPLEJOS
    Complejo* c1 = new Complejo(4, 3);
    Complejo* c2 = new Complejo(4, -2);

    cout << "\n=========COMPLEJOS=========" << endl;
    cout << "c1 = " << c1->toString() << endl;
    cout << "c2 = " << c2->toString() << endl;
    cout << "Suma: " << c1->suma(c2)->toString() << endl;
    cout << "Resta: " << c1->resta(c2)->toString() << endl;
    cout << "Multiplicacion: " << c1->multiplicacion(c1)->toString() << endl;
    try {
        Numero* resultado = c1->division(c2);
        cout << "Division: " << resultado->toString() << "\n" << endl;
        delete resultado;
    } catch (const exception& e) {
        cout << "\nError al dividir: " << e.what() << endl;
    }

    delete e1; delete e2;
    delete r1; delete r2;
    delete c1; delete c2;

    return 0;
}