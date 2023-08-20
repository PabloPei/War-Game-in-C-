#ifndef __CASILLERO_TRANSITABLE_H__
#define __CASILLERO_TRANSITABLE_H__

#include <time.h>
#include "Casillero.h"
#include "Material.h"
#include "Madera.h"
#include "Piedra.h"
#include "Metal.h"
#include "formatos.h"
#include "Andycoins.h"

class Casillero_transitable : public Casillero{

//atributos:
protected:
    int jugador;
    bool hay_jugador;
    Material* material;
    bool hay_material;

//metodos:
public:
    //PRE: datos fila y columna validos (enteros > 0)
    //POST: construye un casillero transitable
    Casillero_transitable(int fila, int columna);

    //PRE: datos fila y columna validos (enteros > 0) y nombre valido
    //POST: construye un casillero transitable
    Casillero_transitable(int fila, int columna, std::string nombre_material);

    //PRE:
    //POST:imprime por pantalla que tipo de casillero es y si tiene o no un material 
    virtual void mostrar() = 0;

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
    //POST: devuelve el tipo de elemento que ocupa el casillero
    std::string obtener_tipo();

    //PRE:
    //POST:
    bool ocupado();

    //PRE:
    //POST:
    bool hay_material_en_casillero();

    //PRE:
    //POST:
    virtual::string obtener_nombre_atributo();

    //PRE:
    //POST:
    void cambiar_atributo(std::string nombre);

    //PRE:
    //POST:
    void eliminar_atributo();

    //PRE:
    //POST:
    void agregar_jugador(int jugador);

    //PRE:
    //POST:
    void eliminar_jugador();

    //PRE:
    //POST:
    bool hay_jugador_en_casillero();

    //PRE:
    //POST:
    Material* obtener_material();

    //PRE:
    //POST:
    int obtener_energia(int personaje);

    //PRE:
    //POST:
    ~Casillero_transitable();
};
#endif
