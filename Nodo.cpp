#include <iostream>
#include "Nodo.h"
using namespace std;

Nodo::Nodo(int dato){
    this->dato = dato;
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
}

int Nodo::getDato(){
    return dato;
}

void Nodo::setDato(int dato){
    this->dato = dato;
}

Nodo* Nodo::getHijoIzq(){
    return hijoIzq;
}

void Nodo::setHijoIzq(Nodo* hijoIzq){
    this->hijoIzq = hijoIzq;
}

Nodo* Nodo::getHijoDer(){
    return hijoDer;
}

void Nodo::setHijoDer(Nodo* hijoDer){
    this->hijoDer = hijoDer;
}

Nodo::~Nodo(){};