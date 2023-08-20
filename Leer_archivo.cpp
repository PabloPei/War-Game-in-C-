#include "Leer_archivo.h"

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Leer_archivo::abrir_archivo() {
    archivo.open(path);

    if(!archivo.is_open()){
        return error;
    }


    return OK;

}

/* ---------------------------------------------------------------------------------------------------------*/

void Leer_archivo::cerrar_archivo() {
    archivo.close();
}

/* ---------------------------------------------------------------------------------------------------------*/

