#ifndef __OBJETIVO_H__
#define __OBJETIVO_H__

#include <iostream>
#include <string>
#include "ABB.h"
#include "Edificio.h"
#include "Inventario.h"
#include "Material.h"
#include "Nodo_abb.h"

const std::string STR_MAS_ALTO_NUBES = "Mas alto que las nubes";
const std::string STR_COMPRAR_ANDYPOLIS= "Comprar andypolis";
const std::string STR_EDAD_DE_PIEDRA = "Edad de piedra";
const std::string STR_BOMBARDERO = "Bombardero";
const std::string STR_ENERGETICO = "Energetico";
const std::string STR_LETRADO = "Letrado";
const std::string STR_MINERO = "Minero";
const std::string STR_CANSADO = "Cansado";
const std::string STR_CONSTRUCTOR = "Constructor";
const std::string STR_ARMADO = "Armado";
const std::string STR_EXTREMISTA = "Extremista";

class Objetivo {
//atributos:
private:
    int porcentaje_cumplimiento;
    std::string nombre;

//metodos privados:
    void obtener_edificios(NodoAB<string,Edificio*>* nodo, int &cantidad_construidos, int &cantidad_total, int jugador);

//metodos:
public:

    //PRE:
    //POST:
    Objetivo(std::string);

    //PRE:
    //POST: devuelve el nombre del objetivo
    std::string obtener_nombre();

    //PRE: diccionario e inventario cargados, cantidad_andy, cantidad_bombas_usadas,
    //      cantidad_bombas_compradas,jugador, energia validos
    //POST: devuelve el porcentaje de cumplimiento del objetivo
    int obtener_porcentaje_cumplimiento(ABB<string, Edificio*>* diccionario, int cantidad_andy, int cantidad_bombas_usadas,
                                        int cantidad_bombas_compradas, int jugador,int energia, Inventario* inventario);

    //PRE: diccionario cargado
    //POST: devuelve el porcentaje de cumplimiento del objetivo mas alto que las nubes
    int obtener_porcentaje_mas_alto_nubes(ABB<string, Edificio*>* diccionario);

    //PRE: cantidad_andy y jugador validos
    //POST: devuelve el porcentaje de cumplimiento del objetivo comprar andypolis
    int obtener_porcentaje_comprar_andypolis(int cantidad_andy,int jugador);

    //PRE: inventario cargado
    //POST:devuelve el porcentaje de cumplimiento del objetivo edad de piedra
    int obtener_porcentaje_edad_piedra(Inventario* inventario);

    //PRE: cantidad_bombas_usadas >= 0
    //POST:devuelve el porcentaje de cumplimiento del objetivo bombardero
    int obtener_porcentaje_bombardero(int cantidad_bombas_usadas);

    //PRE: energia >= 0
    //POST:devuelve el porcentaje de cumplimiento del objetivo energetico
    int obtener_porcentaje_energetico(int energia);

    //PRE: diccionario cargado y jugador valido
    //POST:devuelve el porcentaje de cumplimiento del objetivo letrado
    int obtener_porcentaje_letrado(ABB<string, Edificio*>* diccionario, int jugador);

    //PRE: diccionario cargado y jugador valido
    //POST:devuelve el porcentaje de cumplimiento del objetivo minero
    int obtener_porcentaje_minero(ABB<string, Edificio*>* diccionario, int jugador);

    //PRE: energia >= 0
    //POST:devuelve el porcentaje de cumplimiento del objetivo cansado
    int obtener_porcentaje_cansado(int energia);

    //PRE: diccionario cargado y jugador valido
    //POST:devuelve el porcentaje de cumplimiento del objetivo constructor
    int obtener_porcentaje_constructor(ABB<string, Edificio*>* diccionario, int jugador);

    //PRE: inventario cargado
    //POST:devuelve el porcentaje de cumplimiento del objetivo armado
    int obtener_porcentaje_armado(Inventario* inventario);

    //PRE: cantidad_bombas_compradas valido
    //POST:devuelve el porcentaje de cumplimiento del objetivo extremista
    int obtener_porcentaje_extremista(int cantidad_bombas_compradas);

};


#endif
