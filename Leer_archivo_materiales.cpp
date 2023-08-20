#include "Leer_archivo_materiales.h"
#include "Madera.h"
#include "Metal.h"
#include "Piedra.h"
#include "Bombas.h"
#include "Andycoins.h"

Leer_archivo_materiales::Leer_archivo_materiales() {
    this -> error = ERROR_APERTURA_ARCHIVO_MATERIALES;
    this -> path = PATH_MATERIALES;
}

void Leer_archivo_materiales::leer_archivo( Inventario* materiales_j1, Inventario* materiales_j2){

    std::string nombre_material;
    int cantidad_material1;
    int cantidad_material2;

    while(archivo>>nombre_material) {
        archivo >> cantidad_material1;
        archivo >> cantidad_material2;

        Material *materialsito1;
        Material *materialsito2;

        if (nombre_material == MADERA) {
            materialsito1 = new Madera(cantidad_material1);
            materialsito2 = new Madera(cantidad_material2);

        } else if (nombre_material == PIEDRA) {
            materialsito1 = new Piedra(cantidad_material1);
            materialsito2 = new Piedra(cantidad_material2);

        } else if (nombre_material == METAL) {
            materialsito1 = new Metal(cantidad_material1);
            materialsito2 = new Metal(cantidad_material2);

        } else if (nombre_material == ANDYCOINS) {
            materialsito1 = new Andycoins(cantidad_material1);
            materialsito2 = new Andycoins(cantidad_material2);

        } else if (nombre_material == BOMBAS){
            materialsito1 = new Bombas(cantidad_material1);
            materialsito2 = new Bombas(cantidad_material2);
        }

        materiales_j1->dar_de_alta_material(materialsito1);
        materiales_j2->dar_de_alta_material(materialsito2);
    }

}
