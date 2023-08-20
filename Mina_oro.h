#ifndef __MINA_ORO_H__
#define __MINA_ORO_H__

#include <string>
#include "Edificio.h"

const int ANDYCOINS_GENERADOS = 50;
const std::string ANDYCOINS_ = "andycoins";

class Mina_oro:public Edificio {

//atributos:
private:

//metodos:
public:
    //PRE: -
    //POST: Construye un edificio aserradero con todos sus parametros en 0
    Mina_oro(int jugador);

    //PRE: madera,piedra,metal,maximo datos validos (enteros > 0)
    //POST: Construye un edificio aserradero con los parametros correspondientes
    Mina_oro(int madera, int piedra, int metal, int maximo);

    //PRE:
    //POST:
    void describir();

    //PRE:
    //POST:
    void aumentar_recursos_acumulados();
};

#endif
