#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include "nodo.h"

class ListaLigada {
private:
    Nodo* cabeza;
    Nodo* inicio;
    Nodo* final;

public: 
    ListaLigada();

    ~ListaLigada();

    void agregar(const Producto& producto);

    void imprimir() const; 

    void intercambiar(Nodo* nodo1, Nodo* nodo2);   

    void bubblesort();

};

#endif