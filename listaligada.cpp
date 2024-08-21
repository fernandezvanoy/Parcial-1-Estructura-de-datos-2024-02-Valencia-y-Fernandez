#include "listaligada.h"
#include <iostream>

ListaLigada::ListaLigada() : cabeza(nullptr), final(nullptr) {}

//Constructor de la lista ligada, establece cabeza vacía por defecto
ListaLigada::~ListaLigada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente; // Guardar el puntero al siguiente nodo
        delete actual; // Liberar la memoria del nodo actual
        actual = siguiente; // Avanzar al siguiente nodo
    }
}

//Retorno para la variable duración (long long)
long long ListaLigada::sort(int select){
    using namespace std::chrono;


    //decltype transforma el tipo de dato
    //high_resolution_clock::now() inicia el conteo de tiempo y calcula el tiempo total con la diferencia
    //duration_cast<miliseconds> transforma el tiempo obtenido a milisegundos
    //duración obtiene el tipo de dato resultante de delctype(...)
    //.count() accede al valor almacenado de dicha duración
    decltype(duration_cast<milliseconds>(high_resolution_clock::now() - high_resolution_clock::now()).count()) duracion = 0;


    //selecciona entre los métodos de ordenamiento:
    //Inicia los tiempos y posteriormente ejecuta un método de ordenamiento interno de la clase lista ligada
    //al inicio y al final se usan marcas de tiempo para calcular su diferencia
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

//permite agregar un nodo a la lista
//busca el ultimo nodo cuyo apuntador de siguiente esté vacío
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

//Imprime los nodos de la lista accediendo a los datos que almacenan
//recorre uno por uno hasta llegar a nulo
void ListaLigada::imprimir() const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->data << endl;
        actual = actual->siguiente;
    }
}

//Intercambia los datos que almacenan dos nodos con ayuda de una variable temporal
void ListaLigada::intercambiar(Nodo* nodo1, Nodo* nodo2) {
    Producto temp = nodo1->data;
    nodo1->data = nodo2->data;
    nodo2->data = temp;
    //int tempindex = nodo1->index;
    //nodo1->index = nodo2->index;
    //nodo2->index = tempindex;

}

//Método de bubble sort
//Compara los atributos almacenados en datos y segun la condición intercambia estos datos almacenados en los nodos
//lleva los datos mas grandes a los últimos nodos
//una vez no realice ningun cambio termina el ciclo lo que significa la lista ya está ordenada
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


//getters y setters de cabeza y cola
Nodo* ListaLigada::getFinal(){
    return final;
}

Nodo* ListaLigada::getCabeza(){
    return cabeza;
}

//funció auxiliar para ejecutar la función recursiva
void ListaLigada::quicksort() {
    quicksortrec(cabeza, final);
}

//función recursiva quicksort, se usan dos indicadores izquierda y derecha 
void ListaLigada::quicksortrec(Nodo* izquierda, Nodo* derecha) {
    if (derecha != nullptr && izquierda != derecha && izquierda != derecha->siguiente) {
        Nodo* pivote = dividir(izquierda, derecha);
        quicksortrec(izquierda, pivote->anterior);
        quicksortrec(pivote->siguiente, derecha);
    }
}

//Divide la lista
Nodo* ListaLigada::dividir(Nodo* izquierda, Nodo* derecha) {
    Nodo* pivote = derecha; //se elige ultimo nodo como pivote
    Nodo* i = izquierda->anterior;//inicializa i como el nodo anterior a la izquierda

    //recorre la lista desde izquierda hasta antes de la derecha
    for (Nodo* j = izquierda; j != derecha; j = j->siguiente) {
        if (j->data.getAtributo() <= pivote->data.getAtributo()) {

            if (i == nullptr) {
            i = izquierda;
            } else {i = i->siguiente;}

            intercambiar(i, j);
        }
    }

    if (i == nullptr) {
        i = izquierda;
    } else {
        i = i->siguiente;
        }

    intercambiar(i, derecha);
    return i;
}

//Función que permite buscar un nodo segun en que posicion de la lista ligada se encuentra
Nodo* ListaLigada::buscarNodo(int n){
    Nodo* nodoActual = this->cabeza;
    while(nodoActual->index < n){
        nodoActual = nodoActual->siguiente;
    }

    return nodoActual;    
}

Nodo* ListaLigada::mergeSort(Nodo* cabeza) {
        // Caso base: si la lista es vacía o tiene solo un nodo, está ordenada
        if (!cabeza || !cabeza->siguiente) {
            return cabeza;
        }

        // Encuentra el nodo del medio para dividir la lista en dos mitades
        Nodo* mitad = obtenerMitad(cabeza);
        Nodo* siguienteDeMitad = mitad->siguiente;  // Apunta al nodo que sigue al medio
        mitad->siguiente = nullptr;  // Divide la lista en dos partes cortando el enlace

        // Ordena recursivamente ambas mitades
        Nodo* izquierda = mergeSort(cabeza);
        Nodo* derecha = mergeSort(siguienteDeMitad);

        // Combina las dos mitades ordenadas en una lista ordenada
        return merge(izquierda, derecha);
    }

    Nodo* ListaLigada::obtenerMitad(Nodo* cabeza) {
        // Caso base: si la lista es vacía, devuelve el mismo nodo
        if (!cabeza) return cabeza;

        // Inicializa dos punteros, mitad y rápido
        Nodo* mitad = cabeza;
        Nodo* fin = cabeza->siguiente;

        // Avanza mitad un nodo a la vez y rápido dos nodos a la vez
        while (fin && fin->siguiente) {
            mitad = mitad->siguiente;  // mitad avanza un nodo
            fin = fin->siguiente->siguiente;  // Rápido avanza dos nodos
        }

        // mitad estará en la mitad de la lista cuando rápido llegue al final
        return mitad;
    }

    Nodo* ListaLigada::merge(Nodo* izquierda, Nodo* derecha) {
        // Si una de las listas está vacía, devuelve la otra lista
        if (!izquierda) return derecha;
        if (!derecha) return izquierda;

        // Compara los datos en los nodos de ambas listas.
        if (izquierda->data.getAtributo() <= derecha->data.getAtributo()) {
            // Si el nodo de la izquierda es menor o igual, sigue combinando el siguiente nodo de la izquierda con la lista derecha
            izquierda->siguiente = merge(izquierda->siguiente, derecha);
            return izquierda;  // Devuelve el nodo izquierdo como cabeza de la lista combinada
        } else {
            // Si el nodo de la derecha es menor, sigue combinando la lista izquierda con el siguiente nodo de la derecha
            derecha->siguiente = merge(izquierda, derecha->siguiente);
            return derecha;  // Devuelve el nodo derecho como cabeza de la lista combinada
        }
    }










