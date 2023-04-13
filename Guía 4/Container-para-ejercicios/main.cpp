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
int productoria(const vector<int> &v, int desde);
int cantidad_ocurrencias(string s, const vector<string> &v, int hasta);
int contar_coincidencias(const vector<int> &v, int hasta);
vector<int> solo_positivos(const vector<int> &v, int hasta);

//FUNCIONES CLASE PRÁCTICA
int geometrica_recursiva(int n, int q);
vector<string> palabrasMasLargas(vector<string> todasLasPalabras, int longitud);
vector<string> palabrasMasLargas_recursiva(vector<string> todasLasPalabras, int longitud, int desde);
bool es_primo(int numero);
int minimoPrimoDesde(int d);
int nEsimoPrimo(int n);
int sumaDeLosNPrimerosPrimos(int n); 

//MAIN
int main(){
    //Ejercicio 1:
    int n = -4;
    cout << "Veamos si el número " << n << " es par" << endl;
    cout << es_par(n) << endl;


    //Ejercicio 2:
    vector<int> v1 = {1, 2, 2, 4, 5};
    int desde1 = 0;
    cout << "A partir de la posición " << desde1 << " veamos la productoria de todos los elementos del vector: " <<endl;
    imprimir_vector(v1);
    cout << productoria(v1, desde1) << endl;

    vector<string> v2 = {"que", "so", "que", "hola", "hola"};
    string s = "hola";
    int hasta1 = v2.size()-1;
    cout << "Hasta la posición " << hasta1 << " veamos cuántas veces aparece el string " << "'" << s << "'" <<" en el vector: " <<endl;
    imprimir_vector_strings(v2);
    cout << cantidad_ocurrencias(s, v2, hasta1) << endl;

    int hasta2 = v1.size()-1;
    cout << "Hasta la posición " << hasta2 << " veamos cuántas veces aparece el número " << "'i'" << " en la i-ésima posición del vector: " <<endl;
    imprimir_vector(v1);
    cout << contar_coincidencias(v1, hasta2) << endl;

    vector<int> v3 = {-1, 4, 5, 6, -7};
    int hasta3 = v3.size()-1;
    cout << "dado el vector: ";
    imprimir_vector(v3);
    cout << " ahora devolvemos el mismo vector pero sin los números que sean negativos: " << endl;
    vector<int> v3_modificado = solo_positivos(v3, hasta3);
    imprimir_vector(v3_modificado);

    //EJERCICIOS PRÁCTICA
    cout << geometrica_recursiva(5,3) <<endl;


    vector<string> vector = {"hola", "abcd", "d", "wew", "hola"};
    int longitud = 4;
    cout << "dado el vector: ";
    imprimir_vector_strings(vector);
    cout << " y la longitud " << longitud << " devolvemos un nuevo vector solamente con los elementos del vector original que tienen esa longitud: " <<endl;
    imprimir_vector_strings(palabrasMasLargas(vector, longitud));

    cout << es_primo(1) <<endl;
    int numero = 8;
    cout << "el mínimo primo más cercano al " << numero << " es: " << minimoPrimoDesde(numero) << endl;

    int nEsimo = 3;
    cout << "el primo número " << nEsimo << " es: " << nEsimoPrimo(nEsimo) << endl;

    cout << "la suma de los primeros: " << nEsimo << " es: " << sumaDeLosNPrimerosPrimos(nEsimo) << endl;

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
int productoria(const vector<int> &v, int desde){
    //Caso Base (el vector está completo)
    if(desde == v.size()){
        return 1;
    //Caso Recursivo    
    }else{
        int aux = productoria(v, desde+1);
        return v[desde]*aux;
    }
}

int cantidad_ocurrencias(string s, const vector<string> &v, int hasta){
    //Casos Base
    if(hasta == 0 && v[hasta] == s){ //El primer elemento es "s"
        return 1;
    }else if (hasta == 0 && v[hasta] != s){ //El primer elemento no es "s"
        return 0;
    //Caso Recursivo    
    }else{
        int aux = cantidad_ocurrencias(s, v, hasta-1); //llamado recursivo (reducimos el vector en 1)
        return (v[hasta] == s) +aux; //vemos si la posición actual en la que estamos se encuentra el string y le sumamos las recursiones anteriores
    }  
}

int contar_coincidencias(const vector<int> &v, int hasta){
     //Casos Base
    if(hasta == 0 && v[hasta] == hasta){ //El elemento 0 es un 0
        return 1;
    }else if (hasta == 0 && v[hasta] != hasta){ //El elemento 0 no es 0
        return 0;
    //Caso Recursivo    
    }else{
        int aux = contar_coincidencias(v, hasta-1); //llamado recursivo (reducimos el vector en 1)
        return (v[hasta] == hasta) +aux; //vemos si la i-ésima en la que estamos se encuentra el int "i" y le sumamos las recursiones anteriores
    }      
}

vector<int> solo_positivos(const vector<int> &v, int hasta){
    vector<int> v1 = {};
    //Casos Base
    if(hasta == 0 && v[hasta] >= 0){ //El primer elemento es positivo
        v1.push_back(v[hasta]);
        return v1;
    }else if( hasta == 0 && v[hasta] < 0){ //El primer elemento es negativo
        return v1;
    //Caso Recursivo    
    }else{
        vector<int> aux = solo_positivos(v, hasta-1);
        if (v[hasta] >= 0){
            aux.push_back(v[hasta]);
            return aux;
        }else{
            return aux;
        }
    }
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



















