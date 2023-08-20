#include "Mapa.h"

/* ---------------------------------------------------------------------------------------------------------*/

Mapa::Mapa() {
    this -> filas = 0;
    this -> columnas = 0;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mapa::cargar_mapa(int filas, int columnas) {

    this -> filas = filas;
    this -> columnas = columnas;

    this->mapa = new Casillero**[filas];

    for(int i = 0; i < filas; ++i){
        this->mapa[i] = new Casillero*[columnas];
        for (int k= 0; k< columnas; ++k){
            this->mapa[i][k] = nullptr;
        }
    }

}

/* ---------------------------------------------------------------------------------------------------------*/

void Mapa::eliminar_casillero(int fil,int col){
    delete mapa[fil][col];
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mapa::modificar_casillero(std::string nombre, int fil, int col, int jugador){
    if(mapa[fil][col]->obtener_tipo() != "T" && mapa[fil][col]->obtener_tipo() != "L") {
        mapa[fil][col]->cambiar_atributo(nombre);

    }else if(mapa[fil][col]->obtener_tipo() == "T"){
        mapa[fil][col]->cambiar_atributo(nombre,jugador);
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mapa::agregar_casillero(char tipo, int fil, int col) {

    switch(tipo){

        case 'L':{
            mapa[fil][col] = new Casillero_inaccesible(fil, col);
            break;
        }

        case 'B':{
            mapa[fil][col] = new Betun(fil, col);
            break;
        }

        case 'M':{
            mapa[fil][col] = new Muelle(fil, col);
            break;
        }

        case 'C':{
            mapa[fil][col] = new Camino(fil, col);
            break;
        }

        case 'T':{
            mapa[fil][col] = new Casillero_construible(fil, col);
            break;
        }
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Mapa::es_coordenada_valida(int fila, int columna) {

    return ((fila >= 0 && fila < filas) && (columna >= 0 && columna < columnas));
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Mapa::hay_jugador(int fila, int columna){
    return(mapa[fila][columna]->hay_jugador_en_casillero());
}


/* ---------------------------------------------------------------------------------------------------------*/
Lista<Casillero*>* Mapa::casilleros_disponibles_para_lluvia_recursos(){

    Lista<Casillero*>* transitables = new Lista<Casillero*>;

    for(int i = 0; i < filas ; i++) {
        for (int j = 0; j < columnas; j++) {

            if((mapa[i][j]->obtener_tipo() == CAMINO || mapa[i][j]->obtener_tipo() == MUELLE || mapa[i][j]->obtener_tipo() == BETUN) && !(mapa[i][j]->ocupado())){

                Casillero* aux = new Camino(i, j); //me da lo mismo el tipo de casillero aca

                transitables->alta(aux, 1);

            }
        }
    }

    return transitables;
}

/* ---------------------------------------------------------------------------------------------------------*/


Casillero* Mapa::obtener_casillero(int fila, int columna) {

    return this->mapa[fila][columna];
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Mapa::agregar_jugador(int fila, int columna, int jugador) {
    if(this -> es_coordenada_valida(fila,columna)){
        mapa[fila][columna]->agregar_jugador(jugador);
        return true;
    }
    return false;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mapa::eliminar_jugador(int fila, int columna) {

    mapa[fila][columna]->eliminar_jugador();
}


/* ---------------------------------------------------------------------------------------------------------*/

void Mapa::imprimir_mapa() {


    std::cout << std::endl << std::endl << std::endl << '\t' << subrayado << "MAPA" << fin_de_formato << std::endl << std::endl;
    for(int i = 0; i < this->filas; ++i){

        for(int k = 0; k < this -> columnas; ++k)
            std::cout << '\t' <<  " -----";

        std:: cout << std::endl;

        for(int j = 0; j < this->columnas; ++j){

            std::cout << '\t' <<  "|";
            mapa[i][j]->mostrar();
            std::cout << "|";
        }

        std::cout << std::endl;

        for(int k = 0; k < this -> columnas; ++k)
            std::cout << '\t' <<  " -----";

        std::cout <<  std::endl;
    }

}

/* ---------------------------------------------------------------------------------------------------------*/

bool Mapa::atacar_casillero(int fila, int columna, int atacante, ABB<string, Edificio*>* diccionario) {

    bool sin_problemas = mapa[fila][columna] -> atacar(atacante, diccionario);

    return sin_problemas;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Mapa::describir_casillero(int fila, int columna) {

    mapa[fila][columna] -> consultar();
}

/* ---------------------------------------------------------------------------------------------------------*/

int Mapa::obtenerCantidadColumnas() {
    return columnas;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Mapa::obtenerCantidadFilas() {
    return filas;
}

/* ---------------------------------------------------------------------------------------------------------*/

Mapa::~Mapa() {

    if(filas != 0 && columnas != 0) {
        for (int i = 0; i < this->filas; ++i) {

            for (int j = 0; j < this->columnas; ++j) {

                delete this->mapa[i][j];
                this->mapa[i][j] = NULL;
            }
        }

        for (int i = 0; i < this->filas; ++i) {

            delete this->mapa[i];
            this->mapa[i] = NULL;
        }

        delete [] this->mapa;
        this->mapa = NULL;
    }
}

/* ---------------------------------------------------------------------------------------------------------*/
