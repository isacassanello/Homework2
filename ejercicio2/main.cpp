#include <iostream>
#include "curso.h"
#include <memory>
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
    cout << "   0. Salir" << endl;
    cout << "   Seleccione una opción: ";
}

// funcion que valida que el numero ingresado sea un entero positivo
int pedirEnteroPositivo(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor <= 0) {
            cin.clear(); // limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta entrada invalida
            cout << "\nEntrada invalida. Ingrese un numero entero positivo\n";
        } else {
            cin.ignore(); // limpia el \n que queda en el buffer
            return valor;
        }
    }
}

int main(){
    Curso cursoOriginal;
    Curso* cursoCopia = nullptr;
    int opcion = -1;

    while (opcion != 0){
        mostraMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion){
            case 1: {
                string nombre; 
                cout << "\nIngrese nombre completo: ";
                getline(cin, nombre);

                int legajo = pedirEnteroPositivo("Ingrese legajo (entero positivo): ");
                int cantidadCursos = pedirEnteroPositivo("Cuantos cursos desea agregar?: ");

                shared_ptr<Estudiante> nuevo = make_shared<Estudiante>(nombre, legajo);

                for (int i = 0; i < cantidadCursos; ++i) {
                    string nombreCurso;
                    float nota;

                    cout << "Nombre del curso " << (i + 1) << ": ";
                    getline(cin, nombreCurso);

                    // condiciones para la nota asi no se me rompe el programa
                    while (true){
                        cout << "Nota final: ";
                        cin >> nota;

                        if (cin.fail() || nota < 0 || nota > 10){
                            cin.clear(); 
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta la entrada inválida
                            cout << "\nIngrese una nota valida entre 0 y 10 (solo numeros)\n";
                        } else {
                            cin.ignore();
                            break;
                        }
                    }
                    nuevo->agregarCurso(nombreCurso, nota);
                }
                cursoOriginal.inscribirEstudiantes(nuevo);
                break;
            }
            case 2:{
                int legajo = pedirEnteroPositivo("\nIngrese el legajo del estudiante a desinscribir: ");
                cursoOriginal.desinscribirEstudiantes(legajo);
                break;
            }
            case 3: {
                int legajo = pedirEnteroPositivo("Ingrese legajo del estudiante: ");
                shared_ptr<Estudiante> est = cursoOriginal.buscarEstudiante(legajo);
                if (est) cout << "Promedio final: " << est->calcularPromedio() << endl;
                else cout << "Estudiante no encontrado\n";
                break;
            }
            case 4: {
                int legajo = pedirEnteroPositivo("Ingrese legajo del estudiante: ");
                shared_ptr<Estudiante> est = cursoOriginal.buscarEstudiante(legajo);
                if (est) est->mostrarInformacion();
                else cout << "\nEstudiante no encontrado\n";
                break;
            }
            case 5: {
                if (cursoOriginal.estaCompleto()) cout << "\nEl curso esta completo\n";
                else cout << "\nEl curso NO esta completo\n";
                break;
            }
            case 6: {
                if (cursoOriginal.estaVacio()) cout << "El curso esta vacio, no hay estudiantes para mostar" << endl;
                else cursoOriginal.mostrarEstudiantes();

                break;
            }
            case 7: {
                if (cursoCopia != nullptr) {
                    delete cursoCopia;
                }

                cursoCopia = new Curso(cursoOriginal);  // Crear una nueva copia
                cout << "\nCurso copiado correctamente. Mostrando estudiantes del curso copiado:\n";
                cursoCopia->mostrarEstudiantes();
                break;
            }
            case 0: {
                cout << "Saliendo del programa";
                break;

            }
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    }
    return 0;
}

/*
PUNTO C

La relación entre los objetos Curso y Estudiante en esta implementación es de composicion, ya que el Curso contiene punteros a objetos 
Estudiante y controla su ciclo de vida. Esto significa que, si un curso se destruye, los estudiantes que contiene tambien son eliminados.
*/