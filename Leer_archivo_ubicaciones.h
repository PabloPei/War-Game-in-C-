#ifndef __LEER_ARCHIVO_UBICACIONES_H__
#define __LEER_ARCHIVO_UBICACIONES_H__

#include <iostream>
#include <fstream>
#include "Leer_archivo.h"
#include "Mapa.h"
#include "errores.h"
#include "Lista.h"
#include "Edificio.h"
#include "ABB.h"
#include "Jugador.h"


const std::string PATH_UBICACIONES = "ubicaciones.txt";
const std::string DELIMITADOR_1 = "1";
const std::string DELIMITADOR_2 = "2";

class Leer_archivo_ubicaciones:public Leer_archivo {

//atributos:
private:

//metodos:
public:
    //PRE:
    //POST:
    Leer_archivo_ubicaciones();

    //PRE:
    //POST: lee el archivo ubicaciones.txt y posiciona los elementos en el mapa
    bool leer_archivo(Mapa* mapa, ABB<string, Edificio*>* diccionario_edificios, Jugador* jugador_1, Jugador* jugador_2);
};


#endif