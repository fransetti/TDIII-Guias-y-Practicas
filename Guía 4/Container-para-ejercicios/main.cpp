//GUÍA 4
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>



//FUNCIONES ADICIONALES: (hechas por mí para imprimir vectores)
void imprimir_vector(vector<int> lista){
    int i = 0;
    cout <<'{';
    while (i< lista.size()){
        cout <<lista[i];
        i++;
        if(i< lista.size()){
            cout <<", ";
        }
    }
    cout <<'}' << endl;
}

void imprimir_vector_de_vector(vector<vector<int>> lista){
    int i = 0;
    cout <<'{';
    while (i< lista.size()){
        imprimir_vector(lista[i]);
        i++;
        if(i< lista.size()){
            cout <<", ";
        }
    }
    cout <<'}' << endl;
}

void imprimir_vector_strings(vector<string> lista){
    int i = 0;
    cout <<'{';
    while (i< lista.size()){
        cout <<lista[i];
        i++;
        if(i< lista.size()){
            cout <<", ";
        }
    }
    cout <<'}' << endl;
}

//GUÍA 4 FUNCIONES

//FUNCIONES EJERCICIO 1
int fibonacci(int n);
bool es_par(int n);

//FUNCIONES EJERCICIO 2
int productoria(const vector<int> &v); //Devuelve el resultado de multiplicar todos los elementos de un vector
int productoria_aux(const vector<int> &v, int desde);

int cantidad_ocurrencias(string s, const vector<string> &v); //Cuenta la cantidad de apariciones que tiene el string "s" en el vector
int cantidad_ocurrencias_aux(string s, const vector<string> &v, int hasta);

int contar_coincidencias(const vector<int> &v);
int contar_coincidencias_aux(const vector<int> &v, int hasta);

vector<int> solo_positivos(const vector<int> &v); //Devuelve un nuevo vector que sólo contiene los elementos positivos del original
vector<int> solo_positivos_aux(const vector<int> &v, int hasta);

void multiplicar_todos(vector<int> &v, int n); //Multiplica a todos los elementos del vector por "n"
void multiplicar_todos_aux(vector<int> &v, int n, int hasta);

//FUNCIONES EJERCICIO 3
//(mismas funciones de ejercicio 2 pero con Divide And Conquer)
int cantidad_ocurrencias_DC(string s, const vector<string> &v, int desde, int hasta);
void multiplicar_todos_DC(vector<int> &v, int n, int desde, int hasta);


//EJERCICIO 4
int potencia(int n, int m);
int potencia_DC(int n, int m, int desde, int hasta);

int pico_montaña(vector<int> v);
int pico_montaña_DC(vector<int> v, int desde, int hasta);


//EJERCICIO 5
int suma_aux(const vector<int> &v, int desde, int hasta);
int mas_a_la_izquierda_DC(vector<int> v, int desde, int hasta);



//FUNCION EJERCICIO 6
//int sublistaSumMax(vector<int> v, int d, int h);


//EJERCICIO 7
int sumatoria_DC3(const vector<int> & v, int desde, int hasta);
int productoria_DC3(const vector<int> & v, int desde, int hasta);



//EJERCICIOS ORDENAMIENTO -----------------------------------------------------

//FUNCIONES EJERCICIO 12
void selection_sort(vector<int> &v);
void insertion_sort(vector<int> &v);

//extra:
void swap(vector<int> &v, int x, int y);
int buscar_minimoPos(vector<int> v, int desde, int hasta);
void insertion(vector<int> &v, int insert, int insert_pos, int desde, int hasta);


//FUNCIONES EJERCICIO 13
vector<int> mergesort(const vector<int> & v, int d, int h);
vector<int> merge(const vector<int> &v1, const vector<int> &v2);

//FUNCION EJERCICIO 14
vector<int> mergear_muchos(vector<vector<int>> vs);
vector<int> mergear_muchos_DC(vector<vector<int>> vs, int desde, int hasta);


//FUNCIONES EJERCICIO 15
void quicksort3Mitades(vector<int> &v, int d, int h);
vector<int> dividir(vector<int> &v, int d, int h);






//FUNCIONES CLASE PRÁCTICA -----------------------------------------------------
int geometrica_recursiva(int n, int q);
vector<string> palabrasMasLargas(vector<string> todasLasPalabras, int longitud);
vector<string> palabrasMasLargas_recursiva(vector<string> todasLasPalabras, int longitud, int desde);
bool es_primo(int numero);
int minimoPrimoDesde(int d);
int nEsimoPrimo(int n);
int sumaDeLosNPrimerosPrimos(int n); 


//EJERCICIOS CLASE TEÓRICA
void multiplicar_por_k(vector<int> &v, int d);
int multiplicar_por_k_prod(vector<int> &v, int k, int d, int h);
int hallar_minimo(vector<int> &v);
int hallar_elemento(vector<int> v, int d);



























//MAIN
int main(){
    //Ejercicio 1:
    cout << "EJERCICIO 1: INTRO-RECURSIÓN" << endl;
    cout<< "PROBAMOS es_par: " <<endl;
    int n = -4;
    cout << "Veamos si el número " << n << " es par" << endl;
    cout << es_par(n) << endl;
    cout << endl;
    cout << endl;
    cout << endl;






    //Ejercicio 2:
    cout << "EJERCICIO 2: FUNCIONES RECURSIVAS LINEALES" << endl;
    cout<< "PROBAMOS productoria: " <<endl;
    vector<int> v_int = {1, 2, 2, 4, 5};
    cout << "veamos la productoria de todos los elementos del vector: " <<endl;
    imprimir_vector(v_int);
    cout << productoria(v_int) << endl;
    cout << endl;

    cout<< "PROBAMOS contar_coincidencias: " <<endl;
    vector<string> v_string = {"que", "so", "que", "hola", "hola"};
    string s = "hola";
    cout << "Veamos cuántas veces aparece el string " << "'" << s << "'" <<" en el vector: " <<endl;
    imprimir_vector_strings(v_string);
    cout << cantidad_ocurrencias(s, v_string) << endl;
    cout << endl;

    cout<< "PROBAMOS contar_coincidencias: " <<endl;
    cout << "Veamos cuántas veces aparece el número " << "'i'" << " en la i-ésima posición del vector: " <<endl;
    imprimir_vector(v_int);
    cout << contar_coincidencias(v_int) << endl;
    cout << endl;

    cout<< "PROBAMOS solo_positivos: " <<endl;
    v_int = {-1, 4, 5, 6, -7};
    cout << "dado el vector: ";
    imprimir_vector(v_int);
    cout << "ahora devolvemos el mismo vector pero sin los números que sean negativos: " << endl;
    vector<int> v_int_modificado = solo_positivos(v_int);
    imprimir_vector(v_int_modificado);
    cout << endl;

    cout<< "PROBAMOS multiplicar_todos: " <<endl;
    v_int = {1, 2, 3, 4, 5, 6};
    int x = 2;
    cout <<"dado el vector: ";
    imprimir_vector(v_int);
    cout << "ahora devolvemos el mismo vector con todos sus elementos multiplicados por " << x << ": " << endl;
    multiplicar_todos(v_int, x);
    imprimir_vector(v_int);
    cout << endl;
    cout << endl;
    cout << endl;







    //Ejercicio 3:
    cout << "EJERCICIO 3: FUNCIONES DEL EJERCICIO 2 RE-ESCRITAS CON DIVIDE AND CONQUER" << endl;
    cout<< "PROBAMOS cantidad_ocurrencias CON DIVIDE AND CONQUER:" <<endl;
    cout << "Veamos cuántas veces aparece el string " << "'" << s << "'" <<" en el vector: " <<endl;
    imprimir_vector_strings(v_string);
    cout << cantidad_ocurrencias_DC(s, v_string, 0, v_string.size()) << endl;
    cout << endl;

    cout<< "PROBAMOS multiplicar_todos CON DIVIDE AND CONQUER:" <<endl;
    v_int = {1, 2, 3, 4, 5, 6};;
    cout <<"dado el vector: ";
    imprimir_vector(v_int);
    cout << "ahora devolvemos el mismo vector con todos sus elementos multiplicados por " << x << ": " << endl;
    multiplicar_todos_DC(v_int, x, 0, v_int.size());
    imprimir_vector(v_int);
    cout << endl;
    cout << endl;
    cout << endl;









    //Ejercicio 4:
    cout << "EJERCICIO 4: NUEVAS FUNCIONES CON DIVIDE AND CONQUER" << endl;
    cout<< "PROBAMOS potencia CON DIVIDE AND CONQUER:" <<endl;
    n = 2;
    int m = 0;
    cout << "calculamos: " << n << " elevado a la " << m << " y es igual a: " << potencia(n, m) << endl;
    cout << endl;

    cout<< "PROBAMOS pico_montaña CON DIVIDE AND CONQUER: " <<endl;
    v_int = {-1, 4, 6, 9, 3, 0};
    cout <<"dado el vector montaña: ";
    imprimir_vector(v_int);
    cout << "el pico está en el número: " << pico_montaña(v_int) << endl;
    cout << endl;
    cout << endl;
    cout << endl;







    //Ejercicio 5:
    cout << "EJERCICIO 5: 'FUNCION_MÁS_A_LA_IZQUIERDA' CON DIVIDE AND CONQUER" << endl;
    v_int = {9,8,7,6,5,4,3,10};
    cout<< "El vector: ";
    imprimir_vector(v_int);
    cout << "está más a la izquierda?" << endl;
    cout << "respuesta = " << mas_a_la_izquierda_DC(v_int, 0, v_int.size()) << endl;
    cout << endl;
    cout << endl;
    cout << endl;







    //Ejercicio 7:
    cout << "EJERCICIO 7: FUNCIONES CON DIVIDE AND CONQUER PARTIENDO EN 3 MITADES" << endl;
    v_int = {1,2,3,4,5,6};
    cout << "Dado el vector: ";
    imprimir_vector(v_int);
    cout << "Su sumatoria (dividiendo en 3 mitades) es: " << sumatoria_DC3(v_int, 0, 6) << endl;
    cout << "Y su productoria (dividiendo en 3 mitades) es: " << productoria_DC3(v_int, 0, 6) << endl;


    


   
    


    //Ejercicio 6
    /*
    vector<int> vectorSumar = {-1, 2, -10, 8, 1, -3};
    cout << "Dado el vector: ";
    imprimir_vector(vectorSumar);
    cout << " la sumatoria máxima posible es: " << sublistaSumMax(vectorSumar, 0, vectorSumar.size()) << endl;
    */



    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    //ORDENAMIENTO
    cout << "EJERCICIOS DE ORDENAMIENTO" << endl;
    //Ejercicio 12:
    cout << "EJERCICIO 12: SELECTION SORT & INSTERION SORT" << endl;
    v_int = {59, 7, 388, 41, 2, 280, 50, 123};
    cout << "Dado el vector: ";
    imprimir_vector(v_int);
    cout << "Ahora usamos SELECTION SORT para ordenarlo: " << endl;
    selection_sort(v_int);
    imprimir_vector(v_int);
    cout << endl;

    v_int = {59, 7, 388, 41, 2, 280, 50, 123};
    cout << "Ahora, dado el mismo vector de antes: ";
    imprimir_vector(v_int);cout << "Usamos INSERTION SORT para ordenarlo: " << endl;
    insertion_sort(v_int);
    imprimir_vector(v_int);
    cout << endl;
    cout << endl;
    cout << endl;


    //Ejercicio 14:
    cout << "EJERCICIO 14: MERGEAR MUCHOS" << endl;
    vector<vector<int>> vs = {{1,2,5,9},{6,8,10,11},{-1,6,9}};
    cout << "Dado el vector: ";
    imprimir_vector_de_vector(vs);
    cout << "Ahora usamos MERGEAR MUCHOS para ordenarlo en un único vector: " << endl;
    v_int = mergear_muchos(vs);
    imprimir_vector(v_int);
    cout << endl;
    cout << endl;
    cout << endl;



    //Ejercicio 15:
    cout << "EJERCICIO 15: QUICKSORT CON 2 PIVOTS" << endl;
    v_int = {2,9,200,1000,1,5,60,105,48,180,34};
     cout << "Dado el vector: ";
    imprimir_vector(v_int);
    cout << "Ahora usamos QUICKSORT para ordenarlo (lo hacemos usando 2 pivots): " << endl;
    quicksort3Mitades(v_int, 0, v_int.size());
    imprimir_vector(v_int);
    
    cout << endl;
    cout << endl;
    cout << endl;

























    //EJERCICIOS PRÁCTICA
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "EJERCICIOS EXTRA: CLASE PRÁCTICA" << endl;
    cout << geometrica_recursiva(5,3) <<endl;

    cout << endl;
    vector<string> vector = {"hola", "abcd", "d", "wew", "hola"};
    int longitud = 4;
    cout << "dado el vector: ";
    imprimir_vector_strings(vector);
    cout << " y la longitud " << longitud << " devolvemos un nuevo vector solamente con los elementos del vector original que tienen esa longitud: " <<endl;
    imprimir_vector_strings(palabrasMasLargas(vector, longitud));
    cout << endl;

    cout << es_primo(1) <<endl;
    int numero = 8;
    cout << "el mínimo primo más cercano al " << numero << " es: " << minimoPrimoDesde(numero) << endl;
    cout << endl;

    int nEsimo = 3;
    cout << "el primo número " << nEsimo << " es: " << nEsimoPrimo(nEsimo) << endl;
    cout << endl;

    cout << "la suma de los primeros: " << nEsimo << " es: " << sumaDeLosNPrimerosPrimos(nEsimo) << endl;
    cout << endl;



    return 0;
}


















//DEFINICIÓN DE FUNCIONES 

//FUNCIONES EJERCICIO 1
int fibonacci(int n){
    if(n < 2){
        return 1;
    }else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

bool es_par(int n){
    //Casos Base
    if(n == 1){ //Es impar
        return false;
    }else if(n == 0){ //Es par
        return true;
    //Caso Recursivo    
    }else{
        //Si el número es negativo:
        if(n < 0){
            return es_par(n + 2);
        }else{ //Si es positivo:
            return es_par(n - 2);
        }
    }    
}

//FUNCIONES EJERCICIO 2

//CON DESDE:
/*
int productoria(const vector<int> &v){
    return productoria_aux(v, 0);
}


int productoria_aux(const vector<int> &v, int desde){
    //Caso Base (el vector está completo)
    if(desde == v.size()){
        return 1;
    //Caso Recursivo    
    }else{
        int aux = productoria_aux(v, desde+1);
        return v[desde]*aux;
    }
}
*/

//CON HASTA:
int productoria(const vector<int> &v){
    return productoria_aux(v, v.size()-1);
}
int productoria_aux(const vector<int> &v, int hasta){
    //Caso Base (el vector está completo)
    if(hasta == 0){
        return v[hasta];
    //Caso Recursivo    
    }else{
        int aux = productoria_aux(v, hasta-1);
        return v[hasta]*aux;
    }
}







int cantidad_ocurrencias(string s, const vector<string> &v){
    return cantidad_ocurrencias_aux(s, v, v.size()-1);
}

int cantidad_ocurrencias_aux(string s, const vector<string> &v, int hasta){
    //Casos Base
    if(hasta == 0 && v[hasta] == s){ //El primer elemento es "s"
        return 1;
    }else if (hasta == 0 && v[hasta] != s){ //El primer elemento no es "s"
        return 0;
    //Caso Recursivo    
    }else{
        int aux = cantidad_ocurrencias_aux(s, v, hasta-1); //llamado recursivo (reducimos el vector en 1)
        return (v[hasta] == s) +aux; //vemos si la posición actual en la que estamos se encuentra el string y le sumamos las recursiones anteriores
    }  
}



int contar_coincidencias(const vector<int> &v){
    return contar_coincidencias_aux(v, v.size());
}

int contar_coincidencias_aux(const vector<int> &v, int hasta){
     //Casos Base
    if(hasta == 0 && v[hasta] == hasta){ //El elemento 0 es un 0
        return 1;
    }else if (hasta == 0 && v[hasta] != hasta){ //El elemento 0 no es 0
        return 0;
    //Caso Recursivo    
    }else{
        int aux = contar_coincidencias_aux(v, hasta-1); //llamado recursivo (reducimos el vector en 1)
        return (v[hasta] == hasta) +aux; //vemos si la i-ésima en la que estamos se encuentra el int "i" y le sumamos las recursiones anteriores
    }      
}




vector<int> solo_positivos(const vector<int> &v){
    return solo_positivos_aux(v, v.size());
}

vector<int> solo_positivos_aux(const vector<int> &v, int hasta){
    vector<int> v1 = {};
    //Casos Base
    if(hasta == 0 && v[hasta] >= 0){ //El primer elemento es positivo
        v1.push_back(v[hasta]);
        return v1;
    }else if( hasta == 0 && v[hasta] < 0){ //El primer elemento es negativo
        return v1;
    //Caso Recursivo    
    }else{
        vector<int> aux = solo_positivos_aux(v, hasta-1);
        if (v[hasta] >= 0){
            aux.push_back(v[hasta]);
            return aux;
        }else{
            return aux;
        }
    }
}



void multiplicar_todos(vector<int> &v, int n){
    return multiplicar_todos_aux(v, n, 0);
}

void multiplicar_todos_aux(vector<int> &v, int n, int desde){
    //CASO BASE
    if (desde == v.size()){ //Si el vector se queda con 1 solo elemento (el primero):lo multiplicamos por n
        return;
    }else{
    //CASO RECURSIVO    
        v[desde] = v[desde]*n;
        return multiplicar_todos_aux(v, n, desde+1);
    }
}





//FUNCIONES EJERCICIO 3:

int cantidad_ocurrencias_DC(string s, const vector<string> &v, int desde, int hasta){
    //CASO BASE
    if(hasta <= desde){ //Caso: vector vacío
        return 0;
    }else if(desde == hasta-1){//Caso: "desde" es el anteúltimo elemento y "hasta" es el último elemento. Ponemos nuestro enfoque en el elemento "desde"
        return (v[desde] == s);
        
    }else{
        //CASO RECURSIVO: Divide and Conquer System:
        int medio = (desde+hasta)/2;
        int mitad1 = cantidad_ocurrencias_DC(s, v, desde, medio);
        int mitad2 = cantidad_ocurrencias_DC(s, v, medio, hasta);
        return mitad1 + mitad2;
    }
}



void multiplicar_todos_DC(vector<int> &v, int n, int desde, int hasta){
    //CASOS BASE
    if (hasta <= desde){//Caso: vector vacío
        return;
    }
    if (desde == hasta-1){ //Si el vector se queda con 1 solo elemento (el primero):lo multiplicamos por n
        v[desde] = v[desde]*n;
        
    }else{
    //CASO RECURSIVO
        int medio = (desde+hasta)/2;    
        multiplicar_todos_DC(v, n, desde, medio);
        multiplicar_todos_DC(v, n, medio, hasta);
    }
}





//FUNCIONES EJERCICIO 4
int potencia(int n, int m){
    return potencia_DC(n, m, 1, m+1);
}

int potencia_DC(int n, int m, int desde, int hasta){
    //CASOS BASE 
    if(m == 0){
        return 1;
    }else if(desde == hasta-1){
        return n;
    }else{
        //CASO RECURSIVO
        int medio = (desde+hasta)/2;
        int mitad1 = potencia_DC(n, m, desde, medio);
        int mitad2 = potencia_DC(n, m, medio, hasta);
        return mitad1*mitad2;
    } 
}



int pico_montaña(vector<int> v){
    return pico_montaña_DC(v, 0, v.size());
}

int pico_montaña_DC(vector<int> v, int desde, int hasta){
    if(hasta <= desde){
        return 0;
    }else if(desde == hasta-1){
        return v[desde];
    }else{
        int medio = (desde+hasta)/2;
        int mitad1 = pico_montaña_DC(v, desde, medio);
        int mitad2 = pico_montaña_DC(v, medio, hasta);
        return max(mitad1, mitad2);
    }
}



//FUNCION EJERCICIO 5





int suma_aux(const vector<int> &v, int desde, int hasta){
    if(desde == hasta){
        return 0;
    }else{
        return v[desde] + suma_aux(v, desde+1, hasta);
    }
}
int mas_a_la_izquierda_DC(vector<int> v, int desde, int hasta){
    if(desde == hasta-1){
        return true;
    }else{
        int medio = (desde+hasta)/2;
        int suma_inf = suma_aux(v, desde, medio);
        int suma_pos = suma_aux(v, medio, hasta);
        bool bool_inf = mas_a_la_izquierda_DC(v, desde, medio);
        bool bool_pos = mas_a_la_izquierda_DC(v, medio, hasta);

        return suma_inf > suma_pos && bool_inf && bool_pos;
    }
}
















//EJERCICIO 7

int sumatoria_DC3(const vector<int> & v, int desde, int hasta){
    if(hasta <= desde){
        return 0;
    }else if(desde == hasta-1){
        return v[desde];
    }else if(desde==hasta-2){
        return v[desde]+v[hasta-1];
    }else{
        int tercio = (desde+hasta)/3;
        int inferior = sumatoria_DC3(v, desde, desde+tercio);
        int medio = sumatoria_DC3(v, desde+tercio, desde+2*tercio);
        int superior = sumatoria_DC3(v, desde+2*tercio, hasta);
        return inferior+medio+superior;
    }
}



int productoria_DC3(const vector<int> & v, int desde, int hasta){
       if(hasta <= desde){
        return 0;
    }else if(desde == hasta-1){
        return v[desde];
    }else if(desde==hasta-2){
        return v[desde]*v[hasta-1];
    }else{
        int tercio = (desde+hasta)/3;
        int inferior = productoria_DC3(v, desde, desde+tercio);
        int medio = productoria_DC3(v, desde+tercio, desde+2*tercio);
        int superior = productoria_DC3(v, desde+2*tercio, hasta);
        return inferior*medio*superior;
    }
}
















//FUNCIONES EJERCICIO 6
/*
int potencia(int n, int m){
    return potencia_aux(n, m, 0, m);
}

int potencia_aux(int n, int m){
    //CASO BASE
    if(m==0){
        return 1; 
    }else if(m==1){
        return n;
    }else{
        //CASO RECURSIVO
        int izq=potencia(n, m/2);
        int der=potencia(n, n/2);
        return izq*der;
    }
}
*/

//Recorre todas las posibles sublistas
    /*
    int i=0;
    while(i < v.size()){
        j=i+1;
        while(j < v.size()){
            //suma i hasta j
            j++;
        }
        i++;
    }
    */

//FUNCIÓN EJERCICIO 6
/*
int sublistaSumMax(vector<int> v, int d, int h){
    //CASOS BASE
    if(h <= d){ 
        return;
    }
    else if(d == h-1){
        return v[d];
    }else{
   //CASO RECURSIVO 
   //DIVIDE AND CONQUER SYSTEM:
    int med = (d+h)/2; 

    //llamados recursivos
    sublistaSumMax(v, d, med);
    sublistaSumMax(v, med, h); 
    }
}
*/








//FUNCIONES EJERCICIO 12:



void selection_sort(vector<int> &v){
    int i = 0;
    while(i < v.size()){
        int minimo_global = buscar_minimoPos(v, i, v.size());
        swap(v, minimo_global, i);
        i++;
    }
}


void insertion_sort(vector<int> &v){
    int i = 0;
    while (i < v.size()){
        int next_insertion_pos = i;
        insertion(v, v[next_insertion_pos], next_insertion_pos, 0, i);
        i++;
    }
}


//extra:
void swap(vector<int> &v, int x, int y){
    //DADO UN VECTOR, SWAPPEA LAS POSICIONES x E y
    int elemento1 = v[x];
    v[x] = v[y];
    v[y] = elemento1;
}

int buscar_minimoPos(vector<int> v, int desde, int hasta){
    //BUSCA EL MÍNIMO DE UN VECTOR ENTRE LAS POISICONES "desde" Y "hasta"; Y DEVUELVE LA POSICIÓN DEL MINIMO
    int minimo_pos = desde;
    while(desde < hasta){
        if(v[desde] < v[minimo_pos]){
            minimo_pos = desde;
        }
        desde++;
    }
    return minimo_pos;
}

//VERSION 1 DE INSERTION (CON SWAP)

void insertion(vector<int> &v, int insert, int insert_pos, int desde, int hasta){
    //DADO UN VECTOR, ENTRE LAS POSICIONES "desde" Y "hasta", RECORREMOS DESDE "hasta" HASTA "desde" (ITERAMOS AL REVÉS) Y VAMOS SWAPPEANDO "insert" ASI: "insert_pos" CON LA POSICIÓN ACTUAL: "v[i]" HASTA QUE "v[i]" ya no sea mayor a "insert"
    if (desde == hasta){
        return;
    }
    int i = hasta-1;
    while (hasta > desde && insert < v[i]){
        swap(v, i, insert_pos);
        i --;
        hasta--;
        insert_pos--;
    }
}


//VERSION 2 DE INSERTION (CON ITERADORES E INSERT)
/*SIN TERMINAR
void insertion(vector<int> &v, int insert, int insert_pos, int desde, int hasta){
    //DADO UN VECTOR, ENTRE LAS POSICIONES "desde" Y "hasta", RECORREMOS DESDE "hasta" HASTA "desde" (ITERAMOS AL REVÉS) Y VAMOS SWAPPEANDO "insert" ASI: "insert_pos" CON LA POSICIÓN ACTUAL: "v[i]" HASTA QUE "v[i]" ya no sea mayor a "insert"
    if (desde == hasta){
        return;
    }
    int i = hasta-1;
    vector<int>::iterator it = v.begin() + insert_pos;
    while (hasta > desde && insert < v[i]){
        it--;
        i --;
        hasta--;
        insert_pos--;
    }
    v.insert(it, insert);
}
*/

//FUNCIONES EJERCICIO 13:

vector<int> mergesort(const vector<int> & v, int d, int h){
    if(h - d == 0){
        return {};
    }else if(h - d == 1){
        return {v[d]};
    }else;
        int med = (d+h)/2;
        vector<int> izq = mergesort(v, d, med);
        vector<int> der = mergesort(v, med, h);
        return merge(izq, der);
}

vector<int> merge(const vector<int> &v1, const vector<int> &v2){
    vector<int> res;
    int i = 0;
    int j = 0;
    while(i < v1.size() && j<v2.size()){
        if(v1[i] < v2[j]){
            res.push_back(v1[i]);
            i++;
        }else{
            res.push_back(v2[j]);
            j++;
        }
    }
    while(i < v1.size()){
        res.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()){
        res.push_back(v2[j]);
        j++;
    }
    return res;
}




//FUNCION EJERCICIO 14
vector<int> mergear_muchos(vector<vector<int>> vs){
    return mergear_muchos_DC(vs, 0, vs.size());    
}

vector<int> mergear_muchos_DC(vector<vector<int>> vs, int d, int h){
    if(h - d == 0){
        return {};
    }else if(h - d == 1){
        return {vs[d]};
    }else;
        int med = (d+h)/2;
        vector<int> izq = mergear_muchos_DC(vs, d, med);
        vector<int> der = mergear_muchos_DC(vs, med, h);
        return merge(izq, der);
}        




//FUNCIONES EJERCICIO 15
void quicksort3Mitades(vector<int> &v, int d, int h){
    if(d < h-1){
        vector<int> pivots = dividir(v, d, h);
        quicksort3Mitades(v, d, pivots[0]);
        quicksort3Mitades(v, pivots[0]+1, pivots[1]);
        quicksort3Mitades(v, pivots[1]+1, h);
    }
}

vector<int> dividir(vector<int> &v, int d, int h){
    vector<int> res;
    if(v[h-2] > v[h-1]){
        swap(v, h-2, h-1);
    }
    int pivot1 = v[h-2];
    int pivot2 = v[h-1];
    int i = d;
    for(int j = d; j < h-2; j++){
        if(v[j] <= pivot1){
            swap(v, i, j);
            i++;
        }
    }
    swap(v, i, h-2);
    res.push_back(i);
    i++;
    for(int j = i; j < h-1; j++){
        if(v[j] <= pivot2){
            swap(v, i, j);
            i++;
        }
    }
    swap(v, i, h-1);
    res.push_back(i);
    return res;
}











//FUNCIONES CLASE PRÁCTICA

int geometrica_recursiva(int n, int q){
    //Caso base
    if(n <= 0){
        return 1;
    }else{
        //Caso Recursivo
        int aux = geometrica_recursiva(n-1, q);
        return pow(q, n)+aux;
    }
}

vector<string> palabrasMasLargas(vector<string> todasLasPalabras, int longitud){
    return palabrasMasLargas_recursiva(todasLasPalabras, longitud, todasLasPalabras.size());
}

vector<string> palabrasMasLargas_recursiva(vector<string> todasLasPalabras, int longitud, int hasta){
        vector<string> v1 = {};
    //Casos Base
    if(hasta == 0 && todasLasPalabras[hasta].length() == longitud){ 
        v1.push_back(todasLasPalabras[hasta]);
        return v1;
    }else if( hasta == 0 && todasLasPalabras[hasta].length() < 0){ 
        return v1;    
    }else{
        vector<string> aux = palabrasMasLargas_recursiva(todasLasPalabras, longitud, hasta-1);
        if (todasLasPalabras[hasta].length() == longitud){
            aux.push_back(todasLasPalabras[hasta]);
            return aux;
        }else{
            return aux;
        }
    }
}

bool es_primo(int numero){
    if (numero<2){
        return false;
    }
    bool respuesta = false;
    int i = 2;
    int contador_divisores = 0;
    while(i<numero){
        if(numero%i == 0){
            contador_divisores++;
        }
        i++;    
    }
    if(contador_divisores == 0){
        respuesta = true;
    }
    return respuesta;
}
int minimoPrimoDesde(int d){
    //Caso Base
    if(es_primo(d) == true){
        return d;
    }else{
        //Caso Recursivo
        return minimoPrimoDesde(d+1);
    }
}

int nEsimoPrimo(int n){
    if(n == 1){
        return minimoPrimoDesde(n);
    }else{
        return minimoPrimoDesde(nEsimoPrimo(n-1)+1);
    }
}

int sumaDeLosNPrimerosPrimos(int n){
        //Caso Base (el vector está completo)
    if(n == 0){
        return 0;
    //Caso Recursivo    
    }else{
        int aux = sumaDeLosNPrimerosPrimos(n-1);
        return nEsimoPrimo(n)+aux;
    }
}


//EJERCICIOS TEÓRICA

void multiplicar_por_k(vector<int> &v, int k, int d, int h){
//multiplica al vector de entrada por k 
    //CASOS BASE
    if(h <= d){ //no hay ningún rango para multiplicar ni hacer nada
        return;
    }
    else if(d == h-1){//si estamos mirando un vector donde el ante último es "Desde" y el último es "hasta". Estamos enfocando al elemento en el que está "Desde".Otra forma de decirlo "h=d+1" h y d están "al lado"
        v[d] = v[d]*k; //multiplicamos a ese primer valor por k
    }else{
   //CASO RECURSIVO 
   //(si hicieramos recursion lineal, hariamos multiplicar_por_k_prod(v, k, d+1)) y chau, en cada llamado vamos recortando el vector)

   //DIVIDE AND CONQUER SYSTEM:
    int med = (d+h)/2; //idea: partir el vector en 2, y hacer recursión de un lado y del otro. Med me indica en donde se parte. También funciona si el vector no tiene longitud par

    //llamados recursivos
    multiplicar_por_k(v, k, d, med);
    multiplicar_por_k(v, k, med, h); //en el segundo, med no está incluído
    }
}


int multiplicar_por_k_prod(vector<int> &v, int k, int d, int h){
//multiplica al vector de entrada por k y devolver la productoria de multiplicar a los elementos del vector original
    //CASOS BASE
    if(h <= d){ //no hay ningún rango para multiplicar ni hacer nada
        return 1;
    }
    else if(d == h-1){//si estamos mirando un vector donde el ante último es "Desde" y el último es "hasta". Estamos enfocando al elemento en el que está "Desde".Otra forma de decirlo "h=d+1" h y d están "al lado"
        int aux = v[d]; //me guardo el elemento original en una nueva variable
        v[d] = v[d]*k; //multiplicamos a ese primer valor por k
        return aux; //devolvemos el elemento original (lo necesitamos para la productoria)
    }
    else{
   //CASO RECURSIVO 
   //(si hicieramos recursion lineal, hariamos multiplicar_por_k_prod(v, k, d+1)) y chau, en cada llamado vamos recortando el vector)

   //DIVIDE AND CONQUER SYSTEM:
    int med = (d+h)/2; //idea: partir el vector en 2, y hacer recursión de un lado y del otro. Med me indica en donde se parte. También funciona si el vector no tiene longitud par

    //llamados recursivos (como ahora devuelven algo, podemos guardar eso en un INT)
    int a = multiplicar_por_k_prod(v, k, d, med); 
    int b = multiplicar_por_k_prod(v, k, med, h); //en el segundo, med no está incluído

    //Como tenemos que devolver la productoria, hay que COMBINAR los dos llamados recursivos 
    return a*b; //
    }
}



















