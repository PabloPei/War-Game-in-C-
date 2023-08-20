#include "Edificio.h"
#include "formatos.h"
#include "Andypolis.h"
#include "Mapa.h"

/* ---------------------------------------------------------------------------------------------------------*/

Edificio::Edificio(){

    this -> nombre = "0";
    this -> piedra = 0;
    this -> madera = 0;
    this -> metal = 0;
    this -> jugador = 0;
    this -> cantidad_construidos_j1 = 0;
    this -> cantidad_construidos_j2 = 0;
    this -> maximo_permitido = 0;
    this -> recursos_acumulados = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

Edificio::Edificio(std::string nombre, int piedra, int madera, int metal,
                   int maximo_permitido){

    this -> nombre = nombre;
    this -> piedra = piedra;
    this -> madera = madera;
    this -> metal = metal;
    this -> jugador = 0;
    this -> cantidad_construidos_j1 = 0;
    this -> cantidad_construidos_j2 = 0;
    this -> maximo_permitido = maximo_permitido;
    this -> roto = true;
    this -> recursos_acumulados = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

Edificio::Edificio(std::string nombre, int piedra, int madera, int metal,
                   int maximo_permitido,int jugador){

    this -> nombre = nombre;
    this -> piedra = piedra;
    this -> madera = madera;
    this -> metal = metal;
    this -> jugador = jugador;
    this -> cantidad_construidos_j1 = 0;
    this -> cantidad_construidos_j2 = 0;
    this -> maximo_permitido = maximo_permitido;
    this -> roto = true;
    this -> recursos_acumulados = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Edificio::obtener_nombre(){

    return this->nombre;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Edificio::obtener_piedra(){

    return this->piedra;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Edificio::obtener_madera(){

    return this->madera;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Edificio::obtener_metal(){

    return this->metal;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Edificio::obtener_construidos_j1(){

    return this->cantidad_construidos_j1;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Edificio::obtener_construidos_j2(){

    return this->cantidad_construidos_j2;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Edificio::obtener_jugador(){
    return this -> jugador;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Edificio::obtener_maximo(){

    return this->maximo_permitido;
}
/* ---------------------------------------------------------------------------------------------------------*/

int Edificio::obtener_recursos_producidos(){
    int aux = this->recursos_acumulados;
    this -> recursos_acumulados = 0;
    return aux;
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Edificio::esta_roto() {

    return this->roto;
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Edificio::hay_espacio(int jugador) {

    if(jugador == 1){
        return (this->cantidad_construidos_j1 < this->maximo_permitido);
    }
    else
        return (this->cantidad_construidos_j2 < this->maximo_permitido);

}
/* ---------------------------------------------------------------------------------------------------------*/
void Edificio::incrementar_construidos_j1(){

    this->cantidad_construidos_j1 ++;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::incrementar_construidos_j2(){

    this->cantidad_construidos_j2++;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::incrementar_construidos(int jugador){

    if(jugador == 1 )
        this->cantidad_construidos_j1 ++;
    else
        this->cantidad_construidos_j2 ++;
}
/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::decrementar_construidos(int jugador){
    if(jugador == 1 ) {
        this->cantidad_construidos_j1--;
    }else {
        this->cantidad_construidos_j2--;
    }
}


/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::reducir_construidos_j1(){

    this->cantidad_construidos_j1--;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::reducir_construidos_j2(){

    this->cantidad_construidos_j2--;
}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Edificio::obtener_icono(){

    return this->icono;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::modificar_piedra_edificio(int piedra_nueva_cantidad){
    this->piedra = piedra_nueva_cantidad;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::modificar_madera_edificio(int madera_nueva_cantidad){
    this->madera = madera_nueva_cantidad;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::modificar_metal_edificio(int metal_nueva_cantidad){
    this->metal = metal_nueva_cantidad;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::romper() {

    roto = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::imprimir_si_brinda_material(std::string nombre_edificio){

    std::string nombre_material;
    int cantidad_material;
    bool genera_material = (nombre_edificio == MINA || nombre_edificio ==
                                                       ASERRADERO || nombre_edificio == FABRICA ||
                            nombre_edificio == ESCUELA || nombre_edificio == PLANTA_ELECTRICA
                            || nombre_edificio == MINA_ORO);

    if(nombre_edificio == MINA){

        nombre_material = PIEDRA;
        cantidad_material = PIEDRA_GENERADA;

    }else if(nombre_edificio == ASERRADERO){

        nombre_material = MADERA;
        cantidad_material = MADERA_GENERADA;

    }else if(nombre_edificio == FABRICA){

        nombre_material = METAL;
        cantidad_material = METAL_GENERADO;

    }else if(nombre_edificio == ESCUELA){

        nombre_material = ANDYCOINS;
        cantidad_material = ANDYCOINS_ESCUELA;

    }else if(nombre_edificio == PLANTA_ELECTRICA){

        nombre_material = ENERGIA;
        cantidad_material = ENERGIA_GENERADA;

    }else if(nombre_edificio == MINA_ORO){

        nombre_material = ANDYCOINS;
        cantidad_material = ANDYCOINS_GENERADOS;
    }


    if(genera_material){

        std::cout << negrita << '\t' << '\t' << "Genera: "<< cantidad_material << " unidades de " << nombre_material << std::endl;
        std::cout << std::endl << std::endl;
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::imprimir_datos() {


    std::cout << '\t' << fondo_color_purpura << this->nombre << fin_de_formato << std::endl << std::endl;

    std::cout << negrita << '\t' << '\t' <<  "Piedra necesaria: " << this->piedra << fin_de_formato << std::endl;
    std::cout << negrita << '\t' << '\t' <<  "Madera necesaria: " << this->madera << fin_de_formato << std::endl;
    std::cout << negrita << '\t' << '\t' <<  "Metal necesario: " << this->metal << fin_de_formato << std::endl;
    std::cout << negrita << '\t' << '\t' <<  "Cantidad construídos: 0" << fin_de_formato << std::endl;
    std::cout << negrita << '\t' << '\t' <<  "Se pueden construir: " << this->maximo_permitido << fin_de_formato << std::endl;
    imprimir_si_brinda_material(this->nombre);

    std::cout << std::endl << std::endl;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Edificio::imprimir_datos_construidos(int jugador) {


    if(jugador == 1) {
        if(cantidad_construidos_j1 > 0) {
            std::cout << '\t' << fondo_color_purpura << this->nombre << fin_de_formato << std::endl << std::endl;
            std::cout << negrita << '\t' << '\t' << "Cantidad construídos: " << cantidad_construidos_j1
                      << fin_de_formato
                      << std::endl;
            std::cout << negrita << '\t' << '\t' << "Se pueden construir: "
                      << this->maximo_permitido - cantidad_construidos_j1 << fin_de_formato
                      << std::endl;
        }
    }
    else{
        if(cantidad_construidos_j2 > 0) {
            std::cout << '\t' << fondo_color_purpura << this->nombre << fin_de_formato << std::endl << std::endl;
            std::cout << negrita << '\t' << '\t' << "Cantidad construídos: " << cantidad_construidos_j2
                      << fin_de_formato
                      << std::endl;
            std::cout << negrita << '\t' << '\t' << "Se pueden construir: "
                      << this->maximo_permitido - cantidad_construidos_j2 << fin_de_formato
                      << std::endl;
        }
    }

}
/* ---------------------------------------------------------------------------------------------------------*/

Edificio::~Edificio(){

}

