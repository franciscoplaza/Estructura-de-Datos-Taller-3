#include <iostream>
#include <fstream>
#include <sstream>
#include "Transaccion.h"
#include "Nodo.h"
using namespace std;

//este método guarda las tansacciones dentro del txt de transacciones
void guardarTransacciones(Nodo* raiz, ofstream& archivo) {
    if (raiz == nullptr) {
        return;
    }

    guardarTransacciones(raiz->getHijoIzq(), archivo);

    Transaccion* transaccion = raiz->getDato();
    archivo<<transaccion->getId()<<","<<transaccion->getCuentaOrigen()<<","<<transaccion->getCuentaDestino()<<","
    <<transaccion->getMonto()<<","<<transaccion->getUbicacion()<<","<<transaccion->getFecha()<<","<<transaccion->getHora()
    <<endl;

    guardarTransacciones(raiz->getHijoDer(), archivo);
}

//este método actualiza el archivo txt de transacciones
void actualizarArchivoTransacciones(string nombre_archivo, Nodo* raiz_avl) {
    ofstream archivo(nombre_archivo.c_str());
    guardarTransacciones(raiz_avl, archivo);
    archivo.close();
}

//este método inserta un nodo en el ABB ordenado por montos de la transaccion
void insertarNodoAbbMontos(Nodo*& raiz_abb_monto, Transaccion* transaccion){
    if (raiz_abb_monto == nullptr){
        raiz_abb_monto = new Nodo(transaccion);
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

//este método devuelve la altura del nodo
int altura(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->getAltura();
}

//este método devuelve el mayor entre 2 valores
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

//este método devuelve el factor de balance del nodo
int obtenerBalance(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return altura(nodo->getHijoIzq()) - altura(nodo->getHijoDer());
}

//este método realiza una rotación a la derecha en el AVL
void rotacionDerecha(Nodo*& y) {
    Nodo* x = y->getHijoIzq();
    Nodo* T2 = x->getHijoDer();

    x->setHijoDer(y);
    y->setHijoIzq(T2);

    y->setAltura(max(altura(y->getHijoIzq()), altura(y->getHijoDer())) + 1);
    x->setAltura(max(altura(x->getHijoIzq()), altura(x->getHijoDer())) + 1);

    y = x;
}

//este método realiza una rotación a la izquierda en el AVL
void rotacionIzquierda(Nodo*& x) {
    Nodo* y = x->getHijoDer();
    Nodo* T2 = y->getHijoIzq();

    y->setHijoIzq(x);
    x->setHijoDer(T2);

    x->setAltura(max(altura(x->getHijoIzq()), altura(x->getHijoDer())) + 1);
    y->setAltura(max(altura(y->getHijoIzq()), altura(y->getHijoDer())) + 1);

    x = y;
}

//este método inserta un nodo en el AVL ordenado por IDs de la transaccion
void insertarNodoAvl(Nodo*& raiz_avl, Transaccion* transaccion){
    if (raiz_avl == nullptr){
        raiz_avl = new Nodo(transaccion);
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

    raiz_avl->setAltura(1 + max(altura(raiz_avl->getHijoIzq()), altura(raiz_avl->getHijoDer())));
    int balance = obtenerBalance(raiz_avl);

    if (balance > 1 && id < raiz_avl->getHijoIzq()->getDato()->getId()) {
        rotacionDerecha(raiz_avl);
    }

    if (balance < -1 && id > raiz_avl->getHijoDer()->getDato()->getId()) {
        rotacionIzquierda(raiz_avl);
    }

    if (balance > 1 && id > raiz_avl->getHijoIzq()->getDato()->getId()) {
        rotacionIzquierda(raiz_avl->getHijoIzq());
        rotacionDerecha(raiz_avl);
    }

    if (balance < -1 && id < raiz_avl->getHijoDer()->getDato()->getId()) {
        rotacionDerecha(raiz_avl->getHijoDer());
        rotacionIzquierda(raiz_avl);
    }
}

//este método lee el archivo de texto de transacciones e ingresa la transaccion a cada árbol (ABB y AVL)
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
                    //cout<<hora<<endl;
                    Transaccion* transaccion = new Transaccion(id, cuenta_origen, cuenta_destino, monto, ubicacion, fecha, hora);
                    insertarNodoAbbMontos(raiz_abb_monto, transaccion);
                    insertarNodoAvl(raiz_avl, transaccion);
                    break;
            }
            iterador++;
        }
    }
}

//este método recorre todo el árbol AVL y retorna el ID mayor encontrado
int buscarIdMayor(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    int id_mayor = raiz->getDato()->getId();
    while (raiz->getHijoDer() != nullptr){
        raiz = raiz->getHijoDer();
        id_mayor = raiz->getDato()->getId();
    }
    return id_mayor;
}

//este método pide datos para crear una transacción y la agrega al abb
void realizarTransaccion(Nodo*& raiz_avl, Nodo*& raiz_abb_monto){
    int id = buscarIdMayor(raiz_avl) + 1;

    string cuenta_origen;
    cout<<"Ingrese la cuenta de origen: ";
    cin>>cuenta_origen;

    string cuenta_destino;
    cout<<"Ingrese la cuenta de destino: ";
    cin>>cuenta_destino;

    int monto;
    cout<<"Ingrese el monto a transferir: ";
    cin>>monto;

    while(monto <= 0){
        cout<<"El monto de la transferencia debe ser mayor a 0. Intente nuevamente."<<endl;
        cout<<"Ingrese el monto a transferir: ";
        cin>>monto;
    }

    string ubicacion;
    cout<<"Ingrese la ubicación de la transferencia: ";
    cin>>ubicacion;

    string fecha;
    cout<<"Ingrese la fecha de la transferencia: ";
    cin>>fecha;

    string hora;
    cout<<"Ingrese la hora de la transferencia: ";
    cin>>hora;

    Transaccion* transaccion = new Transaccion(id, cuenta_origen, cuenta_destino, monto, ubicacion, fecha, hora);
    insertarNodoAbbMontos(raiz_abb_monto, transaccion);
    insertarNodoAvl(raiz_avl, transaccion);
    actualizarArchivoTransacciones("transacciones.txt", raiz_avl);

    cout << "Transaccion realizada con éxito. ID de la transaccion: " << id << endl;
}

//este método se encarga de mostrar los datos de la transaccion pasada por parámetro
void mostrarDatosTransaccion(Transaccion* transaccion){
    if (transaccion == nullptr){
        cout<<"\nNo se encuentra una transaccion con el ID ingresado."<<endl;
    } else {
        cout<<"\nID transaccion: "<<transaccion->getId()<<endl;
        cout<<"Cuenta de origen: "<<transaccion->getCuentaOrigen()<<endl;
        cout<<"Cuenta de destino: "<<transaccion->getCuentaDestino()<<endl;
        cout<<"Monto de la transaccion: "<<transaccion->getMonto()<<endl;
        cout<<"Ubicacion: "<<transaccion->getUbicacion()<<endl;
        cout<<"Fecha: "<<transaccion->getFecha()<<endl;
        cout<<"Hora: "<<transaccion->getHora()<<endl;
    }
}

//este método busca un id de transacción dentro del AVL
void buscarTransaccionPorId(Nodo* raiz_avl) {
    int id;
    cout<<"Ingrese el ID de la transaccion que desea buscar:";
    cin>>id;
    Transaccion* resultado = nullptr;
    while (raiz_avl != nullptr) {
        int id_nodo = raiz_avl->getDato()->getId();
        if (id < id_nodo) {
            raiz_avl = raiz_avl->getHijoIzq();
        } else if (id > id_nodo) {
            raiz_avl = raiz_avl->getHijoDer();
        } else {
            resultado = raiz_avl->getDato();
            break;
        }
    }

    mostrarDatosTransaccion(resultado);
}

// este metodo muestra las opciones disponibles en el menu
void opciones(){
    cout<<"\n----MENU----"<<endl;
    cout<<"1) Realizar nueva transaccion"<<endl;
    cout<<"2) Buscar transaccion por ID"<<endl;
    cout<<"3) Definir criterios para transacciones sospechosas"<<endl;
    cout<<"4) Generar informe de transacciones sospechosas"<<endl;
    cout<<"5) Salir"<<endl;
    cout<<"Ingresa una opcion: ";
}

int main(){
    Nodo* raiz_avl = nullptr;
    Nodo* raiz_abb_monto = nullptr;
    leerArchivoTransacciones("transacciones.txt", raiz_avl, raiz_abb_monto);

    int opcion = 0;
    while(opcion != 5){
        opciones();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            realizarTransaccion(raiz_avl, raiz_abb_monto);
            break;
        case 2:
            buscarTransaccionPorId(raiz_avl);
            break;
        case 3:
            //definirCriterios()
            break;
        case 4:
            //generarInforme()
            break;
        case 5:
            cout<<"Saliendo..."<<endl;
            break;
        default:
            cout<<"Opcion invalida, intente nuevamente."<<endl;
            break;
        }
    }

    return 0;
}