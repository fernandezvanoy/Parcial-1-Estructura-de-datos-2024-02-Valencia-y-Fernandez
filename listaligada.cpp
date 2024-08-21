#include "listaligada.h"
#include <iostream>

ListaLigada::ListaLigada() : cabeza(nullptr), final(nullptr) {}

ListaLigada::~ListaLigada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente; // Guardar el puntero al siguiente nodo
        delete actual; // Liberar la memoria del nodo actual
        actual = siguiente; // Avanzar al siguiente nodo
    }
}

long long ListaLigada::sort(int select){
    using namespace std::chrono;

    decltype(duration_cast<milliseconds>(high_resolution_clock::now() - high_resolution_clock::now()).count()) duracion = 0;


    if(select == 1){
        auto inicio = high_resolution_clock::now();
        this->bubblesort();
        auto fin = high_resolution_clock::now();

        duracion = duration_cast<milliseconds>(fin - inicio).count();
    }

    if(select == 2){
        auto inicio = high_resolution_clock::now();
        this->quicksort();
        auto fin = high_resolution_clock::now();

        duracion = duration_cast<milliseconds>(fin - inicio).count();
    }

    if(select == 3){
        auto inicio = chrono::high_resolution_clock::now();
        this->mergeSort(this->cabeza);
        auto fin = high_resolution_clock::now();

        duracion = duration_cast<milliseconds>(fin - inicio).count();
    }

    return duracion;

}

void ListaLigada::agregar(const Producto& producto, int index) {
    Nodo* nuevoNodo = new Nodo(producto, index);
    if(cabeza == nullptr){
        cabeza = nuevoNodo;
    
    } else {
        Nodo* actual = cabeza;
        while(actual -> siguiente != nullptr) {
            actual = actual -> siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
    nuevoNodo->anterior = final;
    final = nuevoNodo;
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
    //int tempindex = nodo1->index;
    //nodo1->index = nodo2->index;
    //nodo2->index = tempindex;

}

void ListaLigada::bubblesort() {
    if(cabeza == nullptr) return;

    bool intercambiado;
    do {
        intercambiado = false;
        Nodo* actual = cabeza;
        while(actual->siguiente != nullptr) {
            if(actual->data.getAtributo() > actual->siguiente->data.getAtributo()){
                intercambiar(actual, actual->siguiente);
                intercambiado = true;
            }    
            actual = actual->siguiente;
        }
    } while (intercambiado);

    

}

Nodo* ListaLigada::getFinal(){
    return final;
}

Nodo* ListaLigada::getCabeza(){
    return cabeza;
}

void ListaLigada::quicksort() {
    quicksortrec(cabeza, final);
}

void ListaLigada::quicksortrec(Nodo* izquierda, Nodo* derecha) {
    if (derecha != nullptr && izquierda != derecha && izquierda != derecha->siguiente) {
        Nodo* pivote = dividir(izquierda, derecha);
        quicksortrec(izquierda, pivote->anterior);
        quicksortrec(pivote->siguiente, derecha);
    }
}

Nodo* ListaLigada::dividir(Nodo* izquierda, Nodo* derecha) {
    Nodo* pivote = derecha;
    Nodo* i = izquierda->anterior;

    for (Nodo* j = izquierda; j != derecha; j = j->siguiente) {
        if (j->data.getAtributo() <= pivote->data.getAtributo()) {
            i = (i == nullptr) ? izquierda : i->siguiente;
            intercambiar(i, j);
        }
    }
    i = (i == nullptr) ? izquierda : i->siguiente;
    intercambiar(i, derecha);
    return i;
}

Nodo* ListaLigada::buscarNodo(int n){

    Nodo* nodoActual = this->cabeza;

    while(nodoActual->index < n){
        nodoActual = nodoActual->siguiente;
    }

    return nodoActual;    
}

Nodo* ListaLigada::mergeSort(Nodo* cabeza) {
        // Caso base: si la lista es vacía o tiene solo un nodo, está ordenada.
        if (!cabeza || !cabeza->siguiente) {
            return cabeza;
        }

        // Encuentra el nodo del medio para dividir la lista en dos mitades.
        Nodo* mitad = obtenerMitad(cabeza);
        Nodo* siguienteDeMitad = mitad->siguiente;  // Apunta al nodo que sigue al medio.
        mitad->siguiente = nullptr;  // Divide la lista en dos partes cortando el enlace.

        // Ordena recursivamente ambas mitades.
        Nodo* izquierda = mergeSort(cabeza);
        Nodo* derecha = mergeSort(siguienteDeMitad);

        // Combina las dos mitades ordenadas en una lista ordenada.
        return merge(izquierda, derecha);
    }

    Nodo* ListaLigada::obtenerMitad(Nodo* cabeza) {
        // Caso base: si la lista es vacía, devuelve el mismo nodo.
        if (!cabeza) return cabeza;

        // Inicializa dos punteros, mitad y rápido.
        Nodo* mitad = cabeza;
        Nodo* fin = cabeza->siguiente;

        // Avanza mitad un nodo a la vez y rápido dos nodos a la vez.
        while (fin && fin->siguiente) {
            mitad = mitad->siguiente;  // mitad avanza un nodo.
            fin = fin->siguiente->siguiente;  // Rápido avanza dos nodos.
        }

        // mitad estará en la mitad de la lista cuando rápido llegue al final.
        return mitad;
    }

    Nodo* ListaLigada::merge(Nodo* izquierda, Nodo* derecha) {
        // Si una de las listas está vacía, devuelve la otra lista.
        if (!izquierda) return derecha;
        if (!derecha) return izquierda;

        // Compara los datos en los nodos de ambas listas.
        if (izquierda->data.getAtributo() <= derecha->data.getAtributo()) {
            // Si el nodo de la izquierda es menor o igual, sigue combinando el siguiente nodo de la izquierda con la lista derecha.
            izquierda->siguiente = merge(izquierda->siguiente, derecha);
            return izquierda;  // Devuelve el nodo izquierdo como cabeza de la lista combinada.
        } else {
            // Si el nodo de la derecha es menor, sigue combinando la lista izquierda con el siguiente nodo de la derecha.
            derecha->siguiente = merge(izquierda, derecha->siguiente);
            return derecha;  // Devuelve el nodo derecho como cabeza de la lista combinada.
        }
    }










