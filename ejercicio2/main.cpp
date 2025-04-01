#include <iostream>
#include "curso.h"
#include "estudiante.h"
using namespace std;

void mostraMenu(){
    cout << "\n===== MENU PRINCIPAL =====" << endl;
    cout << "   1. Inscribir estudiante" << endl;
    cout << "   2. Desinscribir estudiante" << endl;
    cout << "   3. Mostrar promedio final del alumno" << endl; // se hace?
    cout << "   4. Buscar estudiante por legajo" << endl;
    cout << "   5. Indicar si el curso esta completo" << endl;
    cout << "   6. Mostrar lista de estudiantes (en orden alfabetico)" << endl;
    cout << "   7. Copiar Curso" << endl;  
    cout << "   8. Salir" << endl;
    cout << "   Seleccione una opción: ";
}

int main(){
    Curso cursoOriginal;
    Curso* cursoCopia = nullptr;
    int opcion = 0;

    while (opcion != 8){
        mostraMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion){
            case 1: {
                string nombre; int legajo; int cantidadCursos;

                cout << "Ingrese nombre completo: ";
                getline(cin, nombre);

                cout << "Ingrese legajo: ";
                cin >> legajo;

                Estudiante* nuevo = new Estudiante(nombre, legajo);

                cout << "Cuantos cursos desea agregar?: ";
                cin >> cantidadCursos;
                cin.ignore();

                for (int i = 0; i < cantidadCursos; ++i) {
                    string nombreCurso;
                    float nota;

                    cout << "Nombre del curso " << (i + 1) << ": ";
                    getline(cin, nombreCurso);

                    cout << "Nota final: ";
                    cin >> nota;
                    cin.ignore();

                    nuevo->agregarCurso(nombreCurso, nota);
                }
                cursoOriginal.inscribirEstudiantes(nuevo);
                break;
            }
            case 2:{
                int legajo;
                cout << "Ingrese el legajo del estudiante a desinscribir: ";
                cin >> legajo;
                cursoOriginal.desinscribirEstudiantes(legajo);
                break;
            }
            case 3: {
                int legajo;
                cout << "Ingrese legajo del estudiante: ";
                cin >> legajo;
                Estudiante* est = cursoOriginal.buscarEstudiante(legajo);
                if (est) cout << "Promedio final: " << est->calcularPromedio() << endl;
                else cout << "Estudiante no encontrado\n";
                break;
            }
            case 4: {
                int legajo;
                cout << "Ingrese legajo del estudiante: ";
                cin >> legajo;
                Estudiante* est = cursoOriginal.buscarEstudiante(legajo);
                if (est) est->mostrarInformacion();
                else cout << "Estudiante no encontrado\n";
                break;
            }
            case 5: {
                if (cursoOriginal.estaCompleto()) cout << "El curso esta completo\n";
                else cout << "El curso NO esta completo";
                break;
            }
            case 6: {
                cursoOriginal.mostrarEstudiantes();
                break;
            }
            case 7: {
                delete cursoCopia;
                cursoCopia = new Curso(cursoOriginal);
                cout << "Curso copiado correctamente. Mostrando estudiantes del curso copiado:\n";
                cursoCopia->mostrarEstudiantes();
                break;
            }
            case 8: {
                delete cursoCopia;

            }
        }
    }
}