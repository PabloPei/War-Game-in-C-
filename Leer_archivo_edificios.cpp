#include "Leer_archivo_edificios.h"

/* ---------------------------------------------------------------------------------------------------------*/

Leer_archivo_edificios::Leer_archivo_edificios() {
    this -> error = ERROR_APERTURA_ARCHIVO_EDIFICIOS;
    this -> path = PATH_EDIFICIOS;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Leer_archivo_edificios::leer_archivo( Mapa* mapa,ABB<string, Edificio*>* diccionario_edificios){

    std::string nombre_edificio;
    std::string nombre_aux;
    std::string basura;
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int cantidad_maxima;

    while(archivo>>nombre_edificio){

        if(nombre_edificio == "planta"){
            archivo>>basura;

            nombre_edificio = PLANTA_ELECTRICA;
        }

        archivo>>nombre_aux;
        if(nombre_edificio=="mina"){
            if(nombre_aux=="oro") {
                nombre_edificio = MINA_ORO;
            }
        }


        if(nombre_edificio == MINA_ORO)
            archivo >> cantidad_piedra;
        else
            cantidad_piedra = stoi(nombre_aux);
        archivo >> cantidad_madera;
        archivo >> cantidad_metal;
        archivo >> cantidad_maxima;


        Edificio* edificio;

        if (nombre_edificio == MINA){
            edificio = new Mina(cantidad_piedra, cantidad_madera, cantidad_metal,
                                cantidad_maxima);

        }else if (nombre_edificio == ASERRADERO){
            edificio = new Aserradero(cantidad_piedra, cantidad_madera,
                                      cantidad_metal, cantidad_maxima);

        }else if (nombre_edificio == FABRICA){
            edificio = new Fabrica(cantidad_piedra, cantidad_madera,
                                   cantidad_metal, cantidad_maxima);

        }else if (nombre_edificio == ESCUELA){
            edificio = new Escuela(cantidad_piedra, cantidad_madera,
                                   cantidad_metal, cantidad_maxima);

        }else if (nombre_edificio == OBELISCO){
            edificio = new Obelisco(cantidad_piedra, cantidad_madera,
                                    cantidad_metal, cantidad_maxima);

        }else if (nombre_edificio == PLANTA_ELECTRICA){
            edificio = new Planta_electrica(cantidad_piedra, cantidad_madera,
                                            cantidad_metal,cantidad_maxima);

        }else if (nombre_edificio == MINA_ORO) {
            edificio = new Mina_oro(cantidad_piedra, cantidad_madera,
                                    cantidad_metal, cantidad_maxima);
        }
        diccionario_edificios->insertar(nombre_edificio,edificio);
    }

}

/* ---------------------------------------------------------------------------------------------------------*/
