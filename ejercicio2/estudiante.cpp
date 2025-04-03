#include "estudiante.h"
#include <iostream>
#include <algorithm>
using namespace std;

// constructor
Estudiante::Estudiante(const string& nombreCompleto, int legajo) {
    this->nombreCompleto = nombreCompleto;
    this->legajo = legajo;
}

// getters
string Estudiante::getNombreCompleto() {return nombreCompleto;}
int Estudiante::getLegajo() {return legajo;}
vector<cursoConNota> Estudiante::getCursosConNotas() const {return cursosConNotas;}

void Estudiante::agregarCurso(const string& nombreCurso, float notaFinal) {
    cursoConNota nuevo;
    nuevo.nombreCurso = nombreCurso;
    nuevo.notaFinal = notaFinal;
    cursosConNotas.push_back(nuevo);
}

float Estudiante::calcularPromedio() const {
    if (cursosConNotas.empty()) return 0.0;

    float suma = 0.0;
    for (size_t i = 0; i < cursosConNotas.size(); ++i){
        suma += cursosConNotas[i].notaFinal;
    }

    return suma/cursosConNotas.size();
}

bool Estudiante::operator < (const Estudiante& otro) const {
    return nombreCompleto < otro.nombreCompleto;
}

ostream& operator<<(ostream& os, const Estudiante& est) {
    os << "Nombre: " << est.nombreCompleto << " | Legajo: " << est.legajo << " | Promedio: " << est.calcularPromedio();
    return os;
}

void Estudiante::mostrarInformacion(){
    cout << "\nNombre: " << nombreCompleto << endl;
    cout << "Legajo: " << legajo << endl;
    cout << "Promedio: " << calcularPromedio() << endl;
}
