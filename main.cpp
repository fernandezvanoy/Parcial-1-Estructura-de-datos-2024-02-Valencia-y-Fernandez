//librerías
#include <iostream>
#include "listaligada.h"
#include "producto.h"
#include "procesos.h"

//main
int main() {
    
    //inicializa una semilla de números aleatorios usando la función time donde transforma el tipo de dato
    //time devuelve los segundos actuales desde Epoch 1 enero 1970
    //static cast<unsigned int> transformael valor devuelto por nullptr de unsigned int a time_t
    srand(static_cast<unsigned int>(time(nullptr)));

    //creacion de la lista
    ListaLigada lista;

    //este objeto usa métodos para generar lso registros que luego se guardan en los nodos
    Procesos generador;
    cout << "Buenos dias" << endl;

    //n = cantidad de registros
    cout << "Ingrese cantidad de registros que desea crear (muchos registros toman gran tiempo)" << endl;
    int n;
    cin >> n;

    //un ciclo que agrega los nodos donde se pasa al constructor de la clase un objeto de tipo Producto que usa los métodos para generar un registro
    for (int i=0;i<n;++i){
        lista.agregar(Producto(generador.generarNumEntero(1, 250000), generador.generarNombre(), generador.generarNumEntero(1, 100), generador.generarNumEntero(100, 200000), 15072024), i);
    }

    //muestra la lista
    cout<< "A continuacion se muestra la lista ya creada"<< endl;
    lista.imprimir();

    //opiones accesibles
    cout << "Ingrese que atributo desea comparar" << endl;
    cout <<"0: Precio, 1: Código" << endl;
    int num;
    cin >> num;

    cout << "Seleccione método" << endl;
    cout <<"1: Bubblesort, 2: Quicksort, 3: Mergesort" << endl;
    int select;
    cin >> select;

    //establece el atributo estático que le indica a todos los registros como que se tienen que ordenar
    lista.getCabeza()->data.setAtributo(num);


    //ee utiliza el tipo de dato long long para almacenar la cantidad de milisegundos y así evitar errores
    //la duración será el retorno de la funcion sort que ordena la lista segun la selección del usuario y retorna la diferencia en milisegundos entre ambos tiempos
    long long duracion = lista.sort(select);

    cout << "Lista ya ordenada" << endl;
    lista.imprimir();

    cout << "\nEl ordenamiento duró: " << duracion << endl;
    cout << "\nFin del programa, nos vemos luego" << endl;


    return 0;
}


