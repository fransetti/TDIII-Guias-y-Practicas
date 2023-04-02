//GUÍA 1: PROGRAMACIÓN BÁSICA EN C++


//EJERCICIO 1 (comentado por ser la práctica inicial)
//a)HOLAMUNDO

/*
#include <iostream>
int main(){
    std::cout << "Hola Mundo" << std::endl;
}*/

//IOSTREAM ES UNA BIBLIOTECA QUE NOS PERMITE HACER USO DE CIN Y COUT, BÁSICAMENTE PERMITE LA ENTRADA Y SALIDA POR LA CONSOLA

//b)LA IMPORTANCIA DE USING NAMESPACE STD

/*
#include <iostream>
using namespace std;

int main(){
    cout << "Hola mundo" << endl;
}
*/

//tanto std::cout y cout hacen lo mismo. La diferencia es que gracias a "using namespace std", se simplifica el uso y no hace falta
//escribir std:: antes de cada cosa.


//c)CONCATENAR VARIABLES UTILIDANZO EL OPERADOR <<

/*
#include <iostream>
using namespace std;

int main(){
    string nombre = "Juan";
    string edad = "30";
    cout << nombre << " y tiene " << edad << " años." << endl;
}
*/

//d)FUNCIONAMIENTO DE CIN (EL INPUT DE C++) PARA TOMAR VALORES

/*
#include <iostream>
using namespace std;

int main(){
    string nombre;

    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Su nombre es " << nombre << "." << endl;
}
*/

//e)Si se ingresa un texto con espacios, usar solo cin NO SIRVE (solo lee la primera línea)


//f)LA FUNCIÓN GETLINE PERMITE LEER UNA LÍNEA COMPLETA DE LA ENTRADA ESTÁNDAR

/*
#include <iostream>
#include <string>
using namespace std;

int main(){
    string nombre_completo;

    cout << "Ingrese su nombre completo: ";
    getline(cin, nombre_completo);
    cout << "Su nombre es " << nombre_completo << "." << endl;
}
*/




//EJERCICIO 2: TIPOS BÁSICOS (De acá en adelante laburo todo en un main, por eso declaro las funciones antes)
#include <iostream>
using namespace std;
//Ya incluyo los tipos string, vector, set y map (los necesitaremos después)
#include <string>
#include <vector>
#include <set>
#include <map>


//CLASES DEFINIDAS:

//Ejercicio 9 a)
enum class Color {Blanco, Negro, Rojo, Verde, Azul};

//Ejercicio 9 c)
enum class DiaSemana {Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo};




//STRUCTS DEFINIDOS (EJERCICIO 11):
struct usuario
{
    string nombre;
    string email;
    int cantidad_de_seguidores;
}usuario1;

struct persona
{
    string nombre;
    int edad;
    string dni;
}p1, p2, p3, p4, p5;

struct materia{
    string nombre;
    int codigo;
    int cantidad_alumnos;
    string nombre_carrera;
};


//DECLARACIÓN Y DEFINICIÓN DE FUNCIONES EJERCICIO 5 EN ADELANTE: 

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


//---------------------------


//FUNCIONES EJERCICIO 5:
string reemplazar_vocales_por_a(string texto_con_vocales){
    int i = 0;
    while (i <= texto_con_vocales.length()){
        if (texto_con_vocales[i] == 'e' || texto_con_vocales[i] == 'i' || texto_con_vocales[i] == 'o' || texto_con_vocales[i] == 'u'){
            texto_con_vocales[i] = 'a';
        }
        i++;
    }
    return texto_con_vocales;  
}


bool suman_cero(int a, int b){
    bool respuesta = a+b == 0;
    return respuesta;
}


int maximo(int a, int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}


int cantidad_de_vocales(string texto){
    int i = 0;
    int contador = 0;
    while(i <= texto.length()){
        if(texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u'){
            contador++;
        }
        i++;
    }
    return contador;
}

//FUNCIONES EJERCICIO 6:

void funcion_A(int n){
    n=5;
}

void funcion_B(int &n){
    n=5;
}

//EJERCICIO 6, b)

void encerrar_entre_parentesis(string &texto){
    texto.insert(0, "(");
    texto.insert(texto.length(), ")");
}

//EJERCICIO 6, c)

int reemplazar_numero(vector<int> &lista, int n){
    int i = 0;
    int contador = 0;
    while (i<=lista.size()){
        if(lista[i] == n){
            lista[i] = 0;
            contador++;
        }
        i++;
    }
    return contador;
}



//FUNCION (propuesta por el ejercicio y mal hecha) EJERCICIO 7 a)
/*
LA SIGUIENTE FUNCION TIENE EL ERROR DE QUE INTENTA MODIFICAR
EL PRIMER ELEMENTO DEL VECTOR Y COMO ESTÁ ESPECIFICADO CON "const", significa
que este no puede modificarse, por eso hay un error y la función no sirve.

void modificar_primero(const vector<int> & lista){
    lista[0] = 0;
}
*/

//FUNCION EJERCICIO 7 b)
bool es_vacio(vector<int> &lista){
    return (lista.size() == 0);
}

//FUNCIONES EJERCICIO 8

int sumatoria(const vector<int> &numeros){
    int i = 0;
    int suma = 0;
    while (i < numeros.size()){
        suma+=numeros[i];
        i++;
    }
    return suma;
}


float conversor_fahrenheit_celsius(float grados_fahrenheit){
    float grados_celsius = (grados_fahrenheit - 32)/1.8;
    return grados_celsius;
}

string es_primo(int numero){
    string respuesta = "no es primo";
    int i = 2;
    int contador_divisores = 0;
    while(i<numero){
        if(numero%i == 0){
            contador_divisores++;
        }
        i++;    
    }
    if(contador_divisores == 0){
        respuesta = "es primo";
    }
    return respuesta;
}

string es_palindromo(string texto){
    string respuesta = "no es palíndromo";
    string texto2 = texto;
    int i = 0;
    int pos = texto.length()-1;
    while(i<texto.length()){
        texto2[i] = texto[pos];
        i++;
        pos--;
    }
    if(texto == texto2){
        respuesta = "es palíndromo";
    }
    return respuesta;
}

string concatenar(vector<string> strings_vector){
    string respuesta = "";
    int i = 0;
    while (i<=strings_vector.size()){
        respuesta.append(strings_vector[i]);
        i++;
    }
    return respuesta;
}

int cantidad_rojos(vector<Color> vector_de_colores){
    int i = 0;
    int contador = 0;
    while (i<vector_de_colores.size()){
        if(vector_de_colores[i] == Color::Rojo){
            contador++;
        }
        i++;
    }
    return contador;
}

//Ejercicio 9 c)

string es_fin_de_semana(DiaSemana dia){
    string respuesta = "No es fin de semana";
    if(dia == DiaSemana::Sabado || dia == DiaSemana::Domingo){
        respuesta = "Es fin de semana";
    }
    return respuesta;
}


//Ejercicio 11 b)

string años_diferencia(persona p1, persona p2){
    string respuesta = "no se llevan más de 10 años de diferencia";
    int diferencia1 = p1.edad - p2.edad;
    int diferencia2 = p2.edad - p1.edad;
        if(diferencia1 > 10 || diferencia2 > 10){
            respuesta = "se llevan más de 10 años de diferencia";
        }
    return respuesta;
}

//11 c)

persona persona_mas_grande(const vector<persona> &lista_de_personas){
    int i = 0;
    persona persona_mas_grande;
    persona_mas_grande.edad = 0;
    while (i < lista_de_personas.size()){
        if(lista_de_personas[i].edad > persona_mas_grande.edad){
            persona_mas_grande = lista_de_personas[i];
        }
        i++;
    }
    return persona_mas_grande;
}

//FIN DE DECLARACION DE FUNCIONES



//a)Escribir un programa que tome dos números enteros por entrada estándar y que imprima si
//la suma de los números ingresados es positiva, negativa o 0.



int main(){

    cout <<"EJERCICIO 2, a)"<< endl;

    int numero1;
    int numero2;

    cout <<"Ingrese el primer número: ";
    cin >> numero1;
    cout <<"Ingrese el segundo número: ";
    cin >> numero2;
    cin.ignore();

    cout << endl;


    int suma = numero1 + numero2;

    if (suma < 0){
        cout <<"La suma es negativa"<< endl;
    }else if (suma == 0){
        cout <<"La suma es igual a 0"<< endl;
    }else{
        cout <<"La suma es positiva"<< endl;
    }  



    

//b)Cuál es la salida del siguiente programa? que hace la línea 6?

    cout <<"EJERCICIO 2, b)"<< endl;

    int n = 5;
    bool condicion = (n == 4 || n == 5);
    if (condicion){
        cout << "verdadero" << endl;
    } else{
        cout << "falso" << endl;
    }


//el programa declara un int n y vale 5.
//luego se declara un bool que es verdadero si n vale 4 o vale 5
//como n vale 5, la condicion se cumple

    cout <<endl;

//c)Indicar la salida al ejecutar el siguiente programa
    cout <<"EJERCICIO 2, c)"<< endl;

    int mi_entero = 9;
    float mi_decimal = 9;

    if(mi_entero / 2 > 4){
        cout << "mi_entero dividido 2 es mayor a 4" << endl;
    } else {
        cout << "mi_entero dividido 2 NO es menor a 4" << endl;
    }    
    
    if(mi_decimal / 2 > 4){
        cout << "mi_decimal dividido 2 es mayor a 4" << endl;
    } else {
        cout << "mi_decimal dividido 2 NO es menor a 4" << endl;
    }



//EXPLICACIÓN DEL PROGRAMA
/*El programa se basa en distinguir la diferencia entre un int y un float.
Sabemos que 9/2 es 4,5. Pero en el caso de mi_entero, como es un int, al 
ejecutar la operación 9/2, va a redondear al entero más cercano (siempre 
para abajo), es decir, en mi_entero se va a guardar el 4. Por lo que la
primer condición debe devolver "mi_entero dividido 2 NO es menor a 4". En
el segundo caso, como mi_decimal es un float, al hacer 9/2, se va a guardar
4,5 como resultado, por lo la segunda condición devuelve "mi_decimal es mayor a 4"
*/



    cout <<endl;
//EJERCICIO 3: TIPOS std::string y std::vector



//a) Dada la variable materia de tipo string, indicar el tipo y el valor 
//de las siguientes expresiones

    cout <<"EJERCICIO 3, a)"<< endl;

    string materia = "Algoritmos y Estructuras de Datos";
    cout << "Para este ejercicio laburamos con el siguiente string: " << materia << endl;

    cout << "Imprimimos: materia[0]" << endl;
    cout << materia[0] << endl; //DEVUELVE "A"
    cout << "Imprimimos: materia[5]" << endl;
    cout << materia[5] << endl; //DEVUELVE "i"
    cout << "Imprimimos: materia.front() == 'E'" << endl;
    bool incisoc = materia.front() == 'E';//DEVUELVE 0 (falso)
    cout << incisoc << endl;
    cout << "Imprimimos: materia.back() == 's'" << endl;
    bool incicod = materia.back() == 's';
    cout << incicod << endl;//DEVUELVE 1 (verdadero)
    cout << "Imprimimos: materia.size()" << endl;
    int incisoe = materia.size(); //DEVUELVE 33
    cout <<incisoe << endl;
    cout << "Imprimimos: materia.length()" << endl;
    int incisof = materia.length();//DEVUELVE 33 
    cout <<incisof << endl;
    cout << "Imprimimos: materia.substr(13, 11)" << endl;
    cout << materia.substr(13, 11) << endl; //DEVUELVE "Estructuras" 

//(la funcion .substr tiene dos parámetros, el primero: la posicion desde la cual se empieza a leer, el segundo: a partir del primer parámetro: la cantidad de posiciones a leer)

    cout <<endl;

//b) Dada la variable mediciones de tipo vector<int>, indique el tipo y el valor de las siguientes expresiones 

    cout <<"EJERCICIO 3, b)"<< endl;

    vector<int> mediciones = {19, 18, 22, 20, 23, 24};

    cout << "Para este ejercicio laburamos con el siguiente vector: ";
     imprimir_vector(mediciones);
    cout << endl;

    cout << "Imprimimos: mediciones[0]" << endl;
    cout << mediciones[0] << endl; //DEVUELVE 19
    cout << "Imprimimos: mediciones[3]" << endl;
    cout << mediciones[3] << endl; //DEVUELVE 20
    cout << "Imprimimos: mediciones.front()" << endl;
    cout << mediciones.front() << endl; //DEVUELVE 19
    cout << "Imprimimos: mediciones.back() == 23" << endl;
    bool incisod = mediciones.back() == 23; //DEVUELVE 0 (falso)
    cout << incisod << endl; 
    cout << "Imprimimos: mediciones.size()" << endl;
    cout << mediciones.size() <<endl; //DEVUELVE 6

    cout <<endl;


//c)Indicar como se modifican las variables materia y mediciones con las siguientes operaciones

    cout <<"EJERCICIO 3, c)"<< endl;
    
    cout << "Modificamos el string materia con: materia.append({} - UTDT)" << endl;
    materia.append("{} - UTDT"); //"Algoritmos y Estructuras de Datos{} - UTDT"
    cout << "String modificado: " << materia << endl;
    cout << endl;

    cout << "Modificamos el string materia con: materia.push_back('X')" << endl;
    materia.push_back('X'); //"Algoritmos y Estructuras de Datos{} - UTDTX"
    cout << "String modificado: " << materia << endl;
    cout << endl;

    cout << "Modificamos el vector mediciones con: mediciones.pop_back()" << endl;
    mediciones.pop_back(); //VECTOR MODIFICADO: {19, 18, 22, 20, 23} POP_BACK BORRA EL ÚLTIMO ELEMENTO
    cout << "Vector modificado: ";
    imprimir_vector(mediciones);
    cout << endl;


    cout << "Modificamos el vector mediciones con: mediciones.push_back(20)" << endl;
    mediciones.push_back(20);//VECTOR MODIFICADO {19, 18, 22, 20, 23, 20} PUSH_BACK AÑADE UN ELEMENTO
    cout << "Vector modificado: ";
    imprimir_vector(mediciones);
    cout << endl;




    cout << endl;

//EJERCICIO 4: CICLOS

//a)Completar el código del siguiente programa para que imprima por pantalla todos los elementos del
//vector mediciones

    cout <<"EJERCICIO 4, a)"<< endl;
    cout <<"Elementos del vector impresos uno a uno:"<< endl;

    int i = 0;
    while (i< mediciones.size()){
        cout <<mediciones[i] <<endl;
        i++;
    }

    cout << endl;
//b)Modificar el programa anterior para que imprima los valores en orden inverso
    cout <<"EJERCICIO 4, b)"<< endl;

//MODIFICACIÓN IMPLEMENTADA CON i INICIANDO EN mediciones.size()-1
    cout <<"MODIFICACIÓN IMPLEMENTADA CON i INICIANDO EN mediciones.size()-1"<< endl;

    i = mediciones.size()-1; //IMPORTANTE: Si vamos a recorrer elemento a elemento empezando desde atrás, al size hay que restarle 1 ya que le i-ésima posición cuenta al 0 como primera posición (si no le restamos 1 nos salimos de rango)
    while (i>=0){ //IMPORTANTE: EL i tiene que poder ser  0 para que se imprima la posición 0, por eso ">="
        cout <<mediciones[i] <<endl;
        i--;
    }

    cout << endl;
//MODIFICACIÓN IMPLEMENTADA CON i INICIANDO EN 0
    cout <<"MODIFICACIÓN IMPLEMENTADA CON i INICIANDO EN 0"<< endl;


    i = 0;
    int pos = mediciones.size()-1;
    while (i< mediciones.size()){
        cout <<mediciones[pos] <<endl;
        i++;
        pos--;
    }

    cout << endl;

//c)COMPLETAR EL CÓDIGO PARA QUE AVERIGUE SI EL TEXTO INGRESADO CONTIENE LA LETRA "z"
//SI LA TIENE, INDICAR LA POSICIÓN.
    cout <<"EJERCICIO 4, c)"<< endl;


    
    string texto;
    cout <<"ingrese el texto: ";
    getline(cin, texto);
    
  
    i = 0;
    int validez = 0;
    string respuesta = "La Z no se encuentra en el texto";

    while (i <= texto.length()){
        if (texto[i] == 'z'){
            respuesta = "La z está en el texto y se encuentra en la posición ";
            cout << respuesta << i << endl;
            validez = 1;
            break;
        }
        i++;
    }

    if (validez == 0){
        cout <<respuesta << endl;
    }

    cout << endl;
//d)Hacer un programa que tome un texto ingresado y remplace todas las vocales por la "a"
   cout <<"EJERCICIO 4, d)"<< endl;

    string texto_con_vocales;
    cout <<"ingrese el texto: ";
    getline(cin, texto_con_vocales);

    i = 0;
    while (i <= texto_con_vocales.length()){
        if (texto_con_vocales[i] == 'e' || texto_con_vocales[i] == 'i' || texto_con_vocales[i] == 'o' || texto_con_vocales[i] == 'u'){
        texto_con_vocales[i] = 'a';
        }
        i++;
    }

    cout << texto_con_vocales << endl;


    cout << endl;



//EJERCICIO 5: FUNCIONES

//a)
    cout <<"EJERCICIO 5: FUNCIONES"<< endl;


    //FUNCIONES CON STRINGS
    cout <<"FUNCIONES CON STRINGS:"<< endl;

    string texto_con_vocaless;
    cout <<"ingrese el texto: ";
    getline(cin, texto_con_vocaless);
    cout << reemplazar_vocales_por_a(texto_con_vocaless) << endl;
    cout << cantidad_de_vocales(texto_con_vocaless) << endl;
    
    cout << endl;

    //FUNCIONES CON ENTEROS
    cout <<"FUNCIONES CON ENTEROS:"<< endl;
    int a;
    cout <<"ingrese número 1: ";
    cin >> a;
    int b;
    cout <<"ingrese número 2: ";
    cin >> b;
    cin.ignore();
    cout << suman_cero(a, b) << endl;
    cout << maximo(a, b) << endl;
    
    //(EJERCICIO 5, e) me aburrí y lo salté)

    cout << endl;

//EJERCICIO 6: PASAJE DE PARÁMETROS POR REFERENCIA

    cout <<"EJERCICIO 6: a)"<< endl;

//LAS FUNCIONES ESTAN DECLARADAS ANTES DEL MAIN


    int numero = 10;
    cout << "numero: " << numero << endl;
    cout << "Llamada a funcion_A(numero)." << endl;
    funcion_A(numero);
    cout << "numero: " << numero << endl;
    cout <<"(vemos que el número no se modifica porque la funcion_A no usa referencia)"<< endl;
    cout << endl;
    cout << "Llamada a funcion_B(numero)." << endl;
    funcion_B(numero);
    cout << "numero: " << numero << endl;
    cout <<"(ahora vemos que el numero si se modificó porque la funcion_B si usa la direccion de memoria, por lo que modifica la variable)"<< endl;



//EXPLICACIÓN DEL PROGRAMA
/*Se crea un int numero el cual vale 10. Y se llama a la función A
que lo que hace es recibir un int "n" y lo iguala a 5. Pero esta 
función en realidad está creando una "copia" de la variable numero del main.
En cambio, cuando se llama a la función B, utilizamos el "&" lo cual significa
que estamos accediendo a la dirección de memoria de la variable original,
por lo que la función B no labura con una copia, labura con la variable original
y por eso la modifica y luego de llamar a la función B, numero sí vale 5.
(El tipo de retorno "void" simplemente significa que las funciones no devuelven nada).
 */

    cout << endl;


//b)IMPLEMENTAR UNA FUNCIÓN QUE TOME UN STRING POR PARÁMETRO Y LO MODIFIQUE PARA QUE EL CONTENIDO SE ENCIERRE ENTRE PARÉNTESIS
//(No se debe devolver un string, sino modificar el que se pasa por parámetro)
    cout <<"EJERCICIO 6: b)"<< endl;

//LA FUNCION ESTA ANTES DEL MAIN

    string texto_para_encerrar_parentesis;
    cout << "Ingrese el texto para encerrar entre paréntesis "<< endl;
    getline(cin, texto_para_encerrar_parentesis);
    cout << endl;
    cout << "A continuación, texto entre paréntesis: "<< endl;
    encerrar_entre_parentesis(texto_para_encerrar_parentesis);
    cout << texto_para_encerrar_parentesis << endl;

    cout << endl;


//c)IMPLEMENTAR UNA FUNCIÓN QUE TOME UN VECTOR DE INTs Y UN ENTERO n1 Y DEVUELVA UN INT.
//DEBE MODIFICAR CADA APARICION DE n1 POR UN 0 Y ADEMAS DEVOLVER LA CANTIDAD DE APARICIONES DE n.
    cout <<"EJERCICIO 6: b)"<< endl;
//LAS FUNCIONES ESTAN ANTES DEL MAIN

    vector<int> lista = {14, 8, 92, 3, 5, 8};
    cout <<"Para este ejercicio usaremos este vector: "<< endl;
    imprimir_vector(lista);
    cout << endl;

    int n1;
    cout << "Ingrese el numero: " << endl;
    cin >> n1;
    cin.ignore();
    cout << endl;
    cout << "La cantidad de veces que aparece el numero es: " << reemplazar_numero(lista, n1) << endl;
    cout << "ahora imprimimos el vector modificado:" << endl;
    imprimir_vector(lista);

    cout << endl;

//EJERCICIO 7 a): El error está explicado en la declaración de la función comentada antes del main

//EJERCICIO 7 b): No transcribí el programa pero el error es claro: al poner que el vector
//no se puede modificar por "const", luego se invoca a la funcion pero este llamado no puede hacerse
    const vector<int> medicioness = {19, 18, 22, 20, 23, 24};
    bool res = es_vacio(mediciones);
    cout << res << endl;

//EJERCICIO 7 c) utilizaría el tercer encabezado ya que si no se requiere modificar el vector de strings, es bueno usar el const para fijar que no se modifique accidentalmente.

    cout << endl;

//EJERCICIO 8 a): 
    cout <<"EJERCICIO 8: a)"<< endl;

    vector<int> lista_numeros = {10,20,32,41};
    cout <<"Para este ejercicio usaremos este vector: "<< endl;
    imprimir_vector(lista_numeros);
    cout << endl;

    cout << "La suma de todos los elementos del vector es: " << sumatoria(lista_numeros) <<endl;

    cout << endl;
//EJERCICIO 8 b):  
    cout <<"EJERCICIO 8: a)"<< endl;
    float grados_fahrenheit = 120;
    cout << grados_fahrenheit << " grados fahrenheit equivalen a "<< conversor_fahrenheit_celsius(grados_fahrenheit) << "Grados Celsius" << endl;
    cout << endl;

//EJERCICIO 8 c)
    cout <<"EJERCICIO 8: c)"<< endl;
    cout <<"A continuación: Tabla de conversiones de grados fahrenheit a celsius de 30 a 100 en intervalos de 10: "<< endl;
    i = 30;
    while (i<=100){
        cout << i << " grados fahrenheit equivalen a "<< conversor_fahrenheit_celsius(i) << " Grados Celsius" << endl;
        i = i + 10;
    }
    cout << endl;

//EJERCICIO 8 d)
    cout <<"EJERCICIO 8: d)"<< endl;
    int primo = 4;
    cout << primo << ' ' << es_primo(primo) << endl;

    cout << endl;

//EJERCICIO 8 e)
    cout <<"EJERCICIO 8: e)"<< endl;
    cout <<"Los números primos que se encuentran entre el 1 y el 100 son: "<< endl;
    i = 1;
    while (i<=100){
        if(es_primo(i) == "es primo"){
            cout <<i<< endl;
        }
        i++;
    }

    cout << endl;

//EJERCICIO 8 f)
    cout <<"EJERCICIO 8: f)"<< endl;
    string palabraa = "oso";
    cout << palabraa << ' ' << es_palindromo(palabraa) << endl;

    cout << endl;

//EJERCICIO 8 g)
    cout <<"EJERCICIO 8: g)"<< endl;
    vector<string> lista_strings = {"hola","como","estas"};
    cout <<"Para este ejercicio usaremos este vector: "<< endl;
    imprimir_vector_strings(lista_strings);
    cout << endl;

    cout << "Todos los strings del vector concatenados: " << concatenar(lista_strings) << endl;    

    cout << endl;

//EJERCICIO 9 a)
//(La clase Color está definida antes del main)

    //un_color es de tipo Color y vale "Color::Blanco"
    //un_color == otro_color es de tipo bool y vale 0
    //un_color == Color::Blanco es de tipo bool y vale 1
    //Color::Blanco == Color::Azul es de tipo bool y vale 0

//EJERCICIO 9 b)
    cout <<"EJERCICIO 9: b)"<< endl;
    vector<Color> lista_colores = {Color::Rojo, Color::Azul, Color::Blanco, Color::Blanco, Color::Rojo, Color::Verde, Color::Negro, Color::Rojo};
    cout <<"La cantidad de veces que aparece el color rojo en el vector {Color::Rojo, Color::Azul, Color::Blanco, Color::Blanco, Color::Rojo, Color::Verde, Color::Negro, Color::Rojo} es: " << cantidad_rojos(lista_colores) << endl;
    cout << endl;

//EJERCICIO 9 c)
    cout <<"EJERCICIO 9: c)"<< endl;
    DiaSemana un_dia = DiaSemana::Sabado;
    cout << es_fin_de_semana(un_dia) << endl;
    cout << endl;

//EJERCICIO 10 a)
//(.contains no lo incluyo porque no es compatible con esta versión del container)
    cout <<"EJERCICIO 10: a)"<< endl;
    set<int> mi_conjunto = {6, 8, -95, 9};

    mi_conjunto.insert(6); //.insert agrega un elemento
    mi_conjunto.insert(7);
    mi_conjunto.erase(9); //.erase elimina un elemento

//Indicar tipo y valor de las siguientes expresiones:
    cout << "Imprimimos: mi_conjunto.size()" << endl;
    cout << mi_conjunto.size() << endl; //es de tipo int e IMPRIME 4
    //mi_conjunto.contains(6);//es de tipo bool IMPRIME 1 (true)
    //mi_conjunto.contains(9);//es de tipo bool IMPRIME 0 (false) 
    bool inciso4 = mi_conjunto.empty();
    cout << "Imprimimos: mi_conjunto.empty()" << endl;
    cout << inciso4 << endl; //es de tipo bool IMPRIME 0 (false)

    cout << endl;

//EJERCICIO 10 b)
    cout <<"EJERCICIO 10: b)"<< endl;
    map<string, int> info_personas = { {"Ada", 1800}, {"Barbara", 1939}};

    //Cómo se modifica info_personas con las siguientes instrucciones?
    info_personas["Rebeca"] = 1926; //Agrega el contenedor rebeca y le provee el valor 1926
    info_personas["Ada"] = 1815; //Modifica el valor del contenedor Ada por 1815

    //Indicar tipo y valor de las siguientes expresiones:
    cout << "Imprimimos: info_personas[Ada]" << endl;
    cout << info_personas["Ada"] << endl; //es de tipo int e IMPRIME 1815
    //info_personas.contains("Alan"); //es de tipo bool e IMPRIME 0 (false)
    cout << "Imprimimos: info_personas.size()" << endl;
    cout << info_personas.size() << endl; //es de tipo int e IMPRIME 3
    cout << "Imprimimos: info_personas.empty()" << endl;
    bool inciso8 = info_personas.empty();
    cout << inciso8 << endl; //es de tipo bool e IMPRIME 0 (false)

    cout << endl;



//EJERCICIO 11 a)
    cout <<"EJERCICIO 11: a)"<< endl;
    cout << "Ingrese su nombre: "<< endl;
    getline(cin, usuario1.nombre);
    cout << "Ingrese su email: "<< endl;
    getline(cin, usuario1.email);
    usuario1.cantidad_de_seguidores = 0;
    cout << endl;

    cout << "Sus datos de usuario son: "<< endl;
    cout << "nombre: " << usuario1.nombre << endl;
    cout << "email: " << usuario1.email << endl;
    cout << "cantidad de seguidores: " << usuario1.cantidad_de_seguidores << endl;
    cout << endl;
    cout << endl;


//Ejercicio 11 b)
    cout <<"EJERCICIO 11: b)"<< endl;
    cout << "Ingrese el nombre de la primera persona: "<< endl;
    getline(cin, p1.nombre);
    cout << "Ingrese el dni de la primera persona: "<< endl;
    getline(cin, p1.dni);
    cout << "Ingrese la edad de la primera persona: "<< endl;
    cin >> p1.edad;
    cin.ignore();
    cout << endl;
    
    cout << "Ingrese el nombre de la segunda persona: "<< endl;
    getline(cin, p2.nombre);
    cout << "Ingrese el dni de la segunda persona: "<< endl;
    getline(cin, p2.dni);
    cout << "Ingrese la edad de la segunda persona: "<< endl;
    cin >> p2.edad;
    cin.ignore();
    cout << endl;
    cout << p1.nombre << " y " << p2.nombre << " " << años_diferencia(p1, p2) <<endl;
    cout << endl;


    //Ejercicio 11 d)
    cout <<"EJERCICIO 11: b)"<< endl;
    cout << "Ingrese el nombre de la tercera persona: "<< endl;
    getline(cin, p3.nombre);
    cout << "Ingrese el dni de la tercera persona: "<< endl;
    getline(cin, p3.dni);
    cout << "Ingrese la edad de la tercera persona: "<< endl;
    cin >> p3.edad;
    cin.ignore();
    cout << "Ingrese el nombre de la cuarta persona: "<< endl;
    getline(cin, p4.nombre);
    cout << "Ingrese el dni de la cuarta persona: "<< endl;
    getline(cin, p4.dni);
    cout << "Ingrese la edad de la cuarta persona: "<< endl;
    cin >> p4.edad;
    cin.ignore();
    cout << "Ingrese el nombre de la quinta persona: "<< endl;
    getline(cin, p5.nombre);
    cout << "Ingrese el dni de la quinta persona: "<< endl;
    getline(cin, p5.dni);
    cout << "Ingrese la edad de la quinta persona: "<< endl;
    cin >> p5.edad;
    cin.ignore();
    cout << endl;
    vector<persona> lista_personas = {p1, p2, p3, p4, p5};
    //persona_mas_grande(lista_personas);
    persona persona_grande = persona_mas_grande(lista_personas);
    cout << "La persona con mayor edad es: " << persona_grande.nombre << endl;


    return 0;
}
















