#include <fstream>
#include <iostream>
#include "Inventario.h"

using namespace std;

/* ---------------------------------------------------------------------------------------------------------*/

Inventario::Inventario() {
    this -> materiales = new Lista<Material *>();
}

/* ---------------------------------------------------------------------------------------------------------*/

Material* Inventario::obtener_material_por_nombre(string nombre_material) {

    return materiales->consulta_por_nombre(nombre_material);

}

/* ---------------------------------------------------------------------------------------------------------*/

void Inventario::mostrar_inventario() {
    system(CLR_SCREEN);

    cout << '\t' << fondo_color_verde << "---- INVENTARIO ----" << fin_de_formato << endl << endl;

    for (int i = materiales->obtener_cantidad(); i >= 1 ; i--){
        std::cout << '\t' <<  "-----------------------------------------------"<<std::endl;
        std::cout << '\t' << " Material: " <<  (materiales->consulta(i))->obtener_nombre()
                  << std::endl << '\t' <<  " Cantidad: "<<(materiales->consulta(i))->obtener_cantidad()
                  <<std::endl;
        std::cout << '\t' << "-----------------------------------------------"<<std::endl;
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Inventario::restar_material_por_nombre(string nombre_material, int cantidad) {

    Material* material;
    material = materiales -> consulta_por_nombre(nombre_material);

    if(cantidad < 0 || cantidad > material -> obtener_cantidad())
        return ERROR_RESTA_MATERIAL_INVALIDA;

    material ->restar_material(cantidad);

    return OK;
}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Inventario::sumar_material_por_nombre(string nombre_material, int cantidad) {

    Material* material;
    material = materiales -> consulta_por_nombre(nombre_material);

    if(cantidad < 0 )
        return ERROR_SUMA_MATERIAL_INVALIDA;

    material -> sumar_material(cantidad);

    return OK;
}
/* ---------------------------------------------------------------------------------------------------------*/

Lista<Material *>* Inventario::obtener_materiales(){
    return materiales;
}
/* ---------------------------------------------------------------------------------------------------------*/

void Inventario::dar_de_alta_material(Material* material){

    materiales->alta(material,1);

}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Inventario::consultar_por_nombre(std::string nombre, Material* material){

    if(!materiales->existe_elemento(nombre)) {
        return ERROR_NO_EXISTE_EL_MATERIAL;
    }

    material = materiales -> consulta_por_nombre(nombre);

    return OK;
}

/* ---------------------------------------------------------------------------------------------------------*/

Inventario::~Inventario() {
    delete this -> materiales;
}

/* ---------------------------------------------------------------------------------------------------------*/

