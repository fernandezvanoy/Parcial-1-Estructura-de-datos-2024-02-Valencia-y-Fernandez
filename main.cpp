
#include <iostream>
#include "listaligada.h"
#include "producto.h"
#include "procesos.h"

int main() {
    
    ListaLigada lista;

    Procesos generador;

    //int codigo; string nombre; int cantidadStock; int precio; int fechaReposicion;

    int n= 0;
    for (int i=0;i<1000;++i){
        ++n;
        lista.agregar(Producto(generador.generarNumEntero(1, 250000), generador.generarNombre(), generador.generarNumEntero(1, 100), generador.generarNumEntero(100, 200000), 15072024));
    }

   
    lista.imprimir();
    cout << n << endl;

    lista.bubblesort();

    cout << "------" << endl;
    lista.imprimir();

    cout << n << endl;

    return 0;
}


