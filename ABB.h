#ifndef __ARBOL_BINARIO_H__
#define __ARBOL_BINARIO_H__

#include "Nodo_abb.h"

template <typename Clave, typename Valor>
class ABB{
//atributos:
private:
    NodoAB<Clave, Valor>* raiz;
    NodoAB<Clave, Valor>* actual;

//metodos privados:


    //PRE:
    //POST: inserta un nuevo nodo al arbol
    NodoAB<Clave, Valor>* insertar(NodoAB<Clave, Valor>* nodo, Clave clave, Valor valor);

    //PRE:
    //POST: elimina el arbol
    void eliminar_arbol(NodoAB<Clave, Valor>*);

    //PRE:
    //POST: imprime el arbol
    void imprimir_arbol(NodoAB<Clave, Valor>* raiz);

    //PRE:
    //POST: encuentra al hijo mas grande de este nodo 
    NodoAB<Clave, Valor>* hallar_maximo(NodoAB<Clave, Valor>* nodo);

    //PRE:
    //POST: encuentra el hijo mas chico de este nodo
    NodoAB<Clave, Valor>* hallar_minimo(NodoAB<Clave, Valor>* nodo);

    //PRE:
    //POST: devuelve el nodo con la clave indicada
    NodoAB<Clave, Valor>* buscar(Clave clave, NodoAB<Clave, Valor>* raiz);

    //PRE:
    //POST: elimina el nodo indicado
    void eliminar_nodo(NodoAB<Clave, Valor>* nodo_eliminar,bool eliminar_dato);

    //PRE:
    //POST: elimina un nodo hoja
    void eliminar_hoja(NodoAB<Clave, Valor>* nodo_eliminar,bool eliminar_dato);

    //PRE:
    //POST: elimina el nodo con un hijo izquierdo
    void eliminar_nodo_con_hijo_izquierdo(NodoAB<Clave, Valor>* nodo_eliminar,bool eliminar_dato);

    //PRE:
    //POST: elimina al nodo con un hijo derecho
    void eliminar_nodo_con_hijo_derecho(NodoAB<Clave, Valor>* nodo_eliminar,bool eliminar_dato);

    //PRE:
    //POST: elimina un nodo con dos hijos
    void eliminar_nodo_con_dos_hijos(NodoAB<Clave, Valor>* nodo_eliminar);

    //PRE:
    //POST: elimina la raiz del arbol
    void eliminar_raiz();

    //PRE:
    //POST: devuelve el nodo sucesor del nodo indicado
    NodoAB<Clave, Valor>* sucesor(NodoAB<Clave, Valor>* nodo);


//metodos:
public:
    //PRE:
    //POST:
    ABB();

    //PRE:
    //POST: devuelve true si el arbol esta vacio y false si no
    bool esta_vacio();

    //PRE:
    //POST: imprime el arbol
    void imprimir_arbol();

    //PRE:
    //POST: devuelve el nodo raiz
    NodoAB<Clave, Valor>* obtener_raiz(){
        return this->raiz;
    }

    //PRE:
    //POST: devuelve el nodo minimo del arbol
    NodoAB<Clave, Valor>* hallar_minimo();

    //PRE:
    //POST: devuelve el nodo maximo del arbol
    NodoAB<Clave, Valor>* hallar_maximo();

    //PRE:
    //POST: devuelve el sucesor del nodo con la clave indicada
    NodoAB<Clave, Valor>* sucesor(Clave clave);

    //PRE:
    //POST: inserta un nodo con clave y valores indicados
    void insertar(Clave clave, Valor valor);

    //PRE:
    //POST: Retorna el valor pedido o un puntero nulo en caso de que no lo encuentre
    Valor buscar(Clave clave);

    //PRE:
    //POST: elimina el arbol
    void eliminar_arbol();

    //PRE:
    //POST: elimina el nodo con la clave indicada
    void eliminar_nodo(Clave clave);


    ~ABB();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////IMPLEMENTACIONES///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename Clave, typename Valor>
ABB<Clave,Valor>::ABB(){
    raiz = nullptr;
    actual = nullptr;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
bool ABB<Clave,Valor>::esta_vacio(){
    return this->raiz == nullptr;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::insertar(NodoAB<Clave, Valor>* nodo, Clave clave, Valor valor) {

    if (nodo == NULL) {
        nodo = new NodoAB<Clave, Valor>(clave, valor);
    }

    else if (clave > nodo->obtener_clave()) {
        nodo->asignar_derecho(insertar(nodo->obtener_derecho(), clave, valor));
        nodo->obtener_derecho()->asignar_padre(nodo);
    }

    else {
        nodo->asignar_izquierdo(insertar(nodo->obtener_izquierdo(), clave, valor));
        nodo->obtener_izquierdo()->asignar_padre(nodo);
    }
    return nodo;
}

template <typename Clave, typename Valor5>
void ABB<Clave,Valor>::insertar(Clave clave, Valor valor){
    this->raiz = insertar(this->raiz, clave, valor);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::imprimir_arbol(NodoAB<Clave, Valor>* raiz){
    if (raiz != nullptr){
        imprimir_arbol(raiz->obtener_izquierdo());
        cout << raiz->obtener_clave();
        cout << ":";
        cout << raiz->obtener_valor() << endl;
        imprimir_arbol(raiz->obtener_derecho());
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::imprimir_arbol(){
    imprimir_arbol(raiz);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::buscar(Clave clave, NodoAB<Clave, Valor>* raiz){

    if (raiz == nullptr || raiz->obtener_clave() == clave){
        return raiz;
    }
    if(clave > raiz->obtener_clave()){
        return buscar(clave, raiz->obtener_derecho());
    }
    return buscar(clave, raiz->obtener_izquierdo());
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
Valor ABB<Clave,Valor>::buscar(Clave clave){
    Valor resultado;
    NodoAB<Clave, Valor>* nodo = buscar(clave, raiz);
    if(nodo == nullptr)
        resultado = nullptr;
    else{
        resultado = nodo->obtener_valor();
    }
    return resultado;

}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::hallar_minimo(NodoAB<Clave, Valor>* nodo){
    if(nodo == NULL)
        return nullptr;
    else if(nodo->obtener_izquierdo() == NULL)
        return nodo;
    else
        return hallar_minimo(nodo->obtener_izquierdo());
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::hallar_minimo(){
    return hallar_minimo(this->raiz);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::hallar_maximo(NodoAB<Clave, Valor>* nodo){
    if(nodo == NULL)
        return nullptr;
    else if(nodo->obtener_derecho() == NULL)
        return nodo;
    else
        return hallar_maximo(nodo->obtener_derecho());
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::hallar_maximo(){
    return hallar_maximo(this->raiz);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::sucesor(NodoAB<Clave, Valor>* nodo){
    if (nodo->obtener_derecho() != NULL)
    {
        return hallar_minimo(nodo->obtener_derecho());
    }
    NodoAB<Clave, Valor>* sucesor = NULL;
    NodoAB<Clave, Valor>* ancestro = this->raiz;
    while(ancestro != nodo) {
        if(nodo->obtener_clave() < ancestro->obtener_clave()) {
            sucesor = ancestro;
            ancestro = ancestro->obtener_izquierdo();
        }
        else
            ancestro = ancestro->obtener_derecho();
    }
    return sucesor;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
NodoAB<Clave, Valor>* ABB<Clave,Valor>::sucesor(Clave clave){
    NodoAB<Clave, Valor>* nodo = this->buscar( clave, this->raiz);
    if(nodo == nullptr)
        return nullptr;
    else return sucesor(nodo);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminar_nodo(NodoAB<Clave, Valor>* nodo_eliminar,bool eliminar_dato){
    //caso particular que sea raiz
    if (nodo_eliminar == this->raiz){
        eliminar_raiz();
    }
    else if (nodo_eliminar->es_hoja()){
        eliminar_hoja(nodo_eliminar,eliminar_dato);
    }
    else if (nodo_eliminar->tiene_hijo_izquierdo()){
        eliminar_nodo_con_hijo_izquierdo(nodo_eliminar,eliminar_dato);
    }
    else if (nodo_eliminar->tiene_hijo_derecho()){
        eliminar_nodo_con_hijo_derecho(nodo_eliminar,eliminar_dato);
    }
    else if (nodo_eliminar->tiene_dos_hijos()){
        eliminar_nodo_con_dos_hijos(nodo_eliminar);
    }

}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminar_nodo(Clave clave){
    NodoAB<Clave, Valor>* nodo_eliminar = buscar(clave, raiz);
    eliminar_nodo(nodo_eliminar,true);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminar_hoja(NodoAB<Clave, Valor>* nodo_eliminar, bool eliminar_dato){
    NodoAB<Clave, Valor>* padre = nodo_eliminar->obtener_padre();
    if (padre->obtener_izquierdo() == nodo_eliminar){
        padre->asignar_izquierdo(nullptr);
    }
    else{
        padre->asignar_derecho(nullptr);
    }

    //libero el edificio y luego el nodo (fijarse si esta bien) !!!
    if(eliminar_dato==true)
        delete nodo_eliminar->obtener_valor();
    delete nodo_eliminar;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminar_nodo_con_hijo_izquierdo(NodoAB<Clave, Valor>* nodo_eliminar,bool eliminar_dato){
    NodoAB<Clave, Valor>* padre = nodo_eliminar->obtener_padre();
    if (padre->obtener_izquierdo() == nodo_eliminar){
        padre->asignar_izquierdo(nodo_eliminar->obtener_izquierdo());
    }
    else{
        padre->asignar_derecho(nodo_eliminar->obtener_izquierdo());
    }
    nodo_eliminar->obtener_izquierdo()->asignar_padre(padre);

    if(eliminar_dato==true)
        delete nodo_eliminar->obtener_valor();
    delete nodo_eliminar;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminar_nodo_con_hijo_derecho(NodoAB<Clave, Valor>* nodo_eliminar, bool eliminar_dato){
    NodoAB<Clave, Valor>* padre = nodo_eliminar->obtener_padre();
    if (padre->obtener_izquierdo() == nodo_eliminar){
        padre->asignar_izquierdo(nodo_eliminar->obtener_derecho());
    }
    else{
        padre->asignar_derecho(nodo_eliminar->obtener_derecho());
    }
    nodo_eliminar->obtener_derecho()->asignar_padre(padre);
    if(eliminar_dato==true)
        delete nodo_eliminar->obtener_valor();
    delete nodo_eliminar;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminar_nodo_con_dos_hijos(NodoAB<Clave, Valor>* nodo_eliminar){
    NodoAB<Clave, Valor>* suc = sucesor(nodo_eliminar->obtener_clave());
    delete nodo_eliminar->obtener_valor();
    nodo_eliminar->asignar_clave(suc->obtener_clave());
    nodo_eliminar->asignar_valor(suc->obtener_valor());
    eliminar_nodo(suc, false);
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminar_raiz(){
    if (this->raiz->es_hoja()){
        NodoAB<Clave, Valor>* aux = raiz;
        this->raiz = nullptr;
        delete aux->obtener_valor();
        delete aux;
    }
    else if (this->raiz->tiene_hijo_izquierdo()){
        delete this->raiz->obtener_valor();
        this->raiz->asignar_clave(this->raiz->obtener_izquierdo()->obtener_clave());
        this->raiz->asignar_valor(this->raiz->obtener_izquierdo()->obtener_valor());
        eliminar_nodo(this->raiz->obtener_izquierdo(),false);
    }
    else if (this->raiz->tiene_hijo_derecho()){
        delete this->raiz->obtener_valor();
        this->raiz->asignar_clave(this->raiz->obtener_derecho()->obtener_clave());
        this->raiz->asignar_valor(this->raiz->obtener_derecho()->obtener_valor());
        eliminar_nodo(this->raiz->obtener_derecho(),false);
    }
    else if (this->raiz->tiene_dos_hijos()){
        delete this->raiz->obtener_valor();
        NodoAB<Clave, Valor>* suc = sucesor(this->raiz);
        this->raiz->asignar_clave(suc->obtener_clave());
        this->raiz->asignar_valor(suc->obtener_valor());
        eliminar_nodo(suc,false);
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminar_arbol(NodoAB<Clave, Valor>* nodo){
    if(nodo == nullptr) {
        return;
    }
    this -> eliminar_arbol(nodo->obtener_derecho());
    this -> eliminar_arbol(nodo->obtener_izquierdo());
    delete nodo->obtener_valor();
    delete nodo;
}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
void ABB<Clave,Valor>::eliminar_arbol(){
    this -> eliminar_arbol(this->raiz);

}

/* ---------------------------------------------------------------------------------------------------------*/

template <typename Clave, typename Valor>
ABB<Clave,Valor>::~ABB(){
    this -> eliminar_arbol();

}

/* ---------------------------------------------------------------------------------------------------------*/


#endif
