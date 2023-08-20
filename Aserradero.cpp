#include "Aserradero.h"

/* ---------------------------------------------------------------------------------------------------------*/

Aserradero::Aserradero(int jugador){

    this->nombre = ASERRADERO;
    this->jugador = jugador;
    this->madera = 0;
    this->piedra = 0;
    this->metal = 0;
    this->icono = ASERRADERO_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->maximo_permitido = 0;
    this -> roto = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

Aserradero::Aserradero(int madera, int piedra, int metal, int maximo){

    this->nombre = ASERRADERO;
    this->madera = madera;
    this->piedra = piedra;
    this->metal = metal;
    this->icono = ASERRADERO_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->jugador = 0;
    this->maximo_permitido = maximo;
    this -> roto = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Aserradero::describir(){

    std::cout<< std::endl << '\t' << negrita << "Soy un "<<this->nombre<<" y estoy en este casillero generando madera."
       << fin_de_formato <<std::endl;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Aserradero::aumentar_recursos_acumulados(){
    this->recursos_acumulados += 25;
}

/* ---------------------------------------------------------------------------------------------------------*/
