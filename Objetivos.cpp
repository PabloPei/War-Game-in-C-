#include <time.h>
#include <iostream>
#include "Objetivos.h"
#include "Objetivo.h"

/* ---------------------------------------------------------------------------------------------------------*/

Objetivos::Objetivos(int jugador) {
    lista_objetivos = new Lista<Objetivo*>();
    generar_objetivos_aleatorios(jugador);
}

/* ---------------------------------------------------------------------------------------------------------*/

void Objetivos::generar_objetivos_aleatorios(int jugador) {

    srand((unsigned)time(NULL)*jugador);
    Objetivo* objetivo;
    objetivo= new Objetivo(nombres_objetivos[0]);
    lista_objetivos->alta(objetivo,1);

    for(int i=2 ; i <= CANTIDAD_OBJETIVOS_POR_JUGADOR; i++ ){
        int indice = rand()%(CANTIDAD_OBJETIVOS-1)+1;
        if(lista_objetivos->existe_elemento(nombres_objetivos[indice]))
            i--;
        else {
            objetivo = new Objetivo(nombres_objetivos[indice]);
            lista_objetivos->alta(objetivo, 1);
        }
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

Lista<Objetivo*>* Objetivos::obtener_lista_de_objetivos(){
    return this->lista_objetivos;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Objetivos::obtener_avance(ABB<string, Edificio*>* diccionario, int cantidad_andy, int cantidad_bombas_usadas,
                              int cantidad_bombas_compradas, int jugador,int energia, Inventario* inventario, int* objetivo_logrado){

    int porcentaje=0;
    int i=1;
    while ( i<=CANTIDAD_OBJETIVOS_POR_JUGADOR && porcentaje < 100){
        porcentaje = lista_objetivos->consulta(i)->obtener_porcentaje_cumplimiento(diccionario,cantidad_andy,cantidad_bombas_usadas,
                                                                                   cantidad_bombas_compradas,jugador,energia,inventario);
        i++;
    }

    *objetivo_logrado=i-1;

    return porcentaje;

}

/* ---------------------------------------------------------------------------------------------------------*/

Objetivo* Objetivos::obtener_objetivo(int i){
    return lista_objetivos->consulta(i);
}

/* ---------------------------------------------------------------------------------------------------------*/

Objetivos::~Objetivos() {
    delete lista_objetivos;
    lista_objetivos = nullptr;
}

/* ---------------------------------------------------------------------------------------------------------*/
