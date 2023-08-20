#include "Leer_archivo_ubicaciones.h"

/* ---------------------------------------------------------------------------------------------------------*/

Leer_archivo_ubicaciones::Leer_archivo_ubicaciones() {
    this -> error = ERROR_APERTURA_ARCHIVO_UBICACIONES;
    this -> path = PATH_UBICACIONES;
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Leer_archivo_ubicaciones::leer_archivo(Mapa* mapa, ABB<string, Edificio*>* diccionario_edificios,
                                        Jugador* jugador_1, Jugador* jugador_2 ){

    std::string nombre_elemento;
    std::string nombre_aux;
    std::string espacio;
    std::string fila_elemento;
    std::string columna_elemento;
    int fila_aux;
    int col_aux;

    getline(archivo,nombre_elemento,' ');

    if(nombre_elemento == "\0")
        return false;

    if(nombre_elemento != "1"){
        do {
            getline(archivo, espacio, '(');
            getline(archivo, fila_elemento, ',');
            getline(archivo, columna_elemento, ')');
            getline(archivo, espacio, '\n');

            fila_aux = stoi(fila_elemento);
            col_aux = stoi(columna_elemento);

            mapa->modificar_casillero(nombre_elemento,fila_aux,col_aux,0);
        }while(getline(archivo,nombre_elemento,' ') && nombre_elemento != "1");
    }


    getline(archivo, espacio, '(');
    getline(archivo, fila_elemento, ',');
    getline(archivo, columna_elemento, ')');
    getline(archivo, espacio, '\n');
    jugador_1->asignar_fil(stoi(fila_elemento));
    jugador_1->asignar_col(stoi(columna_elemento));
    mapa -> agregar_jugador(stoi(fila_elemento), stoi(columna_elemento),1);

    while(getline(archivo,nombre_elemento,' ') && nombre_elemento != "2") {
        if (nombre_elemento == "planta") {
            getline(archivo, espacio, ' ');
            nombre_elemento = PLANTA_ELECTRICA;
        }

        if(nombre_elemento == "mina") {
            getline(archivo, nombre_aux, '(');
            if (nombre_aux == "oro ") {
                nombre_elemento = MINA_ORO;
            }
        }else{
            getline(archivo, espacio, '(');
        }

        getline(archivo, fila_elemento, ',');
        getline(archivo, columna_elemento, ')');
        getline(archivo, espacio, '\n');

        fila_aux = stoi(fila_elemento);
        col_aux = stoi(columna_elemento);

        mapa->modificar_casillero(nombre_elemento,fila_aux,col_aux,1);
        diccionario_edificios -> buscar(nombre_elemento) ->incrementar_construidos_j1();

    }


    getline(archivo, espacio, '(');
    getline(archivo, fila_elemento, ',');
    getline(archivo, columna_elemento, ')');
    getline(archivo, espacio, '\n');
    jugador_2->asignar_fil(stoi(fila_elemento));
    jugador_2->asignar_col(stoi(columna_elemento));
    mapa -> agregar_jugador(stoi(fila_elemento), stoi(columna_elemento),2);


    while(getline(archivo,nombre_elemento,' ')){

        if(nombre_elemento == "planta"){
            getline(archivo, espacio,' ');
            nombre_elemento = PLANTA_ELECTRICA;
        }
        if(nombre_elemento == "mina") {
            getline(archivo, nombre_aux, '(');
            if (nombre_aux == "oro ") {
                nombre_elemento = MINA_ORO;
            }
        }else{
            getline(archivo, espacio, '(');
        }


        getline(archivo, fila_elemento, ',');
        getline(archivo, columna_elemento, ')');
        getline(archivo, espacio, '\n');

        fila_aux = stoi(fila_elemento);
        col_aux = stoi(columna_elemento);


        mapa->modificar_casillero(nombre_elemento,fila_aux,col_aux,2);
        diccionario_edificios -> buscar(nombre_elemento) ->incrementar_construidos_j2();

    }

    return true;
}

/* ---------------------------------------------------------------------------------------------------------*/
