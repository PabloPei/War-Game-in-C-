#include "Casillero_inaccesible.h"
#include <iostream>

/* ---------------------------------------------------------------------------------------------------------*/

Casillero_inaccesible::Casillero_inaccesible(int fila, int columna){
    
    this->fila = fila;
    this->columna = columna;
    this->tipo = LAGO;
    this -> hay_jugador=false;
    this -> jugador = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_inaccesible::agregar_jugador(int jugador) {

    this->jugador = jugador;
    hay_jugador = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_inaccesible::eliminar_jugador() {

    jugador = 0;
    hay_jugador = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_inaccesible::consultar(){

    std::cout<< endl << '\t' << negrita << "Soy un casillero inaccesible, no podes construir aca ni estar parado."
        << fin_de_formato<<std::endl;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Casillero_inaccesible::obtener_fil(){
    
    return this->fila;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Casillero_inaccesible::obtener_col(){
    
    return this->columna;
}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Casillero_inaccesible::obtener_tipo(){

    return tipo;
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Casillero_inaccesible::ocupado(){
    
    return true;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Casillero_inaccesible::obtener_energia(int personaje) {
    int energia;
    if (personaje == 2)energia=5;
    else energia=2;
    return energia;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_inaccesible::mostrar(){


    if(this->hay_jugador){
        if(this->jugador == 1)
            std::cout << fondo_color_azul << TXT_RED_196 << " " << "J1" <<"  " << fin_de_formato;
        else
            std::cout << fondo_color_azul << TXT_RED_196 << "  " << "U" <<"  " << fin_de_formato;

    }else{
        std::cout << fondo_color_azul << "     " << fin_de_formato;
    }
}

/* ---------------------------------------------------------------------------------------------------------*/
