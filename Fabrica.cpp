#include "Fabrica.h"
#include <string>

/* ---------------------------------------------------------------------------------------------------------*/

Fabrica::Fabrica(int jugador){

    this->jugador = jugador;
    this->nombre = FABRICA;
    this->madera = 0;
    this->piedra = 0;
    this->metal = 0;
    this->icono = FABRICA_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->maximo_permitido = 0;
    this -> roto = false;

}

/* ---------------------------------------------------------------------------------------------------------*/

Fabrica::Fabrica(int madera, int piedra, int metal, int maximo){

    this->nombre = FABRICA;
    this->madera = madera;
    this->piedra = piedra;
    this->metal = metal;
    this->icono = FABRICA_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->jugador = 0;
    this->maximo_permitido = maximo;
    this -> roto = false;

}

/* ---------------------------------------------------------------------------------------------------------*/

void Fabrica::reparar() {

    this->roto = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Fabrica::describir(){

    std::cout<< std::endl << '\t' << negrita << "Soy una "<<this->nombre<<" y estoy haciendo metal en este casillero."
        << fin_de_formato <<std::endl;
}
/* ---------------------------------------------------------------------------------------------------------*/

void Fabrica::aumentar_recursos_acumulados(){
    this->recursos_acumulados += 40;
}


/* ---------------------------------------------------------------------------------------------------------*/
