#include "nodo.h"

//Constructor y defaults de la clase nodo
Nodo::Nodo(const Producto& data, int index) : data(data), siguiente(nullptr), anterior(nullptr), index(index) {}


