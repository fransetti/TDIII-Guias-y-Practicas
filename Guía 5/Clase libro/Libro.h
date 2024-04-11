#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <set>
#include <map>


class Libro {
 public:
 // observadores
 int paginas_totales();
 int pagina_actual();
 float porcentaje_leido();
 bool finalizado();

 // constructores
 Libro(string titulo, string autor, int cantidad_paginas);


 // modificadores
 void avanzar_paginas(int n);
 void saltar_a_pagina(int k);

 private:
 string _titulo;
 string _autor;
 int _paginas_totales;
 int _pagina_actual;

};

#endif
