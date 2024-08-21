
#include <iostream>
#include "listaligada.h"
#include "producto.h"
#include "procesos.h"

int main() {
    
    srand(static_cast<unsigned int>(time(nullptr)));

    ListaLigada lista;

    Procesos generador;
    cout << "Buenos dias" << endl;

    cout << "Ingrese cantidad de registros que desea crear" << endl;
    int n;
    cin >> n;
    for (int i=0;i<n;++i){
        lista.agregar(Producto(generador.generarNumEntero(1, 250000), generador.generarNombre(), generador.generarNumEntero(1, 100), generador.generarNumEntero(100, 200000), 15072024), i);
    }

    cout<< "A continuacion se muestra la lista ya creada"<< endl;
    lista.imprimir();

    cout << "Ingrese que atributo desea comparar" << endl;
    cout <<"0: Precio, 1: Código" << endl;
    int num;
    cin >> num;

    cout << "Seleccione método" << endl;
    cout <<"1: Bubblesort, 2: Quicksort, 3: Mergesort" << endl;
    int select;
    cin >> select;

    lista.getCabeza()->data.setAtributo(num);



    long long duracion = lista.sort(select);

    cout << "Lista ya ordenada" << endl;
    lista.imprimir();

    cout << "\nEl ordenamiento duró: " << duracion << endl;
    cout << "\nFin del programa, nos vemos luego" << endl;


    return 0;
}


