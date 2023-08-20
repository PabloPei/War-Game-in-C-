#ifndef __BETUN_H__
#define __BETUN_H__

#include <iostream>
#include "Casillero_Transitable.h"
#include "formatos.h"
#include "Material.h"


class Betun : public Casillero_transitable{

//atributos:
private:
    int energia_requerida;

//metodos:
public:
    //PRE:
    //POST:
    Betun(int fila,int columna);

    //PRE:
    //POST:
    Betun(int fila, int columna,std::string nombre_material);

    //PRE:
    //POST:
    int obtener_energia(int personaje);

    //PRE:
    //POST:
    void mostrar();

};


#endif