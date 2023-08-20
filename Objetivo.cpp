#include "Objetivo.h"

Objetivo::Objetivo(std::string nombre){
    porcentaje_cumplimiento = 0;
    this -> nombre = nombre;

}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Objetivo::obtener_nombre(){
    return this->nombre;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Objetivo::obtener_porcentaje_cumplimiento(ABB<string, Edificio*>* diccionario, int cantidad_andy, int cantidad_bombas_usadas,
                int cantidad_bombas_compradas, int jugador, int energia, Inventario* inventario){

    int porcentaje;
    if(nombre==STR_MAS_ALTO_NUBES){
        porcentaje = obtener_porcentaje_mas_alto_nubes(diccionario);
    }

    else if(nombre==STR_COMPRAR_ANDYPOLIS)
        porcentaje = obtener_porcentaje_comprar_andypolis(cantidad_andy, jugador);
    else if(nombre == STR_EDAD_DE_PIEDRA)
        porcentaje = obtener_porcentaje_edad_piedra(inventario);
    else if(nombre == STR_BOMBARDERO)
        porcentaje = obtener_porcentaje_bombardero(cantidad_bombas_usadas);
    else if(nombre == STR_ENERGETICO)
        porcentaje = obtener_porcentaje_energetico(energia);
    else if(nombre == STR_LETRADO)
        porcentaje = obtener_porcentaje_letrado( diccionario, jugador);
    else if(nombre == STR_MINERO)
        porcentaje =obtener_porcentaje_minero( diccionario, jugador);
    else if(nombre == STR_CANSADO)
        porcentaje = obtener_porcentaje_cansado(energia);
    else if (nombre == STR_CONSTRUCTOR)
        porcentaje = obtener_porcentaje_constructor(diccionario,jugador);
    else if(nombre == STR_ARMADO)
        porcentaje = obtener_porcentaje_armado(inventario);
    else if(nombre == STR_EXTREMISTA)
        porcentaje = obtener_porcentaje_extremista(cantidad_bombas_compradas);


    return porcentaje;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Objetivo::obtener_porcentaje_mas_alto_nubes(ABB<string, Edificio*>* diccionario) {
    int porcentaje = 0;
    Edificio* edificio = diccionario->buscar("obelisco");
    if(edificio==nullptr)
        porcentaje=0;
    else if (edificio->obtener_construidos_j1()+edificio->obtener_construidos_j2() == 1)
            porcentaje = 100;

    return porcentaje;


}

/* ---------------------------------------------------------------------------------------------------------*/


int Objetivo::obtener_porcentaje_comprar_andypolis(int cantidad_andy,int jugador){

    return (cantidad_andy*100/100000);

}

/* ---------------------------------------------------------------------------------------------------------*/


int Objetivo::obtener_porcentaje_edad_piedra(Inventario* inventario){
    int cantidad = inventario->obtener_material_por_nombre("piedra") -> obtener_cantidad();
    return (cantidad*100/50000);
}

/* ---------------------------------------------------------------------------------------------------------*/


int Objetivo::obtener_porcentaje_bombardero(int cantidad_bombas_usadas){
    return (cantidad_bombas_usadas*100/5);
}

/* ---------------------------------------------------------------------------------------------------------*/

int Objetivo::obtener_porcentaje_energetico(int energia){
    return energia*100/100;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Objetivo::obtener_porcentaje_letrado(ABB<string, Edificio*>* diccionario, int jugador){

    int porcentaje;
    if(jugador==1)
        porcentaje = diccionario->buscar("escuela")->obtener_construidos_j1() *100/ diccionario->buscar("escuela")->obtener_maximo();
    else
        porcentaje = diccionario->buscar("escuela")->obtener_construidos_j2() *100 / diccionario->buscar("escuela")->obtener_maximo();

    return porcentaje;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Objetivo::obtener_porcentaje_minero(ABB<string, Edificio*>* diccionario, int jugador){

    int porcentaje;
    if(jugador == 1){
        if(diccionario->buscar("mina")->obtener_construidos_j1() == 1 && diccionario->buscar("mina oro")->obtener_construidos_j1() == 1 )
            porcentaje = 100;
        else if ((diccionario->buscar("mina")->obtener_construidos_j1() + diccionario->buscar("mina oro")->obtener_construidos_j1()) == 1)
            porcentaje = 50;
        else
            porcentaje = 0;
   }else{
        if(diccionario->buscar("mina")->obtener_construidos_j2() == 1 && diccionario->buscar("mina oro")->obtener_construidos_j2() == 1 )
            porcentaje = 100;
        else if ((diccionario->buscar("mina")->obtener_construidos_j2() + diccionario->buscar("mina oro")->obtener_construidos_j2()) == 1)
            porcentaje = 50;
        else
            porcentaje = 0;
    }
    return porcentaje;

}

/* ---------------------------------------------------------------------------------------------------------*/

int Objetivo::obtener_porcentaje_cansado(int energia){
    return 100-energia*100/100;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Objetivo::obtener_porcentaje_constructor(ABB<string, Edificio*>* diccionario, int jugador){
    int cantidad_total=0;
    int cantidad_construidos=0;

    NodoAB<string,Edificio*>* raiz = diccionario->obtener_raiz();
    obtener_edificios(raiz,cantidad_construidos,cantidad_total,jugador);
    return  cantidad_construidos *100 / cantidad_total;

}

/* ---------------------------------------------------------------------------------------------------------*/
void Objetivo::obtener_edificios(NodoAB<string,Edificio*>* nodo, int &cantidad_construidos, int &cantidad_total, int jugador) {

    if (nodo != nullptr) {
        obtener_edificios(nodo->obtener_izquierdo(),cantidad_construidos,cantidad_total,jugador);
        Edificio *aux = nodo->obtener_valor();
        cantidad_total++;
        if(jugador == 1 && aux->obtener_construidos_j1()>=1) {
            cantidad_construidos++;
        }
        else if(jugador ==2 && aux->obtener_construidos_j2() >=1){
            cantidad_construidos++;

        }
        obtener_edificios(nodo->obtener_derecho(),cantidad_construidos,cantidad_total,jugador);

    }
}

/* ---------------------------------------------------------------------------------------------------------*/
int Objetivo::obtener_porcentaje_armado(Inventario* inventario){

    return (inventario->obtener_material_por_nombre("bombas")->obtener_cantidad())*100/10;

}
/* ---------------------------------------------------------------------------------------------------------*/

int Objetivo::obtener_porcentaje_extremista(int cantidad_bombas_compradas){
    return (cantidad_bombas_compradas*100/500);
}