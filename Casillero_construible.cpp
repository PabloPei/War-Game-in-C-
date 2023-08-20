#include "Casillero_construible.h"
#include "iostream"

/* ---------------------------------------------------------------------------------------------------------*/

Casillero_construible::Casillero_construible(int fila, int columna){

    this->jugador = 0;
    this->fila = fila;
    this->columna = columna;
    this->tipo = TERRENO;
    this->hay_edificio = false;
    this->hay_jugador = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

Casillero_construible::Casillero_construible(int fila, int columna, std::string nombre,int jugador){

    this->jugador = 0;
    this->fila = fila;
    this->columna = columna;
    this->hay_edificio = true;
    this->tipo = TERRENO;
    this->hay_jugador = false;

    cambiar_atributo(nombre,jugador);
}

/* ---------------------------------------------------------------------------------------------------------*/

Edificio* Casillero_construible::obtener_edificio(){

    return this->edificio ;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_construible::mostrar(){


    if(!this->hay_edificio && !this->hay_jugador){
        std::cout << fondo_color_verde << "     " << fin_de_formato;

    }else if(this->hay_jugador){
        if(this->jugador == 1)
            std::cout << fondo_color_verde << TXT_RED_196 << " " << "J1" <<"  " << fin_de_formato;
        else
            std::cout << fondo_color_verde << TXT_RED_196 << "  " << "U" <<"  " << fin_de_formato;

    }else{
        std::cout << fondo_color_verde << "  " << this->edificio->obtener_icono() <<"  " << fin_de_formato;
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

int Casillero_construible::obtener_fil(){

    return this->fila;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Casillero_construible::obtener_col(){

    return this->columna;
}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Casillero_construible::obtener_tipo(){

    return this->tipo;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_construible::consultar(){

    if(this->hay_edificio){

        std::cout << endl <<'\t' << negrita << "Soy un casillero construible y tengo una estructura construida."
                 << fin_de_formato << std::endl;
        this->edificio->describir();

    }else if(this -> hay_jugador){
        std::cout << endl << '\t' << negrita << "Soy un casillero construible y tengo al jugador " << jugador <<
                       " parado sobre mi"  << fin_de_formato << std::endl;
    }
    else{

        std::cout<< endl << '\t' << negrita << "Soy un casillero consruible y estoy vacio."<<std::endl;
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

std::string Casillero_construible::obtener_nombre_atributo() {

    std::string nombre;

    if (hay_edificio) {
        nombre = this->edificio->obtener_nombre();

    }else {
        nombre = VACIO;
    }

    return nombre;

}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_construible::cambiar_atributo(std::string nombre, int jugador){
    Edificio* aux;

    if (nombre == MINA){
        aux = new Mina(jugador);

    }else if (nombre == ASERRADERO){
        aux = new Aserradero(jugador);

    }else if (nombre == FABRICA){
        aux = new Fabrica(jugador);

    }else if (nombre == ESCUELA){
        aux = new Escuela(jugador);

    }else if (nombre == OBELISCO){
        aux = new Obelisco(jugador);

    }else if (nombre == PLANTA_ELECTRICA){
        aux = new Planta_electrica(jugador);

    }else if (nombre == MINA_ORO){
        aux = new Mina_oro(jugador);
    }

    this->edificio = aux;
    this->hay_edificio = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_construible::eliminar_atributo() {

    delete edificio;
    edificio = nullptr;

    hay_edificio = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_construible::agregar_jugador(int jugador) {

    this->jugador = jugador;
    hay_jugador = true;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Casillero_construible::eliminar_jugador() {

    jugador = 0;
    hay_jugador = false;
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Casillero_construible::hay_jugador_en_casillero() {
    return this -> hay_jugador;
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Casillero_construible::hay_edificio_en_casillero() {
    return this -> hay_edificio;
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Casillero_construible::ocupado(){
    return (this->hay_edificio || this->hay_jugador);
}

/* ---------------------------------------------------------------------------------------------------------*/

Casillero_construible::~Casillero_construible(){

    delete this->edificio;
    this->edificio = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Casillero_construible::obtener_energia(int personaje) {
    int energia;

    if(hay_edificio)
        energia = 99999999;
    else energia=25;

    return energia;
}
/* ---------------------------------------------------------------------------------------------------------*/
bool Casillero_construible::esta_roto() {
    return edificio->esta_roto();
}
/* ---------------------------------------------------------------------------------------------------------*/

bool Casillero_construible::atacar(int atacante, ABB<string, Edificio*>* diccionario) {

    bool ataque_exitoso;
    int atacado;

    if(atacante == 1)
        atacado = 2;
    else
        atacado = 1;

    if (hay_jugador || !hay_edificio) {
        std::cout << std::endl << '\t' << TXT_RED_196 << "No hay un edificio en este casillero" << fin_de_formato << std::endl;

    }else if (hay_edificio) {

        if (edificio->obtener_jugador() != atacante) {

            ataque_exitoso = true;

            if(edificio -> esta_roto()) {
                std::cout<< std::endl << '\t' << negrita << "Se destruyo " << edificio->obtener_nombre()<<
                         fin_de_formato <<std::endl;
                diccionario->buscar(edificio->obtener_nombre())->decrementar_construidos(atacado);
                this->eliminar_atributo();
            }else {
                edificio->romper();
                std::cout << std::endl << '\t' << negrita << edificio->obtener_nombre()<<" atacada con exito."
                         << fin_de_formato<< std::endl;
            }

        }else {
            std::cout << std::endl << '\t' << "Este edificio es de tu propiedad, no lo podes atacar"
                      <<std::endl;
        }
    }

    return ataque_exitoso;
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Casillero_construible::reparar(int reparador) {

    bool reparado = false;

    if(edificio->obtener_jugador() == reparador) {
        if((edificio->obtener_nombre() == MINA || edificio->obtener_nombre() == MINA_ICONO
            || edificio->obtener_nombre() == FABRICA) && edificio->esta_roto()){

            reparado = true;
            edificio->reparar();
            std::cout << endl << '\t' << negrita << "Reparacion de  "<<edificio->obtener_nombre()
                      << " exitosa."<< fin_de_formato << std::endl;

        }else {

            std::cout << endl << '\t' << negrita << "Este edificio no requiere reparacion" << fin_de_formato
                      << std::endl;
        }

    }else {
        std::cout<<"Este edificio no es de tu propiedad"<<std::endl;
    }

    return reparado;
}

/* ---------------------------------------------------------------------------------------------------------*/
