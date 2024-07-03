#pragma once
#include <iostream>
#include "Transaccion.h"
using namespace std;

class Nodo{
    private:
        Transaccion* dato;
        Nodo* hijoIzq;
        Nodo* hijoDer;

    public:
        Nodo(Transaccion* dato);
        Transaccion* getDato();
        void setDato(Transaccion* dato);
        Nodo*& getHijoIzq();
        void setHijoIzq(Nodo* hijoIzq);
        Nodo*& getHijoDer();
        void setHijoDer(Nodo* hijoDer);
        ~Nodo();    
};