#ifndef TIEMPO_H
#define TIEMPO_H
#include <string>
using namespace std;

class Tiempo{
    private: 
        int hora; // horas del 1 al 12
        int minuto; // minutos del 0 al 59
        int segundo; // segundos del 0 al 59
        string periodo; // "a.m" o "p.m"

    public:
        // constructores sobrecargados
        Tiempo(); // sin parametros -> 00h, 00m, 00s a.m
        Tiempo(int h); // solo hora -> HHh, 00m, 00s a.m
        Tiempo(int h, int m); // hora y minutos -> HHh, MMm, 00s a.m
        Tiempo(int h, int m, int s); // hora, minutos y segundos -> HHh, MMm, SSs a.m
        Tiempo(int h, int m, int s, const string& p); // hora, minutos, segundos y periodo -> HHh, MMm, SSs a.m/p.m

        // setters: permiten modificar cada componente con validacion
        void setHora(int h);
        void setMinuto(int m);
        void setSegundo(int s);
        void setPeriodo(const string& p);

        // getters: obtengo el valor actual de cada componente
        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;
        string getPeriodo() const;

        // metodos para mostrar la hora
        void show12h(); 
        void show24h();
};

string normalizarPeriodo(string p);

#endif