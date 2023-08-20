#include "Mina.h"
#include <string>

/* ---------------------------------------------------------------------------------------------------------*/

Mina::Mina(int jugador){

    this->jugador = jugador;
    this->nombre = MINA;
    this->madera = 0;
    this->piedra = 0;
    this->metal = 0;
    this->icono = MINA_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->maximo_permitido = 0;
    this -> roto = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

Mina::Mina(int madera, int piedra, int metal, int maximo){

    this->nombre = MINA;
    this->madera = madera;
    this->piedra = piedra;
    this->metal = metal;
    this->icono = MINA_ICONO;
    this->cantidad_construidos_j1 = 0;
    this->cantidad_construidos_j2 = 0;
    this->jugador=0;
    this->maximo_permitido = maximo;
    this -> roto = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mina::reparar() {

    this->roto = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mina::describir(){

    std::cout<< std::endl << '\t' << negrita << "Soy una "<<this->nombre<<", estoy sacando la piedra de este casillero."
        << fin_de_formato <<std::endl;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mina::aumentar_recursos_acumulados(){
    this->recursos_acumulados += 15;
}

/* ---------------------------------------------------------------------------------------------------------*/


