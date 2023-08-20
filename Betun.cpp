#include "Betun.h"

/* ---------------------------------------------------------------------------------------------------------*/

Betun::Betun(int fila, int columna)
        : Casillero_transitable(fila, columna){
    this -> energia_requerida = 0;
    this -> tipo = BETUN;
}

/* ---------------------------------------------------------------------------------------------------------*/

Betun::Betun(int fila, int columna, std::string nombre_material)
        : Casillero_transitable(fila, columna, nombre_material){
    this -> energia_requerida = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Betun::mostrar() {

    if(!this->hay_material  && !this->hay_jugador){
        std::cout << fondo_color_gris_oscuro << "     " << fin_de_formato ;

    }else if(this->hay_jugador){
        if(this->jugador == 1)
            std::cout << fondo_color_gris_oscuro << TXT_RED_196 << " " << "J1" <<"  " << fin_de_formato;
        else
            std::cout << fondo_color_gris_oscuro << TXT_RED_196 << "  " << "U" <<"  " << fin_de_formato;

    }else{
        std::cout << fondo_color_gris_oscuro << "  " << this->material->obtener_icono() << "  " << fin_de_formato ;
    }

}

/* ---------------------------------------------------------------------------------------------------------*/

int Betun::obtener_energia(int personaje) {
    int energia=0;
    return energia;
}

/* ---------------------------------------------------------------------------------------------------------*/
