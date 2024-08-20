#include "producto.h"

Producto::Producto(const int codigo, const string& nombre, int cantidadStock, int precio, int fechaReposicion)
    :codigo(codigo), nombre(nombre), cantidadStock(cantidadStock), precio(precio), fechaReposicion(fechaReposicion) {}

int Producto::getCantidadStock() {
    return cantidadStock;
}      

int Producto::getPrecio() {
    return precio;
}

int Producto::getCodigo() {
    return codigo;
}

ostream& operator<<(ostream& os, const Producto& producto) {
    os << "Codigo producto: " << producto.codigo << ", Nombre: " << producto.nombre << ", Cantidad en stock: " << producto.cantidadStock << ", Precio: " << producto.precio << ", Fecha de ultima reposicion: " << producto.fechaReposicion;
    return os;
}
