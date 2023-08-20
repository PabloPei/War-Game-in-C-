#include "Mina_oro.h"

/* ---------------------------------------------------------------------------------------------------------*/

Mina_oro::Mina_oro(int jugador){

    this->nombre = MINA_ORO;
    this->jugador = jugador;
    this->madera = 0;
    this->piedra = 0;
    this->metal = 0;
    this->icono = MINA_ORO_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->maximo_permitido = 0;
    this -> roto = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

Mina_oro::Mina_oro(int madera, int piedra, int metal, int maximo){

    this->nombre = MINA_ORO;
    this->madera = madera;
    this->piedra = piedra;
    this->metal = metal;
    this->icono = MINA_ORO_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->jugador = 0;
    this->maximo_permitido = maximo;
    this -> roto = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mina_oro::describir(){

    std::cout<< std::endl << '\t' << negrita << "Soy un "<<this->nombre<<" y estoy en este casillero generando Andycoins."
             << fin_de_formato <<std::endl;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mina_oro::aumentar_recursos_acumulados(){
    this->recursos_acumulados += 50;
}


/* ---------------------------------------------------------------------------------------------------------*/

