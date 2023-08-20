#ifndef __MINA_H__
#define __MINA_H__

#include "Edificio.h"

const int PIEDRA_GENERADA = 15;
const std::string PIEDRA_ = "piedra";

class Mina:public Edificio {

//atributos:
private:

//metodos:
public:
    //PRE: -
    //POST: Construye un edificio mina con todos sus parametros en 0
    Mina(int jugador);

    //PRE: madera,piedra,metal,maximo datos validos (enteros > 0)
    //POST: Construye un edificio mina con los parametros correspondientes
    Mina(int madera, int piedra, int metal, int maximo);

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
