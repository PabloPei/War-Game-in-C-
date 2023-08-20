#ifndef __EDIFICIO_H__
#define __EDIFICIO_H__

#include <string>
#include <iostream>
#include "formatos.h"

const std::string MINA = "mina";
const std::string ASERRADERO = "aserradero";
const std::string FABRICA = "fabrica";
const std::string ESCUELA = "escuela";
const std::string OBELISCO = "obelisco";
const std::string PLANTA_ELECTRICA = "planta electrica";
const std::string MINA_ORO = "mina oro";
const std::string MINA_ICONO = "M";
const std::string ASERRADERO_ICONO = "A";
const std::string FABRICA_ICONO = "F";
const std::string ESCUELA_ICONO = "E";
const std::string OBELISCO_ICONO = "O";
const std::string PLANTA_ELECTRICA_ICONO = "P";
const std::string MINA_ORO_ICONO = "G";


class Edificio{

//atributos:
protected:
    std::string nombre;
    int piedra;
    int madera;
    int metal;
    std::string icono;
    int cantidad_construidos_j1;
    int cantidad_construidos_j2;
    int jugador;
    int maximo_permitido;
    int recursos_acumulados;
    bool roto;

//metodos:
public:
    //PRE:
    //POST: Construye un edificio con todos sus parametros nulos
    Edificio();

    //PRE:
    //POST:
    Edificio(std::string nombre, int piedra, int madera, int metal,
             int maximo_permitido,int jugador);

    //PRE:  datos piedra, madera, metal y maximo permitidos datos validos (enteros > 0) y nombre valido
    //POST: Construye un edificio con los parametros correspondientes
    Edificio(std::string nombre, int piedra, int madera, int metal,
             int maximo_permitido);

    //PRE:
    //POST: devuelve el nombre del edificio
    std::string obtener_nombre();

    //PRE:
    //POST: devuelve la madera necesaria para construir el edificio
    int obtener_piedra();

    //PRE:
    //POST: devuelve la madera necesaria para construir el edificio
    int obtener_madera();


    //PRE:
    //POST: devuelve el metal necesario para construir el edificio
    int obtener_metal();

    //PRE:
    //POST: devuelve la cantidad de edificios construidos;
    int obtener_jugador();

    //PRE:
    //POST: devuelve la cantidad de edificios construidos;
    int obtener_construidos_j1();

    //PRE:
    //POST: aumenta los recursos acumulados por el edificio
    virtual void aumentar_recursos_acumulados(){};

    //PRE:
    //POST: devuelve la cantidad de recursos acumulada
    int obtener_recursos_producidos();

    //PRE:
    //POST: devuelve la cantidad de edificios construidos;
    int obtener_construidos_j2();

    //PRE:
    //POST: devuelve el numero maxio de edificios permitidos
    int obtener_maximo();

    //PRE:
    //POST: devuelve roto
    bool esta_roto();

    //PRE:
    //POST: devuelve true si el jugador tiene permitido construir mas edificio de este tipo y false si no
    bool hay_espacio(int jugador);

    //PRE:
    //POST: incrementa en 1 cantidad_construidos
    void incrementar_construidos_j1();

    //PRE:
    //POST: incrementa en 1 cantidad_construidos
    void incrementar_construidos_j2();

    //PRE:
    //POST:
    void decrementar_construidos(int jugador);

    //PRE:
    //POST:
    void incrementar_construidos(int jugador);

    //PRE: cantidad_construidos > 0
    //POST: reduce en 1 cantidad_construidos
    void reducir_construidos_j1();

    //PRE: cantidad_construidos > 0
    //POST: reduce en 1 cantidad_construidos
    void reducir_construidos_j2();

    //PRE:
    //POST: describe el edificio para el usuario que consulta un casillero
    virtual void describir()=0;

    //PRE:
    //POST: imprime el icono del edificio;
    std::string obtener_icono();

    //PRE: Recibe una cantidad de piedra mayor a 0 y menor a 50000
    //POST: modifica la cantidad de piedra necesaria para contruir un edificio
    void modificar_piedra_edificio(int piedra_nueva_cantidad);

    //PRE: Recibe una cantidad de madera mayor a 0 y menor a 50000
    //POST: modifica la cantidad de madera necesaria para contruir un edificio
    void modificar_madera_edificio(int madera_nueva_cantidad);

    //PRE: Recibe una cantidad de metal mayor a 0 y menor a 50000
    //POST: modifica la cantidad de metal necesaria para contruir un edificio
    void modificar_metal_edificio(int metal_nueva_cantidad);

    //PRE:
    //POST: imprime que material brinda el edificio
    void imprimir_si_brinda_material(std::string nombre_edificio);

    //PRE:
    //POST: imprime los datos del edificio
    void imprimir_datos();

    //PRE: jugador = 1 o jugador = 2
    //POST: imprime los datos del edificio si este fue construido por jugador
    void imprimir_datos_construidos(int jugador);

    //PRE:
    //POST: cambia el atributo roto a true
    void romper();

    //PRE:
    //POST: cambia el atributo roto a false
    virtual void reparar(){};

    virtual ~Edificio();
};

#endif
