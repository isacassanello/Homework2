#include <iostream>
#include "tiempo.h"
using namespace std;

void mostrarMenuGeneral(){
    cout << "\n=========== MENU PRINCIPAL ===========\n";
    cout << "1. Crear reloj sin parametros\n"; 
    cout << "2. Crear reloj solo con la hora\n"; 
    cout << "3. Crear reloj con hora y minutos\n";
    cout << "4. Crear reloj con hora, minutos y segundos\n"; 
    cout << "5. Crear reloj completo (hora, minutos, segundos, periodo)\n"; 
    cout << "6. Ver reloj completo en formato 12h\n"; 
    cout << "7. Ver reloj completo en formato 24h\n"; 
    cout << "8. Modificar hora\n";
    cout << "9. Modificar minutos\n";
    cout << "10. Modificar segundos\n";
    cout << "11. Modificar periodo\n"; // si pongo pm y depsues muestro la hora en reloj 12 me tira 00, 00, 00 pm y eso no existe
    cout << "12. Mostrar componentes individuales\n"; 
    cout << "0. Salir\n";
    cout << "============================\n";
    cout << "Opcion: ";
}

void mostraMenuIndividual(){
    cout << "\n=========== MENU COMPONENTES INDIVIDUALES ===========\n";
    cout << "1. Mostrar solo hora\n";
    cout << "2. Mostrar solo minuto\n";
    cout << "3. Mostrar solo seguro\n";
    cout << "4. Mostrar solo periodo\n";
    cout << "4. Mostrar solo hora\n";
    cout << "0. Volver al menú principal\n";
    cout << "============================\n";
    cout << "Opcion: ";
}

int main(){
    Tiempo T;
    int opcion = -1;

    while (opcion != 0){
        mostrarMenuGeneral();
        cin >> opcion;

        switch(opcion){
            case 1: {
                T = Tiempo();
                cout << "Hora creada sin parametros";
                break;
            }
            case 2: {
                int hora;
                cout << "Ingrese una hora: "; cin >> hora;
                T = Tiempo(hora);
                break;
            }
            case 3: {
                int hora, minuto;
                cout << "Ingrese una hora: "; cin >> hora;
                cout << "Ingrese los minutos: "; cin >> minuto;
                T = Tiempo(hora, minuto);
                break;
            }
            case 4: {
                int hora, minuto, segundo;
                cout << "Ingrese una hora: "; cin >> hora;
                cout << "Ingrese los minutos: "; cin >> minuto;
                cout << "Ingrese los segundos: "; cin >> segundo;
                T = Tiempo(hora, minuto, segundo);    
                break;      
            }
            case 5: {
                int hora, minuto, segundo;
                string periodo;
                cout << "Ingrese una hora: "; cin >> hora;
                cout << "Ingrese los minutos: "; cin >> minuto;
                cout << "Ingrese los segundos: "; cin >> segundo;
                cout << "Ingrese el periodo: "; cin >> periodo;
                periodo = normalizarPeriodo(periodo);
                T = Tiempo(hora, minuto, segundo, periodo);  
                break;      
            }
            case 6: {
                cout << "Hora en formato 12h: ";
                T.show12h();
                break;
            }
            case 7: {
                cout << "Hora en formato 24h: ";
                T.show24h();
                break;
            }
            case 8: {
                int nuevaHora;
                cout << "Ingrese nueva hora: "; cin >> nuevaHora;
                T.setHora(nuevaHora);
                break;
            }
            case 9: {
                int nuevoMinuto;
                cout << "Ingrese nuevo munuto: "; cin >> nuevoMinuto;
                T.setMinuto(nuevoMinuto);
                break;
            }
            case 10: {
                int nuevoSegundo;
                cout << "Ingrese nuevo segundo: "; cin >> nuevoSegundo;
                T.setSegundo(nuevoSegundo);
                break;
            }
            case 11: {
                string nuevoPeriodo;
                cout << "Ingrese nuevo periodo: "; cin >> nuevoPeriodo;
                T.setPeriodo(nuevoPeriodo);
                break;
            }
            case 12: {
                int subopcion = -1;

                while (subopcion !=0) {
                    mostraMenuIndividual();
                    cin >> subopcion;

                    switch (subopcion){
                        case 1: {
                            cout << "Hora: " << T.getHora() << "h\n"; break;
                        }
                        case 2: {
                            cout << "Minutos: " << T.getMinuto() << "m\n"; break;
                        }
                        case 3: {
                            cout << "Segundos: " << T.getSegundo() << "s\n"; break;
                        }
                        case 4: {
                            cout << "Periodo: " << T.getPeriodo() << "\n"; break;
                        }
                        case 0: {
                            cout << "Volviendo al menu principal\n"; break; 
                        }
                        default:
                            cout << "Opcion invalida. Intente nuevamente\n";
                    }

                }
                break;
            }
        }
    }
    return 0;
}