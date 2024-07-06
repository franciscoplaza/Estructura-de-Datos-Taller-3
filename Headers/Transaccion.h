#pragma once
#include <iostream>
using namespace std;

class Transaccion{
    private:
        int id;
        string cuenta_origen;
        string cuenta_destino;
        int monto;
        string ubicacion;
        string fecha;
        string hora;

    public:
        Transaccion(int id, string cuenta_origen, string cuenta_destino, int monto, string ubicacion, string fecha, string hora);
        int getId();
        void setId(int id);
        string getCuentaOrigen();
        void setCuentaOrigen(string cuenta_origen);
        string getCuentaDestino();
        void setCuentaDestino(string cuenta_destino);
        int getMonto();
        void setMonto(int monto);
        string getUbicacion();
        void setUbicacion(string ubicacion);
        string getFecha();
        void setFecha(string fecha);
        string getHora();
        void setHora(string hora);
        ~Transaccion();
};