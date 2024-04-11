#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>




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

//estructura<tipo>::iterator HOLA


//EJERCICIO 1: FACTURAS DE RAPIPAGO
int atender_rapipago(queue<int> fila_facturas){
    int factura_actual;
    int cantidad_atendi = 0;
    while(!fila_facturas.empty()){
        factura_actual = fila_facturas.front();
        fila_facturas.pop();
        cantidad_atendi++;
        if(factura_actual > 2){
            factura_actual = factura_actual - 2;
            fila_facturas.push(factura_actual);
        }
    }    
    return cantidad_atendi;
}


bool madera_valida(tuple<float,float> madera){
    bool res = false;
    if(1.5 <= get<1>(madera) && get<1>(madera) <= 3){
        res = true;
    }
    return res;
}

int suma_maderas_validas(multiset<tuple<float,float>> camion){
    int res = 0;
    //auto it = camion.begin();
    multiset<tuple<float,float>>::iterator it;
    it = camion.begin();
    while(it != camion.end()){
        if(madera_valida(*it)){
            res = res + get<0>(*it);
        }
    it++;    
    }
    return res;
}

/*
bool todos_balanceados(string cadena){
    bool res = false;
    stack<char> pilaParentesis;
    stack<char> pilaCorchete;
    int i = 0;
    while(i < cadena.size()){
        if(cadena[i] == '['){
            pilaCorchete.push('[');
        }
        if(cadena[i] == '('){
            pilaParentesis.push('(');
        }    
        if(pilaCorchete.top() == ']' ){
            if(pilaCorchete.size() > 0){
                pilaCorchete.pop();
            }
        }
        if(pilaParentesis.top() == ')'){
            if(pilaParentesis.size() > 0){
                pilaParentesis.pop();
            }
        }
        i++;
    }
    if(pilaParentesis.size() == 0 && pilaCorchete.size() == 0){
        res = true;
    }
    return res;
}


//MAIN
int main(){
    
    string xd = "[a(s))vb";
    cout << todos_balanceados(xd) << endl;
    
    return 0;
}


*/


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

// Nodo de un arbol binario
struct nodo {
   int elem;
   nodo *izq, *der;
};

// Descompone N en un arbol de divisores
nodo* descomponer(int N) {
  // Pre: N>1
  nodo* raiz = new nodo({N, nullptr, nullptr});
  int i = 2;
  while(i < N && N % i != 0){
    i++;
  }
  if(i == N){
    return raiz; 
  }
  else{
      raiz->izq = descomponer(i); //El primo que encontré que lo divide
      raiz->der = descomponer(N/i); //quiero hacer la recursión y seguir descomponiendo
      //i*N/i = N 
      return raiz;
  } 
}

void print_inorder(nodo* n) {
    if (n == nullptr) return;

    print_inorder(n->izq);
    std::cout << n->elem << " ";
    print_inorder(n->der);
}

void destruir(nodo* n) {
    if (n == nullptr) return;
    destruir(n->izq);
    destruir(n->der);
    delete n;
}

  int main() {
      nodo* raiz = descomponer(2310);
      cout << "inorder: ";
      print_inorder(raiz);
      destruir(raiz);
  }













