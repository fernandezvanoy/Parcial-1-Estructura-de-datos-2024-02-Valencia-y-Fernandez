#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

using namespace std;

class Producto{
private:

    //Informacion de cada producto
    int codigo;
    string nombre;
    int cantidadStock;
    int precio;
    int fechaReposicion;

    //atribto estático que indica como se ordenarán posteriormente
    static int num;

public:
    //Constructor 
    Producto(const int codigo, const string& nombre, int cantidadStock, int precio, int fechaReposicion);

    //otros métodos
    int getPrecio();
    int getCodigo();
    
    int getAtributo();

    static void setAtributo(int num);

    //sobrecarga del operador <<
    //se usa el friend para acceder a los métodos privados de Producto
    friend ostream& operator<<(ostream& os, const Producto& producto);

};

#endif