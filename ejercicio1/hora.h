#ifndef HORA_H
#define HORA_H
#include <string>
using namespace std;


class Hora{
    private: 
        int hora; // horas del 1 al 12
        int minuto; // mins del 0 al 59
        int segundo; // segs del 0 al 59
        string periodo; // a.m o p.m

    public:
        Hora(); // sin parametros -. 0h, 0m, 0s a.m
        Hora(int h); // solo hora
        Hora(int h, int m); // hora y minutos
        Hora(int h, int m, int s); // hora, minutos y segundos
        Hora(int h, int m, int s, const string& p); // hora, minutos, segundos y periodo

        void setHora(int h);
        void setMinuto(int m);
        void setSegundo(int s);
        void setPeriodo(const string& p);

        int getHora();
        int getMinuto();
        int getSegundo();
        std::string getPeriodo();

        void mostrar12h();
        void mostrar24h();
};

#endif