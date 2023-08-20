#include "Muelle.h"

/* ---------------------------------------------------------------------------------------------------------*/

Muelle::Muelle(int fila, int columna) :
                Casillero_transitable(fila, columna){
    this -> energia_requerida = 0;
    this -> tipo = MUELLE;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Muelle::mostrar() {

    if(!this->hay_material  && !this->hay_jugador){
        std::cout << fondo_color_marron << "     " << fin_de_formato ;

    }else if(this->hay_jugador){
        if(this->jugador == 1)
            std::cout << fondo_color_marron << TXT_RED_196 << " " << "J1" <<"  " << fin_de_formato;
        else
            std::cout << fondo_color_marron << TXT_RED_196 << "  " << "U" <<"  " << fin_de_formato;

    }else{
        std::cout << fondo_color_marron << "  " << this->material->obtener_icono() << "  " << fin_de_formato ;
    }

}

/* ---------------------------------------------------------------------------------------------------------*/

int Muelle::obtener_energia(int personaje) {
    int energia;
    if (personaje == 2)energia=2;
    else energia = 5;
    return energia;
}

/* ---------------------------------------------------------------------------------------------------------*/
