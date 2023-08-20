#ifndef __LEER_ARCHIVO_MAPA_H__
#define __LEER_ARCHIVO_MAPA_H__

#include <fstream>
#include "Leer_archivo.h"
#include "Mapa.h"
#include "errores.h"
#include "Casillero.h"
#include "Casillero_Transitable.h"
#include "Casillero_construible.h"
#include "Casillero_inaccesible.h"

const std::string PATH_MAPA = "mapa.txt";

class Leer_archivo_mapa:public Leer_archivo{

//atributos:
private:

//metodos:
public:

    //PRE:
    //POST:
    Leer_archivo_mapa();

    //PRE:
    //POST: lee el archivo mapa.txt y carga el objeto mapa
    void leer_archivo(Mapa* mapa);

};

#endif
