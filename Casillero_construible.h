#ifndef __CASILLERO_CONSTRUIBLE_H__
#define __CASILLERO_CONSTRUIBLE_H__

#include "Casillero.h"
#include "Edificio.h"
#include "Mina.h"
#include "Mina_oro.h"
#include "Aserradero.h"
#include "Fabrica.h"
#include "Escuela.h"
#include "Obelisco.h"
#include "Planta_electrica.h"
#include "formatos.h"
#include "ABB.h"



class Casillero_construible:public Casillero{

//atributos:
private:
    int jugador;
    bool hay_jugador;
    Edificio* edificio;
    bool hay_edificio;

//metodos:
public:

    //PRE: datos fila y columna validos (enteros > 0)
    //POST: construye un casillero construible
    Casillero_construible(int fila, int columna);

    //PRE: datos fila y columna validos (enteros > 0) y nombre valido
    //POST: construye un casillero construible
    Casillero_construible(int fila, int columna, std::string nombre,int jugador);

    //PRE:
    //POST: retorna el edificio de este casillero;
    Edificio* obtener_edificio();

    //PRE:
    //POST: imprime el icono del casillero o del edificio que lo ocupa
    void mostrar();

    //PRE:
    //POST: muestra que tipo de casillero es y si esta ocupado o no
    void consultar();

    //PRE:
    //POST:
    int obtener_fil();

    //PRE:
    //POST:
    int obtener_col();

    //PRE:
    //POST: devuelve el tipo de elemento que ocupa el casillero
    std::string obtener_tipo();

    //PRE:
    //POST: devuelve true si hay un edificio o false si no
    bool ocupado();

    //PRE:
    //POST:
    std::string obtener_nombre_atributo();

    //PRE:
    //POST:
    void cambiar_atributo(std::string nombre, int jugador);

    //PRE:
    //POST:
    void eliminar_atributo();

    //PRE:
    //POST:
    void agregar_jugador(int jugador);

    //PRE:
    //POST:
    bool hay_jugador_en_casillero();

    //PRE:
    //POST:
    bool hay_edificio_en_casillero();

    //PRE:
    //POST:
    bool esta_roto();

    //PRE:
    //POST:
    void eliminar_jugador();

    //PRE:
    //POST:
    int obtener_energia(int personaje);

    bool atacar(int atacante, ABB<string, Edificio*>* diccionario);

    bool reparar(int reparador);

    //PRE:
    //POST:
    ~Casillero_construible();


};

#endif
