#include "Andycoins.h"


Andycoins::Andycoins(){

    this->nombre= ANDYCOINS;
    this->icono = ANDYCOINS_ICONO;
    this->cantidad = 0;
}


Andycoins::Andycoins(int cantidad){

    this->nombre= ANDYCOINS;
    this->icono = ANDYCOINS_ICONO;
    this->cantidad = cantidad;
}
