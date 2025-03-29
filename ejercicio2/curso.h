#ifndef CURSO_H
#define CURSO_H
#include "estudiante.h"
#include <vector>
using namespace std;

class Curso{
    private:
        vector<Estudiante*> estudiantes;

    public:
        // constructor
        Curso(); 

        // destructor
        ~Curso();

        // metodos para inscribir, desincribir y consultas estudiantes
        void inscribirEstudiantes(Estudiante* estudiante);
        void desinscribirEstudiantes(int legajo);
        Estudiante* buscarEstudiante(int legajo);

        // metodo para mostrar los estudiantes
        void mostrarEstudiantes();
};

#endif