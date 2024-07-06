#pragma once
#include <queue>
#include <string>
#include "Transaccion.h"

using namespace std;

class Cuenta {
    private:
        string numeroCuenta;
        int cantidadTransacciones;
        queue<Transaccion*> transacciones;

    public:
        Cuenta(string numeroCuenta);
        string getNumeroCuenta();
        void setNumeroCuenta(string numeroCuenta);
        int getCantidadTransacciones();
        void setCantidadTransacciones(int cantidadTransacciones);
        void incrementarTransacciones(Transaccion* transaccion);
        queue<Transaccion*>& getTransacciones();
        ~Cuenta();
};
