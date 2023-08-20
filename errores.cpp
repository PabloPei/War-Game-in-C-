#include <iostream>
#include "errores.h"

using namespace std;

void imprimir_error(Status_t st){
    cout << endl << endl;
    cout << '\t' << TXT_RED_196 << errores[st] << fin_de_formato << endl;
}
