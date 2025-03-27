#include "hora.h"
#include <iostream>
#include <string>
using namespace std;

// funcion que valida el valor ingresado de la hora
int validar_hora(){
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
int validar_minuto(){
    int m;
    cout << "Ingrese un minuto valido (entre 0 y 59 incluidos)";
    cin >> m;
    
    while (m < 0 || m > 59) {
        cout << "Minuto invalido. Ingrese nuevamente";
        cin >> m;
    }

    return m;
}

// funcion que valida el valor ingresado de los segundos
int validar_segundo(){
    int s;
    cout << "Ingrese un segundo valido (entre 0 y 59 incluidos)";
    cin >> s;
    
    while (s < 0 || s > 59) {
        cout << "Segundo invalido. Ingrese nuevamente";
        cin >> s;
    }

    return s;
}


// funcion que valida la hora, si esta fuera del rango, le pide al usuadrion que ingrese un numero correcto

// constrcuctores
Hora::Hora() {
    hora = minuto = segundo = 0;
    periodo = "a.m."; 
}

Hora::Hora(int h){
    if (h >= 1 && h <= 12){
        hora = h;
        minuto = segundo = 0; periodo = "a.m";
    } else {
        h = validar_hora();
        hora = h;
    }
    minuto = segundo = 0; periodo = "a.m";
}

Hora::Hora(int h, int m){
    if (h >= 1 && h <= 12 && m >= 0 && m < 60){
        hora = h;
        minuto = m; 
        segundo = 0; periodo = "a.m";
    } else {
        h = validar_hora();
        hora = h;
        m = validar_minuto();
        minuto = m;
    }
    segundo = 0; periodo = "a.m";
}

Hora::Hora(int h, int m, int s){
    if (h >= 1 && h <= 12 && m >= 0 && m < 60 && s >= 0 && s < 60){
        hora = h;
        minuto = m; 
        segundo = s;
        periodo = "a.m";
    } else {
        h = validar_hora();
        hora = h;
        m = validar_minuto();
        minuto = m;
        s = validar_segundo();
        segundo = s;
    }
    periodo = "a.m";
}

Hora::Hora(int h, int m, int s, const string&p){
    if (1 <= h && h <= 12 && m >= 0 && m < 60 && s >= 0 && s < 60 && p == "a.m" || p == "p.m"){
        hora = h; minuto = m; segundo = s; periodo = p;
    } else {
        h = validar_hora();
        hora = h;
        m = validar_minuto();
        minuto = m;
        s = validar_segundo();
        segundo = s;
        // falta validar el periodo
    }
}

// setters
void Hora::setHora(int h){
    if (h >= 1 && h <= 12) hora = h;
    else cout << "Hora invalida, debe estar entre 1 y 12 (incluidos)\n";
}

void Hora::setMinuto(int m){
    if (m >= 0 && m < 60) minuto = m;
    else cout << "Minuto/s invalio/s, debe estar entre 0 y 59 (incluidos)\n";
}

void Hora::setSegundo(int s){
    if (s >= 0 && s < 60) segundo = s;
    else cout << "Segundo/s invalio/s, debe estar entre 0 y 59 (incluidos)\n";
}

void Hora::setPeriodo(const string& p) {
    if (p == "a.m" || p == "p.m") periodo = p;
    else cout << "Periodo invalido, debe ser 'a.m' o 'p.m'.\n";
}

// getters
int Hora::getHora() {return hora;}
int Hora::getMinuto() {return minuto;}
int Hora::getSegundo() {return segundo;}
string Hora::getPeriodo() {return periodo;}