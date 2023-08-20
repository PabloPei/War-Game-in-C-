#ifndef TRABAJO_PRACTICO_3_INVENTARIO_H
#define TRABAJO_PRACTICO_3_INVENTARIO_H


#include <string>
#include "Lista.h"
#include "errores.h"
#include "Material.h"
#include "errores.h"
#include "Madera.h"
#include "Metal.h"
#include "Piedra.h"
#include "Bombas.h"
#include "Andycoins.h"


class Inventario {

//atributos:
private:
    Lista<Material *> *materiales;

//metodos:
public:

    //PRE:
    //POST:
    Inventario();

    //PRE: nombre_material valido
    //POST: devuelve el material con nombre_material
    Material* obtener_material_por_nombre(std::string nombre_material);

    //PRE:
    //POST: imprime por pantalla el inventario
    void mostrar_inventario();

    //PRE: nombre valido y cantidad > 0
    //POST: resta cantidad al material que tiene nombre_material
    Status_t restar_material_por_nombre(std::string nombre_material, int cantidad);

    //PRE: nombre valido y cantidad > 0
    //POST: suma cantidad al material que tiene nombre_material
    Status_t sumar_material_por_nombre(std::string nombre_material, int cantidad);

    //PRE:
    //POST: devuelve la lista de materiales
    Lista<Material *>* obtener_materiales();

    //PRE:
    //POST: agrega un material al inventario
    void dar_de_alta_material(Material* material);

    //PRE:
    //POST:
    Status_t consultar_por_nombre(std::string nombre, Material* material);

    //PRE:
    //POST:
    ~Inventario();
};

#endif
