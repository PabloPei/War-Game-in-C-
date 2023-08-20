#ifndef __MAPA_H__
#define __MAPA_H__

#include <iostream>
#include "Casillero.h"
#include "Casillero_inaccesible.h"
#include "Casillero_construible.h"
#include "Casillero_Transitable.h"
#include "Betun.h"
#include "Camino.h"
#include "Muelle.h"
#include "formatos.h"
#include "Lista.h"
#include "ABB.h"


class Mapa {

//atributos:
private:
    Casillero*** mapa;
    int filas;
    int columnas;

//metodos:
public:

    //PRE:
    //POST:
    Mapa();

    //PRE: filas y columnas > 0
    //POST: carga la matriz mapa
    void cargar_mapa(int filas, int columnas);

    //PRE: filas y columnas valido
    //POST: elimina el casillero indicado
    void eliminar_casillero(int filas, int columnas);

    //PRE: nombre valido, coordeanda valida y jugador = 1 o jugador = 2
    //POST: modifica el atributo del casillero indicado
    void modificar_casillero(std::string nombre, int fil, int col,int jugador);

    //PRE: tipo, fil y col validos
    //POST: agrega un casillero de tipo indicado en la coordenada (fil,col)
    void agregar_casillero(char tipo, int fil, int col);

    //PRE: 
    //POST: devuelve true si la coordenada es valida y false si no 
    bool es_coordenada_valida(int fila, int columna);

    //PRE:
    //POST: devuelve la lista de casilleros sobre los cuales pueden caer materiales
    Lista<Casillero*>* casilleros_disponibles_para_lluvia_recursos();

    //PRE: fila y columna validas
    //POST: devuelve el casillero en la coordenada (fila,columna)
    Casillero* obtener_casillero(int fila, int columna);

    //PRE:
    //POST:Devuelve falso si no se pude agregar al jugador por ser un casillero innaccesible o estar fuera del rango
    bool agregar_jugador(int fila, int columna, int jugador);

    //PRE: fila y columna valida
    //POST: elimina al jugador en el casillero indicado 
    void eliminar_jugador(int fila, int columna);

    //PRE: fil y col validas
    //POST: devuelve true si hay un jugador en el casillero indicado y false si no
    bool hay_jugador(int fila, int columna);


    //PRE:
    //POST: devuelve la cantidad de columnas de la matriz mapa
    int obtenerCantidadColumnas();

    //PRE:
    //POST: devuelve la cantidad de filas de la matriz mapa
    int obtenerCantidadFilas();

    //PRE:
    //POST: imprime la matriz mapa
    void imprimir_mapa();

    //PRE: fila, columna, atacante validos y diccionario cargado
    //POST: ataca el casillero indicado
    bool atacar_casillero(int fila, int columna, int atacante, ABB<string, Edificio*>* diccionario);

    //PRE: fila y columna validos
    //POST: describe el casillero indicado
    void describir_casillero(int fila, int columna);


    //PRE:
    //POST:
    ~Mapa();

};


#endif
