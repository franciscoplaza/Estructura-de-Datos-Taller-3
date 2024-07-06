#include <iostream>
#include "../Headers/Transaccion.h"
using namespace std;

Transaccion::Transaccion(int id, string cuenta_origen, string cuenta_destino, int monto, string ubicacion, string fecha, string hora){
    this->id = id;
    this->cuenta_origen = cuenta_origen;
    this->cuenta_destino = cuenta_destino;
    this->monto = monto;
    this->ubicacion = ubicacion;
    this->fecha = fecha;
    this->hora = hora;
}

int Transaccion::getId(){
    return id;
}

void Transaccion::setId(int id){
    this->id = id;
}

string Transaccion::getCuentaOrigen(){
    return cuenta_origen;
}

void Transaccion::setCuentaOrigen(string cuenta_origen){
    this->cuenta_origen = cuenta_origen;
}

string Transaccion::getCuentaDestino(){
    return cuenta_destino;
}

void Transaccion::setCuentaDestino(string cuenta_destino){
    this->cuenta_destino = cuenta_destino;
}

int Transaccion::getMonto(){
    return monto;
}

void Transaccion::setMonto(int monto){
    this->monto = monto;
}

string Transaccion::getUbicacion(){
    return ubicacion;
}

void Transaccion::setUbicacion(string ubicacion){
    this->ubicacion = ubicacion;
}

string Transaccion::getFecha(){
    return fecha;
}

void Transaccion::setFecha(string fecha){
    this->fecha = fecha;
}

string Transaccion::getHora(){
    return hora;
}

void Transaccion::setHora(string hora){
    this->hora = hora;
}

Transaccion::~Transaccion(){};