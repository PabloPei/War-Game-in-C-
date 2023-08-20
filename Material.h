#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include <string>


const std::string MADERA = "madera";
const std::string PIEDRA = "piedra";
const std::string METAL = "metal";
const std::string ANDYCOINS = "andycoins";
const std::string ENERGIA = "energia";
const std::string BOMBAS = "bombas";
const std::string MADERA_ICONO = "W";
const std::string PIEDRA_ICONO = "S";
const std::string METAL_ICONO = "I";
const std::string ANDYCOINS_ICONO = "C";


class Material{

//atributos:
protected:
    std::string nombre;
    std::string icono;
    int cantidad;

//metodos:
public:

    //PRE:
    //POST:
    Material();

    //PRE:
    //POST:
    Material(std::string nombre, int cantidad);

    //PRE:
    //POST: devuelve el nombre del material
    std::string obtener_nombre();

    //PRE:
    //POST: devuelve la cantidad del metal;
    int obtener_cantidad();

    //PRE:
    //POST: imprime el icono del material
    std::string obtener_icono();

    //PRE:
    //POST: suma cantidad_agregada a cantidad del material
    void sumar_material(int cantidad_agregada);

    //PRE: cantidad_sustraida <= this->cantidad
    //POST: resta cantidad_sustraida a cantidad del material
    void restar_material(int cantidad_sustraida);
};
#endif
