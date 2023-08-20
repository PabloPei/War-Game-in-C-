#include "Andypolis.h"

/* ---------------------------------------------------------------------------------------------------------*/

Andypolis::Andypolis(){
    turno = 1;
    rondas = 0;
    jugador_1 = nullptr;
    jugador_2 = nullptr;
    casilleros_transitables = nullptr;
    mapa = nullptr;
}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Andypolis::cargar_mapa() {

    Status_t st = OK;

    this -> mapa = new Mapa();

    Leer_archivo_mapa lector_mapa;
    st = lector_mapa.abrir_archivo();

    if(st != OK)
        return st;

    lector_mapa.leer_archivo(mapa);

    lector_mapa.cerrar_archivo();

    return st;
}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Andypolis::cargar_ubicaciones(){

    Status_t st = OK;

    Leer_archivo_ubicaciones lector_ubicaciones;

    st = lector_ubicaciones.abrir_archivo();

    if(st != OK){
        fstream archivo_ubicaciones("ubicaciones.txt", ios::out);
        archivo_ubicaciones.close();
        return st;
    }

    if(!(lector_ubicaciones.leer_archivo(mapa,diccionario,jugador_1,jugador_2)))
        st = ARCHIVO_UBICACIONES_VACIO;

    lector_ubicaciones.cerrar_archivo();

    return st;
}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Andypolis::cargar_diccionario() {

    Status_t st = OK;

    this -> diccionario = new ABB<string, Edificio*>();

    Leer_archivo_edificios lector_edificios;

    st = lector_edificios.abrir_archivo();

    if(st != OK)
        return st;

    lector_edificios.leer_archivo(mapa,diccionario);

    lector_edificios.cerrar_archivo();

    return st;

}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Andypolis::cargar_jugador(){

    Status_t st = OK;

    jugador_1 = new Jugador(1);
    Inventario* inventario1 = jugador_1->obtener_inventario();

    jugador_2 = new Jugador(2);
    Inventario* inventario2 = jugador_2->obtener_inventario();

    Leer_archivo_materiales lector_materiales;

    st=lector_materiales.abrir_archivo();

    if(st != OK)
        return st;


    lector_materiales.leer_archivo(inventario1,inventario2);
    lector_materiales.cerrar_archivo();

    jugador_1->asignar_inventario(inventario1);
    jugador_2->asignar_inventario(inventario2);

    jugador_1->obtener_grafo()->crearMatrizAdyacencia(mapa);
    jugador_2->obtener_grafo()->crearMatrizAdyacencia(mapa);

    jugador_1->obtener_grafo()->cargarCaminosTablero(mapa, 1);
    jugador_1->obtener_grafo()->calcularMatricesFloyd();

    jugador_2->obtener_grafo()->cargarCaminosTablero(mapa, 2);
    jugador_2->obtener_grafo()->calcularMatricesFloyd();

    return OK;
}

/* ---------------------------------------------------------------------------------------------------------*/


void Andypolis::presione_para_volver(){

    std::string basura;

    getline(std::cin, basura,'\n');
    std::cout << std::endl << std::endl << '\t' << "Presione ENTER para volver al menu";
    getline(std::cin, basura,'\n');
}

/* ---------------------------------------------------------------------------------------------------------*/


void Andypolis::presione_para_volver_sin_entrada(){

    std::string basura;

    std::cout << std::endl << std::endl << '\t' << "Presione ENTER para volver al menu";
    getline(std::cin, basura,'\n');
}


/* ---------------------------------------------------------------------------------------------------------*/

Inventario* Andypolis::obtener_inventario_actual() {

    Inventario* inventario;

    if (turno == 1) {
        inventario = jugador_1->obtener_inventario();

    }else {
        inventario = jugador_2->obtener_inventario();
    }

    return inventario;
}

/* ---------------------------------------------------------------------------------------------------------*/

Jugador* Andypolis::obtener_jugador_actual(){
    Jugador* jugador;

    if (turno == 1) {
        jugador = jugador_1;

    }else {
        jugador = jugador_2;
    }

    return jugador;
}


/* ---------------------------------------------------------------------------------------------------------*/

bool Andypolis::tiene_energia_suficiente(int cantidad){

    Jugador* jugador = obtener_jugador_actual();

    return (jugador->obtener_energia() >= cantidad);
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::restar_energia(int cantidad) {

    Jugador* jugador = obtener_jugador_actual();

    jugador->restar_energia(cantidad);
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::sumar_energia(int cantidad) {

    Jugador* jugador = obtener_jugador_actual();

    jugador->sumar_energia(cantidad);
}


/* ---------------------------------------------------------------------------------------------------------*/

bool Andypolis::restar_materiales_por_reparacion(std::string nombre_demolido) {

    Inventario* inventario = obtener_inventario_actual();
    Edificio* edificio = diccionario->buscar(nombre_demolido);

    int cantidad_madera = inventario->obtener_material_por_nombre(MADERA)->obtener_cantidad();
    int cantidad_piedra = inventario->obtener_material_por_nombre(PIEDRA)->obtener_cantidad();
    int cantidad_metal = inventario->obtener_material_por_nombre(METAL)->obtener_cantidad();

    bool materiales_suficientes = ((cantidad_madera >= (edificio->obtener_madera()/4)) &&
                                   (cantidad_piedra >= (edificio->obtener_piedra()/4)) &&
                                   (cantidad_metal >= (edificio->obtener_metal()/4)));

    inventario->restar_material_por_nombre(MADERA, (edificio->obtener_madera()/4));
    inventario->restar_material_por_nombre(PIEDRA, (edificio->obtener_piedra()/4));
    inventario->restar_material_por_nombre(METAL, (edificio->obtener_metal()/4));

    return materiales_suficientes;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::restar_materiales_por_construccion(std::string nombre_edificio) {

    Inventario* inventario = obtener_inventario_actual();
    Edificio* edificio = diccionario->buscar(nombre_edificio);

    inventario->restar_material_por_nombre(MADERA, (edificio->obtener_madera()));
    inventario->restar_material_por_nombre(PIEDRA, (edificio->obtener_piedra()));
    inventario->restar_material_por_nombre(METAL, (edificio->obtener_metal()));

}

/* ---------------------------------------------------------------------------------------------------------*/

Status_t Andypolis::iniciar() {

    Status_t st;

    /////////////////////cargo los archivos //////////////////////////

    if ((st = this->cargar_diccionario()) != OK)
        return st;
    else if ((st = this->cargar_mapa())!= OK)
        return st;
    else if ( (st = this->cargar_jugador()) != OK)
        return st;
    else
        st = this->cargar_ubicaciones();
    return st;
}

void Andypolis::jugar(Status_t st){

    bool partida_renudada = true;
    bool partida_finalizada = false;
    int opcion = COMENZAR_PARTIDA;
    string opcion_str;
    Menu menu;


    ////////////////////////// partida nueva /////////////////////////////////////
    if(st == ERROR_APERTURA_ARCHIVO_UBICACIONES || st == ARCHIVO_UBICACIONES_VACIO){
        menu.mostrar_mensaje_bienvenida();
        std::cout << '\t' << TXT_YELLOW_220 << "╔═══════════════════╗" << fin_de_formato << std::endl;
        std::cout << '\t' << TXT_YELLOW_220 << "║   Nueva partida   ║" << fin_de_formato << endl;
        std::cout << '\t' << TXT_YELLOW_220 << "╚═══════════════════╝" << fin_de_formato << std::endl;
        do {
            menu.mostrar_menu_1();
            opcion_str = menu.ingresar_opcion();
            st = menu.validar_opcion_1(opcion_str);
            while (st != OK){
                imprimir_error(st);
                st = menu.validar_opcion_1(opcion_str);
            }
            opcion = menu.obtener_opcion();
            procesar_opcion_menu_1(&opcion);
            menu.mostrar_mensaje_bienvenida();
        } while (opcion != GUARDAR_Y_SALIR && opcion != COMENZAR_PARTIDA);
        partida_renudada = false;
        st = OK;
    }


    ////////////////////////////////// partida comenzada ////////////////////////////////////

    if(st == OK && opcion == COMENZAR_PARTIDA){

        menu.mostrar_mensaje_bienvenida();

        srand((unsigned)time(NULL));
        turno = rand()%2+1;
        jugador_1->sumar_energia(50);
        jugador_2->sumar_energia(50);
        this -> lluvia_de_recursos();

        //me fijo que no haya ganado de entrada
        if(partida_ganada()!=true) {
            if (partida_renudada == true) {
                std::cout << '\t' << TXT_YELLOW_220 << "╔═══════════════════╗" << fin_de_formato << std::endl;
                std::cout << '\t' << TXT_YELLOW_220 << "║ Partida reanudada ║" << fin_de_formato << endl;
                std::cout << '\t' << TXT_YELLOW_220 << "╚═══════════════════╝" << fin_de_formato << std::endl;
            }

            do {
                if (turno == 1) {
                    cout << endl << endl << '\t' << fondo_color_verde << "--- Turno jugador 1  ---" << fin_de_formato;
                    cout << endl << endl << '\t' << negrita << "ENERGIA: " << jugador_1->obtener_energia()
                         << fin_de_formato;
                } else {
                    cout << endl << endl << '\t' << fondo_color_verde << "--- Turno jugador 2  ---" << fin_de_formato;
                    cout << endl << endl << '\t' << negrita << "ENERGIA: " << jugador_2->obtener_energia()
                         << fin_de_formato;
                }

                cout << '\t' << '\t' << negrita << "Ronda: " << (int) (rondas + 2) / 2 << fin_de_formato;

                mapa->imprimir_mapa();
                menu.mostrar_menu_2();
                opcion_str = menu.ingresar_opcion();
                st = menu.validar_opcion_2(opcion_str);

                while (st != OK) {
                    imprimir_error(st);
                    opcion_str = menu.ingresar_opcion();
                    st = menu.validar_opcion_2(opcion_str);
                }

                opcion = menu.obtener_opcion();
                procesar_opcion_menu_2(opcion);

                if (obtener_jugador_actual()->obtener_energia() == 0)
                    finalizar_turno();

                menu.mostrar_mensaje_bienvenida();

                partida_finalizada = partida_ganada();

            } while (opcion != GUARDAR_Y_SALIR_2 && partida_finalizada == false);
        }
    }

    //si se gano la partida guardo el resultado
    if(partida_finalizada==true)
        guardar();

    menu.mostrar_mensaje_despedida();
}

/* ---------------------------------------------------------------------------------------------------------*/

bool Andypolis::partida_ganada() {
    Objetivos* objetivos;
    Jugador* jugador;
    bool partida_finalizada = false;
    int obj_cumplido;

    jugador = obtener_jugador_actual();
    objetivos = jugador->obtener_objetivos();
    if(objetivos->obtener_avance(diccionario,jugador->obtener_andycoins_acumulados(), jugador->obtener_bombas_usadas(),
                                 jugador->obtener_bombas_compradas(),jugador->obtener_id(),jugador->obtener_energia(),
                                 jugador->obtener_inventario(),&obj_cumplido)>=100) {
        cout <<endl<<endl<<endl;
        cout << endl << '\t' << fondo_color_verde << " --- Ha ganado !!! --- " << fin_de_formato;
        cout << endl << endl << endl << '\t' << negrita << "Cumplio el objetivo: " << objetivos->obtener_objetivo(obj_cumplido)->obtener_nombre() << fin_de_formato;
        partida_finalizada=true;
    }

    return partida_finalizada;

}


/* ---------------------------------------------------------------------------------------------------------*/
void Andypolis::procesar_opcion_menu_1(int* opcion_elegida){

    switch(*opcion_elegida){
        case MODIFICAR_EDIFICIO: modificar_edificio_por_nombre();  break;

        case LISTAR_EDIFICIOS:  listar_todos_los_edificios() ; break;

        case MOSTRAR_MAPA:  mostrar_mapa(); break;

        case COMENZAR_PARTIDA: comenzar_partida(opcion_elegida); break;

        case GUARDAR_Y_SALIR:  guardar();

    }
}

/* ------------------------------------------ FUNCIONES MENÚ 1 ----------------------------------------------*/

void Andypolis::modificar_edificio_por_nombre(){

    system(CLR_SCREEN);
    std::string nombre_edificio;
    int cant_nueva_piedra, cant_nueva_madera, cant_nueva_metal;


    std::cout << '\t' << fondo_color_verde << "---- Modificar edificio por nombre ----" << fin_de_formato << std::endl << std::endl;
    std::cout << '\t' << subrayado << "Ingrese el nombre del edificio que desea modificar:" << fin_de_formato <<" ";
    getline(std::cin, nombre_edificio);


    Edificio* aux = diccionario -> buscar(nombre_edificio);


    if(!(aux)){
        std::cout << std::endl << endl << '\t' << TXT_RED_196 << "Nombre de edificio a modificar inválido." << fin_de_formato << std::endl << std::endl;
        presione_para_volver_sin_entrada();
        return;
    }

    if (nombre_edificio == OBELISCO) {
        std::cout << std::endl << endl << '\t' << TXT_RED_196 << "El edificio Obelisco no es modificable" << fin_de_formato << std::endl << std::endl;
        presione_para_volver_sin_entrada();
        return;
    }

    cout<<endl;
    std::cout << '\t' << TXT_YELLOW_220 << "╔══════════════════════════════════════════════╗" << fin_de_formato << std::endl;
    std::cout << '\t' << TXT_YELLOW_220 << "║ Es posible modificar el edificio elegido     ║" << fin_de_formato << std::endl;
    std::cout << '\t' << TXT_YELLOW_220 << "║ Ingrese un valor mayor a 0 y menor a 50000   ║" << fin_de_formato << std::endl;
    std::cout << '\t' << TXT_YELLOW_220 << "║ Presione 0 si no desea modificar el material ║" << fin_de_formato << std::endl;
    std::cout << '\t' << TXT_YELLOW_220 << "╚══════════════════════════════════════════════╝" << fin_de_formato << std::endl;

    std::cout << std::endl << endl << '\t' << fondo_color_anaranjado << "Nuevo valor para el material piedra:" << fin_de_formato <<" ";
    std::cin >> cant_nueva_piedra;

    if (cant_nueva_piedra > 0 && cant_nueva_piedra < 50000) {
        aux->modificar_piedra_edificio(cant_nueva_piedra);
        std::cout << endl  << '\t' << negrita << "El valor del material se cambio exitosamente" << fin_de_formato;
    }
    else if(cant_nueva_piedra == 0) {
        std::cout << endl << '\t' << negrita << "La cantidad del material no cambio" << fin_de_formato;
    }
    else {
        std::cout << endl << '\t' << TXT_RED_196 << "El nuevo valor ingresado no se encuentra en el rango de validez" << fin_de_formato;
    }

    std::cout << endl << endl << '\t' << fondo_color_amarillo << "Nuevo valor para el material madera:" << fin_de_formato <<" ";
    std::cin >> cant_nueva_madera;

    if (cant_nueva_madera > 0 && cant_nueva_madera < 50000) {
        aux->modificar_madera_edificio(cant_nueva_madera);
        std::cout << endl <<  '\t' << negrita << "El valor del material se cambio exitosamente" << fin_de_formato;
    }
    else if(cant_nueva_madera == 0) {
        std::cout << endl <<  '\t' << negrita << "La cantidad del material no cambio" << fin_de_formato;
    }
    else {
        std::cout << endl <<  '\t' << TXT_RED_196 << "El nuevo valor ingresado no se encuentra en el rango de validez" << fin_de_formato;
    }

    std::cout << endl << endl <<  std::endl << '\t' << fondo_color_verde << "Nuevo valor para el material metal:" << fin_de_formato <<" ";
    std::cin >> cant_nueva_metal;

    if (cant_nueva_metal > 0 && cant_nueva_metal < 50000) {
        aux->modificar_metal_edificio(cant_nueva_metal);
        std::cout << endl << '\t' << negrita << "El valor del material se cambio exitosamente" << fin_de_formato << std::endl << std::endl;
    }
    else if(cant_nueva_metal == 0) {
        std::cout << endl  << '\t' << negrita << "La cantidad del material no cambio" << fin_de_formato << std::endl << std::endl;
    }
    else {
        std::cout << endl << '\t' << TXT_RED_196 << "El nuevo valor ingresado no se encuentra en el rango de validez" << fin_de_formato << std::endl << std::endl;
    }

    presione_para_volver();
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::mostrar_mapa() {

    system(CLR_SCREEN);
    mapa->imprimir_mapa();
    presione_para_volver_sin_entrada();

}

/* ---------------------------------------------------------------------------------------------------------*/
void Andypolis::comenzar_partida(int* opcion_elegida){

    system(CLR_SCREEN);
    int numero_jugador;
    int fila;
    int columna;
    int fila_2;
    int columna_2;

    std::cout << '\t' << fondo_color_verde << "---- COMIENZO DE PARTIDA ----" << fin_de_formato << std::endl << std::endl;
    std::cout << '\t' << subrayado << "Ingrese el numero de jugador que desea ser:" << fin_de_formato << " ";
    cin >> numero_jugador;

    if (numero_jugador != 1 && numero_jugador != 2){
        std::cout << endl <<  '\t' << TXT_RED_196 << "El numero de jugador ingresado no se encuentra en el rango de validez" << fin_de_formato;
        *opcion_elegida =0;
        presione_para_volver();
        return;
    }


    std::cout << endl <<'\t' << subrayado << "Ingrese la fila del jugador 1:" << fin_de_formato << " ";
    cin >> fila;
    std::cout << endl << '\t' << subrayado << "Ingrese la columna del jugador 1:" << fin_de_formato << " ";
    cin >> columna;

    if( !(mapa ->agregar_jugador(fila,columna,1))) {
        std::cout << endl <<  '\t' << TXT_RED_196 << "La coordenada no es valida" << fin_de_formato;
        *opcion_elegida =0;
        presione_para_volver();
        return;
    }
    jugador_1->asignar_fil(fila);
    jugador_1->asignar_col(columna);

    std::cout << endl << '\t' << subrayado << "Ingrese la fila del jugador 2:" << fin_de_formato << " ";
    cin >> fila_2;


    std::cout << endl << '\t' << subrayado << "Ingrese la columna del jugador 2:" << fin_de_formato << " ";
    cin >> columna_2;

    while(fila_2 == fila && columna_2 == columna) {
        std::cout << endl << '\t' << TXT_RED_196 << " En esta posición se encuentra el jugador 1" << fin_de_formato << " ";
        std::cout << endl << '\t' << subrayado << "Ingrese la fila del jugador 2 " << fin_de_formato << " ";
        cin >> fila_2;


        std::cout << endl << '\t' << subrayado << "Ingrese la columna del jugador 2" << fin_de_formato << " ";
        cin >> columna_2;
    }

    if( !(mapa ->agregar_jugador(fila_2,columna_2,2))) {
        std::cout << endl <<  '\t' << TXT_RED_196 << "La coordenada no es valida" << fin_de_formato;
        *opcion_elegida =0;
        presione_para_volver();
        return;
    }
    jugador_2->asignar_fil(fila_2);
    jugador_2->asignar_col(columna_2);

    *opcion_elegida = COMENZAR_PARTIDA;

    presione_para_volver();

}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::listar_todos_los_edificios_wrapper(NodoAB<string , Edificio*>* nodo){

    if (nodo != nullptr){
        listar_todos_los_edificios_wrapper(nodo->obtener_izquierdo());

        nodo->obtener_valor()->imprimir_datos();
        listar_todos_los_edificios_wrapper(nodo->obtener_derecho());
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::listar_todos_los_edificios(){
    system(CLR_SCREEN);
    std::cout << '\t' << fondo_color_verde << " --- LISTA DE EDIFICIOS --- " <<  EMOJI_EDIFICIO << fin_de_formato << std::endl << std::endl;
    NodoAB<string, Edificio*>* raiz = diccionario->obtener_raiz();
    listar_todos_los_edificios_wrapper(raiz);
    presione_para_volver_sin_entrada();
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::procesar_opcion_menu_2(int opcion_elegida){

    switch(opcion_elegida){

        case CONSTRUIR_POR_NOMBRE:  construir_por_nombre(); break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:  listar_edificios_construidos(); break;

        case DEMOLER_POR_COORDENADA: demoler_por_coordenada();  break;

        case ATACAR_POR_COORDENADA: atacar_por_coordenada(); break;

        case REPARAR_POR_COORDENADA: reparar_por_coordenada();  break;

        case COMPRAR_BOMBAS:  comprar_bombas(); break;

        case CONSULTAR_COORDENADA:  consultar_coordenada(); break;

        case MOSTRAR_INVENTARIO:  mostrar_inventario(); break;

        case MOSTRAR_OBJETIVOS:  imprimir_objetivos(); break;

        case RECOLECTAR_RECURSOS:  recolectar_recursos_producidos(); break;

        case MOVERSE_COORDENADA:  moverse_coordenada(); break;

        case FINALIZAR_TURNO:  finalizar_turno(); break;

        case GUARDAR_Y_SALIR_2:  guardar(); break;
    }
}

/* ---------------------------------------OPCIONES MENU 2-------------------------------------------*/

void Andypolis::construir_por_nombre(){

    system(CLR_SCREEN);

    std::string nombre_edificio;
    char confirmacion;
    int fila_indicada;
    int columna_indicada;

    std::cout << '\t' << fondo_color_verde << "---- Construccion de edificio ----" << fin_de_formato << std::endl << std::endl;

    if(!(tiene_energia_suficiente(15))){
        cout << '\t' << TXT_RED_196 << "No tiene la energia suficiente" << fin_de_formato << endl;
        return;
    }

    std::cout << '\t' << subrayado << "Ingrese el nombre del edificio que desea construir:" << fin_de_formato << " ";
    getline(std::cin, nombre_edificio);


    if(se_puede_construir(nombre_edificio,turno)){

        std::cout << std::endl << '\t' << "Es posible construir el edificio, desea hacerlo? " <<
                  "(Ingrese S para si y cualquier otra letra para no): ";
        std::cin >> confirmacion;

        if(confirmacion == SI){

            std::cout << std::endl << '\t' << "Ingrese la fila donde quiere construir el edificio: ";
            std::cin >> fila_indicada;

            std::cout << std::endl << '\t' << "Ingrese la columna donde quiere construir el edificio: ";
            std::cin >> columna_indicada;


            if(!(mapa->es_coordenada_valida(fila_indicada,columna_indicada))){
                std::cout << std::endl << '\t' << TXT_RED_196 << "Ubicacion invalida." << fin_de_formato ;

            }else if( mapa->obtener_casillero(fila_indicada,columna_indicada)->obtener_tipo()!= TERRENO) {
                std::cout << endl << '\t' << TXT_RED_196 << "No se puede construir en este casillero" << fin_de_formato << std::endl;

            }else if (mapa->obtener_casillero(fila_indicada,columna_indicada)->ocupado())
                std::cout << endl <<'\t' << TXT_RED_196 << "No se puede construir en este casillero, esta ocupado" << fin_de_formato << std::endl;
            else{

                mapa->modificar_casillero(nombre_edificio,fila_indicada,columna_indicada,turno);

                this -> diccionario->buscar(nombre_edificio) -> incrementar_construidos(turno);

                this->restar_materiales_por_construccion(nombre_edificio);

                std::cout << std::endl << '\t' << "Edificio construido con exito.";
                this->restar_energia(15);

            }
        }
    }

    this->presione_para_volver();

}

/* ---------------------------------------------------------------------------------------------------------*/

bool Andypolis::se_puede_construir(std::string nombre_edificio, int jugador){

    bool se_puede = false;

    if((this->diccionario->buscar(nombre_edificio))==nullptr){

        std::cout << std::endl << '\t'<< TXT_RED_196 << "Nombre de edificio invalido." << fin_de_formato;


    }else if(!this->hay_materiales_suficientes(nombre_edificio)){

    }else if(!(this->diccionario->buscar(nombre_edificio)->hay_espacio(jugador))){

        std::cout << std::endl << '\t' << TXT_RED_196 << "No se puede construir, ya se alcanzo el maximo de " <<
                  "construcciones permitidas de este edificio" << fin_de_formato  ;


    }else{

        se_puede = true;
    }

    return se_puede;
}


/* ---------------------------------------------------------------------------------------------------------*/

bool Andypolis::hay_materiales_suficientes(std::string nombre_edificio){

    bool materiales_suficientes = false;

    Edificio* aux = this->diccionario->buscar(nombre_edificio);
    Inventario* inventario = obtener_inventario_actual();
    Material* madera = inventario->obtener_material_por_nombre("madera");
    Material* piedra = inventario->obtener_material_por_nombre("piedra");
    Material* metal = inventario->obtener_material_por_nombre("metal");

    if(!(aux->obtener_madera() <= madera->obtener_cantidad())){

        std::cout <<  endl << '\t' << TXT_RED_196 <<"No hay suficiente madera para construir el edificio. "
                  << "Se necesita " << aux->obtener_madera() << " y tenes " <<
                  madera->obtener_cantidad() << fin_de_formato ;

    }else if(!(aux->obtener_piedra() <= piedra->obtener_cantidad())){

        std::cout << endl << '\t' << TXT_RED_196 << "No hay suficiente piedra para construir el edificio. "
                  << "Se necesita " << aux->obtener_piedra() << " y tenes " <<
                  piedra->obtener_cantidad() <<fin_de_formato;

    }else if(!(aux->obtener_metal() <= metal->obtener_cantidad())){

        std::cout <<  endl << '\t' << TXT_RED_196 <<"No hay suficiente metal para construir el edificio. "
                  << "Se necesita " << aux->obtener_metal() << " y tenes " <<
                  metal->obtener_cantidad() << fin_de_formato;

    }else{
        materiales_suficientes = true;
    }

    return materiales_suficientes;
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::listar_edificios_construidos_wrapper(NodoAB<string , Edificio*>* nodo){

    if (nodo != nullptr){
        listar_edificios_construidos_wrapper(nodo->obtener_izquierdo());
        nodo->obtener_valor()->imprimir_datos_construidos(turno);
        imprimir_coordenadas_y_reparacion(nodo->obtener_clave());
        listar_edificios_construidos_wrapper(nodo->obtener_derecho());
    }
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::listar_edificios_construidos(){
    system(CLR_SCREEN);
    std::cout << '\t' << fondo_color_verde << " --- LISTA DE EDIFICIOS --- " <<  EMOJI_EDIFICIO << fin_de_formato << std::endl << std::endl;
    NodoAB<string, Edificio*>* raiz = diccionario->obtener_raiz();
    listar_edificios_construidos_wrapper(raiz);
    presione_para_volver_sin_entrada();
}
/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::imprimir_coordenadas_y_reparacion(string nombre){

    Casillero* aux;
    for(int i = 0; i < mapa->obtenerCantidadFilas() ; i++){
        for(int j = 0; j < mapa->obtenerCantidadColumnas(); j++){
            aux =mapa->obtener_casillero(i,j);

            if(aux->hay_edificio_en_casillero()) {

                if (aux->obtener_edificio()->obtener_nombre() == nombre &&
                    aux->obtener_edificio()->obtener_jugador() == turno) {
                    std::cout << '\t' << '\t' << negrita << "Coordenadas: " << " (" << i << ", " << j << ")" ;
                    if(aux->esta_roto() && (nombre == MINA || nombre == FABRICA))
                        std::cout << '\t' << negrita << "Necesita reparacion" << endl;
                    else
                        std::cout << '\t' << negrita << "No necesita reparacion" << endl;

                }
            }
        }
    }


}
/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::comprar_bombas(){

    system(CLR_SCREEN);

    int cantidad;
    Material* andycoins;
    Material* bombas;

    std::cout << '\t' << fondo_color_verde << "---- Tienda de bombas ----" << fin_de_formato << std::endl << std::endl;

    if(!(tiene_energia_suficiente(5))){
        cout << endl << '\t'  << TXT_RED_196 << "No tiene la energia suficiente" << fin_de_formato << endl;
        return;
    }

    andycoins = obtener_inventario_actual()->obtener_material_por_nombre(ANDYCOINS);
    bombas = obtener_inventario_actual()->obtener_material_por_nombre(BOMBAS);
    cout << subrayado << '\t' << "Ingrese la cantidad de bombas que desea:" << fin_de_formato << " ";
    cin >> cantidad;
    if(!(cantidad * 100 > andycoins->obtener_cantidad())){
        cout << endl << '\t' << "Se han adquirido " << cantidad <<" bombas " <<endl;
        obtener_jugador_actual()->aumentar_bombas_compradas(cantidad);
        andycoins->restar_material(cantidad*100);
        bombas->sumar_material(cantidad);
        cout << endl << '\t' << "Quedan " << andycoins->obtener_cantidad() << " andycoins" <<endl;
        this->restar_energia(5);
    }
    else
        cout << endl << '\t' << TXT_RED_196  << "No tiene la cantidad sufiiente de Andycoins" << fin_de_formato << endl;

    presione_para_volver();

}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::consultar_coordenada() {

    int fila;
    int columna;

    system(CLR_SCREEN);

    std::cout << '\t' << fondo_color_verde << "---- Consulta coordenada ----" << fin_de_formato << std::endl << std::endl;

    if(tiene_energia_suficiente(15)){
        std::cout<< endl << '\t' <<subrayado << "Ingrese la fila del casillero que quiere consultar:" << fin_de_formato << " ";
        std::cin>>fila;
        std::cout<< endl << '\t' <<subrayado << "Ingrese la columna del casillero que quiere consultar:" << fin_de_formato << " ";
        std::cin>> columna;

        if(mapa->es_coordenada_valida(fila, columna)) {
            mapa->describir_casillero(fila, columna);
            restar_energia(15);

        }else {
            std::cout << endl << '\t' << TXT_RED_196 << "Coordenada invalida." << fin_de_formato << std::endl;
        }

    }else {
        std::cout << endl << '\t' << TXT_RED_196 << "No tenes energia suficiente." << fin_de_formato << std::endl;
    }
    presione_para_volver();

}

/* ---------------------------------------------------------------------------------------------------------*/
void Andypolis::recolectar_recursos_producidos(){

    Casillero* aux;

    system(CLR_SCREEN);

    std::cout << '\t' << fondo_color_verde << "---- Recoleccion de recursos ----" << fin_de_formato << std::endl << std::endl;

    if(!(tiene_energia_suficiente(20))){
        cout << '\t' << TXT_RED_196 << "No tiene la energia suficiente" << fin_de_formato << endl;
        return;
    }

    for(int i = 0; i < mapa->obtenerCantidadFilas() ; i++){
        for(int j = 0; j < mapa->obtenerCantidadColumnas(); j++){
            aux =mapa->obtener_casillero(i,j);

            if(aux->hay_edificio_en_casillero() && aux->obtener_edificio()->obtener_jugador() == turno) {

                recolectar_recurso(aux->obtener_edificio());
            }
        }
    }
    restar_energia(20);
    presione_para_volver_sin_entrada();
}

/* ---------------------------------------------------------------------------------------------------------*/
void Andypolis::recolectar_recurso(Edificio* edificio){

    std::string nombre_edificio = edificio->obtener_nombre();
    int cantidad = edificio->obtener_recursos_producidos();
    if(nombre_edificio == MINA){
        obtener_jugador_actual()->obtener_inventario()->sumar_material_por_nombre("piedra",cantidad);
        cout << endl << '\t' << negrita <<"Se han recolectado " << cantidad << " piedras" << endl << fin_de_formato;
    }
    else if(nombre_edificio == ASERRADERO){
        obtener_jugador_actual()->obtener_inventario()->sumar_material_por_nombre("madera",cantidad);
        cout << endl << '\t' << negrita <<"Se han recolectado " << cantidad << " maderas" << endl << fin_de_formato;

    }
    else if(nombre_edificio == FABRICA){
        obtener_jugador_actual()->obtener_inventario()->sumar_material_por_nombre("metales",cantidad);
        cout << endl << '\t' << negrita <<"Se han recolectado " << cantidad << " metales" << endl << fin_de_formato;

    }
    else if(nombre_edificio == ESCUELA){
        obtener_jugador_actual()->obtener_inventario()->sumar_material_por_nombre("andycoins",cantidad);
        cout << endl << '\t' << negrita <<"Se han recolectado " << cantidad << " andycoins" << endl << fin_de_formato;
        obtener_jugador_actual()->aumentar_andycoins_acumulados(cantidad);
    }
    else if(nombre_edificio == PLANTA_ELECTRICA){
        sumar_energia(cantidad);
        cout << endl << '\t' << negrita <<"Se han recolectado " << cantidad << " de energia" << endl << fin_de_formato;

    }
    else if(nombre_edificio == MINA_ORO){
        obtener_jugador_actual()->obtener_inventario()->sumar_material_por_nombre("andycoins",cantidad);
        cout << endl << '\t' << negrita <<"Se han recolectado " << cantidad << " andycoins" << endl << fin_de_formato;
        obtener_jugador_actual()->aumentar_andycoins_acumulados(cantidad);
    }
}
/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::actualizar_recursos_producidos(){

    Casillero* aux;
    for(int i = 0; i < mapa->obtenerCantidadFilas() ; i++){
        for(int j = 0; j < mapa->obtenerCantidadColumnas(); j++){
            aux =mapa->obtener_casillero(i,j);

            if(aux->hay_edificio_en_casillero()) {

                if (aux->obtener_edificio()->obtener_jugador() == turno) {
                    aux->obtener_edificio()->aumentar_recursos_acumulados();

                }
            }
        }
    }

}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::finalizar_turno(){

    obtener_jugador_actual() ->sumar_energia(20);

    if(turno == 1)
        turno = 2;
    else
        turno = 1;

    rondas++;

    if(rondas % 2 == 0)
        this -> lluvia_de_recursos();

    actualizar_recursos_producidos();
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::demoler_por_coordenada() {

    int fila;
    int columna;

    system(CLR_SCREEN);

    std::cout << '\t' << fondo_color_verde << "---- Demolicion de edificio ----" << fin_de_formato << std::endl << std::endl << endl ;

    std::cout<< '\t' << subrayado << "Ingrese que fila que quiere demoler:" << fin_de_formato<< " " ;
    std::cin>>fila;
    std::cout<< endl << '\t' << subrayado << "Ingrese que columna quiere demoler:" << fin_de_formato << " ";
    std::cin>> columna;

    if(tiene_energia_suficiente(15)) {

        if(mapa->es_coordenada_valida(fila, columna)) {

            Casillero* casillero = mapa->obtener_casillero(fila, columna);
            std::string nombre_edificio = casillero->obtener_nombre_atributo();
            Inventario* inventario = obtener_inventario_actual();

            if(casillero->obtener_tipo() == TERRENO && nombre_edificio != VACIO) {

                Edificio* edificio = diccionario->buscar(nombre_edificio);

                inventario ->sumar_material_por_nombre(MADERA, (edificio->obtener_madera()/2));
                inventario ->sumar_material_por_nombre(PIEDRA, (edificio->obtener_piedra()/2));
                inventario ->sumar_material_por_nombre(METAL, (edificio->obtener_metal()/2));

                edificio->decrementar_construidos(turno);
                casillero->eliminar_atributo();
                restar_energia(15);

                std::cout << endl <<'\t' << "Demolicion exitosa" << std::endl;
            }else {
                std::cout << endl << '\t' << TXT_RED_196 << "No hay un edificio en este casillero" << fin_de_formato << std::endl;
            }

        }else {

            std::cout<< endl << '\t' << TXT_RED_196 << "Coordenada invalida"<< fin_de_formato << std::endl;
        }

    }else {
        std::cout << endl << '\t' << TXT_RED_196 <<  "No hay suficiente energia" << fin_de_formato << std::endl;
    }
    presione_para_volver();
}
/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::atacar_por_coordenada() {

    int fila;
    int columna;
    Inventario* inventario = obtener_inventario_actual();

    system(CLR_SCREEN);
    std::cout << '\t' << fondo_color_verde << "---- Atacar edificio ----" << fin_de_formato << std::endl << std::endl << endl ;



    if (tiene_energia_suficiente(30)) {
        if (inventario->obtener_material_por_nombre(BOMBAS)->obtener_cantidad() > 0) {

            std::cout<< '\t' << subrayado << "Ingrese que fila que quiere atacar:" << fin_de_formato << " ";
            std::cin>>fila;
            std::cout << endl << '\t' << subrayado << "Ingrese que columna quiere atacar:" << fin_de_formato <<" ";
            std::cin>> columna;

            if (mapa->es_coordenada_valida(fila, columna)) {
                if(mapa->obtener_casillero(fila,columna)->obtener_tipo()==TERRENO) {
                    if (mapa->atacar_casillero(fila, columna, turno, diccionario)) {
                        inventario->restar_material_por_nombre(BOMBAS, 1);
                        obtener_jugador_actual()->aumentar_bombas_usadas(1);
                        restar_energia(30);
                    }
                }else
                    std::cout << endl << '\t' << TXT_RED_196 << "No hay un edificio en este terreno" << fin_de_formato << std::endl;

            }else {
                std::cout<< endl << '\t' << TXT_RED_196 << "Coordenada invalida"<< fin_de_formato << std::endl;
            }

        }else {
            std::cout<< endl << '\t' << TXT_RED_196 << "No hay bombas para atacar." << fin_de_formato << std::endl;
        }
    }else {
        std::cout << endl << '\t' << TXT_RED_196 << "No hay energia suficiente" << fin_de_formato << std::endl;
    }
    presione_para_volver();
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::reparar_por_coordenada(){

    int fila;
    int columna;

    system(CLR_SCREEN);
    std::cout << '\t' << fondo_color_verde << "---- Reparar Edificio ----" << fin_de_formato << std::endl << std::endl << endl ;


    if(tiene_energia_suficiente(25)){
        std::cout<< endl << '\t' << subrayado << "Ingrese que fila que quiere reparar:" << fin_de_formato << " ";
        std::cin>>fila;
        std::cout<< endl << '\t' << subrayado << "Ingrese que columna quiere reparar:" << fin_de_formato << " ";
        std::cin>> columna;

        if (mapa->es_coordenada_valida(fila, columna)) {
            Casillero* casillero = mapa->obtener_casillero(fila, columna);

            if (casillero->obtener_tipo() == TERRENO &&
                casillero->obtener_nombre_atributo() != VACIO) {

                if(restar_materiales_por_reparacion(casillero->obtener_nombre_atributo())){
                    casillero->reparar(turno);
                    restar_energia(25);
                }else
                    std::cout << endl <<endl << '\t' << TXT_RED_196 << "No hay suficientes materiales para reparar" << fin_de_formato << std::endl;

            }else
                std::cout << endl <<endl << '\t' << TXT_RED_196 << "No hay un edificio en este terreno" << fin_de_formato << std::endl;

        }else {
            std::cout << endl << endl << '\t' << TXT_RED_196 << "Coordenada invalida." << fin_de_formato << std::endl;
        }
    }else {
        std::cout <<  endl << endl << '\t' << TXT_RED_196 << "No hay energia suficiente" << fin_de_formato << std::endl;
    }

    presione_para_volver();
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::moverse_coordenada(){

    int fila;
    int columna;
    system(CLR_SCREEN);
    std::cout << endl << '\t' << fondo_color_verde << "---- Moverse a coordenada ----" << fin_de_formato << std::endl << std::endl;
    std::cout << endl << '\t' << subrayado << "Ingrese la fila a donde quiere moverse:" << fin_de_formato << " ";
    std::cin >> fila;
    std::cout << endl << '\t' << subrayado << "Ingrese la columna a donde quiere moverse:" << fin_de_formato<< " ";
    std::cin >> columna;

    if (mapa->es_coordenada_valida(fila, columna)) {

        obtener_jugador_actual()->mover_jugador(fila,columna,mapa);

    }else {

        std::cout << endl << '\t' << TXT_RED_196 << "Coordenada invalida." << fin_de_formato << std::endl;
    }

    presione_para_volver();
}


/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::mostrar_inventario(){

    obtener_inventario_actual()->mostrar_inventario();
    presione_para_volver_sin_entrada();
}

/* ---------------------------------------------------------------------------------------------------------*/
void Andypolis::imprimir_objetivos(){

    system(CLR_SCREEN);

    cout << '\t' << fondo_color_verde << "---- OBJETIVOS ----" << fin_de_formato << endl << endl;

    Jugador* jugador = obtener_jugador_actual();
    Lista<Objetivo*>* lista_objetivos = jugador->obtener_objetivos()->obtener_lista_de_objetivos();

    for (int i = lista_objetivos->obtener_cantidad(); i >= 1 ; i--){
        std::cout << '\t' <<  "-----------------------------------------------"<<std::endl;
        std::cout << '\t' << negrita <<" Objetivo: " << fin_de_formato<<  lista_objetivos->consulta(i)->obtener_nombre()
        << std::endl << '\t' << negrita <<  " Avance: " <<fin_de_formato<<lista_objetivos->consulta(i)->obtener_porcentaje_cumplimiento(diccionario,
                      jugador->obtener_andycoins_acumulados(), jugador->obtener_bombas_usadas(),jugador->obtener_bombas_compradas(),
                      jugador->obtener_id(),jugador->obtener_energia(),jugador->obtener_inventario()) << negrita << "%" << fin_de_formato
                     <<std::endl;
        std::cout << '\t' << "-----------------------------------------------"<<std::endl;
    }

    presione_para_volver_sin_entrada();

}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::lluvia_de_recursos() {

    // sorteo el nombre del material
    string nombre_material;
    srand((unsigned)time(NULL));
    int numerito =  rand()% 4 + 1;

    switch(numerito){

        case 1:{
            nombre_material = PIEDRA;
            break;
        }
        case 2:{
            nombre_material = MADERA;
            break;
        }
        case 3:{
            nombre_material = METAL;
            break;
        }
        case 4:{
            nombre_material = ANDYCOINS;
            break;
        }
    }

    //me fijo si se puede construir
    int fil,col,cantidad;

    if(rondas == 0)
        casilleros_transitables = mapa -> casilleros_disponibles_para_lluvia_recursos();

    if(casilleros_transitables->obtener_cantidad() == 0){

    }else{

        cantidad = casilleros_transitables->obtener_cantidad();
        int indice = rand() % casilleros_transitables->obtener_cantidad() + 1;

        fil = casilleros_transitables->consulta(indice)->obtener_fil();
        col = casilleros_transitables->consulta(indice)->obtener_col();

        while (mapa ->hay_jugador(fil,col) && cantidad > 0) {
            int indice = rand() % casilleros_transitables->obtener_cantidad() + 1;
            fil = casilleros_transitables->consulta(indice)->obtener_fil();
            col = casilleros_transitables->consulta(indice)->obtener_col();
            cantidad--;
        }

        if(cantidad == 0) {
            return;
        }

        mapa->modificar_casillero(nombre_material,fil,col,0);

        casilleros_transitables->baja(indice);

    }


}

/* ---------------------------------------------------------------------------------------------------------*/
void Andypolis::guardar_materiales(){
    //guardo materiales

    std::ofstream archivo_materiales(PATH_MATERIALES);

    if(!archivo_materiales){
        std::cout<< endl << '\t' << TXT_RED_196 << "Error al abrir materiales.txt" << fin_de_formato;
        return;
    }

    Lista<Material*>* materiales_1 = jugador_1->obtener_inventario()->obtener_materiales();
    Lista<Material*>* materiales_2 = jugador_2->obtener_inventario()->obtener_materiales();
    int cantidad_1;
    int cantidad_2;

    for(int i = 1; i <= materiales_1->obtener_cantidad(); i++){

        std::string nombre_material = materiales_1->consulta(i)->obtener_nombre();
        cantidad_1 = materiales_1->consulta(i)->obtener_cantidad();
        cantidad_2 = materiales_2->consulta(i)->obtener_cantidad();
        archivo_materiales <<  nombre_material << ' ' <<  cantidad_1 << ' ' <<  cantidad_2 <<std::endl;
    }
    archivo_materiales.close();
}

/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::guardar_ubicaciones(){
    //guardo ubicaciones

    std::ofstream archivo_ubicaciones(PATH_UBICACIONES);
    Casillero* aux;
    std::string nombre_elemento;


    if(!archivo_ubicaciones){
        std::cout<< endl << '\t' << TXT_RED_196 << "Error al abrir ubicaciones.txt" << fin_de_formato;
        return;
    }

    //no se comenzo la partida aun
    if(jugador_1->obtener_fil() == -1)
       return;

    //primero guardo materiales
    for(int i = 0; i < mapa->obtenerCantidadFilas(); i++){

        for(int j = 0; j < mapa->obtenerCantidadColumnas() ; j++){
            aux = mapa->obtener_casillero(i,j);
            if(aux->hay_material_en_casillero()){

                nombre_elemento=(aux->obtener_nombre_atributo());

                archivo_ubicaciones << nombre_elemento<< " (" << i <<',' << j
                                    << ")\n";
            }
        }
    }
    //guardo jugador 1
    archivo_ubicaciones << "1" << " (" << jugador_1->obtener_fil() <<',' << jugador_1->obtener_col() << ")\n";


    //guardo edificios del jugador 1
    for(int i = 0; i < mapa->obtenerCantidadFilas(); i++){

        for(int j = 0; j < mapa->obtenerCantidadColumnas() ; j++){
            aux = mapa->obtener_casillero(i,j);
            if(aux->hay_edificio_en_casillero()){
                if( aux->obtener_edificio()->obtener_jugador()==1){
                    nombre_elemento=(aux->obtener_nombre_atributo());

                    archivo_ubicaciones << nombre_elemento<< " (" << i <<',' << j
                                        << ")\n";
                }

            }
        }
    }

    //guardo jugador 2
    archivo_ubicaciones << "2" << " (" << jugador_2->obtener_fil() <<',' << jugador_2->obtener_col() << ")\n";

    //guardo edificios del jugador 2


    for(int i = 0; i < mapa->obtenerCantidadFilas(); i++){

        for(int j = 0; j < mapa->obtenerCantidadColumnas() ; j++){
            aux = mapa->obtener_casillero(i,j);
            if(aux->hay_edificio_en_casillero()){
                if( aux->obtener_edificio()->obtener_jugador()==2){
                    nombre_elemento=(aux->obtener_nombre_atributo());

                    archivo_ubicaciones << nombre_elemento<< " (" << i <<',' << j
                                        << ")\n";
                }

            }
        }
    }
}
/* ---------------------------------------------------------------------------------------------------------*/
void Andypolis::guardar_edificios() {

    std::ofstream archivo_edificios(PATH_EDIFICIOS);
    NodoAB<string,Edificio*>* raiz = diccionario->obtener_raiz();
    obtener_edificios(raiz);
    archivo_edificios.close();

}

/* ---------------------------------------------------------------------------------------------------------*/
void Andypolis::obtener_edificios(NodoAB<string,Edificio*>* nodo) {

    if (nodo != nullptr) {
        obtener_edificios(nodo->obtener_izquierdo());
        fstream archivo(PATH_EDIFICIOS, ios::app);
        Edificio *aux = nodo->obtener_valor();
        archivo << aux->obtener_nombre() << " " << aux->obtener_piedra() << " "
                << aux->obtener_madera() << " " << aux->obtener_metal() << " " << aux->obtener_maximo() << endl;
        obtener_edificios(nodo->obtener_derecho());

    }
}
/* ---------------------------------------------------------------------------------------------------------*/

void Andypolis::guardar(){

    this -> guardar_materiales();
    this -> guardar_ubicaciones();
    this -> guardar_edificios();

}

/* ---------------------------------------------------------------------------------------------------------*/

Andypolis::~Andypolis(){

    delete diccionario;
    diccionario = nullptr;

    delete mapa;
    mapa = nullptr;

    delete casilleros_transitables;
    casilleros_transitables = nullptr;

    delete jugador_1;
    jugador_1 = nullptr;

    delete jugador_2;
    jugador_2 = nullptr;
}

/* ---------------------------------------------------------------------------------------------------------*/