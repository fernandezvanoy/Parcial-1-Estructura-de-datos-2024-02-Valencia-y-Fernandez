#include "listaligada.h"
#include <iostream>

ListaLigada::ListaLigada() : cabeza(nullptr) {}

ListaLigada::~ListaLigada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente; // Guardar el puntero al siguiente nodo
        delete actual; // Liberar la memoria del nodo actual
        actual = siguiente; // Avanzar al siguiente nodo
    }
}

void ListaLigada::agregar(const Producto& producto) {
    Nodo* nuevoNodo = new Nodo(producto);
    if(cabeza == nullptr){
        cabeza = nuevoNodo;
    } else {
        Nodo* actual = cabeza;
        while(actual -> siguiente != nullptr) {
            actual = actual -> siguiente;
        }
        actual->siguiente = nuevoNodo;
    }

}

void ListaLigada::imprimir() const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->data << endl;
        actual = actual->siguiente;
    }
}

void ListaLigada::intercambiar(Nodo* nodo1, Nodo* nodo2) {
    Producto temp = nodo1->data;
    nodo1->data = nodo2->data;
    nodo2->data = temp;
}

void ListaLigada::bubblesort() {
    if(cabeza == nullptr) return;

    bool intercambiado;
    do {
        intercambiado = false;
        Nodo* actual = cabeza;
        while(actual->siguiente != nullptr) {
            if(actual->data.getCodigo() > actual->siguiente->data.getCodigo()){
                intercambiar(actual, actual->siguiente);
                intercambiado = true;
            }    
            actual = actual->siguiente;
        }
    } while (intercambiado);

    

}

