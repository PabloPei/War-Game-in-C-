#ifndef __ASERRADERO_H__
#define __ASERRADERO_H__

#include <string>
#include "Edificio.h"

const int MADERA_GENERADA = 25;
const std::string MADERA_ = "madera";

class Aserradero:public Edificio {

//atributos:
private:

//metodos:
public:
    //PRE: -
    //POST: Construye un edificio aserradero con todos sus parametros en 0
    Aserradero(int jugador);

    //PRE: madera,piedra,metal,maximo datos validos (enteros > 0)
    //POST: Construye un edificio aserradero con los parametros correspondientes
    Aserradero(int madera, int piedra, int metal, int maximo);

    //PRE:
    //POST:
    void aumentar_recursos_acumulados();

    //PRE:
    //POST:
    void describir();
};
#endif
