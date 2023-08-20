#ifndef GRAFOS_FLOYD_H
#define GRAFOS_FLOYD_H
#include <string>
#include "Lista.h"
#include "Casillero.h"
#include <iostream>
#include "Mapa.h"
#include "Coordenadas.h"

using namespace std;

class Floyd {
private:
    int ** matrizCostos;
    int ** matrizCaminos;
    int cantidadVertices;

    //pre: requiere una matriz de adyacencia bien cargada
    //post: crea la matriz costo inicializandola con los valores de la matriz de adyacencia
    int ** crearMatrizCostos(int ** matrizAdyacencia);

    //post: crea una matriz de caminos
    int ** crearMatrizCaminos();

    //post: libera la memora de las matrices de costos y caminos
    void liberarMatrices();

    //void mostrarMatrices();

public:
    Floyd(int cantidadVertices);

    //post:calcula las matrices de costos y caminos.
    void calcularMatrices(int ** matrizAdyacencia);

    //post: muestra el camino minimo entre el origen y el destino imprimiendo los vertices a visitar y su costo final
    void caminoMinimo(int origen, int destino, Mapa* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria);

    //PRE: posicion y posicionfinal validas
    //POST: obtiene la coordenada invertida del mapa 
    void obtenerPosicionInversa(Mapa* tablero, int posicion, int posicionFinal[]);

    //post: libera la memoria pedida
    ~Floyd();
};


#endif //GRAFOS_FLOYD_H
