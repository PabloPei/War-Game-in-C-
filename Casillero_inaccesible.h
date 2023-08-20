#ifndef __CASILLERO_INACCESIBLE_H__
#define __CASILLERO_INACCESIBLE_H__

#include "Casillero.h"
#include "formatos.h"

class Casillero_inaccesible: public Casillero{

//atributos:
private:
    bool hay_jugador;
    int jugador;
//metodos:
public:

    //PRE: datos de fila y columna validos (enteros > 0)
    //POST: construye un casillero inaccesible
    Casillero_inaccesible(int fila, int columna);

    //PRE:
    //POST: imprime el icono del casillero o del edificio que lo ocupa
    void mostrar();

    //PRE:
    //POST: muestra que tipo de casillero es y si esta ocupado o no
    void consultar();

    //PRE:
    //POST:
    int obtener_fil();

    //PRE:
    //POST:
    int obtener_col();

    //PRE:
    //POST:
    void agregar_jugador(int jugador);

    //PRE:
    //POST:
    void eliminar_jugador();

    //PRE:
    //POST: devuelve el tipo de elemento que ocupa el casillero
    std::string obtener_tipo();

    //PRE:
    //POST:
    int obtener_energia(int personaje);

    //PRE:
    //POST: devuelve true si hay un edificio o false si no
    bool ocupado();
};
#endif
