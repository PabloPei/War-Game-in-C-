#ifndef __MUELLE_H__
#define __MUELLE_H__

#include <iostream>
#include "Casillero_Transitable.h"
#include "formatos.h"
#include "Material.h"


class Muelle : public Casillero_transitable{

//atributos:
private:
    int energia_requerida;

//metodos:
public:
    //PRE:
    //POST:
    Muelle(int fila, int columna);

    //PRE:
    //POST:
    Muelle(int fila, int columna,std::string nombre_material);

    //PRE:
    //POST:
    int obtener_energia(int personaje);

    //PRE:
    //POST:
    void mostrar();
};


#endif