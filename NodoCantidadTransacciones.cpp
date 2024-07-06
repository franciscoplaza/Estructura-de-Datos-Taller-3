#include <iostream>
#include "NodoCantidadTransacciones.h"
#include "Cuenta.h"

using namespace std;

NodoCantidadTransacciones::NodoCantidadTransacciones(int cantidad) {
    this->cantidad = cantidad;
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
}

int NodoCantidadTransacciones::getCantidad() {
    return cantidad;
}

void NodoCantidadTransacciones::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

queue<Cuenta*>& NodoCantidadTransacciones::getCuentas() {
    return cuentas;
}

NodoCantidadTransacciones*& NodoCantidadTransacciones::getHijoIzq() {
    return hijoIzq;
}

void NodoCantidadTransacciones::setHijoIzq(NodoCantidadTransacciones* hijoIzq) {
    this->hijoIzq = hijoIzq;
}

NodoCantidadTransacciones*& NodoCantidadTransacciones::getHijoDer() {
    return hijoDer;
}

void NodoCantidadTransacciones::setHijoDer(NodoCantidadTransacciones* hijoDer) {
    this->hijoDer = hijoDer;
}

void NodoCantidadTransacciones::agregarCuenta(Cuenta* cuenta) {
    cuentas.push(cuenta);
}

NodoCantidadTransacciones::~NodoCantidadTransacciones() {};
