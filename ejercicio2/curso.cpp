#include "curso.h"
#include <iostream>
#include <algorithm>
using namespace std;

Curso::Curso() {}

Curso::~Curso(){
    while (!estudiantes.empty()) {
        delete estudiantes.back();
        estudiantes.pop_back();
    }
}

// inscribir estudiante (si no esta inscripto y hay lugar)
void Curso::inscribirEstudiantes(Estudiante* estudiante){
    if (estudiantes.size() >= 20){
        cout << "El curso esta completo. No se puede inscribir a " << estudiante->getNombreCompleto() << endl;
        return;
    }
    if (buscarEstudiante(estudiante->getLegajo()) != NULL) {
        cout << "El estudiante ya esta inscripto";
        return;
    }
    estudiantes.push_back(estudiante);
}

void Curso::desinscribirEstudiantes(int legajo){
    for (size_t i = 0; i < estudiantes.size(); ++i){
        if(estudiantes[i] -> getLegajo() == legajo){
            delete estudiantes[i];
            estudiantes.erase(estudiantes.begin() + i); // inicio un contador y le sumo las posiciones avanzadas para borrarlo. luego se elimina del vector
            cout << "Estudiante desinscripto correctamente";
            return;
        }
    }
    cout << "Estudiante no encontrado" << endl;
}

Estudiante* Curso::buscarEstudiante(int legajo){
    for (size_t i = 0; i < estudiantes.size(); i++){
        if (estudiantes[i] -> getLegajo() == legajo) return estudiantes[i];
    }
    return nullptr;
}


