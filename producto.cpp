#include "producto.h"


//declaración del atributo estático num para saber como ordenar los productos
int Producto::num;

Producto::Producto(const int codigo, const string& nombre, int cantidadStock, int precio, int fechaReposicion)
    :codigo(codigo), nombre(nombre), cantidadStock(cantidadStock), precio(precio), fechaReposicion(fechaReposicion) {}

//setters y getters
int Producto::getPrecio() {
    return precio;
}

int Producto::getCodigo() {
    return codigo;
}

//obtiene un atributo segun como se dese ordenar
int Producto::getAtributo(){


    if(this->num == 0 ){
        return precio;
    }

    if(this->num == 1){
        return codigo;
    }
    return -1;
}

void Producto::setAtributo(int n){
    num = n;
}

ostream& operator<<(ostream& os, const Producto& producto) {
    // Sobrecarga del operador << para la clase Producto
    // "ostream&" indica que la función devuelve una referencia a un objeto de tipo ostream
    // "operator<<" es el operador de inserción que estamos sobrecargando
    // "ostream& os" es el flujo de salida (por ejemplo, cout)
    // "const Producto& producto" es el objeto Producto que queremos imprimir

    os << "Codigo producto: " << producto.codigo 
       << ", Nombre: " << producto.nombre 
       << ", Cantidad en stock: " << producto.cantidadStock 
       << ", Precio: " << producto.precio 
       << ", Fecha de ultima reposicion: " << producto.fechaReposicion;
    // Aquí concatenamos varios atributos del objeto producto a la secuencia de salida (os)
    // Usamos el operador << para añadir texto y los valores de los atributos del producto
    // Esto forma una cadena de texto que representa al objeto Producto de manera legible

    return os;
    // Devolvemos el flujo de salida os para permitir encadenamiento de operaciones de salida (por ejemplo, cout << producto << endl)
}

