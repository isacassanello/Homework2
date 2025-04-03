#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// estructura auxiliar para guardar el nombre de un curso y su nota final
struct cursoConNota{
    string nombreCurso;
    float notaFinal;
};

class Estudiante{
    private:
        string nombreCompleto;
        int legajo;
        vector<cursoConNota> cursosConNotas; // lista de cursos que el estudiante curso con su nota final
    
    public:
        // constructor: inicializa un estudiante con su nombre y legajo
        Estudiante(const string& nombreCompleto, int legajo);
    
        // getters: para acceder a los datos privados del estudiante
        string getNombreCompleto();
        int getLegajo();
        vector<cursoConNota> getCursosConNotas() const; // devuelve la lista de cursos con notas (const para seguridad de que no se altere el estado del estudiante por accidente)

        // manejo de los cursos
        void agregarCurso(const string& nombreCurso, float notaFinal); // agrega un curso con su nota final a la lista del estudiante
        float calcularPromedio() const; // calcula el promedio general de todas las notas del estudiante

        bool operator < (const Estudiante& otro) const; // sobrecarga del operador < para ordenar estudiantes alfabeticamente por nombre
        friend ostream& operator<<(ostream& os, const Estudiante& est); // sobrecarga del operador << para imprimir los datos del estudiante

        // metodo para mostrar los datos del estudiante
        void mostrarInformacion();
};


#endif