#include <iostream>
#include "curso.h"
#include "estudiante.h"
using namespace std;

void mostraMenu(){
    cout << "\n===== MENU PRINCIPAL =====" << endl;
    cout << "1. Inscribir estudiante" << endl;
    cout << "2. Desinscribir estudiante" << endl;
    cout << "3. Buscar estudiante por legajo" << endl;
    cout << "4. Mostrar lista de estudiantes (orden alfabetico)" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main(){
    Curso curso;
    int opcion;

    while (opcion != 5){
        mostraMenu();
        cin >> opcion;

        switch(opcion){
            case 1: {
                cin.ignore();
                string nombre; int legajo; int cantidadCursos;

                cout << "Ingrese nombre completo: ";
                getline(cin, nombre);

                cout << "Ingrese legajo: ";
                cin >> legajo;

                Estudiante* nuevo = new Estudiante(nombre, legajo);

                cout << "Cuantos cursos desea agregar? ";
                cin >> cantidadCursos;

                for (int i = 0; i < cantidadCursos; ++i) {
                    cin.ignore();
                    string nombreCurso;
                    float nota;

                    cout << "Nombre del curso " << (i + 1) << ": ";
                    getline(cin, nombreCurso);

                    cout << "Nota final: ";
                    cin >> nota;

                    nuevo->agregarCurso(nombreCurso, nota);
                }
                curso.inscribirEstudiantes(nuevo);
                break;
            }
            case 2:{

            }
        }
    }
}