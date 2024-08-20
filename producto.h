#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

using namespace std;

class Producto{
private:
    int codigo;
    string nombre;
    int cantidadStock;
    int precio;
    int fechaReposicion;

public:
    //Constructor 
    Producto(const int codigo, const string& nombre, int cantidadStock, int precio, int fechaReposicion);

    int getCantidadStock();
    int getPrecio();
    int getCodigo();

    friend ostream& operator<<(ostream& os, const Producto& producto);

};

#endif