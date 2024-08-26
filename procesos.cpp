#include "procesos.h"
#include "listaligada.h"

Procesos::Procesos() {}

 
//se genera numeros enteros aleatorios con ayuda de una funcion
int Procesos::generarNumEntero(int min, int max) const{
    //utiliza 
    return min + rand() % (max - min + 1);
}

//esta funcion se utiliza para generar un nombre de un producto aleatorio
string Procesos::generarNombre(){

    //crea dos string que será generados aleatoriamente a partir de el retorno de la función lista random
    string nombre1 = listaRandom();
    string nombre2 = listaRandom();

    //se concatenan ambos onombres y se retornan directamente al constructor del producto que se usará como argumento para el constructor de Nodo
    return nombre1 + " " + nombre2;
      
}

//selecciona una de las listas de manera aleatoria
string Procesos::listaRandom(){
    int n = generarNumEntero(1, 5);

    string a;

    //un vez generado el numero que indica la lista se asiga un valor a que será el resultado de la funcion obtener item random
    //el cual busca un nombre aleatorio dentro de las listas
    if (n == 1) {
        a = obtenerItemRandom(lista1);
    }else if(n==2) {
        a = obtenerItemRandom(lista2);
    }else if(n==3) {
        a = obtenerItemRandom(lista3);
    }else if(n==4) {
        a = obtenerItemRandom(lista4);
    }else if(n==5) {
        a = obtenerItemRandom(lista5);
    }else {
        a = obtenerItemRandom(lista6);
    }
    return a;
}

//recibe como parametroel vector cuyos elementos serán los nombres aleatorios 
string Procesos::obtenerItemRandom(vector<string> lista){

    //selecciona un elemento aleatorio dentro de las listas
    int indice = rand() % lista.size();
    return lista[indice];   
}

//funcion utilizada para generar una fecha aleatoria 
int Procesos::generarfecha(){

    //genera 3 numeros enteros aletarios entre un cierto rango
    //utiliza estos numeros para hacer multiplicacions y sumarlos
    int dia = generarNumEntero(1, 30);

    int mes = generarNumEntero(1, 12);

    int ano =generarNumEntero(22, 24);

    //retorna un entero como fecha para ese producto
    int fecha = ano + mes*100 + dia*10000;

    return fecha;
}





