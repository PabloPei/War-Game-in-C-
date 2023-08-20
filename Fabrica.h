#ifndef __FABRICA_H__
#define __FABRICA_H__

#include "Edificio.h"

const int METAL_GENERADO = 40;
const std::string METAL_ = "metal";

class Fabrica:public Edificio {

//atributos:
private:

//metodos:
public:
    //PRE: -
    //POST: Construye un edificio fabrica con todos sus parametros en 0
    Fabrica(int jugador);

    //PRE: madera,piedra,metal,maximo datos validos (enteros > 0)
    //POST: Construye un edificio fabrica con los parametros correspondientes
    Fabrica(int madera, int piedra, int metal, int maximo);

    //PRE:
    //POST:
    void describir();

    //PRE:
    //POST:
    void reparar();

    //PRE:
    //POST:
    void aumentar_recursos_acumulados();
    
};

#endif
