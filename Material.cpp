#include "Material.h"
#include <iostream>

/* ---------------------------------------------------------------------------------------------------------*/

Material::Material(){

    this->nombre = "0";
    this->icono = " ";
    this->cantidad = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

Material::Material(std::string nombre, int cantidad){

    this->nombre = nombre;
    this->icono = nombre[0];
    this->cantidad = cantidad;
}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Material::obtener_nombre(){

    return this->nombre;
}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Material::obtener_icono(){

    return this->icono;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Material::obtener_cantidad(){

    return this->cantidad;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Material::sumar_material(int cantidad_agregada){

    this->cantidad += cantidad_agregada;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Material::restar_material(int cantidad_sustraida){

    this->cantidad -= cantidad_sustraida;
}
/* ---------------------------------------------------------------------------------------------------------*/
