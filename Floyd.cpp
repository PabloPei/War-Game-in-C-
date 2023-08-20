#include "Floyd.h"

const int INFINITO = 99999999;
const int POSICION_NO_ENCONTRADA = -1;


int ** Floyd::crearMatrizCaminos(){

    int ** caminos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        caminos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++) {
            caminos[i][j] = j;
        }
    }

    return caminos;
}

int ** Floyd::crearMatrizCostos(int ** matrizAdyacencia){

    int ** costos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        costos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++){
            costos[i][j] = matrizAdyacencia[i][j];
        }
    }
    return costos;
}


void Floyd::calcularMatrices(int ** matrizAdyacencia) {
    ;
    matrizCostos = crearMatrizCostos(matrizAdyacencia);
    matrizCaminos = crearMatrizCaminos();

    int costo;

    for (int verticeIntermedio = 0; verticeIntermedio < cantidadVertices; verticeIntermedio++){

        for (int origen = 0; origen < cantidadVertices; origen++){

            for(int destino = 0; destino < cantidadVertices; destino++){

                costo = matrizCostos[origen][verticeIntermedio] + matrizCostos[verticeIntermedio][destino];

                if (matrizCostos[origen][destino] > costo){
                    matrizCostos[origen][destino] = costo;
                    matrizCaminos[origen][destino] = matrizCaminos[origen][verticeIntermedio];
                }

                else if (matrizCostos[origen][destino] == INFINITO){
                    matrizCaminos[origen][destino] = POSICION_NO_ENCONTRADA;
                }
            }
        }
    }
}

void Floyd::caminoMinimo(int origen, int destino, Mapa* tablero, Lista<Coordenadas*>* movimientos, int &energiaNecesaria) {
    int posicionOrigen[2];
    int posicionDestino[2];
    obtenerPosicionInversa(tablero, origen, posicionOrigen);
    obtenerPosicionInversa(tablero, destino, posicionDestino);

    if(matrizCaminos[origen][destino] == POSICION_NO_ENCONTRADA){
        cout << "No hay un camino que conecte el casillero (" <<  posicionOrigen[0] << "," << posicionOrigen[1] << ") con (" << posicionDestino[0] << "," << posicionDestino[1] << ")"; //vertices->consulta(destino + 1);
    }else{
        energiaNecesaria = matrizCostos[origen][destino];
        do{
            origen = matrizCaminos[origen][destino];
            Coordenadas* nuevaCoordenada = new Coordenadas(posicionOrigen[1], posicionOrigen[0]);
            movimientos->alta(nuevaCoordenada,1);
            obtenerPosicionInversa(tablero, origen, posicionOrigen);
        }while(origen != destino);
        Coordenadas* nuevaCoordenada = new Coordenadas(posicionOrigen[1], posicionOrigen[0]);
        movimientos->alta(nuevaCoordenada,1);
    }
    cout << endl;

}

void Floyd::liberarMatrices() {
    if(matrizCostos != nullptr && matrizCaminos != nullptr){
        for(int i = 0; i < cantidadVertices; i++){
            delete[] matrizCostos[i];
            delete[] matrizCaminos[i];
        }
        delete[] matrizCostos;
        delete[] matrizCaminos;

        matrizCostos = nullptr;
        matrizCaminos = nullptr;
    }
}

Floyd::~Floyd() {
    liberarMatrices();
}

Floyd::Floyd(int cantidadVertices) {
    this -> matrizCaminos = nullptr;
    this -> matrizCostos = nullptr;
    this -> cantidadVertices = cantidadVertices;
}

void Floyd::obtenerPosicionInversa(Mapa* tablero, int posicion, int posicionFinal[]){
    int posicionX;
    int posicionY;
    posicionX = posicion % tablero->obtenerCantidadColumnas();
    posicionY = posicion / tablero->obtenerCantidadColumnas();
    posicionFinal[0] = posicionX;
    posicionFinal[1] = posicionY;
}


