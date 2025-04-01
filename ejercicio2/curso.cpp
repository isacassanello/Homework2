#include "curso.h"
#include <iostream>
#include <algorithm>
using namespace std;

Curso::Curso() {}

// copia de Curso con DEEP COPY
Curso::Curso(const Curso& otro){
    // recorro los punteros a estudiantes que hay en el Curso original ('otro')
    for (size_t i = 0; i < otro.estudiantes.size(); ++i){
        Estudiante* original = otro.estudiantes[i];
        if (!original) continue;

        string nombre = original->getNombreCompleto();
        int legajo = original->getLegajo();

        // creo un nuevo estudiante copiando nombre y legajo
        Estudiante* copia = new Estudiante(nombre, legajo);

        // copio los cursos y las notas
        vector<cursoConNota> cursos = original->getCursosConNotas();
        for (size_t j = 0; j < cursos.size(); ++j) {
            copia->agregarCurso(cursos[j].nombreCurso, cursos[j].notaFinal);
        }

        estudiantes.push_back(copia);
    }
}
/*
 Justificacion:
 Curso contiene punteros a objetos Estudiante, una Shallow Copy solo copiaria la direccion de los punteros, lo que puede generar problemas
 de que si hago un delete del objeto en la copia, me puede hacer ese mismo delete en el original (doble delete) ya que ambos cursos apuntan
 a los mismos objetos. Por eso, hago una DEEP COPY de la clase Curso, creo un nuevo obejeto. Cada estudiante original es clonado usando el 
 constructor copia, para que el nuevo curso tenga sus propias instancias independientes
*/

// inscribir estudiante (si no esta inscripto y hay lugar)
void Curso::inscribirEstudiantes(Estudiante* estudiante){
    if (estaCompleto()){
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
            cout << "Estudiante desinscripto correctamente\n";
            return;
        }
    }
    cout << "Estudiante no encontrado\n" << endl;
}

Estudiante* Curso::buscarEstudiante(int legajo){
    for (size_t i = 0; i < estudiantes.size(); i++){
        if (estudiantes[i] -> getLegajo() == legajo) return estudiantes[i];
    }
    return nullptr;
}

bool Curso::estaCompleto(){
    return estudiantes.size() >= 20;
}

// funcion comparadora
bool compararEstudiantes(Estudiante* a, Estudiante* b) {
    return *a < *b;
}

void Curso::mostrarEstudiantes(){
    // copia del vector para no modificar el original
    vector<Estudiante*> copia = estudiantes; 

    // ordeno la copia
    sort(copia.begin(), copia.end(), compararEstudiantes);

    // recorro la copia e imprimo los nombres ordenados
    for (size_t i = 0; i < copia.size(); i++) {
        if (copia[i]){
            cout << "Estudiante " << i + 1 << ": ";
            cout << *copia[i] << endl;
        } else cout << "Estudiante en posicion " << i << " es nullptr" << endl;
    }
}

