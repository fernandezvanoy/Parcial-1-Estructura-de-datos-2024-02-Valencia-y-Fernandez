#ifndef NODO_H
#define NODO_H

#include "producto.h"

class Nodo{
public:
    Producto data;
    Nodo* siguiente;
    Nodo* anterior;
    int index;

    Nodo(const Producto& data, int index);

    //int getIndex();
};

#endif