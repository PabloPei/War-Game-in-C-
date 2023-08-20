#include <iostream>
#include <string>
#include "Inventario.h"
#include "Leer_archivo_materiales.h"
#include "Leer_archivo_mapa.h"
#include "Leer_archivo_edificios.h"
#include "Leer_archivo_ubicaciones.h"
#include "Mapa.h"
#include "Menu.h"
#include "Lista.h"
#include "errores.h"
#include "Grafo.h"
#include "Coordenadas.h"
#include "Andypolis.h"

using namespace std;

int main() {


    Status_t st;

    Andypolis andypolis;
    st = andypolis.iniciar();
    if(st != OK && st != ERROR_APERTURA_ARCHIVO_UBICACIONES && st !=ARCHIVO_UBICACIONES_VACIO )
        imprimir_error(st);
    else
        andypolis.jugar(st);


    return 0;
}
