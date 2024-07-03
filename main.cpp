#include <iostream>
#include <fstream>
#include <sstream>
#include "Transaccion.h"
#include "Nodo.h"
using namespace std;

void insertarNodoAbbMontos(Nodo*& raiz_abb_monto, Transaccion* transaccion){
    //cout<<"Entro a insertar nodo abb"<<endl;
    if (raiz_abb_monto == nullptr){
        raiz_abb_monto = new Nodo(transaccion);
        //cout<<raiz_abb_monto<<endl;
        //cout<<"Se creo el nodo"<<endl;
        return;
    }
    Transaccion* transaccion_actual = raiz_abb_monto->getDato();
    int monto_actual = transaccion_actual->getMonto();
    int monto = transaccion->getMonto();

    if(monto < monto_actual){
        insertarNodoAbbMontos(raiz_abb_monto->getHijoIzq(), transaccion);
    } else if (monto > monto_actual){
        insertarNodoAbbMontos(raiz_abb_monto->getHijoDer(), transaccion);
    } else {
        return;
    }
}


void leerArchivoTransacciones(string nombre_archivo, Nodo*& raiz_avl, Nodo*& raiz_abb_monto){
    int iterador;
    ifstream archivo(nombre_archivo.c_str());
    string linea;
    string parte;

    int id, monto;
    string cuenta_origen, cuenta_destino, ubicacion, fecha, hora;


    while(getline(archivo, linea)){
        stringstream input_stringstream(linea);
        iterador = 0;
        while(getline(input_stringstream, parte, ',')){
            switch(iterador){
                case 0:
                    id = stoi(parte);
                    break;
                case 1:
                    cuenta_origen = parte;
                    break;
                case 2:
                    cuenta_destino = parte;
                    break;
                case 3:
                    monto = stoi(parte);
                    break;
                case 4:
                    ubicacion = parte;
                    break;
                case 5:
                    fecha = parte;
                    break;
                case 6:
                    hora = parte;
                    cout<<hora<<endl;
                    Transaccion* transaccion = new Transaccion(id, cuenta_origen, cuenta_destino, monto, ubicacion, fecha, hora);
                    insertarNodoAbbMontos(raiz_abb_monto, transaccion);
                    break;
            }
            iterador++;
            
        }

    }
}

void insertarNodoAvl(Nodo* raiz_avl, Transaccion* transaccion){ //pendiente
    if (raiz_avl == nullptr){
        raiz_avl = new Nodo(transaccion);
        cout<<"Se insertó nuevo Nodo"<<endl;
        return;
    }
    Transaccion* transaccion_actual = raiz_avl->getDato();
    int id_actual = transaccion_actual->getId();
    int id = transaccion->getId();

    if(id < id_actual){
        insertarNodoAvl(raiz_avl->getHijoIzq(), transaccion);
    } else if (id > id_actual){
        insertarNodoAvl(raiz_avl->getHijoDer(), transaccion);
    } else {
        return;
    }
}


int main(){
    Nodo* raiz_avl = nullptr;
    Nodo* raiz_abb_monto = nullptr;
    leerArchivoTransacciones("transacciones.txt", raiz_avl, raiz_abb_monto);
    // cout<<raiz_abb_monto->getDato()->getMonto()<<endl;
    // cout<<raiz_abb_monto->getHijoIzq()->getDato()->getMonto()<<endl;
    // cout<<raiz_abb_monto->getHijoDer()->getDato()->getMonto()<<endl;

    return 0;
}