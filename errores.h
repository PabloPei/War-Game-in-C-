#ifndef __ERRORES_H__
#define __ERRORES_H__

#include <string>
#include "formatos.h"

using namespace std;

const int MAX_ERRORS = 25;
const string STR_OK = "Ok";
const string STR_ERROR_ENTRADA_INVALIDA = "¡El dato ingresado es invalido!";
const string STR_ERROR_PUNTERO_NULO = "Error interno del sistema";
const string STR_ERROR_MATERIAL_INVALIDO = "¡Ese material no es valido!";
const string STR_ERROR_EDIFICIO_INEXISTENTE = "¡Este edificio no existe!";
const string STR_ERROR_NO_HAY_CONSTRUIDOS = "¡No hay mas edificios de este tipo, no podes destruir mas!";
const string STR_ERROR_MAXIMO_EDIFICIOS_ALCANZADO = "¡Alcanzaste el maximo de edificios posible!";
const string STR_ERROR_MATERIALES_INSUFICIENTES = "¡No tenes suficiente materiales para construir!";
const string STR_ERROR_NUMERO_OPCION_INVALIDA = "¡Ese numero está fuera de rango!";
const string STR_ERROR_CODIGO_INEXISTENTE = "¡Ese codigo no existe!";
const string STR_ERROR_APERTURA_ARCHIVO_MATERIALES = "No se ha podido abrir el archivo materiales.txt!";
const string STR_ERROR_RESTA_MATERIAL_INVALIDA = "La cantidad ingresada no es valida para restar al material";
const string STR_ERROR_SUMA_MATERIAL_INVALIDA = "La cantidad ingresada no es valida para sumar al material";
const string STR_ERROR_APERTURA_ARCHIVO_MAPA = "No se ha podido abrir el archivo mapa.txt";
const string STR_ERROR_APERTURA_ARCHIVO_UBICACIONES = "No se ha podido abrir el archivo  ubicaciones.txt";
const string STR_ERROR_APERTURA_ARCHIVO_EDIFICIOS = "No se ha podido abrir el archivo edificios.txt";
const string STR_ERROR_OPCION_VACIA = "No ha ingresado ninguna opcion. Debe ingresar un numero ";
const string STR_ERROR_NO_ES_NUMERO = "Ha ingresado un caracter distinto a un numero, vuelva a intentarlo";
const string STR_ERROR_OPCION_FUERA_DE_RANGO = "Ha ingresado una opcion fuera del rango, vuelva a intentarlo";
const string STR_ERROR_NO_EXISTE_EL_MATERIAL = "El material buscado no se encuentra en el inventario";
const string STR_ARCHIVO_UBICACIONES_VACIO = "El archivo ubiicaciones esta vacio";

const string errores[MAX_ERRORS] = {
        STR_OK,
        STR_ERROR_ENTRADA_INVALIDA,
        STR_ERROR_PUNTERO_NULO,
        STR_ERROR_MATERIAL_INVALIDO,
        STR_ERROR_EDIFICIO_INEXISTENTE,
        STR_ERROR_NO_HAY_CONSTRUIDOS,
        STR_ERROR_MAXIMO_EDIFICIOS_ALCANZADO,
        STR_ERROR_MATERIALES_INSUFICIENTES,
        STR_ERROR_NUMERO_OPCION_INVALIDA,
        STR_ERROR_CODIGO_INEXISTENTE,
        STR_ERROR_APERTURA_ARCHIVO_MATERIALES,
        STR_ERROR_RESTA_MATERIAL_INVALIDA,
        STR_ERROR_SUMA_MATERIAL_INVALIDA,
        STR_ERROR_APERTURA_ARCHIVO_MAPA,
        STR_ERROR_APERTURA_ARCHIVO_UBICACIONES,
        STR_ERROR_APERTURA_ARCHIVO_EDIFICIOS,
        STR_ERROR_OPCION_VACIA,
        STR_ERROR_NO_ES_NUMERO,
        STR_ERROR_OPCION_FUERA_DE_RANGO,
        STR_ERROR_NO_EXISTE_EL_MATERIAL,
        STR_ARCHIVO_UBICACIONES_VACIO
};

enum Status_t {
    OK,
    ERROR_ENTRADA_INVALIDA,
    ERROR_PUNTERO_NULO,
    ERROR_MATERIAL_INVALIDO,
    ERROR_EDIFICIO_INEXISTENTE,
    ERROR_NO_HAY_CONSTRUIDOS,
    ERROR_MAXIMO_EDIFICIOS_ALCANZADO,
    ERROR_MATERIALES_INSUFICIENTES,
    ERROR_NUMERO_OPCION_INVALIDA,
    ERROR_CODIGO_INEXISTENTE,
    ERROR_APERTURA_ARCHIVO_MATERIALES,
    ERROR_RESTA_MATERIAL_INVALIDA,
    ERROR_SUMA_MATERIAL_INVALIDA,
    ERROR_APERTURA_ARCHIVO_MAPA,
    ERROR_APERTURA_ARCHIVO_UBICACIONES,
    ERROR_APERTURA_ARCHIVO_EDIFICIOS,
    ERROR_OPCION_VACIA,
    ERROR_NO_ES_NUMERO,
    ERROR_OPCION_FUERA_DE_RANGO,
    ERROR_NO_EXISTE_EL_MATERIAL,
    ARCHIVO_UBICACIONES_VACIO};


// pre: -
// pos: imprime el error en funcion del tipo de status_t que ingresan
void imprimir_error(Status_t st);


#endif