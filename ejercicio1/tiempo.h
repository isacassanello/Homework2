#ifndef TIEMPO_H
#define TIEMPO_H
#include <string>
using namespace std;

class Tiempo{
    private: 
        int hora; // horas del 1 al 12
        int minuto; // mins del 0 al 59
        int segundo; // segs del 0 al 59
        string periodo; // a.m o p.m

    public:
        // constructores
        Tiempo(); // sin parametros -. 0h, 0m, 0s a.m
        Tiempo(int h); // solo hora
        Tiempo(int h, int m); // hora y minutos
        Tiempo(int h, int m, int s); // hora, minutos y segundos
        Tiempo(int h, int m, int s, const string& p); // hora, minutos, segundos y periodo

        // setters
        void setHora(int h);
        void setMinuto(int m);
        void setSegundo(int s);
        void setPeriodo(const string& p);

        // setters
        int getHora();
        int getMinuto();
        int getSegundo();
        string getPeriodo();

        // metodos para mostrar la hora
        void show12h();
        void show24h();
};

string normalizarPeriodo(string p); // puedp esto?

#endif