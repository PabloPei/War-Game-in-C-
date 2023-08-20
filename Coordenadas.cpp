#include "Coordenadas.h"

/* ---------------------------------------------------------------------------------------------------------*/

Coordenadas::Coordenadas(int coordenadaX, int coordenadaY){
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Coordenadas::obtenerCoordenadaX(){
    return coordenadaX;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Coordenadas::obtenerCoordenadaY(){
    return coordenadaY;
}

/* ---------------------------------------------------------------------------------------------------------*/
