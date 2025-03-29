#include "estudiante.h"
#include <iostream>
using namespace std;

// consructor
Estudiante::Estudiante(const string& nombreCompleto, int legajo) {
    this->nombreCompleto = nombreCompleto;
    this->legajo = legajo;
}

// setters
string Estudiante::getNombreCompleto() {return nombreCompleto;}
int Estudiante::getLegajo() {return legajo;}

void Estudiante::agregarCurso(const string& nombreCurso, float notaFinal) {
    cursoConNota nuevo;
    nuevo.nombreCurso = nombreCurso;
    nuevo.notaFinal = notaFinal;
    cursosConNotas.push_back(nuevo);
}

float Estudiante::calcularPromedio() {
    if (cursosConNotas.empty()) return 0.0;

    float suma = 0.0;
    for (size_t i = 0; i < cursosConNotas.size(); ++i){
        suma += cursosConNotas[i].notaFinal;
    }

    return suma/cursosConNotas.size();
}

void Estudiante::mostrarInformacion(){
    cout << "Nombre: " << nombreCompleto << endl;
    cout << "Legajo: " << legajo << endl;
    cout << "Promedio: " << calcularPromedio() << endl;

}
