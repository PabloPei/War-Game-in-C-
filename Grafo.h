#ifndef __GRAFO_H__
#define __GRAFO_H__

#include <string>
#include "Casillero.h"
#include "Mapa.h"
#include "Floyd.h"
#include "Coordenadas.h"
#include "Lista.h"

const int INFINITO = 99999999;

using namespace std;

class Grafo {

//atributos:
private:
    int** matrizDeAdyacencia;
    int cantidadVertices;
    Floyd * floyd;


//metodos privados:

    //PRE:
    //POS: Obtiene la cantidad de casilleros del tablero y por ende la cantidad de vértices del grafo
    int obtenerLargo(Mapa* tablero);

    //PRE:
    //POS: Inicializa la matriz con 0 en la diagonal e infinito en el resto
    void inicializarMatrizAdyacencia();

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void caminoMinimo(int origen, int destino, Mapa* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria);

    //post libera la memoria de la matriz de adyacencia
    void liberarMatrizAdyacencia();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrarMatrizAdyacencia();

//metodos publicos:
public:

    Grafo();

    //PRE:
    //POS: crea una matriz de tamaño cantidadVertices*cantidadVertices donde cantidadVertices es el resultado
    //     de hacer la cantidadFilas*cantidadColumnas del tablero.
    void crearMatrizAdyacencia(Mapa* tablero);

    //Post: muestra por terminal el camino mínimo desde un origen a un destino
    void caminoMinimo(Casillero* origen, Casillero* destino, Mapa* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregarCamino(Casillero* origen, Casillero* destino, int pesoOrigen, int pesoDestino, int clase, Mapa* tablero);

    //post: imprime por pantalla el grafo
    void mostrarGrafo();

    ~Grafo();

    //post: calcula la matrices que requiere el metodo de floyd para funcionar
    void calcularMatricesFloyd();

    //PRE:
    //POS: Genera un camino entre cada casillero y su derecho y entre el casillero y su inferior y lo carga a la matriz de adyacencia
    //IMPORTANTE: Queda la ultima fila y columna sin cargar
    void cargarCaminosTablero(Mapa* tablero, int clase);

    //PRE:
    //POS: Carga la ultima fila y columna que quedaron sin cargar en cargarCaminosTablero.
    void cargarCaminosUltimaColumna(Mapa* tablero, int clase);

    //PRE:
    //POS: Carga la ultima fila y columna que quedaron sin cargar en cargarCaminosTablero.
    void cargarCaminosUltimaFila(Mapa* tablero, int clase);

    //PRE:
    //POS: Obtiene la posicion que ocuparía un casillero del tablero en una lista de vertices.
    //     Sirve para ubicarlos en las posiciones de la matriz de adyacencia.
    int obtenerPosicion(Mapa* tablero, Casillero* casillero);

};


#endif
