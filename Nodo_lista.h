#ifndef __NODO_H__
#define __NODO_H__

template <typename Dato>

class Nodo {

//atributos:
private:
    Dato dato;
    Nodo* siguiente;

//metodos:
public:
    Nodo(Dato d);

    //PRE:
    //POS: le asigna el valor de d al atributo dato
    void cambiar_dato(Dato d);

    //PRE:
    //POS: cambia el siguiente del nodo a la direccion apuntada por pn
    void cambiar_siguiente(Nodo* pn);

    //PRE:
    //POS: devuelve el atributo dato
    Dato obtener_dato();

    //PRE:
    //POS: devuelve el atributo siguiente
    Nodo* obtener_siguiente();

    ~Nodo();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////IMPLEMENTACIONES///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename Dato>
Nodo<Dato>::Nodo(Dato d) {
    dato = d;
    siguiente = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
void Nodo<Dato>::cambiar_dato(Dato d) {
    dato = d;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
void Nodo<Dato>::cambiar_siguiente(Nodo* pn) {
    siguiente = pn;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
Dato Nodo<Dato>::obtener_dato() {
    return dato;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente() {
    return siguiente;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Dato>
Nodo<Dato>::~Nodo(){
    delete dato;
}

/* ---------------------------------------------------------------------------------------------------------*/

#endif
