#ifndef __LISTA_H__
#define __LISTA_H__

#include "Nodo_lista.h"
#include <string>


template <typename Dato>
class Lista {

//atributos:
private:
    Nodo<Dato>* primero;
    int cantidad;

//metodos:
public:

    //PRE: -
    //POS: tope = 0
    Lista();

    //PRE: 1 <= pos <= cantidad + 1
    //POS: agrega d a la lista en la posicion pos e incrementa tope en 1
    void alta(Dato d, int pos);

    //PRE: 1 <= pos <= cantidad
    //POS: devuelve el dato que esta en la posicion pos
    Dato consulta(int pos);

    //PRE: elemento con nombre dentro de la lista
    //POST: devuelve el dato con el nombre indicado
    Dato consulta_por_nombre(std::string nombre);

    //PRE:
    //POST: devuelve true si el elemento con nombre_elemento se encuentra en la
    //      lista
    bool existe_elemento(std::string nombre_elemento);

    //PRE:
    //POST: devuelve la cantidad de elementos de la lista
    int obtener_cantidad();

    //PRE: 1 <= pos <= cantidad
    //POS: elimina el dato que esta en pos y decrementa tope
    void baja(int pos);


    //PRE: -
    //POS: devuelve true si la lista esta vacia, false si no
    bool vacia();

    //Destructor
    ~Lista();

private:
    //PRE: posicion valida (entero > 0 y < tope)
    //POS: devuelve un puntero al nodo
    Nodo<Dato>* obtener_nodo(int pos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////IMPLEMENTACIONES/////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
Lista<Dato>::Lista() {
    primero = 0;
    cantidad = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
bool Lista<Dato>::vacia() {
    return (cantidad == 0);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
void Lista<Dato>::alta(Dato d, int pos) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(d);
    Nodo<Dato>* siguiente = primero;

    if (pos == 1) {
        primero = nuevo;
    }
    else {
        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
void Lista<Dato>::baja(int pos) {
    Nodo<Dato>* baja = primero;
    if (pos == 1)
        primero = baja->obtener_siguiente();
    else {
        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        baja = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(baja->obtener_siguiente());
    }
    cantidad--;

    delete baja;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
Dato Lista<Dato>::consulta(int pos) {
    Nodo<Dato>* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
Dato Lista<Dato>::consulta_por_nombre(std::string nombre) {

    Dato dato ;
    bool encontrado = false;

    Nodo<Dato>* aux = primero;

    while(aux && !encontrado){

        dato = (aux->obtener_dato());
        encontrado = (aux->obtener_dato()->obtener_nombre())== nombre;

        aux = aux->obtener_siguiente();

    }

    return dato;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
bool Lista<Dato>::existe_elemento(std::string nombre_elemento){

    bool existe = false;
    int i = 0;

    Nodo<Dato>* aux = primero;

    while(!existe && i < cantidad){

        existe = (aux->obtener_dato())->obtener_nombre() == nombre_elemento;

        aux = aux->obtener_siguiente();
        i++;
    }

    return existe;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
int Lista<Dato>::obtener_cantidad(){

    return this->cantidad;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
Lista<Dato>::~Lista() {
    while (! vacia())
        baja(1);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos) {
    Nodo<Dato>* aux = primero;
    for (int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

/* ---------------------------------------------------------------------------------------------------------*/

#endif
