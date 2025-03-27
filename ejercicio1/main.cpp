#include <iostream>
#include "hora.h"
using namespace std;

void mostrarMenu(){
    cout << "\n=========== MENÚ ===========\n";
    cout << "1. Crear hora sin parametros\n";
    cout << "2. Crear hora con solo la hora\n";
    cout << "3. Crear hora con hora y minutos\n";
    cout << "4. Crear hora con hora, minutos y segundos\n";
    cout << "5. Crear hora completa (hora, minutos, segundos, periodo)\n";
    cout << "6. Ver hora en formato 12h\n";
    cout << "7. Ver hora en formato 24h\n";
    cout << "8. Modificar hora\n";
    cout << "9. Modificar minutos\n";
    cout << "10. Modificar segundos\n";
    cout << "11. Modificar periodo\n";
    cout << "12. Mostrar componentes individuales y hora completa\n"; 
    cout << "0. Salir\n";
    cout << "============================\n";
    cout << "Opcion: ";
}

int main(){
    Tiempo T;
    int opcion = -1;

    while (opcion != 0){
        mostrarMenu();
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

            }
        }
    }
    
    opcion == 12 {
        cout << "\nHora actual separada:\n";
        cout << "Hora: " << h.getHora() << "h\n";
        cout << "Minutos: " << h.getMinuto() << "m\n";
        cout << "Segundos: " << h.getSegundo() << "s\n";
        cout << "Periodo: " << h.getPeriodo() << "\n";
    
        cout << "Hora completa en formato 12h: ";
        h.show12h();
    }

}