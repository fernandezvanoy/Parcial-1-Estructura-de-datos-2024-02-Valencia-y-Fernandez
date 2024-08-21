#include "procesos.h"
#include "listaligada.h"

Procesos::Procesos() {}

 

int Procesos::generarNumEntero(int min, int max) const{
    return min + std::rand() % (max - min + 1);
}

string Procesos::generarNombre(){
    string nombre1 = listaRandom();
    string nombre2 = listaRandom();

    return nombre1 + " " + nombre2;
      
}

string Procesos::listaRandom(){
    int n = generarNumEntero(1, 5);

 

    string a;

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

string Procesos::obtenerItemRandom(vector<string> lista){
    int indice = rand() % lista.size();
    return lista[indice];   
}





