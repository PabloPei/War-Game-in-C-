#include "Planta_electrica.h"

/* ---------------------------------------------------------------------------------------------------------*/

Planta_electrica::Planta_electrica(int jugador){

    this->jugador = jugador;
    this->nombre = PLANTA_ELECTRICA;
    this->madera = 0;
    this->piedra = 0;
    this->metal = 0;
    this->icono = PLANTA_ELECTRICA_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->maximo_permitido = 0;
    this -> roto = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

Planta_electrica::Planta_electrica(int madera, int piedra, int metal, int maximo){

    this->nombre = PLANTA_ELECTRICA;
    this->madera = madera;
    this->piedra = piedra;
    this->metal = metal;
    this->icono = PLANTA_ELECTRICA_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->jugador = 0;
    this->maximo_permitido = maximo;
    this -> roto = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Planta_electrica::describir(){

    std::cout<<"\tSoy una "<<this->nombre<<" y estoy ocupando este casillero."
        <<std::endl;
}


/* ---------------------------------------------------------------------------------------------------------*/

void Planta_electrica::aumentar_recursos_acumulados(){
    this->recursos_acumulados += 15;
}


/* ---------------------------------------------------------------------------------------------------------*/
