#include <iostream>
#include "Libro.h"

using namespace std;

int main(){

    Libro libro1 = Libro("Harry Potter", "JK ROWLING", 389);
    Libro libro2("Star Wars", "George Lucas", 400);
    cout << "Cantidad de páginas del libro 1 = " << libro1.paginas_totales() << endl;
    cout << "Ahora voy a leer 4 páginas" << endl;
    libro1.avanzar_paginas(4);
    cout << "Listo, ya leí: " << libro1.pagina_actual() << " páginas" << endl;
    cout << "Terminé el libro? RESPUESTA: " << libro1.finalizado() << endl;
    cout << "Ahora voy a leer todo el libro" << endl;
    libro1.avanzar_paginas(385);
    cout << "Terminé el libro? RESPUESTA: " << libro1.finalizado() << endl;
    vector<string> xd = {"hola", "como", "hola", "como", "si", "que", "si", "hola"};
    int i = 0;
    set<string> conjunto = {};
    while(i<xd.size()){
        conjunto.insert(xd[i]);
        i++;
    }
    set<string>::iterator it;
    it = conjunto.begin();
    while(it != conjunto.end()){
        cout << *it << endl;
        it++;
    }
    return 0;
}