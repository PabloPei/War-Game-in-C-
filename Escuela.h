#ifndef __ESCUELA_H__
#define __ESCUELA_H__

#include "Edificio.h"

const int ANDYCOINS_ESCUELA = 25;

class Escuela:public Edificio {

//atributos:
private:

//metodos:
public:
    //PRE: -
    //POST: Construye un edificio escuela con todos sus parametros en 0
    Escuela(int jugador);

    //PRE: madera,piedra,metal,maximo datos validos (enteros > 0)
    //POST: Construye un edificio aserradero con los parametros correspondientes
    Escuela(int madera, int piedra, int metal, int maximo);

    //PRE:
    //POST:
    void describir();

    //PRE:
    //POST:
    void aumentar_recursos_acumulados();

};

#endif
