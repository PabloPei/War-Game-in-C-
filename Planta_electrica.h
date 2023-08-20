#ifndef __PLANTA_ELECTRICA_H__
#define __PLANTA_ELECTRICA_H__

#include "Edificio.h"

const int ENERGIA_GENERADA = 15;

class Planta_electrica:public Edificio {

//atributos:
private:

//metodos:
public:

    //PRE: -
    //POST: Construye un edificio planta_electrica con todos sus parametros en 0
    Planta_electrica(int jugador);

    //PRE: madera,piedra,metal,maximo datos validos (enteros > 0)
    //POST: Construye un edificio planta_electrica con los parametros correspondientes
    Planta_electrica(int madera, int piedra, int metal, int maximo);

    //PRE:
    //POST:
    void describir();

    //PRE:
    //POST:
    void aumentar_recursos_acumulados();
};

#endif
