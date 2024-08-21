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

    static int num;

public:
    //Constructor 
    Producto(const int codigo, const string& nombre, int cantidadStock, int precio, int fechaReposicion);

  
    int getPrecio();
    int getCodigo();
    
    int getAtributo();

    static void setAtributo(int num);

    friend ostream& operator<<(ostream& os, const Producto& producto);

};

#endif