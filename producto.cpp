#include "producto.h"


int Producto::num;

Producto::Producto(const int codigo, const string& nombre, int cantidadStock, int precio, int fechaReposicion)
    :codigo(codigo), nombre(nombre), cantidadStock(cantidadStock), precio(precio), fechaReposicion(fechaReposicion) {}


int Producto::getPrecio() {
    return precio;
}

int Producto::getCodigo() {
    return codigo;
}

int Producto::getAtributo(){


    if(this->num == 0 ){
        return precio;
    }

    if(this->num == 1){
        return codigo;
    }
    return -1;
}

void Producto::setAtributo(int n){
    num = n;
}

ostream& operator<<(ostream& os, const Producto& producto) {
    os << "Codigo producto: " << producto.codigo << ", Nombre: " << producto.nombre << ", Cantidad en stock: " << producto.cantidadStock << ", Precio: " << producto.precio << ", Fecha de ultima reposicion: " << producto.fechaReposicion;
    return os;
}
