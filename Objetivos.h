#ifndef __OBJETIVOS_H__
#define __OBJETIVOS_H__

#include <iostream>
#include <string.h>
#include <time.h>
#include "Objetivo.h"
#include "Lista.h"
#include "formatos.h"

const int CANTIDAD_OBJETIVOS = 11;
const int CANTIDAD_OBJETIVOS_POR_JUGADOR = 4;

const std::string nombres_objetivos[CANTIDAD_OBJETIVOS] = {
        STR_MAS_ALTO_NUBES,
        STR_COMPRAR_ANDYPOLIS,
        STR_EDAD_DE_PIEDRA,
        STR_BOMBARDERO,
        STR_ENERGETICO,
        STR_LETRADO,
        STR_MINERO,
        STR_CANSADO,
        STR_CONSTRUCTOR,
        STR_ARMADO,
        STR_EXTREMISTA
};

class Objetivos {
//atributos:
private:
    Lista<Objetivo*>* lista_objetivos;

//metodos:
public:

    //PRE:
    //POST:
    Objetivos(int jugador);

    //PRE: jugador valido
    //POST: asigna aleatoriamente los objetivos a jugador
    void generar_objetivos_aleatorios(int jugador);

    //PRE:
    //POST: devuelve la lista de objetivos
    Lista<Objetivo*>* obtener_lista_de_objetivos();

    //PRE: i valido
    //POST: devuelve el objetivo en la posicion i
    Objetivo* obtener_objetivo(int i);

    //PRE: diccionario e inventario cargados, cantidad_andy, cantidad_bombas_usadas,
    //     cantidad_bombas_compradas, jugador, energia y objetivo_logrado validos
    //POST: devuelve el porcentaje de avance de los objetivos
    int obtener_avance(ABB<string, Edificio*>* diccionario, int cantidad_andy, int cantidad_bombas_usadas,
                       int cantidad_bombas_compradas, int jugador,int energia, Inventario* inventario,int* objetivo_logrado);

    //PRE:
    //POST:
    ~Objetivos();
};


#endif
