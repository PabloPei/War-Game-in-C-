#include "Casillero_Transitable.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

/* ---------------------------------------------------------------------------------------------------------*/

Casillero_transitable::Casillero_transitable(int fila, int columna){

    this->jugador = 0;
    this->hay_jugador = false;
    this->fila = fila;
    this->columna = columna;
    this->material = NULL;
    this->hay_material=false;
}

/* ---------------------------------------------------------------------------------------------------------*/

Casillero_transitable::Casillero_transitable(int fila, int columna,
                                             std::string nombre_material){


    if(nombre_material == MADERA){

        this->material = new Madera(50);

    }else if(nombre_material == PIEDRA){

        this->material = new Piedra(100);

    }else if(nombre_material == METAL){

        this->material = new Metal(50);

    }else{

        this->material = new Andycoins(250);
    }


    this->jugador = 0;
    this->hay_jugador = false;
    this->fila = fila;
    this->columna = columna;
    this->hay_material = true;

}

/* ---------------------------------------------------------------------------------------------------------*/

int Casillero_transitable::obtener_fil(){

    return this->fila;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Casillero_transitable::obtener_col(){

    return this->columna;
}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Casillero_transitable::obtener_tipo(){


    return this->tipo;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_transitable::consultar(){

    if(hay_material){

        std::cout<< endl << '\t' << negrita << "Soy un casillero transitable y en el momento tengo "
                 << material->obtener_nombre() << fin_de_formato <<std::endl;

    }else if(this->hay_jugador){
        std::cout<< endl << '\t' << negrita << "Soy un casillero transitable y tengo al jugador " << jugador <<
                 "parado sobre mi."<< fin_de_formato << std::endl;
    }else{

        std::cout<< endl << '\t' << negrita << "Soy un casillero transitable y estoy vacio."<< fin_de_formato << std::endl;
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Casillero_transitable::ocupado(){
    return (this->hay_material || this->hay_jugador);
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Casillero_transitable::hay_material_en_casillero(){
    return (this->hay_material);
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_transitable::cambiar_atributo(std::string nombre){

    Material* aux;
    int cantidad_bolsas;
    srand((unsigned)time(NULL));

    if(nombre == MADERA) {
        cantidad_bolsas= rand()%3;
        aux = new Madera(50 * cantidad_bolsas);
    }else if(nombre == PIEDRA) {
        cantidad_bolsas= rand()%1 +1 ;
        aux = new Piedra(100 * cantidad_bolsas);
    }else if(nombre == METAL) {
        cantidad_bolsas= rand()%2 +2;
        aux = new Metal(50 * cantidad_bolsas);
    }else{
        cantidad_bolsas= rand()%1;
        aux = new Andycoins(250 * cantidad_bolsas);
    }

    this -> material = aux;
    this -> hay_material = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_transitable::eliminar_atributo() {

    delete material;
    material = nullptr;

    hay_material = false;
}

/* ---------------------------------------------------------------------------------------------------------*/
Material* Casillero_transitable::obtener_material() {
    return this->material;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_transitable::agregar_jugador(int jugador) {

    this->jugador = jugador;
    hay_jugador = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_transitable::eliminar_jugador() {

    jugador = 0;
    hay_jugador = false;
}

/* ---------------------------------------------------------------------------------------------------------*/
bool Casillero_transitable::hay_jugador_en_casillero() {
    return this -> hay_jugador;
}
/* ---------------------------------------------------------------------------------------------------------*/

Casillero_transitable::~Casillero_transitable(){

    delete this->material;
    this->material = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Casillero_transitable::obtener_energia(int personaje) {
    int energia=0;
    return energia;
}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Casillero_transitable::obtener_nombre_atributo() {
    std::string nombre;

    if (hay_material) {
        nombre = this->material->obtener_nombre();

    }else {
        nombre = " ";
    }

    return nombre;
}

/* ---------------------------------------------------------------------------------------------------------*/
