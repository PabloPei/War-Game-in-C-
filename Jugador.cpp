#include "Jugador.h"

/* ---------------------------------------------------------------------------------------------------------*/

Jugador::Jugador(int id, int energia) {

    this->id = id;
    this->fila = -1;
    this->columna = -1;
    this->energia = energia;
    this->andycoins_acumulados=0;
    this->bombas_usadas=0;
    this->bombas_compradas=0;
    this->inventario = new Inventario;
    this->grafo = new Grafo;
    this->andycoins_acumulados = 0;
    this->objetivos=new Objetivos(id);

}

/* ---------------------------------------------------------------------------------------------------------*/

bool Jugador::puede_moverse(Casillero* casillero){

    return((((casillero->obtener_tipo() == TERRENO) && !casillero->ocupado()) || (casillero->obtener_tipo() == CAMINO ||
    casillero->obtener_tipo() == BETUN || casillero->obtener_tipo() == MUELLE)) && !(casillero->hay_jugador_en_casillero()));
}

/* ---------------------------------------------------------------------------------------------------------*/

void Jugador::recolectar_materiales(Casillero* casillero) {

    if(casillero->hay_material_en_casillero()) {
        std::string nombre_material = casillero->obtener_nombre_atributo();
        int cantidad = casillero -> obtener_material() -> obtener_cantidad();
        this->inventario->sumar_material_por_nombre(nombre_material, cantidad);
        casillero->eliminar_atributo();
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

int Jugador::obtener_fil() {

    return this->fila;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Jugador::obtener_id(){
    return this->id;
}

/* ---------------------------------------------------------------------------------------------------------*/
Objetivos* Jugador::obtener_objetivos(){
    return this->objetivos;
}
/* ---------------------------------------------------------------------------------------------------------*/

void Jugador::asignar_fil(int fila){
    this -> fila = fila;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Jugador::obtener_col() {

    return this->columna;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Jugador::asignar_col(int col){
    this -> columna = col;
}

/* ---------------------------------------------------------------------------------------------------------*/

int Jugador::obtener_energia() {

    return this->energia;
}

/* ---------------------------------------------------------------------------------------------------------*/

Inventario* Jugador::obtener_inventario() {

    return this->inventario;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Jugador::asignar_inventario(Inventario* inventario) {
    this->inventario = inventario;
}

/* ---------------------------------------------------------------------------------------------------------*/

Grafo* Jugador::obtener_grafo() {

    return this->grafo;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Jugador::mover_jugador(int fila_destino, int columna_destino, Mapa* mapa) {

    Lista<Coordenadas*> camino;
    bool habia_jugador = true;
    int energia_necesaria;
    int fila_aux, columna_aux;

    Casillero* origen = mapa->obtener_casillero(this->fila, this->columna);
    Casillero* destino = mapa->obtener_casillero(fila_destino, columna_destino);

    grafo->caminoMinimo(origen, destino, mapa, (&camino), energia_necesaria);

    //si en el camino hay un edificio recalcula !!
    for(int j=camino.obtener_cantidad();j>0;j--){
        fila_aux = camino.consulta(j)->obtenerCoordenadaX();
        columna_aux = camino.consulta(j)->obtenerCoordenadaY();

        if(mapa->obtener_casillero(fila_aux,columna_aux)->hay_edificio_en_casillero()){
            grafo->cargarCaminosTablero(mapa,id);
            grafo->calcularMatricesFloyd();
            grafo->caminoMinimo(origen, destino, mapa, (&camino), energia_necesaria);

        }
    }

    if (puede_moverse(destino)){
        if(camino.obtener_cantidad() > 0 && energia >= energia_necesaria){

            for (int i = camino.obtener_cantidad(); i > 0 ; i--) {
                system(CLR_SCREEN);
                fila_aux = fila;
                columna_aux = columna;
                fila = camino.consulta(i)->obtenerCoordenadaX();
                columna = camino.consulta(i)->obtenerCoordenadaY();

                if(!(mapa->obtener_casillero(fila,columna)->hay_jugador_en_casillero())) {
                    if(!habia_jugador)
                        mapa->eliminar_jugador(fila_aux, columna_aux);
                    habia_jugador = false;
                    mapa->agregar_jugador(fila, columna, id);
                }
                else if (!habia_jugador) {
                    mapa->eliminar_jugador(fila_aux, columna_aux);
                    habia_jugador = true;
                }
                mapa->imprimir_mapa();

                if(habia_jugador)
                    mapa->eliminar_jugador(fila_aux, columna_aux);

                //guardo ubicacion vieja para borrar
                fila_aux = fila;
                columna_aux = columna;
                recolectar_materiales(mapa->obtener_casillero(fila,columna));


                sleep(1);

            }
            restar_energia(energia_necesaria);

        }else if (energia < energia_necesaria) {

            cout << '\t' << TXT_RED_196 << "No tiene la energia suficiente" << fin_de_formato << endl;
        }
    }else {

        cout << '\t' << TXT_RED_196 << "Casillero destino no valido" << fin_de_formato << endl;
    }
}


/* ---------------------------------------------------------------------------------------------------------*/

void Jugador::restar_energia(int cantidad) {

    if(this-> energia >= 0 + cantidad)
        this->energia -= cantidad;
    else if (this-> energia > 0 && this->energia < 0+cantidad)
        this ->energia=0;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Jugador::sumar_energia(int cantidad) {

    if (this -> energia <= 100 - cantidad)
        this->energia += cantidad;
    else if(this -> energia < 100 && this->energia > 100-cantidad)
        this->energia = 100;

}
/* ---------------------------------------------------------------------------------------------------------*/


void Jugador::aumentar_andycoins_acumulados(int cantidad){
    andycoins_acumulados+=cantidad;
}

/* ---------------------------------------------------------------------------------------------------------*/


int Jugador::obtener_andycoins_acumulados(){
    return this->andycoins_acumulados;
}

/* ---------------------------------------------------------------------------------------------------------*/


void Jugador::aumentar_bombas_usadas(int cantidad){
    bombas_usadas+=cantidad;
}

/* ---------------------------------------------------------------------------------------------------------*/


int Jugador::obtener_bombas_usadas(){
    return this->bombas_usadas;
}

/* ---------------------------------------------------------------------------------------------------------*/


void Jugador::aumentar_bombas_compradas(int cantidad){
    bombas_compradas+=cantidad;
}

/* ---------------------------------------------------------------------------------------------------------*/


int Jugador::obtener_bombas_compradas(){
    return this->bombas_compradas;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Jugador::mostrar() {

    std::cout << id;
}

/* ---------------------------------------------------------------------------------------------------------*/

Jugador::~Jugador() {

    delete objetivos;
    objetivos = nullptr;

    delete inventario;
    inventario = nullptr;

    delete grafo;
    grafo = nullptr;
}

/* ---------------------------------------------------------------------------------------------------------*/
