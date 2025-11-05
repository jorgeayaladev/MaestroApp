#include "NodoLista.h"
#include <functional>
typedef unsigned int uint;
template <class T>
class Lista {
private:
    NodoLista<T>* nodo;
    typedef function<int(T, T)> Comp;
    NodoLista<T>* ini;
    uint lon; // número de elementos en la lista

public:
    Lista() : ini(nullptr), lon(0) { nodo = new NodoLista<T>(); }
    ~Lista();
    /*Lista() {
        NodoLista = new NodoLista<T>();
    };*/
    Lista(NodoLista<T>* pNodoLista) {
        nodo = pNodoLista;
    };
    uint longitud();
    bool esVacia();
    void agregaInicial(T elem);
    void agregaPos(T elem, uint pos);
    void agregaFinal(T elem);
    void modificarInicial(T elem);
    void modificarPos(T elem, uint pos);
    void modificarFinal(T elem);
    void eliminaInicial();
    void eliminaPos(uint pos);
    void eliminaFinal();
    T obtenerInicial();
    T obtenerPos(uint pos);
    T obtenerFinal();
    T buscar(T elem);


    //~Lista(void);
    void agregar(T pNodoLista); //sumar NodoListas a la lista
    T suma(T i);
    int size();
    void borrar(void); //borra la cabeza
    void addOrdenado(T d);// suma NodoListas ordenados de menor a mayor

};
template <class T>
uint Lista<T>::longitud() {
    return lon;
}
template <class T>
bool Lista<T>::esVacia() {
    return lon == 0;
}
template <class T>
void Lista<T>::agregaInicial(T elem) {
    NodoLista<T>* nuevo = new NodoLista<T>(elem);
    if (nuevo != nullptr) {
        ini = nuevo;
        lon++;
    }
}
template <class T>
T Lista<T>::buscar(T elem) {
    NodoLista<T>* aux = ini;
    while (aux != nullptr) {
        if (comparar(aux->elem, elem) == 0) {
            return aux->elem;
        }
        aux = aux->sgte;
    }
    return 0;
}

template <class T>
void Lista<T>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        NodoLista<T>* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        NodoLista<T>* nuevo = new NodoLista<T>(elem);
        nuevo->set_Sgte(aux->get_Sgte());
        if (nuevo != nullptr) {

            aux->set_Sgte(nuevo);
            lon++;
        }
    }
}
template <class T>
void Lista<T>::agregaFinal(T elem) {
    agregaPos(elem, lon); // ;)
}

template <class T>
void Lista<T>::eliminaInicial() {
    if (lon > 0) {
        NodoLista<T>* aux = ini;
        ini = ini->sgte;
        delete aux;
        lon--;
    }
}

template <class T>
void Lista<T>::eliminaPos(uint pos) {
}
template <class T>
void Lista<T>::eliminaFinal() {
}

template <class T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->elem = elem;
    }
}

template <class T>
void Lista<T>::modificarPos(T elem, uint pos) {
    if (pos >= 0 && pos < lon) {
        NodoLista<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sgte;
        }
        aux->elem = elem;
    }
}
template <class T>
void Lista<T>::modificarFinal(T elem) {
    modificar(elem, lon - 1);
}

template <class T>
T Lista<T>::obtenerInicial() {
    return obtenerPos(0);
}


template <class T>
T Lista<T>::obtenerPos(uint pos) {
    if (pos >= 0 && pos < lon) {
        NodoLista<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        return aux->get_Elem();
    }
    else {
        return NULL;
    }
}
template <class T>
T Lista<T>::obtenerFinal() {
    return obtenerPos(lon - 1);
}

template <class T>
void Lista<T>::agregar(T d) //100
{
    NodoLista<T>* nuevo = new NodoLista<T>(d);
    nuevo->set_Sgte(NodoLista);
    NodoLista = nuevo;
}

//Metodos Extra de Gabriel Ramirez

template <class T>
T Lista<T>::suma(T i)
{
    if (esvacia())
        return i;
    else
        return cabeza() + resto()->suma(i);
}

template <class T>
void Lista<T>::addOrdenado(T d)
{
    if (esvacia() || cabeza() >= d)
        agregar(d);
    else
    {
        resto()->addOrdenado(d);
    }
}

template <class T>
void Lista<T>::borrar(void)
{
    if (!esvacia())
    {
        NodoLista<T>* aux = NodoLista;
        NodoLista = NodoLista->get_Sgte();
        delete aux;
    }
}




