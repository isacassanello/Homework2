#include "curso.h"
#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;

// constructor por defecto: no necesita inicializar nada explicitamente
Curso::Curso() {}

// constructor copia (shallow copy): copia el vector de shared_ptr
Curso::Curso(const Curso& otro) {
    estudiantes = otro.estudiantes; // los shared_ptr se copian
}
/*
Justificación:
Una SHALLOW COPY es peligrosa si uso raw_ptr, porque copias solo las direcciones de los punteros, lo que puede generar problemas
de que si hago un delete del objeto en la copia, me puede hacer ese mismo delete en el original (doble delete) ya que ambos cursos 
apuntan a los mismos objetos. Pero al usar shared_ptr, evito ese problema. Aunque siga copiando punteros, cuando ningun shared_ptr 
apunta mas al objeto, el objeto se destruye automaticamente, no necesito hacer delete, ni preocuparme por liberar memoria. Por eso, 
en este caso si es seguro hacer una shallow copy, porque los estudiantes deben ser compartidos entre cursos, y shared_ptr lo permite 
sin necesidad de hacer deep copy.
*/

// inscribir estudiante (si no esta inscripto y hay lugar)
void Curso::inscribirEstudiantes(shared_ptr<Estudiante> estudiante){
    if (estaCompleto()){
        cout << "\nEl curso esta completo. No se puede inscribir a " << estudiante->getNombreCompleto() << "\n" << endl;
        return;
    }
    // evita duplicados: verifica que el legajo no este repetido
    if (buscarEstudiante(estudiante->getLegajo()) != NULL) {
        cout << "\nEl estudiante ya esta inscripto\n";
        return;
    }
    // agrega el estudiante al vector
    estudiantes.push_back(estudiante);
}

// desinscribe un estudiante por legajo (lo elimina del vector)
void Curso::desinscribirEstudiantes(int legajo){
    for (size_t i = 0; i < estudiantes.size(); ++i){
        if(estudiantes[i] -> getLegajo() == legajo){
            estudiantes.erase(estudiantes.begin() + i); // inicio un contador y le sumo las posiciones avanzadas para borrarlo. luego se elimina del vector
            // el shared_ptr se destruye automaticamente si ya no es compartido
            cout << "Estudiante desinscripto correctamente\n";
            return;
        }
    }
    cout << "Estudiante no encontrado\n" << endl;
}

// busca un estudiante por legajo y devuelve un shared_ptr al mismo
shared_ptr<Estudiante> Curso::buscarEstudiante(int legajo){
    for (size_t i = 0; i < estudiantes.size(); i++){
        shared_ptr<Estudiante> actual = estudiantes[i]; // puntero al estudiante en posicion i
        if (actual -> getLegajo() == legajo) return actual;
    }
    return nullptr;
}

// devuelve true si ya hay 20 estudiantes
bool Curso::estaCompleto(){
    return estudiantes.size() >= 20;
}

// devuelve true si no hay ningun estudiante inscripto
bool Curso::estaVacio() {
    return estudiantes.empty();
}

// funcion auxiliar para comparar estudiantes por nombre (para ordenar)
bool compararEstudiantes(shared_ptr<Estudiante> a, shared_ptr<Estudiante> b) {
    return *a < *b;
}

// muestra los estudiantes en orden alfabetico
void Curso::mostrarEstudiantes(){
    // copia del vector para no modificar el original
    vector<shared_ptr<Estudiante>> copia = estudiantes; 

    // ordeno la copia
    sort(copia.begin(), copia.end(), compararEstudiantes);

    // recorro la copia e imprimo los nombres ordenados
    for (size_t i = 0; i < copia.size(); i++) {
        if (copia[i]){
            cout << "\nEstudiante " << i + 1 << ": ";
            cout << *copia[i] << endl;
        } else cout << "Estudiante en posicion " << i << " es nullptr" << endl;
    }
}

