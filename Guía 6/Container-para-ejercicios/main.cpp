//GUÍA 6
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>


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


template <typename T>

//CLASES:


//EJERCICIO 1:
class Pila {

 public:
    Pila();
    bool es_vacia() const;
    const T& tope() const;
    void apilar(T elem);
    void desapilar();

 private:
    list<T> elementos;
    //REP: -es_vacia()=True <=> |_elementos|=0
    //     -tope() es igual al último elemento insertado al final de la pila <=> es_vacia()=True
};

template <typename T>



//IMPLEMENTACIÓN: 
Pila<T>::Pila() {
}

template <typename T>
bool Pila<T>::es_vacia() const {
    if(this->elementos.empty()){
        return true;
    }else{
        return false;
    }
}

template <typename T>
const T& Pila<T>::tope() const {
    auto it = this->elementos.begin();
    while(it != this->elementos.end()){
        it++;
    }
    it--;
    return *it;
}

template <typename T>
void Pila<T>::apilar(T elem) {
    this->elementos.push_back(elem);
}

template <typename T>
void Pila<T>::desapilar() {
    auto it = this->elementos.begin();
    while(it != this->elementos.end()){
        it++;
    }
    it--;
    this->elementos.erase(it);
}








//EJERCICIO 2:
class FilaDeSuper{
 public:
    FilaDeSuper();
        // POST: La FilaDeSuper es vacía y sus cajas están libres.
    int cantidad_esperando() const;
    string siguiente() const;
    bool esta_ocupada(int caja) const;
        // PRE: caja es igual a 1 o 2.
    void llega_persona(string dni);
        // PRE: dni es un dni válido
        // POST: El dni se agrega al final de la fila
    void atender_siguiente(int caja);
        // PRE: caja es igual a 1 o 2, cantidad_esperando() no es 0 y esta_ocupada(caja) es false.
        // POST: Se quita de la fila a la siguiente() persona que estaba esperando.
        // Y esta_ocupada(caja) se vuelve true.
    void liberar_caja(int caja);
        // PRE: caja es igual a 1 o 2, esta_ocupada(caja) es true.
        // POST: esta_ocupada(caja) se vuelve false.
 private:
    queue<string> fila_de_espera;
    bool caja_uno_ocupada;
    bool caja_dos_ocupada;
    //REP: -caja_uno_ocupada = True <=> se llamó a atender_siguiente(1)
    //     -idem para caja_dos_ocupada
    //     -fila_de_espera es una cola en la que esperan las personas mientras las 2 cajas están ocupadas
    //     -|fila_de_espera|=(#veces que se llamó a llega_persona(string DNI)) - (#veces que se llamó a atender_siguiente(int caja))
};

//IMPLEMENTACIÓN:

FilaDeSuper::FilaDeSuper(){
    // POST: La FilaDeSuper es vacía y sus cajas están libres.
    this->caja_uno_ocupada = false;
    this->caja_dos_ocupada = false;
 }


int FilaDeSuper::cantidad_esperando() const{
    return this->fila_de_espera.size();
}


string FilaDeSuper::siguiente() const{
    return this->fila_de_espera.front();
}


bool FilaDeSuper::esta_ocupada(int caja) const{
     // PRE: caja es igual a 1 o 2.
     if(caja == 1){
         return this->caja_uno_ocupada;
     }else{
         return this->caja_dos_ocupada;
     }
}
   

void FilaDeSuper::llega_persona(string dni){
    // PRE: dni es un dni válido
    // POST: El dni se agrega al final de la fila
    this->fila_de_espera.push(dni);
}    


void FilaDeSuper::atender_siguiente(int caja){
    // PRE: caja es igual a 1 o 2, cantidad_esperando() no es 0 y esta_ocupada(caja) es false.
    // POST: Se quita de la fila a la siguiente() persona que estaba esperando.
    // Y esta_ocupada(caja) se vuelve true.
    this->fila_de_espera.pop();
    if(caja == 1){
        this->caja_uno_ocupada = true;
    }else{
        this->caja_dos_ocupada = true;
    }
}  


void FilaDeSuper::liberar_caja(int caja){
    // PRE: caja es igual a 1 o 2, esta_ocupada(caja) es true.
    // POST: esta_ocupada(caja) se vuelve false.
    if(caja == 1){
        this->caja_uno_ocupada = false;
    }else{
        this->caja_dos_ocupada = false;
    }
}    









//EJERCICIO 3:
template <typename T1, typename T2>
// Asumir que el tipo T1 tiene operador de igualdad ==
class Diccionario{
 public:
    Diccionario();
        // POST: El diccionario está vacío.
    bool esta_definida(T1 clave) const;
        // PRE: Verdadero
    const T2 & obtener_valor(T1 clave) const;
        // PRE: esta_definida(clave)
    void definir(T1 clave, T2 valor);
        // PRE: Verdadero
        // POST: esta_definida(clave) es verdadero y obtener_valor(clave)
        // es igual a valor. El resto del diccionario se mantiene igual.
    void borrar(T1 clave);
        // PRE: esta_definida(clave)
        // POST: esta_definida(clave) es falso. El resto del diccionario
        // se mantiene igual.
    void actualizar_ultimo(T2 valor);    
 private:
    list< pair<T1,T2> > claves_valores;
    typename list< pair<T1,T2> >::iterator iterador_al_ultimo;
    //REP: -Para toda clave en claves_valores => esta_definida(clave) = true
    //     -Para toda clave en claves_valores => obtener_valor(clave) = el valor asociado a esa clave (hablando de un mismo par)
};




//IMPLEMENTACION: 
template <typename T1, typename T2>
Diccionario<T1,T2>::Diccionario(){
    // POST: El diccionario está vacío.
    this->iterador_al_ultimo=this->claves_valores.end();
}



template <typename T1, typename T2>
bool Diccionario<T1,T2>::esta_definida(T1 clave) const{
    // PRE: Verdadero
    auto it = this->claves_valores.begin();
    while(it != this->claves_valores.end()){
        if(it->first == clave){
            return true;
        }
        it++;
    }
    return false;
}    



template <typename T1, typename T2>
const T2 & Diccionario<T1,T2>::obtener_valor(T1 clave) const{
    // PRE: esta_definida(clave)
    auto it = this->claves_valores.begin();
    while(it->first != clave){
        it++;
    }
    return it->second;
}



template <typename T1, typename T2>
void Diccionario<T1,T2>::definir(T1 clave, T2 valor){
    // PRE: Verdadero
    // POST: esta_definida(clave) es verdadero y obtener_valor(clave)
    // es igual a valor. El resto del diccionario se mantiene igual.
    this->claves_valores.push_back({clave,valor});
    this->iterador_al_ultimo = prev(this->claves_valores.end());
}



template <typename T1, typename T2>
void Diccionario<T1,T2>::borrar(T1 clave){
    // PRE: esta_definida(clave)
    // POST: esta_definida(clave) es falso. El resto del diccionario
    // se mantiene igual.
    auto it = this->claves_valores.begin();
    while(it->first != clave){
        it++;
        if (!this->claves_valores.empty()) {
                this->iterador_al_ultimo = prev(this->claves_valores.end());
            } else {
                this->iterador_al_ultimo = this->claves_valores.end();
            }
    }
    this->claves_valores.erase(it);
}


template <typename T1, typename T2>
void Diccionario<T1,T2>::actualizar_ultimo(T2 valor){
    auto it = this->claves_valores.begin();
    while(it->first != this->iterador_al_ultimo->first){
        it++;
    }
    it->second = valor;
}





//EJERCICIO 6:
struct arbol_binario{
    int valor;
    arbol_binario* izq;
    arbol_binario* der;
};

void imprimir_arbol(arbol_binario* abb, int cont){
    if(abb == nullptr){
        return;
    }else{
        imprimir_arbol(abb->der, cont+1);
        for(int i=0; i<cont; i++){
            cout << "   " ;
        }
        cout << abb->valor << endl;
        imprimir_arbol(abb->izq, cont+1);
    }
}


bool verificar_abb(const arbol_binario* raiz){
    if(raiz == nullptr){
        return true;
    }else if(raiz->izq < raiz->der){
        return false;
    }else if(raiz->izq > raiz->der){
        return true;
    }else{
        return verificar_abb(raiz->izq) && verificar_abb(raiz->der);
    }
}


bool verificar_max_heap(const arbol_binario* raiz){
    if(raiz == nullptr){ //CASO: ARBOL VACÍO
        return true;
    }else if(raiz && raiz->der == nullptr && raiz->izq == nullptr){ //CASO LLEGAMOS A UNA HOJA
        return true;
    }else if((raiz->izq == nullptr) && (raiz->der)){ //CASO: EL ARBOL NO ES IZQUIERDISTA (hay hijo derecho pero no hay hijo izquierdo)
        return false;
    }else if(raiz->valor < raiz->der->valor || raiz->valor < raiz->izq->valor){ //CASO el padre no es mayor que los hijos
        return false;
    }else{
        //if((raiz->izq) && (raiz->der) && (raiz > raiz->der) && (raiz > raiz->izq)){
            return verificar_max_heap(raiz->izq) && verificar_max_heap(raiz->der);
        //}
    }
}


//EXTRA (PRÁCTICA HEAP)
vector<int> _heap;
    //REP: -_heap[i] >= _heap[2*i+1] and _heap[i] >= _heap[2*i+2]
    //     para todo 0 <= i < (_heap.size()-1)/2


int padre(int pos){
    return (pos-1)/2;
}

int hijo_izq(int pos){
    return 2*pos+1;
}

int hijo_der(int pos){
    return 2*pos+2;
}

void swap(vector<int> &v, int x, int y){
    //DADO UN VECTOR, SWAPPEA LAS POSICIONES x E y
    int elemento1 = v[x];
    v[x] = v[y];
    v[y] = elemento1;
}


int max_hijo(const vector<int> &heap, int pos){
    int ret = pos;
    if(hijo_izq(pos) < heap.size() && heap[ret] < heap[hijo_izq(pos)]){
        ret = hijo_izq(pos);
    }
    if(hijo_der(pos) < heap.size() && heap[ret] < heap[hijo_der(pos)]){
        ret = hijo_der(pos);
    }
    return ret;
}

void downheap(vector<int> &heap, int pos){ //O(log N)
    int pos_bajar = max_hijo(heap, pos);
    if(pos_bajar != pos){
        swap(heap, pos, pos_bajar);
        downheap(heap, pos_bajar);
    }
}

//(la hice yo)
void upheap(vector<int> &heap, int pos){ //O(log N)
    //Hace ascender por el heap al elemento en la ubicación pos
    int pos_subir = padre(pos);
    if(pos_subir != pos && heap[pos] > heap[pos_subir]){
        swap(heap, pos, pos_subir);
        upheap(heap, pos_subir);
    }
}

void insertar_heap(int n, vector<int> &heap){
    heap.push_back(n);
    upheap(heap, heap.size()-1);
}

void eliminar_maximo(vector<int> &heap){
    heap[0] = heap[heap.size()-1];   //pone último en la raíz
    heap.pop_back();   //saca el último
    downheap(heap, 0);  //baja la raíz
}



//FUNCIONES EXTRAS
//maxhijo con un rango [desde, hasta]
int max_hijo_DC(const vector<int> &heap, int pos, int d, int h){
    int ret = pos;
    if(hijo_izq(pos) < heap.size() && heap[ret] < heap[hijo_izq(pos)]){
        ret = hijo_izq(pos);
    }
    if(hijo_der(pos) < heap.size() && heap[ret] < heap[hijo_der(pos)]){
        ret = hijo_der(pos);
    }
    return ret;
}

//downheap con un rango [desde, hasta]
void downheap_DC(vector<int> &heap, int pos, int d, int h){ //O(log N)
    int pos_bajar = max_hijo_DC(heap, pos, d, h);
    if(pos_bajar != pos){
        swap(heap, pos, pos_bajar);
        downheap(heap, pos_bajar);
    }
}




//IGNORAR
//heapify con downheap usando divide and conquer (la original sin parametros llama a esta auxiliar)
void heapify_DC_D(vector<int> &heap, int desde, int hasta){
    for(int i = hasta; i >= desde; i--){
        downheap(heap, i);    
    }
}

//version de heapify con downheap
void heapify_D(vector<int> &heap){
    heapify_DC_D(heap, 0, heap.size()-1);
}
//IGNORAR




//heapify con upheap usando divide and conquer (la original sin parametros llama a esta auxiliar)
void heapify_DC_S(vector<int> &heap, int desde, int hasta){ //O(N LOG N)
    for(int i = desde; i <= hasta; i++){ //O(N)
        cout << "SUBIMOS LA POSICION " << i << endl;
        upheap(heap, i); //O(LOG N)    
        imprimir_vector(heap);
    }
}

//HEAPIFY CON UPHEAP (desde el primero hasta el último)
void heapify(vector<int> &heap){
    heapify_DC_S(heap, 0, heap.size()-1);
}

//HEAPSORT CON HEAPIFY N VECES => NO DA LA COMPLEJIDAD! 
void heapsort_S(vector<int> &v){//O(N * (N LOG N))
    for(int i = v.size()-1; i>=0; i--){ //N ITERACIONES
        heapify_DC_S(v, 0, i);// O(N LOG N)
        swap(v, 0, i);
    }
}


//HEAPSORT EN N LOG N
void heapsort(vector<int> &v){
    vector<int> heap = v;
    heapify(heap);
    for(int i = v.size()-1; i>=0; i--){
        v[i] = heap[0];
        eliminar_maximo(heap);
    }
}




//CONTINUACIÓN GUÍA 6:

/*

//EJERCICIO 7:
template <typename T>
class DiccionarioDeInt{
 public:
    DiccionarioDeInt();
    bool esta_definida(int clave) const;
    const T& obtener_valor(int clave) const;
    void definir(int clave, T valor);
    void borrar(int clave);
    ~DiccionarioDeInt();

 private:
    struct nodo {
    nodo(int c, T v) : clave(c), valor(v), hijo_izq(nullptr), hijo_der(nullptr) {}
    int clave;
    T valor;
    nodo* hijo_izq;
    nodo* hijo_der;
    };
    nodo* raiz;
    bool esta_definida_DC(int clave, nodo raiz) const;
};

//IMPLEMENTACION:
template <typename T>
DiccionarioDeInt<T>::DiccionarioDeInt(){
}

template <typename T>
bool DiccionarioDeInt<T>::esta_definida(int clave) const{
    return esta_definida_DC(int clave, nodo raiz);
}

template <typename T>
bool DiccionarioDeInt<T>::esta_definida_DC(int clave, nodo raiz) const{
    if(this->raiz == nullptr){
        return false;
    }else if(clave == this->clave){
        return true;
    }else if(clave < this->clave){
        return esta_definida(clave, this->hijo_izq);
    }else if(clave >= this->clave){
        return esta_definida(clave, this->hijo_der);
    }
}
template <typename T>
void DiccionarioDeInt<T>::definir(int clave, T valor){
    if(this->raiz == nullptr){
        this->raiz = new nodo(clave, valor);
    }else if(clave < this->clave){
        definir(clave, valor, this->hijo_izq);
    }else if(clave >= this->clave){
        definir(clave, this->hijo_der);
    }
}
*/

struct arbol_ternario{
    int valor;
    arbol_ternario* hijo_izquierdo;
    arbol_ternario* hijo_medio;
    arbol_ternario* hijo_derecho;
};

void multiplicar_por(arbol_ternario* raiz, int k){
    if(raiz == nullptr){
        return;
    }else{
        raiz->valor = raiz->valor*k;
        multiplicar_por(raiz->hijo_izquierdo, k);
        multiplicar_por(raiz->hijo_medio, k);
        multiplicar_por(raiz->hijo_derecho, k);
    }
}

int main() {
    //EJERCICIO 1: PILA
    cout << "EJERCICIO 1: IMPLEMENTACIÓN DE LA CLASE PILA: " << endl;
    cout << "Generamos una pila vacia." << endl;
    Pila<int> MiPila;
    cout << "La pila está vacía? Respuesta: " << MiPila.es_vacia() << endl;
    cout << "Ahora apilamos los siguientes numeros: 1, 2, 3, 4" << endl;
    MiPila.apilar(1);
    MiPila.apilar(2);
    MiPila.apilar(3);
    MiPila.apilar(4);
    cout << "La pila está vacía? Respuesta: " << MiPila.es_vacia() << endl;
    cout << "El último elemento en ser agregado a la pila fue: " << MiPila.tope() << endl;
    cout << "Ahora desapilamos el 4 y el 3" << endl;
    MiPila.desapilar();
    MiPila.desapilar();
    cout << "La pila está vacía? Respuesta: " << MiPila.es_vacia() << endl;
    cout << "El último elemento en ser agregado a la pila fue: " << MiPila.tope() << endl;
    cout << "Ahora desapilamos todo" << endl;
    MiPila.desapilar();
    MiPila.desapilar();
    cout << "La pila está vacía? Respuesta: " << MiPila.es_vacia() << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;




    //EJERCICIO 2: COLA 
    cout << "EJERCICIO 2: IMPLEMENTACION DE CARRITO DE SUPER USANDO COLA" << endl;
    cout << "El supermercado acaba de abrir, y tenemos 2 cajas dispobiles para atender a las personas que lleguen. La cola de espera está vacía." << endl;
    FilaDeSuper FilaWalmart;
    cout << "La cantidad de personas esperando en la cola de espera es: " << FilaWalmart.cantidad_esperando() << endl;
    cout << "La caja 1 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(1) << endl;
    cout << "La caja 2 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(2) << endl;
    cout << "Está empezando a llegar gente al super" << endl;
    cout << "A las personas que están en la fila las vamos a identificar por su DNI." << endl;
    FilaWalmart.llega_persona("45392384");
    FilaWalmart.llega_persona("49345492");
    FilaWalmart.llega_persona("34928459");
    FilaWalmart.llega_persona("12943493");
    FilaWalmart.llega_persona("52493953");
    FilaWalmart.llega_persona("19458320"); 
    cout << "La cantidad de personas esperando en la cola de espera es: " << FilaWalmart.cantidad_esperando() << endl;
    cout << "La persona que llegó primera y será la primera en ser atendida es la que tiene el DNI:" << FilaWalmart.siguiente() << endl;
    cout << "Ahora las cajas 1 y 2 empiezan a atender" << endl;
    FilaWalmart.atender_siguiente(1);
    FilaWalmart.atender_siguiente(2);
    cout << "La caja 1 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(1) << endl;
    cout << "La caja 2 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(2) << endl;
    cout << "La cantidad de personas esperando en la cola de espera es: " << FilaWalmart.cantidad_esperando() << endl;
    cout << "Ahora la persona que está primera y será la próxima en ser atendida es la que tiene el DNI:" << FilaWalmart.siguiente() << endl;
    cout << "La caja 1 va más rápido que la 2, ya se está liberando" << endl;
    FilaWalmart.liberar_caja(1);
    cout << "La caja 1 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(1) << endl;
    cout << "La caja 2 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(2) << endl;
    cout << "Ahora la caja 1 pasa a atender al siguiente" << endl;
    FilaWalmart.atender_siguiente(1);
    cout << "La caja 1 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(1) << endl;
    cout << "La caja 2 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(2) << endl;
    cout << "La cantidad de personas esperando en la cola de espera es: " << FilaWalmart.cantidad_esperando() << endl;
    cout << "Ahora la persona que está primera y será la próxima en ser atendida es la que tiene el DNI:" << FilaWalmart.siguiente() << endl;
    cout << "Las cajas 1 y 2 se están liberando al mismo tiempo ahora" << endl;
    FilaWalmart.liberar_caja(1);
    FilaWalmart.liberar_caja(2);
    cout << "La caja 1 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(1) << endl;
    cout << "La caja 2 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(2) << endl;
    cout << "Tanto las cajas 1 como la 2 pasan a atender a los que siguen." << endl;
    FilaWalmart.atender_siguiente(1);
    FilaWalmart.atender_siguiente(2);
    cout << "La caja 1 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(1) << endl;
    cout << "La caja 2 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(2) << endl;
    cout << "La cantidad de personas esperando en la cola de espera es: " << FilaWalmart.cantidad_esperando() << endl;
    cout << "Ahora solo queda una persona en ser atendida que es la única en la fila y tiene el DNI:" << FilaWalmart.siguiente() << endl;
    cout << "La caja 1 se está liberando" << endl;
    FilaWalmart.liberar_caja(1);
    cout << "La caja 1 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(1) << endl;
    FilaWalmart.atender_siguiente(1);
    cout << "Ya no debería haber más gente en la fila." << endl;
    cout << "La caja 1 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(1) << endl;
    cout << "La caja 2 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(2) << endl;
    cout << "Las cajas ya están terminando de atender." << endl;
    FilaWalmart.liberar_caja(1);
    FilaWalmart.liberar_caja(2);
    cout << "La caja 1 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(1) << endl;
    cout << "La caja 2 está ocupada? Respuesta: " << FilaWalmart.esta_ocupada(2) << endl;
    cout << "La cantidad de personas esperando en la cola de espera es: " << FilaWalmart.cantidad_esperando() << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;



    //EJERCICIO 3: DICCIONARIO 
    cout << "EJERCICIO 3: IMPLEMENTACIÓN DE DICCIONARIO" << endl;
    cout << "Creamos un diccionario vacío en el que están las materias que cursé en UTDT y los puntajes que les otorgo." << endl;
    Diccionario<string,int> PuntajeMaterias;
    cout <<"Ahora agregamos algunas materias" << endl;
    PuntajeMaterias.definir("mate1", 10);
    PuntajeMaterias.definir("mate2", 10);
    PuntajeMaterias.definir("algebra", 8);
    PuntajeMaterias.definir("micro", 6);
    PuntajeMaterias.definir("introEstadistica", 10);
    PuntajeMaterias.definir("TDI", 9);
    PuntajeMaterias.definir("TDII", 10);
    PuntajeMaterias.definir("TDIII", 8);
    cout << "TD IV está definida? Respuesta: " << PuntajeMaterias.esta_definida("TDIV") << endl;
    cout << "TD II está definida? Respuesta: " << PuntajeMaterias.esta_definida("TDII") << endl;
    cout << "Su valor es... " << PuntajeMaterias.obtener_valor("TDII") << endl;
    cout << "micro está definida? Respuesta: " << PuntajeMaterias.esta_definida("micro") << endl;
    cout << "Su valor es... " << PuntajeMaterias.obtener_valor("micro") << endl;
    cout << "micro fue muy mala, la elimino" << endl;
    PuntajeMaterias.borrar("micro");
    cout << "micro está definida? Respuesta: " << PuntajeMaterias.esta_definida("micro") << endl;
    cout << "Ahora que vi la parte de estructuras de datos, TDIII que fue la última que cursé me gusta, más le quiero subir la nota de 8 a 9" << endl;
    cout << "El valor de TDIII es: " << PuntajeMaterias.obtener_valor("TDIII") << endl;
    cout << "Ahora cambiamos el puntaje." << endl;
    PuntajeMaterias.actualizar_ultimo(9);
    cout << "El valor de TDIII ahora es: " << PuntajeMaterias.obtener_valor("TDIII") << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    //EJERCICIO 6: VERIFICAR MAX HEAP
    cout << "EJERCICIO 3: VERIFICAR MAX HEAP" << endl;
    cout << "Creemos un árbol y veamos si es heap" << endl;
    //arbol_binario* n2h1 = new arbol_binario({12, nullptr, nullptr});
    arbol_binario* n2h2 = new arbol_binario({15, nullptr, nullptr});
    arbol_binario* n2h3 = new arbol_binario({17, nullptr, nullptr});
    arbol_binario* n2h4 = new arbol_binario({10, nullptr, nullptr});
    arbol_binario* n1h1 = new arbol_binario({50, nullptr, n2h2});
    arbol_binario* n1h2 = new arbol_binario({37, n2h3, n2h4});
    arbol_binario* raiz = new arbol_binario({99, n1h1, n1h2});
    imprimir_arbol(raiz, 0);
    cout << "El arbol es max_heap? respuesta: " << verificar_max_heap(raiz) << endl;
    
    //PRACTICA EXTRA: HEAP
    cout <<"PRÁCTICA EXTRA: HEAP" << endl;
    cout << endl;
    cout <<"1- FUNCIÓN 'SUBIR'" << endl;
    cout << "Sea el siguiente vector: " << endl;
    vector<int> heap = {1, 5, 7, 6, 9, 4};
    imprimir_vector(heap);
    cout << "Ahora subimos el 9" << endl;
    upheap(heap, 4);
    imprimir_vector(heap);
    cout << endl;

    
    cout << "2- FUNCIÓN 'BAJAR'" << endl;
    cout << "Sea (nuevamente) el siguiente vector: " << endl;
    heap = {1, 5, 7, 6, 9, 4};
    imprimir_vector(heap);
    cout << "Ahora bajamos el 4" << endl;
    downheap(heap, 5);
    imprimir_vector(heap);
    cout << endl;

    cout << "Ahora bajamos el 9" << endl;
    downheap(heap, 4);
    imprimir_vector(heap);
    cout << endl;

    cout << "Ahora bajamos el 6" << endl;
    downheap(heap, 3);
    imprimir_vector(heap);
    cout << endl;

    cout << "Ahora bajamos el 7" << endl;
    downheap(heap, 2);
    imprimir_vector(heap);
    cout << endl;

    cout << "Ahora bajamos el 5" << endl;
    downheap(heap, 1);
    imprimir_vector(heap);
    cout << endl;
    
    cout << "Ahora bajamos el 1" << endl;
    downheap(heap, 0);
    imprimir_vector(heap);
    cout << endl;

    cout << "3- HEAPIFY: ARMAR HEAP" << endl;
    cout << "Sea (nuevamente) el vector: " << endl;
    heap = {1, 5, 7, 6, 9, 4};
    imprimir_vector(heap);
    cout << "Ahora aplicamos heapify con BAJAR: lo convertimos en un heap" << endl;
    heapify_D(heap);
    imprimir_vector(heap);
    cout << endl;

    cout << "Sea (nuevamente) el vector: " << endl;
    heap = {1, 5, 7, 6, 9, 4};
    imprimir_vector(heap);
    cout << "Ahora aplicamos heapify con SUBIR: lo convertimos en un heap" << endl;
    heapify(heap);
    imprimir_vector(heap);
    cout << endl;
    
    
    
    cout << "4- HEAPSORT" << endl;
    cout << "Sea (nuevamente) el vector: " << endl;
    heap = {1, 5, 7, 6, 9, 4};
    imprimir_vector(heap);
    cout << "Ahora lo ordenamos usando heapsort" << endl;
    heapsort(heap);
    imprimir_vector(heap);
    

    cout << "EJERCICIO 7: DICCIONARIO CON ARBOL" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Definimos diccionario: " << endl;
    //DiccionarioDeInt<int> MyMap = DiccionarioDeInt();








    return 0;
}