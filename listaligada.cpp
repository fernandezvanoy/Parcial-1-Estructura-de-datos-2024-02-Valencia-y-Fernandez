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

        //inicia una marca de tiempo
        //luego hace referencia a la instancia de la clase e invoca la función bubble sort
        //toma la segunda marca de tiempo
        auto inicio = high_resolution_clock::now();
        this->bubblesort();
        auto fin = high_resolution_clock::now();

        //calcula la diferencia entre ambas marcas de tiempo
        duracion = duration_cast<milliseconds>(fin - inicio).count();
    }

    if(select == 2){

        //inicia una marca de tiempo
        //luego hace referencia a la instancia de la clase e invoca la función quick sort
        //toma la segunda marca de tiempo
        auto inicio = high_resolution_clock::now();
        this->quicksort();
        auto fin = high_resolution_clock::now();

        duracion = duration_cast<milliseconds>(fin - inicio).count();
    }

    if(select == 3){

        //inicia una marca de tiempo
        //luego hace referencia a la instancia de la clase e invoca la función merge sort
        //toma la segunda marca de tiempo
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
      final->siguiente = nuevoNodo;
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
//no cambia los apuntadores de los nodos solo los datos que contienen los nodos
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

// Función auxiliar para ejecutar la función recursiva
void ListaLigada::quicksort()
{
    quicksortrec(cabeza, final);
    // llama a la función recursiva quicksortrec
    // pasando como parámetros el primer nodo (cabeza) y el último nodo (final) de la lista ligada
}

// Función recursiva quicksort, se usan dos indicadores izquierda y derecha
void ListaLigada::quicksortrec(Nodo *izquierda, Nodo *derecha)
{
    // verifica que la lista no esté vacía, que izquierda no sea igual a derecha
    // y que izquierda no sea el nodo siguiente a derecha (caso base para detener la recursión)
    if (derecha != nullptr && izquierda != derecha && izquierda != derecha->siguiente)
    {

        Nodo *pivote = dividir(izquierda, derecha);
        // llama a la función dividir para colocar los elementos menores al pivote a su izquierda
        // y los mayores a su derecha, luego devuelve el nuevo pivote

        quicksortrec(izquierda, pivote->anterior);
        // llama recursivamente a quicksortrec para ordenar la sublista a la izquierda del pivote

        quicksortrec(pivote->siguiente, derecha);
        // llama recursivamente a quicksortrec para ordenar la sublista a la derecha del pivote
    }
}

// Divide la lista en torno al pivote y coloca los elementos menores a su izquierda
// y los mayores a su derecha
Nodo *ListaLigada::dividir(Nodo *izquierda, Nodo *derecha)
{
    Nodo *pivote = derecha;
    // elige el último nodo de la sublista como pivote

    Nodo *i = izquierda->anterior;
    // inicializa el puntero i como el nodo anterior a la izquierda
    // para rastrear la posición donde colocar el siguiente elemento menor o igual al pivote

    // recorre la lista desde el nodo izquierdo hasta el nodo anterior al derecho
    for (Nodo *j = izquierda; j != derecha; j = j->siguiente)
    {

        // si el valor del nodo actual (j) es menor o igual al valor del pivote
        if (j->data.getAtributo() <= pivote->data.getAtributo())
        {

            if (i == nullptr)
            {
                i = izquierda;
                // si i es nullptr (es decir, estamos al inicio de la lista),
                // lo establece en el nodo izquierdo
            }
            else
            {
                i = i->siguiente;
                // si i ya está en un nodo válido, avanza al siguiente nodo
            }

            intercambiar(i, j);
            // intercambia los valores entre los nodos i y j
            // colocando el nodo menor o igual al pivote en su posición correcta
        }
    }

    if (i == nullptr)
    {
        i = izquierda;
        // si i aún es nullptr, se establece en el nodo izquierdo
    }
    else
    {
        i = i->siguiente;
        // si i está en un nodo válido, avanza al siguiente nodo
    }

    intercambiar(i, derecha);
    // finalmente, intercambia el nodo en i con el pivote,
    // colocando el pivote en su posición correcta

    return i;
    // devuelve la posición del pivote después de la partición
}

//Función que permite buscar un nodo segun en que posicion de la lista ligada se encuentra
Nodo* ListaLigada::buscarNodo(int n){
    Nodo* nodoActual = this->cabeza;
    while(nodoActual->index < n){
        nodoActual = nodoActual->siguiente;
    }

    return nodoActual;    
}

Nodo *ListaLigada::mergeSort(Nodo *cabeza)
{
    // Caso base: si la lista es vacía o tiene solo un nodo, está ordenada
    if (!cabeza || !cabeza->siguiente)
    {
        return cabeza;
    }

    // Encuentra el nodo del medio para dividir la lista en dos mitades
    Nodo *mitad = obtenerMitad(cabeza);
    Nodo *siguienteDeMitad = mitad->siguiente; // Apunta al nodo que sigue al medio
    mitad->siguiente = nullptr;                // Divide la lista en dos partes cortando el enlace

    // Ordena recursivamente ambas mitades
    Nodo *izquierda = mergeSort(cabeza);
    Nodo *derecha = mergeSort(siguienteDeMitad);

    // Combina las dos mitades ordenadas en una lista ordenada
    return merge(izquierda, derecha);
}

Nodo *ListaLigada::obtenerMitad(Nodo *cabeza)
{
    // Caso base: si la lista es vacía, devuelve el mismo nodo
    if (!cabeza)
        return cabeza;

    // Inicializa dos punteros, mitad y rápido
    Nodo *mitad = cabeza;
    Nodo *fin = cabeza->siguiente;

    // Avanza mitad un nodo a la vez y rápido dos nodos a la vez
    while (fin && fin->siguiente)
    {
        mitad = mitad->siguiente;        // mitad avanza un nodo
        fin = fin->siguiente->siguiente; // Rápido avanza dos nodos
    }

    // mitad estará en la mitad de la lista cuando rápido llegue al final
    return mitad;
}

Nodo *ListaLigada::merge(Nodo *izquierda, Nodo *derecha)
{
    // Si una de las listas está vacía, devuelve la otra lista
    if (!izquierda)
        return derecha;
    if (!derecha)
        return izquierda;

    // Compara los datos en los nodos de ambas listas.
    if (izquierda->data.getAtributo() <= derecha->data.getAtributo())
    {
        // Si el nodo de la izquierda es menor o igual, sigue combinando el siguiente nodo de la izquierda con la lista derecha
        izquierda->siguiente = merge(izquierda->siguiente, derecha);
        return izquierda; // Devuelve el nodo izquierdo como cabeza de la lista combinada
    }
    else
    {
        // Si el nodo de la derecha es menor, sigue combinando la lista izquierda con el siguiente nodo de la derecha
        derecha->siguiente = merge(izquierda, derecha->siguiente);
        return derecha; // Devuelve el nodo derecho como cabeza de la lista combinada
    }
}
