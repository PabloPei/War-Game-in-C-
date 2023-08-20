

#ifndef COORDENADAS_H_
#define COORDENADAS_H_

class Coordenadas{
//atributos:
private:
    int coordenadaX;
    int coordenadaY;

//metodos:
public:
    //PRE:
    //POST:
    Coordenadas(int coordenadaX, int coordenadaY);

    //PRE:
    //POST: devuelve la coordenadaX
    int obtenerCoordenadaX();

    //PRE:
    //POST: devuelve coordenadaY
    int obtenerCoordenadaY();
};



#endif /* COORDENADAS_H_ */
