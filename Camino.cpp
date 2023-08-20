#include "Camino.h"

/* ---------------------------------------------------------------------------------------------------------*/

Camino::Camino(int fila, int columna)
        :Casillero_transitable(fila, columna){
    this -> energia_requerida = 0;
    this -> tipo = CAMINO;
}

/* ---------------------------------------------------------------------------------------------------------*/

Camino::Camino(int fila, int columna,std::string nombre_material)
        :Casillero_transitable(fila, columna,nombre_material){
    this -> energia_requerida = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Camino::mostrar() {

    if(!this->hay_material && !this->hay_jugador){
        std::cout << fondo_color_gris << "     " << fin_de_formato ;

    }else if(this->hay_jugador){
        if(this->jugador == 1)
            std::cout << fondo_color_gris << TXT_RED_196 << " " << "J1" <<"  " << fin_de_formato;
        else
            std::cout << fondo_color_gris << TXT_RED_196 << "  " << "U" <<"  " << fin_de_formato;

    }else{
        std::cout << fondo_color_gris << "  " << this->material->obtener_icono() << "  " << fin_de_formato ;
    }

}

/* ---------------------------------------------------------------------------------------------------------*/

int Camino::obtener_energia(int personaje) {
    int energia=4;
    return energia;
}

/* ---------------------------------------------------------------------------------------------------------*/
