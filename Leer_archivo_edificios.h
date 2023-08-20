#ifndef __LEER_ARCHIVO_EDIFICIOS_H__
#define __LEER_ARCHIVO_EDIFICIOS_H__

#include <fstream>
#include "Leer_archivo.h"
#include "Mapa.h"
#include "errores.h"
#include "ABB.h"
#include "Nodo_abb.h"
#include "Edificio.h"

const std::string PATH_EDIFICIOS = "edificios.txt";

class Leer_archivo_edificios:public Leer_archivo {

//atributos:
private:

//metodos:
public:

    //PRE:
    //POST:
    Leer_archivo_edificios();

    //PRE:
    //POST: lee el archivo edificios.txt y carga el diccionario
    void leer_archivo(Mapa* mapa,ABB<string, Edificio*>* diccionario_edificios);

};


#endif
