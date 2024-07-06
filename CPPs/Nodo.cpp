#include <iostream>
#include "../Headers/Nodo.h"
#include "../Headers/Transaccion.h"
using namespace std;

Nodo::Nodo(Transaccion* dato){
    this->dato = dato;
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
    this->altura = 1;
}

Transaccion* Nodo::getDato(){
    return dato;
}

void Nodo::setDato(Transaccion* dato){
    this->dato = dato;
}

Nodo*& Nodo::getHijoIzq(){
    return hijoIzq;
}

void Nodo::setHijoIzq(Nodo* hijoIzq){
    this->hijoIzq = hijoIzq;
}

Nodo*& Nodo::getHijoDer(){
    return hijoDer;
}

void Nodo::setHijoDer(Nodo* hijoDer){
    this->hijoDer = hijoDer;
}

int Nodo::getAltura() {
    return altura;
}

void Nodo::setAltura(int altura) {
    this->altura = altura;
}

Nodo::~Nodo(){};