#ifndef CURSO_H
#define CURSO_H
#include "estudiante.h"
#include <vector>
#include <memory> // para usar shared_ptr
using namespace std;

// Clase Curso: representa un curso con una lista de estudiantes
// uso shared_ptr porque me permite que varios cursos compartan a un mismo estudiante, y cuando ningun curso lo necesite mas, se libera automatiamente

class Curso{
    private:
        vector<shared_ptr<Estudiante>> estudiantes; // lista de estudiantes inscriptos en el curso

    public:
        // constructor por defecto
        Curso();
        
        // constructor copia
        Curso(const Curso& otro);

        // metodos para inscribir, desincribir y consultar estudiantes
        void inscribirEstudiantes(shared_ptr<Estudiante> estudiante);
        void desinscribirEstudiantes(int legajo);
        shared_ptr<Estudiante> buscarEstudiante(int legajo);

        // consulta si el curso esta completo (20 alumnos) o vacio
        bool estaCompleto();
        bool estaVacio();

        // metodo para mostrar los estudiantes
        void mostrarEstudiantes();
};

#endif