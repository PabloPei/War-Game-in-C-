#include "Obelisco.h"

/* ---------------------------------------------------------------------------------------------------------*/

Obelisco::Obelisco(int jugador){

    this->jugador = jugador;
    this->nombre = OBELISCO;
    this->madera = 0;
    this->piedra = 0;
    this->metal = 0;
    this->icono = OBELISCO_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->maximo_permitido = 0;
    this -> roto = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

Obelisco::Obelisco(int madera, int piedra, int metal, int maximo){

    this->nombre = OBELISCO;
    this->madera = madera;
    this->piedra = piedra;
    this->metal = metal;
    this->icono = OBELISCO_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->jugador = 0;
    this->maximo_permitido = maximo;
    this -> roto = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Obelisco::describir(){

    std::cout<<std::endl << '\t' << negrita << "Soy un "<<this->nombre<<" y estoy ocupando este casillero."
         << fin_de_formato <<std::endl;
}


/* ---------------------------------------------------------------------------------------------------------*/

