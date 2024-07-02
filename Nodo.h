#pragma once
#include <iostream>
using namespace std;

class Nodo{
    private:
        int dato;
        Nodo* hijoIzq;
        Nodo* hijoDer;

    public:
        Nodo(int dato);
        int getDato();
        void setDato(int dato);
        Nodo* getHijoIzq();
        void setHijoIzq(Nodo* hijoIzq);
        Nodo* getHijoDer();
        void setHijoDer(Nodo* hijoDer);
        ~Nodo();    
};