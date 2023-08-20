#ifndef __CASILLERO_H__
#define __CASILLERO_H__

#include <iostream>
#include <string>
#include "Edificio.h"
#include "Material.h"
#include "ABB.h"


const std::string LAGO = "L";
const std::string CAMINO = "C";
const std::string BETUN = "B";
const std::string MUELLE = "M";
const std::string TERRENO = "T";

const std::string VACIO = "0";

class Casillero{

//atributos:
protected:
    int fila;
    int columna;
    std::string tipo;

//metodos:
public:

    //PRE:
    //POST: imprime el casillero por pantalla
    virtual void mostrar()=0;

    //PRE:
    //POST: describe el casillero y al elemento que lo ocupa
    virtual void consultar() = 0;

    //PRE:
    //POST: devuelve el atributo fila
    virtual int obtener_fil() = 0;

    //PRE:
    //POST:devuelve el atributo columna
    virtual int obtener_col() = 0;

    //PRE:
    //POST:devuelve el tipo de casillero si esta desocupado o el icono del
    //      elemento que lo ocupa
    virtual std::string obtener_tipo() = 0;

    //PRE:
    //POST: devuelve true si el casillero esta ocupado y false si no
    virtual bool ocupado() = 0;

    //PRE:
    //POST: devuelve el nombre del atributo del casillero
    virtual std::string obtener_nombre_atributo(){
        return VACIO;
    };

    //PRE:
    //POST: cambia el atributo del casillero segun corresponda
    virtual void cambiar_atributo(std::string nombre, int jugador){};

    //PRE:
    //POST:
    virtual void cambiar_atributo(std::string nombre){};

    //PRE:
    //POST: elimina el atributo del casillero
    virtual void eliminar_atributo(){};

    //PRE:
    //POST: devuelve true si hay un jugador parado sobre el casillero actual
    virtual bool hay_jugador_en_casillero(){
        return false;
    };

    //PRE:
    //POST: devuelve true si hay un edificio en el casillero actual y false si no
    virtual bool hay_edificio_en_casillero(){
        return false;
    };

    //PRE:
    //POST: devuelve true si hay un material en el casillero y false si no
    virtual bool hay_material_en_casillero(){
        return false;
    };

    //PRE:
    //POST: agrega un jugador al casillero
    virtual void agregar_jugador(int jugador){};

    //PRE:
    //POST: elimina al jugador del casillero
    virtual void eliminar_jugador(){};

    //PRE:
    //POST: devuelve la energia que gasta pasar por el casillero
    virtual int obtener_energia(int personaje)=0;

    //PRE:
    //POST: devuelve el edificio que esta en el casillero, en caso de no haber ninguno devuelve nullptr
    virtual Edificio* obtener_edificio(){
        return nullptr;
    };

    //PRE:
    //POST: devuelve el material que esta en el casillero, en caso de no haber ninguno devuelve nullptr
    virtual Material* obtener_material(){
        return nullptr;
    };

    //PRE:
    //POST: ataca el casillero, devuelve true si el ataque fue exitoso y false si no
    virtual bool atacar(int atacante,ABB<string, Edificio*>* diccionario) {
        return false;
    };

    //PRE:
    //POST: devuelve true si se repara el edificio que se encuentra en el casillero, si no se pudo reparar devuelve false
    virtual bool reparar(int reparador){
        return false;
    };

    //PRE:
    //POST: devuelve true si el edificio que se encuentra en el casillero esta roto
    virtual bool esta_roto() {
        return false;
    };

    //PRE:
    //POST:
    virtual ~Casillero(){};
};
#endif
