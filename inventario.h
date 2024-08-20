#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "listaligada.h"




using namespace std;

class Inventario{
private:
    ListaLigada inventario;
    ListaLigada nombre1;
    ListaLigada nombre2;

public:
    Inventario();

    rellenar();
};

#endif