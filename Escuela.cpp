#include "Escuela.h"

/* ---------------------------------------------------------------------------------------------------------*/

Escuela::Escuela(int jugador){

    this->jugador = jugador;
    this->nombre = ESCUELA;
    this->madera = 0;
    this->piedra = 0;
    this->metal = 0;
    this->icono = ESCUELA_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->maximo_permitido = 0;
    this -> roto = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

Escuela::Escuela(int madera, int piedra, int metal, int maximo){

    this->nombre = ESCUELA;
    this->madera = madera;
    this->piedra = piedra;
    this->metal = metal;
    this->icono = ESCUELA_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->jugador = 0;
    this->maximo_permitido = maximo;
    this -> roto = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Escuela::describir(){

    std::cout<<std::endl <<'\t' << negrita << "Soy una "<<this->nombre<<" y estoy educando a los ciudadanos de Andypolis en este casillero."
        << fin_de_formato <<std::endl;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Escuela::aumentar_recursos_acumulados(){
    this->recursos_acumulados += 25;
}

/* ---------------------------------------------------------------------------------------------------------*/
