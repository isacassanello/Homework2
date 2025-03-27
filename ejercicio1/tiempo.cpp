#include "tiempo.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// funcion que valida el valor ingresado de la hora
int validarHora(){
    int h;
    cout << "Ingrese una hora valida (entre 1 y 12 incluidos)";
    cin >> h;
    
    while (h < 1 || h > 12) {
        cout << "Hora invalida. Ingrese nuevamente";
        cin >> h;
    }

    return h;
}

// funcion que valida el valor ingresado de los minutos
int validarMinuto(){
    int m;
    cout << "Ingrese un minuto valido (entre 0 y 59 incluidos)";
    cin >> m;
    
    while (m < 0 || m >= 60) {
        cout << "Minuto invalido. Ingrese nuevamente";
        cin >> m;
    }

    return m;
}

// funcion que valida el valor ingresado de los segundos
int validarSegundo(){
    int s;
    cout << "Ingrese un segundo valido (entre 0 y 59 incluidos)";
    cin >> s;
    
    while (s < 0 || s >= 60) {
        cout << "Segundo invalido. Ingrese nuevamente";
        cin >> s;
    }

    return s;
}

// funcion que valida el valor ingresado del periodo
const string validarPeriodo(){
    string p;
    cout << "Ingrese un periodo ('a.m' o 'p.m')";
    cin >> p;

    while (p != "a.m" || p != "p.m"){
        cout << "Periodo invalido. Ingrese nuevamente";
        cin >> p;
    }

    return p;
}

// constrcuctores
Tiempo::Tiempo() {
    hora = minuto = segundo = 0;
    periodo = "a.m."; 
}

Tiempo::Tiempo(int h){
    if (h >= 1 && h <= 12){
        hora = h;
        minuto = segundo = 0; periodo = "a.m";
    } else {
        h = validarHora();
        hora = h;
    }
    minuto = segundo = 0; periodo = "a.m";
}

Tiempo::Tiempo(int h, int m){
    if (h >= 1 && h <= 12 && m >= 0 && m < 60){
        hora = h;
        minuto = m; 
        segundo = 0; periodo = "a.m";
    } else {
        h = validarHora();
        hora = h;
        m = validarMinuto();
        minuto = m;
    }
    segundo = 0; periodo = "a.m";
}

Tiempo::Tiempo(int h, int m, int s){
    if (h >= 1 && h <= 12 && m >= 0 && m < 60 && s >= 0 && s < 60){
        hora = h;
        minuto = m; 
        segundo = s;
        periodo = "a.m";
    } else {
        h = validarHora();
        hora = h;
        m = validarMinuto();
        minuto = m;
        s = validarSegundo();
        segundo = s;
    }
    periodo = "a.m";
}

Tiempo::Tiempo(int h, int m, int s, const string&p){
    if (1 <= h && h <= 12 && m >= 0 && m < 60 && s >= 0 && s < 60 && p == "a.m" || p == "p.m"){
        hora = h; minuto = m; segundo = s; periodo = p;
    } else {
        h = validarHora();
        hora = h;
        m = validarMinuto();
        minuto = m;
        s = validarSegundo();
        segundo = s;
        string per = validarPeriodo();
        periodo = per;
    }
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
    if (p == "a.m" || p == "p.m") periodo = p;
    else {
        string per = validarPeriodo();
        periodo = per;
    }
}

// getters
int Tiempo::getHora() {return hora;}
int Tiempo::getMinuto() {return minuto;}
int Tiempo::getSegundo() {return segundo;}
string Tiempo::getPeriodo() {return periodo;}

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