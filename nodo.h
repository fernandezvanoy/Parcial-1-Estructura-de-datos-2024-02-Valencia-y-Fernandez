#ifndef NODO_H
#define NODO_H

#include "producto.h"

//clase nodo
class Nodo{
public:

    //Atributos publicos de nodo para su facil acceso
    //datos que almacena cada nodo (producto)
    Producto data;
    //apuntador al nodo siguiente
    Nodo* siguiente;
    //apuntador al nodo anterior
    Nodo* anterior;
    //indice del nodo en la lista al momento de su generacióm
    int index;

    //se pasa como parametros al constructor el producto y su indice para su creación
    Nodo(const Producto& data, int index);

};

#endif