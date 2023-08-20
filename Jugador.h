#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "Grafo.h"
#include "Mapa.h"
#include "Inventario.h"
#include "Objetivos.h"
#include "ABB.h"
#include <iostream>

const char SIMBOLO_J1 = 'J';
const char SIMBOLO_J2 = 'U';

class Jugador {

//atributos:
private:
    int id;
    int fila;
    int columna;
    int energia;
    int andycoins_acumulados;
    int bombas_usadas;
    int bombas_compradas;
    Objetivos* objetivos;
    Inventario* inventario;
    Grafo* grafo;

//metodos privados:

    //PRE:
    //POST:
    bool puede_moverse(Casillero* casillero);

    //PRE:
    //POST:
    void recolectar_materiales(Casillero* casillero);

//metodos publicos:
public:

    //PRE:
    //POST:
    Jugador(int id, int energia=0);

    //PRE:
    //POST: devuelve la fila donde se encuentra el jugador
    int obtener_fil();

    //PRE:
    //POST: devuelve la columna donde se encuentra el jugador
    int obtener_col();

    //PRE:
    //POST: devuelve el id del jugador
    int obtener_id();

    //PRE: fil valida
    //POST: asigna una nueva fila al jugador
    void asignar_fil(int fil);

    //PRE: col valida
    //POST: asigna una nueva columna al jugador
    void asignar_col(int col);

    //PRE:
    //POST: devuelve la cantidad de energia que tiene el jugador
    int obtener_energia();


    //PRE:
    //POST: devuelve los objetivos que tiene que cumplir el jugador
    Objetivos* obtener_objetivos();

    //PRE:
    //POST: devuelve el inventario del jugador
    Inventario* obtener_inventario();

    //PRE:
    //POST: devuelve el grafo del jugador
    Grafo* obtener_grafo();

    //PRE:
    //POST:mueve al jugador
    void mover_jugador(int fila_destino, int columna_destino, Mapa* mapa);

    //PRE:cantidad valida
    //POST: aumenta la cantidad de andycoins acumuladas
    void aumentar_andycoins_acumulados(int cantidad);

    //PRE:
    //POST: devuelve la cantidad de andycoins acumulados
    int obtener_andycoins_acumulados();

    //PRE:cantidad valida
    //POST: incrementa la cantidad de bombas usadas
    void aumentar_bombas_usadas(int cantidad);

    //PRE:
    //POST: devuelve la cantidad de bombas usadas por el jugador
    int obtener_bombas_usadas();

    //PRE: cantidad valida
    //POST: aumenta la cantidad de bombas compradas por el jugador
    void aumentar_bombas_compradas(int cantidad);

    //PRE:
    //POST: devuelve la cantidad de bombas compradas por el jugador
    int obtener_bombas_compradas();

    //PRE:cantidad valida
    //POST: resta cantidad a energia
    void restar_energia(int cantidad);

    //PRE:cantidad valida
    //POST: suma cantidad a energia
    void sumar_energia(int cantidad);

    //PRE:
    //POST: imprime el icono del jugador
    void mostrar();

    //PRE:
    //POST: asigna inventario a inventario
    void asignar_inventario(Inventario* inventario);

    //PRE:
    //POST:
    ~Jugador();
};

#endif
