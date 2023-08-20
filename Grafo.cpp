#include "Grafo.h"

/* ---------------------------------------------------------------------------------------------------------*/

const int POSICION_NO_ENCONTRADA = -1;
Grafo::Grafo() {
    matrizDeAdyacencia = nullptr;
    cantidadVertices = 0;
    floyd = nullptr;//new Floyd(cantidadVertices);
}

/* ---------------------------------------------------------------------------------------------------------*/

int Grafo::obtenerLargo(Mapa* tablero){
    return (tablero->obtenerCantidadColumnas() * tablero->obtenerCantidadFilas());
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::crearMatrizAdyacencia(Mapa* tablero){
    cantidadVertices = obtenerLargo(tablero);
    floyd = new Floyd(cantidadVertices);
    matrizDeAdyacencia = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        matrizDeAdyacencia[i] = new int[cantidadVertices];
    }
    inicializarMatrizAdyacencia();
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::inicializarMatrizAdyacencia(){
    for (int i = 0; i < cantidadVertices; i++){
        for (int j = 0; j < cantidadVertices; j++){
            if (j == i)
                matrizDeAdyacencia[i][j] = 0;
            else
                matrizDeAdyacencia[i][j] = INFINITO;
        }
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::mostrarGrafo() {
    mostrarMatrizAdyacencia();
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::agregarCamino(Casillero* origen, Casillero* destino, int pesoOrigen, int pesoDestino,int clase, Mapa* tablero) {
    int posicionOrigen = obtenerPosicion(tablero, origen);
    int posicionDestino = obtenerPosicion(tablero, destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicionDestino== POSICION_NO_ENCONTRADA || posicionOrigen == POSICION_NO_ENCONTRADA)) {
        matrizDeAdyacencia[posicionOrigen][posicionDestino] = pesoDestino;
        matrizDeAdyacencia[posicionDestino][posicionOrigen] = pesoOrigen;
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::caminoMinimo(Casillero* origen, Casillero* destino, Mapa* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria) {
    int posicionOrigen = obtenerPosicion(tablero, origen);
    int posicionDestino = obtenerPosicion(tablero, destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    caminoMinimo(posicionOrigen, posicionDestino, tablero, movimientos, energiaNecesaria);
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::liberarMatrizAdyacencia() {
    for(int i = 0; i < cantidadVertices; i++){
        delete[] matrizDeAdyacencia[i];
    }
    delete[] matrizDeAdyacencia;
}

/* ---------------------------------------------------------------------------------------------------------*/

Grafo::~Grafo() {
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = nullptr;
    delete floyd;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::mostrarMatrizAdyacencia() {
    cout << "Matriz de adyacencia de clase: " << endl;
    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices * 2; j++) {
            if(j == cantidadVertices * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matrizDeAdyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matrizDeAdyacencia[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::caminoMinimo(int origen, int destino, Mapa* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria) {
    floyd -> caminoMinimo(origen, destino, tablero, movimientos, energiaNecesaria);
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::calcularMatricesFloyd() {
    floyd -> calcularMatrices(matrizDeAdyacencia);
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::cargarCaminosTablero(Mapa* tablero, int clase){
    int cantidadFilas = tablero->obtenerCantidadFilas();
    int cantidadColumnas = tablero->obtenerCantidadColumnas();

    for (int i = 0; i < cantidadFilas - 1; i++){
        for (int j = 0; j < cantidadColumnas - 1; j++){
            int pesoOrigen = tablero->obtener_casillero(i, j)->obtener_energia(clase);
            int pesoDestino = tablero->obtener_casillero(i+1, j)->obtener_energia(clase);

            agregarCamino(tablero->obtener_casillero(i, j), tablero->obtener_casillero(i+1, j), pesoOrigen, pesoDestino, clase, tablero);
            pesoDestino = tablero->obtener_casillero(i, j+1)->obtener_energia(clase);
            agregarCamino(tablero->obtener_casillero(i, j), tablero->obtener_casillero(i, j+1), pesoOrigen, pesoDestino, clase, tablero);

        }
    }

    cargarCaminosUltimaColumna(tablero, clase);
    cargarCaminosUltimaFila(tablero, clase);
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::cargarCaminosUltimaColumna(Mapa* tablero, int clase){
    int cantidadFilas = tablero->obtenerCantidadFilas();
    int cantidadColumnas = tablero->obtenerCantidadColumnas();
    int ultimaColumna = cantidadColumnas - 1;
    for (int i = 0; i < cantidadFilas - 1; i++){
        int pesoOrigen = tablero->obtener_casillero(i, ultimaColumna)->obtener_energia(clase); 
        int pesoDestino = tablero->obtener_casillero(i+1, ultimaColumna)->obtener_energia(clase); 
        agregarCamino(tablero->obtener_casillero(i, ultimaColumna), tablero->obtener_casillero(i+1, ultimaColumna), pesoOrigen, pesoDestino, clase, tablero);
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

void Grafo::cargarCaminosUltimaFila(Mapa* tablero, int clase){
    int cantidadFilas = tablero->obtenerCantidadFilas();
    int cantidadColumnas = tablero->obtenerCantidadColumnas();
    int ultimaFila = cantidadFilas - 1;
    for (int i = 0; i < cantidadColumnas - 1; i++){
        int pesoOrigen = tablero->obtener_casillero(ultimaFila, i)->obtener_energia(clase);  
        int pesoDestino = tablero->obtener_casillero(ultimaFila, i+1)->obtener_energia(clase); 
        agregarCamino(tablero->obtener_casillero(ultimaFila, i), tablero->obtener_casillero(ultimaFila, i+1), pesoOrigen, pesoDestino, clase, tablero);
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

int Grafo::obtenerPosicion(Mapa* tablero, Casillero* casillero){
    int posicionFinal;
    int cantidadFilas = tablero->obtenerCantidadFilas();
    int cantidadColumnas = tablero->obtenerCantidadColumnas();
    for (int i = 0; i < cantidadFilas; i++){
        for (int j = 0; j < cantidadColumnas; j++){
            if (tablero->obtener_casillero(i, j) == casillero)
                posicionFinal = i * cantidadColumnas + j;
        }
    }
    return posicionFinal;
}

/* ---------------------------------------------------------------------------------------------------------*/
