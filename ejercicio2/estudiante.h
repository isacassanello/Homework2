#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct cursoConNota{
    string nombreCurso;
    float notaFinal;
};

class Estudiante{
    private:
        string nombreCompleto;
        int legajo;
        vector<cursoConNota> cursosConNotas;
    
    public:
        // constructores
        Estudiante(const string& nombreCompleto, int legajo);
    
        // getters
        string getNombreCompleto();
        int getLegajo();

        // manejo de los cursos
        void agregarCurso(const string& nombreCurso, float notaFinal);
        float calcularPromedio();

        // metodo para mostrar los datos del estudiante
        void mostrarInformacion();

};


#endif