#include <iostream>
#include <string>

using namespace std;

#ifndef __NODOAB_H__
#define __NODOAB_H__

template <typename Clave, typename Valor>
class NodoAB{
//atributos:
private:
    Clave clave;
    Valor valor;
    NodoAB<Clave, Valor>* izquierdo;
    NodoAB<Clave, Valor>* derecho;
    NodoAB<Clave, Valor>* padre;

//metodos:
public:
    //PRE:
    //POST:
    NodoAB();

    //PRE:
    //POST:
    NodoAB(Clave clave, Valor valor);

    //PRE:
    //POST: asigna la clave indicada
    void asignar_clave(Clave clave);

    //PRE:
    //POST: asigna el valor indicado 
    void asignar_valor(Valor valor);

    //PRE:
    //POST: asigna un hijo izquierdo indicado por izquierdo 
    void asignar_izquierdo(NodoAB *izquierdo);

    //PRE:
    //POST: asigna un hijo derecho indicado por derecho
    void asignar_derecho(NodoAB *derecho);

    //PRE:
    //POST: asigna el padre del nodo
    void asignar_padre(NodoAB *padre);

    //PRE:
    //POST: devuelve true si el nodo tiene un hijo derecho
    bool tiene_hijo_derecho();

    //PRE:
    //POST: devuelve true si tiene un hijo izquierdo
    bool tiene_hijo_izquierdo();

    //PRE:
    //POST: devuelve true si tiene dos hijos y false si no
    bool tiene_dos_hijos();

    //PRE:
    //POST: devuelve true si este nodo es una hoja
    bool es_hoja();

    //PRE:
    //POST: devuelve la clave del nodo
    Clave obtener_clave();

    //PRE:
    //POST: devuelve el valor del nodo
    Valor obtener_valor();

    //PRE:
    //POST: devuelve el hijo izquierdo del nodo
    NodoAB<Clave, Valor>* obtener_izquierdo();

    //PRE:
    //POST: devuelve el hijo derecho del nodo
    NodoAB<Clave, Valor>* obtener_derecho();

    //PRE:
    //POST: devuelve el padre del nodo
    NodoAB<Clave, Valor>* obtener_padre();


};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////IMPLEMENTACIONES///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



template <typename Clave, typename Valor>
NodoAB<Clave,Valor>::NodoAB(){
    clave = " ";
    valor = 0;
    izquierdo = nullptr;
    derecho = nullptr;
    padre = nullptr;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave,Valor>::NodoAB(Clave clave, Valor valor) {
    this->clave = clave;
    this->valor = valor;
    izquierdo = nullptr;
    derecho = nullptr;
    padre = nullptr;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignar_clave(Clave clave){
    this->clave = clave;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignar_valor(Valor valor){
    this->valor = valor;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignar_izquierdo(NodoAB<Clave, Valor>* izquierdo){
    this->izquierdo = izquierdo;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignar_derecho(NodoAB<Clave, Valor>* derecho){
    this->derecho = derecho;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void NodoAB<Clave,Valor>::asignar_padre(NodoAB<Clave, Valor>* padre){
    this->padre = padre;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
Clave NodoAB<Clave,Valor>::obtener_clave(){
    return this->clave;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
Valor NodoAB<Clave,Valor>::obtener_valor(){
    return this->valor;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* NodoAB<Clave,Valor>::obtener_izquierdo(){
    return this->izquierdo;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* NodoAB<Clave,Valor>::obtener_derecho(){
    return this->derecho;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* NodoAB<Clave,Valor>::obtener_padre(){
    return this->padre;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
bool NodoAB<Clave,Valor>::tiene_dos_hijos(){
    return (obtener_izquierdo() != nullptr && obtener_derecho() != nullptr);

}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
bool NodoAB<Clave,Valor>::tiene_hijo_derecho(){
    return (obtener_derecho() != nullptr && obtener_izquierdo() == nullptr);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
bool NodoAB<Clave,Valor>::tiene_hijo_izquierdo(){
    return(obtener_izquierdo() != nullptr && obtener_derecho() == nullptr);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
bool NodoAB<Clave,Valor>::es_hoja(){
    if (obtener_izquierdo() == nullptr && obtener_derecho() == nullptr)
        return true;
    return false;
}

/* ---------------------------------------------------------------------------------------------------------*/

#endif
