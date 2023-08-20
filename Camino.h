#ifndef __CAMINO_H__
#define __CAMINO_H __

#include <iostream>
#include "Casillero_Transitable.h"
#include "formatos.h"
#include "Material.h"


class Camino : public Casillero_transitable{

//atributos:
private:
    int energia_requerida;

//metodos:
public:
    //PRE:
    //POST:
    Camino(int fila, int columna);

    //PRE:
    //POST:
    Camino(int fila, int columna,std::string nombre_material);

    //PRE:
    //POST:
    int obtener_energia(int personaje);

    //PRE:
    //POST:
    void mostrar();
};


#endif