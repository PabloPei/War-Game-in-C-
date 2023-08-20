#ifndef __LEER_ARCHIVO_H__
#define __LEER_ARCHIVO_H__

#include <iostream>
#include <fstream>
#include <string>
#include "Lista.h"
#include "errores.h"

class Leer_archivo{

//atributos:
protected:
    Status_t error;
    std::string path;
    std::fstream archivo;

//metodos
public:

    //PRE:
    //POST: abre el archivo
    Status_t abrir_archivo();

    //PRE:
    //POST: cierra el archivo
    void cerrar_archivo();
};

#endif