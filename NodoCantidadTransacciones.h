#pragma once
#include <queue>
#include "Cuenta.h"

using namespace std;

class NodoCantidadTransacciones {
    private:
        int cantidad;
        queue<Cuenta*> cuentas;
        NodoCantidadTransacciones* hijoIzq;
        NodoCantidadTransacciones* hijoDer;

    public:
        NodoCantidadTransacciones(int cantidad);
        int getCantidad();
        void setCantidad(int cantidad);
        queue<Cuenta*>& getCuentas();
        NodoCantidadTransacciones*& getHijoIzq();
        void setHijoIzq(NodoCantidadTransacciones* hijoIzq);
        NodoCantidadTransacciones*& getHijoDer();
        void setHijoDer(NodoCantidadTransacciones* hijoDer);
        void agregarCuenta(Cuenta* cuenta);
        ~NodoCantidadTransacciones();
};
