#include "Leer_archivo_mapa.h"

/* ---------------------------------------------------------------------------------------------------------*/

Leer_archivo_mapa::Leer_archivo_mapa() {
    this -> error = ERROR_APERTURA_ARCHIVO_MAPA;
    this -> path = PATH_MAPA;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Leer_archivo_mapa::leer_archivo( Mapa* mapa){
    int filas;
    int columnas;
    char tipo_de_casillero;

    archivo>>filas;
    archivo>>columnas;

    mapa -> cargar_mapa(filas,columnas);

    for(int fil = 0; fil<filas; fil++){

        for(int col = 0; col < columnas; col++){

            archivo>>tipo_de_casillero;
            mapa->agregar_casillero(tipo_de_casillero,fil,col);

        }
    }
}
/* ---------------------------------------------------------------------------------------------------------*/
