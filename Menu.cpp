#include <iostream>
#include "Menu.h"

using namespace std;

/* ---------------------------------------------------------------------------------------------------------*/

Menu::Menu(){
    this->opcion_elegida = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/
void Menu::mostrar_mensaje_bienvenida(){

    system(CLR_SCREEN);
    cout << endl << endl;
    cout << '\t' <<TXT_RED_196 << "█████╗  ███╗   ██╗██████╗ ██╗   ██╗██████╗  ██████╗ ██╗     ██╗███████╗" << endl;
    cout << '\t'  << "██╔══██╗████╗  ██║██╔══██╗╚██╗ ██╔╝██╔══██╗██╔═══██╗██║     ██║██╔════╝" << endl;
    cout << '\t'  << "███████║██╔██╗ ██║██║  ██║ ╚████╔╝ ██████╔╝██║   ██║██║     ██║███████╗" << endl;
    cout << '\t'  << "██╔══██║██║╚██╗██║██║  ██║  ╚██╔╝  ██╔═══╝ ██║   ██║██║     ██║╚════██║" << endl;
    cout << '\t'  << "██║  ██║██║ ╚████║██████╔╝   ██║   ██║     ╚██████╔╝███████╗██║███████║" << endl;
    cout << '\t'  << "╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝    ╚═╝   ╚═╝      ╚═════╝ ╚══════╝╚═╝╚══════╝" << fin_de_formato << endl;

}

/* ---------------------------------------------------------------------------------------------------------*/

void Menu::mostrar_mensaje_despedida(){
    cout << endl << endl << endl << endl ;
    cout << negrita << '\t' << MSJ_MENU_DESPEDIDA << fin_de_formato;
    cout << endl << endl << endl << endl << endl;
}


/* ---------------------------------------------------------------------------------------------------------*/

void Menu::mostrar_menu_1(){
    cout << fin_de_formato << endl << endl <<endl;
    cout << '\t' << subrayado << MSJ_INICIO_MENU << fin_de_formato << endl;
    cout << '\t' << "╔════════════════════════════════════════════════╗" << endl;
    cout << '\t' << "║ " << negrita      << MSJ_MENU_OPCION_1 << fin_de_formato << " ║" << endl;
    cout << '\t' << "║════════════════════════════════════════════════║" << endl;
    cout << '\t' << "║ " << negrita      << MSJ_MENU_OPCION_2 << fin_de_formato << " ║" << endl;
    cout << '\t' << "║════════════════════════════════════════════════║" << endl;
    cout << '\t' << "║ " << negrita      << MSJ_MENU_OPCION_3 << fin_de_formato << " ║" << endl;
    cout << '\t' << "║════════════════════════════════════════════════║" << endl;
    cout << '\t' << "║ " << negrita      << MSJ_MENU_OPCION_4 << fin_de_formato << " ║" << endl;
    cout << '\t' << "║════════════════════════════════════════════════║" << endl;
    cout << '\t' << "║ " << negrita      << MSJ_MENU_OPCION_5 << fin_de_formato << " ║" << endl;
    cout << '\t' << "╚════════════════════════════════════════════════╝" << endl;

}

/* ---------------------------------------------------------------------------------------------------------*/

void Menu::mostrar_menu_2(){

    Gotoxy gotoxy;

    cout << endl <<endl;
    cout << gotoxy.pos(15,100) << subrayado << MSJ_INICIO_MENU << fin_de_formato << endl;
    cout << gotoxy.pos(16,100) << "╔════════════════════════════════════════════════╗" << endl;
    cout << gotoxy.pos(17,100) << "║ " << negrita       << MSJ_MENU_OPCION_6 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(18,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(19,100) << "║ " << negrita       << MSJ_MENU_OPCION_7 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(20,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(21,100) << "║ " << negrita       << MSJ_MENU_OPCION_8 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(22,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(23,100) << "║ " << negrita       << MSJ_MENU_OPCION_9 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(24,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(25,100) << "║ " << negrita       << MSJ_MENU_OPCION_10 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(26,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(27,100) << "║ " << negrita       << MSJ_MENU_OPCION_11<< fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(28,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(29,100) << "║ " << negrita       << MSJ_MENU_OPCION_12 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(30,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(31,100) << "║ " << negrita       << MSJ_MENU_OPCION_13 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(32,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(33,100) << "║ " << negrita       << MSJ_MENU_OPCION_14 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(34,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(35,100) << "║ " << negrita       << MSJ_MENU_OPCION_15 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(36,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(37,100) << "║ " << negrita       << MSJ_MENU_OPCION_16 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(38,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(39,100) << "║ " << negrita       << MSJ_MENU_OPCION_17 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(40,100) << "║════════════════════════════════════════════════║" << endl;
    cout << gotoxy.pos(41,100) << "║ " << negrita       << MSJ_MENU_OPCION_18 << fin_de_formato << " ║" << endl;
    cout << gotoxy.pos(42,100) << "╚════════════════════════════════════════════════╝" << endl;
}

/* ---------------------------------------------------------------------------------------------------------*/

string Menu::ingresar_opcion() {
    string  opcion_elegida_str;
    cout << endl << '\t' << negrita  <<"OPCION: " <<fin_de_formato;
    getline(cin, opcion_elegida_str);
    return opcion_elegida_str;
}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Menu::validar_opcion_1(string opcion_elegida_str) {

    char caracter;
    int N = (int) opcion_elegida_str.length();
    Status_t validez = OK;

    if(!N)
        validez = ERROR_OPCION_VACIA;

    int i =0;
    caracter = opcion_elegida_str[i];
    while (caracter != '\0' && validez == OK) {
        if (isdigit(caracter) == 0)
            validez = ERROR_NO_ES_NUMERO;
        i++;
        caracter = opcion_elegida_str[i];
    }

    if(  validez == OK) {
        this->opcion_elegida = stoi(opcion_elegida_str);
        if (opcion_elegida > OPCION_MAXIMA_1 || opcion_elegida < OPCION_MINIMA_1){
            validez = ERROR_OPCION_FUERA_DE_RANGO;
        }
    }
    return validez;

}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Menu::validar_opcion_2(string opcion_elegida_str) {

    char caracter;
    int N = (int) opcion_elegida_str.length();
    Status_t validez = OK;

    if(!N)
        validez = ERROR_OPCION_VACIA;

    int i =0;
    caracter = opcion_elegida_str[i];
    while (caracter != '\0' && validez == OK) {
        if (isdigit(caracter) == 0)
            validez = ERROR_NO_ES_NUMERO;
        i++;
        caracter = opcion_elegida_str[i];
    }

    if(  validez == OK) {
        this->opcion_elegida = stoi(opcion_elegida_str);
        if (opcion_elegida > OPCION_MAXIMA_2 || opcion_elegida < OPCION_MINIMA_2){
            validez = ERROR_OPCION_FUERA_DE_RANGO;
        }
    }
    return validez;

}

/* ---------------------------------------------------------------------------------------------------------*/

int Menu::obtener_opcion(){
    return this -> opcion_elegida;
}
