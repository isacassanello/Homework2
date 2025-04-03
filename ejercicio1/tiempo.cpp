#include "tiempo.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// funcion que valida el valor ingresado de la hora
int validarHora(){
    int h;
    cout << "Ingrese una hora valida (entre 1 y 12 incluidos): ";
    cin >> h;
    
    while (h < 1 || h > 12) {
        cout << "Hora invalida. Ingrese nuevamente: ";
        cin >> h;
    }

    return h;
}

// funcion que valida el valor ingresado de los minutos
int validarMinuto(){
    int m;
    cout << "Ingrese un minuto valido (entre 0 y 59 incluidos): ";
    cin >> m;
    
    while (m < 0 || m >= 60) {
        cout << "Minuto invalido. Ingrese nuevamente: ";
        cin >> m;
        break;
    }

    return m;
}

// funcion que valida el valor ingresado de los segundos
int validarSegundo(){
    int s;
    cout << "Ingrese un segundo valido (entre 0 y 59 incluidos): ";
    cin >> s;
    
    while (s < 0 || s >= 60) {
        cout << "Segundo invalido. Ingrese nuevamente: ";
        cin >> s;
    }

    return s;
}

// cuando el usuario ingrese el periodo, esta funcion modifica las entradas para estandarizar
string normalizarPeriodo(string p) {
    for (int i = 0; i < p.length(); i++) p[i] = tolower(p[i]); // convierto en minuscula lo que ingrese el usuario
    // condiciones para que no me tire error 
    if (p == "am") return "a.m";
    if (p == "pm") return "p.m";
    return p;
}

// funcion que valida el valor ingresado del periodo
const string validarPeriodo(){
    string p;
    cout << "Ingrese un periodo ('a.m' o 'p.m'): ";
    cin >> p;
    // numeric_limits<streamsize>::max(): define la cantidad maxima de caracteres a ignorar. En este caso, el maximo posible
    // '\n': es el caracter de parada. cin.ignore se detiene cuando encuentra un salto de linea
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    p = normalizarPeriodo(p);

    while (p != "a.m" && p != "p.m"){
        cout << "Periodo invalido. Ingrese nuevamente ('a.m' o 'p.m'): ";
        cin >> p;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        p = normalizarPeriodo(p);
    }

    return p;
}

// constrcuctores
Tiempo::Tiempo() {
    hora = minuto = segundo = 0;
    periodo = "a.m."; 
}

Tiempo::Tiempo(int h){
    if (h >= 1 && h <= 12) hora = h;
    else hora = validarHora();

    minuto = segundo = 0; periodo = "a.m";
}

Tiempo::Tiempo(int h, int m){
    if (h >= 1 && h <= 12) hora = h;
    else hora = validarHora();
    
    if (m >= 0 && m < 60) minuto = m;
    else minuto = validarMinuto();

    segundo = 0; periodo = "a.m";
}

Tiempo::Tiempo(int h, int m, int s){
    if (h >= 1 && h <= 12) hora = h;
    else hora = validarHora();
    
    if (m >= 0 && m < 60) minuto = m;
    else minuto = validarMinuto();
    
    if (s >= 0 && s < 60) segundo = s;
    else segundo = validarSegundo();

    periodo = "a.m";
}

Tiempo::Tiempo(int h, int m, int s, const string&p){
    if (h >= 1 && h <= 12) hora = h;
    else hora = validarHora();
    
    if (m >= 0 && m < 60) minuto = m;
    else minuto = validarMinuto();
    
    if (s >= 0 && s < 60) segundo = s;
    else segundo = validarSegundo();

    string per = normalizarPeriodo(p);
    if (per == "a.m" || per == "p.m") periodo = per;
    else periodo = validarPeriodo();
}

// setters
void Tiempo::setHora(int h){
    if (h >= 1 && h <= 12) hora = h;
    else {
        h = validarHora();
        hora = h;
    }
}

void Tiempo::setMinuto(int m){
    if (m >= 0 && m < 60) minuto = m;
    else {
        m = validarMinuto();
        minuto = m;
    }
}

void Tiempo::setSegundo(int s){
    if (s >= 0 && s < 60) segundo = s;
    else {
        s = validarSegundo();
        segundo = s;
    }
}

void Tiempo::setPeriodo(const string& p) {
    string per = normalizarPeriodo(p);
    if (per == "a.m" || per == "p.m") {
        periodo = per;
        if (hora == 0 && periodo == "p.m"){ 
            /*
            esta condicion es para el caso en el que inicio un reloj sin parametros, luego modifico el periodo a "p.m". Si en este caso
            pido que se imprima el reloj en formato 12h, me imprime 00h, 00m, 00s p.m y eso no existe. Con esta condicion, si el periodo 
            es "p.m" y la hora es 00h entonces, la hora se convierte en 12h. Y el formato imprime 12h, 00m, 00s p.m lo cual existe
            */
            hora = 12;
        }
    }
    else 
        periodo = validarPeriodo();
}

// getters
int Tiempo::getHora() const{return hora;}
int Tiempo::getMinuto() const{return minuto;}
int Tiempo::getSegundo() const{return segundo;}
string Tiempo::getPeriodo() const{return periodo;}

// funcion que muestra el reloj de 12 horas
void Tiempo::show12h(){
    cout << setw(2) << setfill('0') << hora << "h, "
         << setw(2) << setfill('0') << minuto << "m, "
         << setw(2) << setfill('0') << segundo << "s "
         << periodo << endl;
}

// funcion que muestra el reloj de 24 horas
void Tiempo::show24h() {
    int h24;

    if (periodo == "p.m" && hora != 12){
        h24 = hora + 12;
    } else if (periodo == "a.m" && hora == 12){
        h24 = 0;
    } else {
        h24 = hora;
    }

    cout << setw(2) << setfill('0') << h24 << ":"
         << setw(2) << setfill('0') << minuto << ":"
         << setw(2) << setfill('0') << segundo << endl;
}