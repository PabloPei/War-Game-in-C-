#ifndef __ANDYPOLIS_H__
#define __ANDYPOLIS_H__

#include <iostream>
#include <time.h>
#include "Casillero.h"
#include "Casillero_Transitable.h"
#include "Casillero_construible.h"
#include "Casillero_inaccesible.h"
#include "Jugador.h"
#include "Lista.h"
#include "formatos.h"
#include "Menu.h"
#include "errores.h"
#include "Leer_archivo_ubicaciones.h"
#include "Leer_archivo_mapa.h"
#include "Leer_archivo_materiales.h"
#include "Leer_archivo_edificios.h"
#include "Mapa.h"
#include "ABB.h"
#include "Edificio.h"
#include "Objetivos.h"
#include "Objetivo.h"


using namespace std;

const char SI = 'S';

class Andypolis {

//atributos:
private:
    int turno;
    int rondas;
    Jugador* jugador_1;
    Jugador* jugador_2;
    Mapa* mapa;
    Lista<Casillero*>* casilleros_transitables;
    ABB<string, Edificio*>* diccionario;


//metodos privados:

    //PRE:
    //POST: devuelve el inventario del jugador actual
    Inventario* obtener_inventario_actual();

    //PRE:
    //POST: devuelve el jugador actual
    Jugador* obtener_jugador_actual();

    //PRE: cantidad > 0
    //POST: devuelve true si el jugador tiene la energia necesaria para realizar la accion y false si no.
    bool tiene_energia_suficiente(int cantidad);

    //PRE: 0 < cantidad <= energia
    //POST: resta cantidad a la energia del jugador actual
    void restar_energia(int cantidad);

    //PRE: 0 < cantidad
    //POST: suma cantidad a la energia del jugador actual
    void sumar_energia(int cantidad);

    //PRE: nombre valido
    //POST: resta los materiales al jugador que reparo el edificio con nombre_demolido
    bool restar_materiales_por_reparacion(string nombre_demolido);

    //PRE: jugador = 1 o jugador = 2 y nombre valido
    //POST: devuelve true si el jugador puede construir un edificio de este tipo y false si no
    bool se_puede_construir(std::string nombre_edificio, int jugador);

    //PRE: nombre_edificio valido
    //POST: devuelve true si el jugador actual tiene materiales suficientes para construir y false si no.
    bool hay_materiales_suficientes(std::string nombre_edificio);

    //PRE: nombre_edificio valido
    //POST: resta los materiales por construccion al jugador actual
    void restar_materiales_por_construccion(std::string nombre_edificio);

    //PRE:
    //POST: recorre el arbol imprimiendo todos los edificios construidos
    void listar_edificios_construidos_wrapper(NodoAB<string , Edificio*>* nodo);

    //PRE: nombre valido
    //POST: imprime las coordenadas donde se encuentran los edificios construidos y si requieren reparacion o no
    void imprimir_coordenadas_y_reparacion(string nombre);

    //PRE:
    //POST: actualiza la cantidad de recursos producidos por los edificios que generan recursos
    void actualizar_recursos_producidos();

    //PRE: edificio valido
    //POST: recolecta los recursos producidos por edificio
    void recolectar_recurso(Edificio* edificio);

    //PRE:
    //POST: guarda las ubicaciones del mapa en el archivo ubicaciones.txt
    void guardar_ubicaciones();

    //PRE:
    //POST: guarda los materiales y sus cantidades en el archivo materiales.txt
    void guardar_materiales();

    //PRE:
    //POST: guarda los edificios y sus caracteristicas en el archivo edificios.txt
    void guardar_edificios();

    //PRE:
    //POST:
    void obtener_edificios(NodoAB<string,Edificio*>* nodo);

    //PRE:
    //POST: devuelve true si el jugador gano la partida y false si no
    bool partida_ganada();

    //PRE:
    //POST: le pide al usuario que presione enter para volver al menu principal
    void presione_para_volver();

    //PRE:
    //POST: le pide al usuario que presione enter para volver al menu principal
    void presione_para_volver_sin_entrada();

    //PRE:
    //POST:recorre el arbol imprimiendo todos los edificios
    void listar_todos_los_edificios_wrapper(NodoAB<string , Edificio*>* nodo);


//metodos publicos:
public:

    //PRE:
    //POST:
    Andypolis();

    //PRE:
    //POST: carga el objeto mapa con los datos del archivo mapa.txt
    Status_t cargar_mapa();

    //PRE:
    //POST: carga el diccionario con los datos del archivo edificios.txt
    Status_t cargar_diccionario();

    //PRE:
    //POST: carga las ubicaciones de jugadores, materiales y edificios
    //      que se encuentran en el mapa segun indica ubicaciones.txt
    Status_t cargar_ubicaciones();

    //PRE:
    //POST: carga los datos del jugador
    Status_t cargar_jugador();

    //PRE:
    //POST: inicia la ejecucion del juego
    Status_t iniciar();

    //PRE:
    //POST: comienza una partida nueva
    void jugar(Status_t st);

    //PRE:
    //POST: procesa la opcion elegida por el usuario en el primer menu
    void procesar_opcion_menu_1(int* opcion_elegida);


    //PRE:
    //POST: modifica el edificio nombrado por el usuario
    void modificar_edificio_por_nombre();

    //PRE:
    //POST: imprime por pantalla el mapa
    void mostrar_mapa();

    //PRE:
    //POST: imprime por pantalla todos los edificios
    void listar_todos_los_edificios();


    //PRE:
    //POST: comienza la partida
    void comenzar_partida(int* opcion_elegida );

    //PRE:
    //POST: procesa la opcion elegida por el usuario en el segundo menu
    void procesar_opcion_menu_2(int opcion_elegida);

    //PRE:
    //POST: construye el edificio nombrado por el usuario si este cuenta con los recursos necesarios
    void construir_por_nombre();

    //PRE:
    //POST: lista los edificios construidos por el jugador
    void listar_edificios_construidos();

    //PRE:
    //POST: destruye el edificio indicado por el jugador si este es de su propiedad
    void demoler_por_coordenada();

    //PRE:
    //POST: ataca la coordenada indicada por el jugador si en esta se encuentra un edificio del jugador rival
    void atacar_por_coordenada();

    //PRE:
    //POST: mueve al jugador a la coordenada indicada si tiene la energia para hacerlo y el casillero es valido
    void moverse_coordenada();

    //PRE:
    //POST: repara el edificio en la coordenada indicada por el usuario si este es de su propiedad
    void reparar_por_coordenada();

    //PRE:
    //POST: recolecta los recursos producidos por los edificios
    void recolectar_recursos_producidos();

    //PRE:
    //POST: compra bombas si el jugador tiene las andycoins necesarias
    void comprar_bombas();

    //PRE:
    //POST: describe que hay en la coordenada indicada por el usuario
    void consultar_coordenada();

    //PRE:
    //POST: imprime el inventario del jugador actual
    void mostrar_inventario();

    //PRE:
    //POST: imprime los objetivos del jugador actual
    void imprimir_objetivos();

    //PRE:
    //POST: finaliza el turno del jugador actual
    void finalizar_turno();

    //PRE:
    //POST: genera recursos alrededor del mapa
    void lluvia_de_recursos();

    //PRE:
    //POST: guarda los cambios realizados en los archivos correspondientes
    void guardar();

    //PRE:
    //POST:
    ~Andypolis();
};


#endif
