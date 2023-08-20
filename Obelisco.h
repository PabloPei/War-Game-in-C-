#ifndef __OBELISCO_H__
#define __OBELISCO_H__

#include "Edificio.h"

class Obelisco:public Edificio {

//atributos:
private:

//metodos:
public:
    //PRE: -
    //POST: Construye un edificio obelisco con todos sus parametros en 0
    Obelisco(int jugador);

    //PRE: madera,piedra,metal,maximo datos validos (enteros > 0)
    //POST: Construye un edificio obelisco con los parametros correspondientes
    Obelisco(int madera, int piedra, int metal, int maximo);

    //PRE:
    //POST:
    void describir();


};

#endif
