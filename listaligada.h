#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include "nodo.h"
#include <chrono>

class ListaLigada {
private:

    Nodo* cabeza;
    Nodo* inicio;
    Nodo* final;
    

public: 
    ListaLigada();

    ~ListaLigada();

    Nodo* getFinal();

    Nodo* getCabeza();

    void agregar(const Producto& producto, int index);

    void imprimir() const; 

    void intercambiar(Nodo* nodo1, Nodo* nodo2);   

    void bubblesort();

    void quicksort();

    Nodo* buscarNodo(int n);
    
    void quicksortrec(Nodo* cabeza, Nodo* final);


    Nodo* dividir(Nodo* alto, Nodo* bajo);

    Nodo* mergeSort(Nodo* head);

    Nodo* obtenerMitad(Nodo* head);

    Nodo* merge(Nodo* izquierda, Nodo* derecha);

    long long sort(int select);

};

#endif