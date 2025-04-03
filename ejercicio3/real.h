#ifndef REAL_H
#define REAL_H
#include "numero.h"
 
class Real : public Numero {
    private:
        double valor;

    public:
        Real(double v);
        shared_ptr<Numero> suma(const Numero& otro) override;
        shared_ptr<Numero> resta(const Numero& otro) override;
        shared_ptr<Numero> multiplicacion(const Numero& otro) override;
        shared_ptr<Numero> division(const Numero& otro) override;
        string toString() override;
        
        // getter
        double getValor();
};

#endif