#ifndef __LEER_ARCHIVO_MATERIALES_H__
#define __LEER_ARCHIVO_MATERIALES_H__

#include <iostream>
#include <fstream>
#include "Leer_archivo.h"
#include "Inventario.h"
#include "Material.h"
#include "errores.h"
#include "Madera.h"
#include "Metal.h"
#include "Piedra.h"
#include "Bombas.h"
#include "Andycoins.h"

const std::string PATH_MATERIALES = "materiales.txt";

class Leer_archivo_materiales:public Leer_archivo{

//atributos:
private:

//metodos:
public:

    //PRE:
    //POST:
    Leer_archivo_materiales();

    //PRE:
    //POST: lee el archivo materiales.txt y carga los inventarios de ambos jugadores
    void leer_archivo( Inventario* materiales_j1, Inventario* materiales_j2);

};

#endif