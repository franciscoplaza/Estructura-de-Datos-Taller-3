#include <iostream>
#include "Cuenta.h"

using namespace std;

Cuenta::Cuenta(string numeroCuenta) {
    this->numeroCuenta = numeroCuenta;
    this->cantidadTransacciones = 0;
}

string Cuenta::getNumeroCuenta() {
    return numeroCuenta;
}

void Cuenta::setNumeroCuenta(string numeroCuenta) {
    this->numeroCuenta = numeroCuenta;
}

int Cuenta::getCantidadTransacciones() {
    return cantidadTransacciones;
}

void Cuenta::setCantidadTransacciones(int cantidadTransacciones) {
    this->cantidadTransacciones = cantidadTransacciones;
}

void Cuenta::incrementarTransacciones(Transaccion* transaccion) {
    transacciones.push(transaccion);
    cantidadTransacciones++;
}

queue<Transaccion*>& Cuenta::getTransacciones() {
    return transacciones;
}

Cuenta::~Cuenta() {};