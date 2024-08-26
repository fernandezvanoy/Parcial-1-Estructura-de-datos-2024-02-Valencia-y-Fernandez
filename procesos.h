#ifndef PROCESOS_H
#define PROCESOS_H


#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>  
#include <ctime>   
#include <iomanip>

using namespace std;

class Procesos {
private:

    //aqui se almacenan las palabras que usa el generador para generar los nombres de los productos
    vector<string> lista1 = {"Pan", "Postre", "Pasta", "Cereal", "Tortilla", "Cupcake", "Galleta", "Arroz"};
    vector<string> lista2 = {"Trigo", "Avena", "Maiz", "Harina", "Centeno", "Aniz", "Soda", "Integral"};
    vector<string> lista3 = {"Energia", "Cafeina", "Delicia", "Dulce", "Fresco", "Suave", "Crocante", "Ligero"};
    vector<string> lista4 = {"Jugo", "Leche", "Yogur", "Batido", "Mermelada", "Salsa", "Condimento", "Miel"};
    vector<string> lista5 = {"Aceite", "Vinagre", "Sal", "Azucar", "Especia", "Hierba", "Polvo", "Lata" };
    vector<string> lista6 = {"Pollo", "Pavo", "Carne", "Bolsa", "Plastico", "Papel", "Vidrio", "Pack"};


public:
    Procesos();

    int generarNumEntero(int min, int max) const;
    
    string generarNombre();

    string listaRandom();

    string obtenerItemRandom(vector<string>);

    int generarfecha();

};

#endif