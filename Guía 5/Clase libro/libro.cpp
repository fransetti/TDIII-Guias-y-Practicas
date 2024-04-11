#include "Libro.h"

using namespace std;

Libro::Libro(string titulo, string autor, int cantidad_paginas){
    _titulo = titulo;
    _autor = autor;
    _paginas_totales = cantidad_paginas;
    _pagina_actual = 0;
}

int Libro::paginas_totales() {
    return this->_paginas_totales;
}


int Libro::pagina_actual() {
    return this->_pagina_actual;
}

float Libro::porcentaje_leido() {
    return (this->_pagina_actual/this->_paginas_totales); 
}

void Libro::avanzar_paginas(int n){
    this->_pagina_actual = this->_pagina_actual + n;
}

void Libro::saltar_a_pagina(int k){
    this->_pagina_actual = k;
}

bool Libro::finalizado(){
    if(this->_pagina_actual == this->_paginas_totales){
        return true;
    }else{
        return false;
    }
}