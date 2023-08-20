#ifndef __MENU_H__
#define __MENU_H__

#include <string>
#include "formatos.h"
#include "errores.h"
#include "Gotoxy.h"

using namespace std;

const int OPCION_MINIMA_1 = 1;
const int OPCION_MAXIMA_1 = 5;
const int MODIFICAR_EDIFICIO = 1;
const int LISTAR_EDIFICIOS = 2;
const int MOSTRAR_MAPA = 3;
const int COMENZAR_PARTIDA = 4;
const int GUARDAR_Y_SALIR = 5;

const int OPCION_MINIMA_2 = 1;
const int OPCION_MAXIMA_2 = 13;
const int CONSTRUIR_POR_NOMBRE = 1;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int DEMOLER_POR_COORDENADA = 3;
const int ATACAR_POR_COORDENADA = 4;
const int REPARAR_POR_COORDENADA = 5;
const int COMPRAR_BOMBAS = 6;
const int CONSULTAR_COORDENADA = 7;
const int MOSTRAR_INVENTARIO = 8;
const int MOSTRAR_OBJETIVOS = 9;
const int RECOLECTAR_RECURSOS = 10;
const int MOVERSE_COORDENADA = 11;
const int FINALIZAR_TURNO = 12;
const int GUARDAR_Y_SALIR_2 =13;


const string MSJ_MENU_BIENVENIDA = "Bienevenido a Andypolis: La ciudad de los programadores";
const string MSJ_MENU_DESPEDIDA = "Se han realizado los cambios! hasta luego!   ";
const string MSJ_INICIO_MENU = " Que operacion desea realizar?                  ";
const string MSJ_MENU_OPCION_1 = "1. Modificar edificio por nombre              ";
const string MSJ_MENU_OPCION_2 = "2. Listar todos los edificios                 ";
const string MSJ_MENU_OPCION_3 = "3. Mostrar mapa                               ";
const string MSJ_MENU_OPCION_4 = "4. Comenzar partida                           ";
const string MSJ_MENU_OPCION_5 = "5. Guardar y salir                            ";
const string MSJ_MENU_OPCION_6 = "1. Construir edificio por nombre              ";
const string MSJ_MENU_OPCION_7 = "2. Listar mis edificios construidos           ";
const string MSJ_MENU_OPCION_8 = "3. Demoler un edificio por coordenada         ";
const string MSJ_MENU_OPCION_9 = "4. Atacar un edificio por coodenada           ";
const string MSJ_MENU_OPCION_10 = "5. Reparar un edificio por coordenada         ";
const string MSJ_MENU_OPCION_11 = "6. Comprar bombas                             ";
const string MSJ_MENU_OPCION_12 = "7. Consultar coordenada                       ";
const string MSJ_MENU_OPCION_13 = "8. Mostrar inventario                         ";
const string MSJ_MENU_OPCION_14 = "9. Mostrar objetivos                          ";
const string MSJ_MENU_OPCION_15 = "10. Recolectar recursos producidos            ";
const string MSJ_MENU_OPCION_16 = "11. Moverse a una coordenada                  ";
const string MSJ_MENU_OPCION_17 = "12. Finalizar turno                           ";
const string MSJ_MENU_OPCION_18 = "13. Guardar y salir                           ";

class Menu{

//Atributos:
private:
    int opcion_elegida;

//Metodos:
public:
    //PRE:
    //POST: Crea un objeto de tipo menu
    Menu();

    //PRE:
    //POST: imprime por pantalla un mensaje de bienvenida
    void mostrar_mensaje_bienvenida();

    //PRE:
    //POST: imprime por pantalla un mensaje de despedida
    void mostrar_mensaje_despedida();

    //PRE:
    //POST: imprime por pantalla el menu
    void mostrar_menu_1();

    //PRE:
    //POST: imprime por pantalla el menu
    void mostrar_menu_2();

    //PRE:
    //POST:Permite al usuario ingresar la opcion que desea para el menu
    string ingresar_opcion();

    //PRE: -
    //POS: devuelve true si la opcion ingresada es valida y false sino
    Status_t validar_opcion_1(string opcion_elegida_str);

    //PRE: -
    //POS: devuelve true si la opcion ingresada es valida y false sino
    Status_t validar_opcion_2(string opcion_elegida_str);

    //PRE:
    //POS: devuelve el numero de opcion elegida
    int obtener_opcion();


};

#endif
