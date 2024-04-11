//GUÍA 3 (Funciones con ciclos)


#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <set>
#include <map>



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

//FUNCIONES EJERCICIO 3
bool todos_positivos(vector<int> vec){
    bool res = true;
    int i = 0;

    while(i < vec.size()){
        if(vec[i]<0){
            res = false;
        }
        i++;
    }

    return res; 
}

bool no_contiene_equis(string str){
    bool res = true;
    int i = 0;

    while(i < str.size()){
        if(str[i] == 'x'){
            res = false;
        }
        i++;
    }

    return res;
}

//FUNCIONES EJERCICIO 6

void sumar_n(vector<int> &ls, int n){
    int i = 0;

    while(i < ls.size()){
        ls[i] = ls[i] + n;
        i++;
    }

} 

int suma_y_reset(vector<int> &v){
    int i = 0;
    int res = 0;

    while(i < v.size()){
        res = res + v[i];
        v[i] = 0;
        i++;
    }

    return res;
}

//MAIN
int main(){
    vector<int> positivosNegativos = {1,4,2,5};
    imprimir_vector(positivosNegativos);
    cout << todos_positivos (positivosNegativos) <<endl;


    string x = "hfjd";
    cout << x << endl;
    cout << no_contiene_equis(x) <<endl;


    vector<int> prueba = {1, 9, 7, 7};
    sumar_n(prueba, 10);
    imprimir_vector(prueba);
    cout << suma_y_reset(prueba) <<endl;
    imprimir_vector(prueba);

    return 0;
}
















