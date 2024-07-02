#include <iostream>
#include <fstream>
#include <sstream>
#include "Transaccion.h"
#include "Nodo.h"
using namespace std;

void leerArchivoTransacciones(string nombre_archivo, Nodo* raiz_avl){
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
                    break;
            }
            iterador++;
        }

    }
}

int main(){
    Nodo* raiz_avl = nullptr;
    leerArchivoTransacciones("transacciones.txt", raiz_avl);

    return 0;
}