#pragma once
#include "NodoLista.h"

template <typename T>
class ListaSimple {
private:
    NodoLista<T>* cabeza;
    int tamanio;

public:
    ListaSimple();
    ~ListaSimple();

    void agregar(T elemento);
    void eliminar(int posicion);
    T obtener(int posicion);
    int getTamanio();
    bool estaVacia();
    void limpiar();
};

template <typename T>
ListaSimple<T>::ListaSimple() {
    cabeza = nullptr;
    tamanio = 0;
}

template <typename T>
ListaSimple<T>::~ListaSimple() {
    limpiar();
}

template <typename T>
void ListaSimple<T>::agregar(T elemento) {
    NodoLista<T>* nuevo = new NodoLista<T>(elemento);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    }
    else {
        NodoLista<T>* actual = cabeza;
        while (actual->get_Sgte() != nullptr) {
            actual = actual->get_Sgte();
        }
        actual->set_Sgte(nuevo);
    }
    tamanio++;
}

template <typename T>
void ListaSimple<T>::eliminar(int posicion) {
    if (posicion < 0 || posicion >= tamanio) return;

    if (posicion == 0) {
        NodoLista<T>* temp = cabeza;
        cabeza = cabeza->get_Sgte();
        delete temp;
    }
    else {
        NodoLista<T>* actual = cabeza;
        for (int i = 0; i < posicion - 1; i++) {
            actual = actual->get_Sgte();
        }
        NodoLista<T>* temp = actual->get_Sgte();
        actual->set_Sgte(temp->get_Sgte());
        delete temp;
    }
    tamanio--;
}

template <typename T>
T ListaSimple<T>::obtener(int posicion) {
    if (posicion < 0 || posicion >= tamanio) return T();

    NodoLista<T>* actual = cabeza;
    for (int i = 0; i < posicion; i++) {
        actual = actual->get_Sgte();
    }
    return actual->get_Elem();
}

template <typename T>
int ListaSimple<T>::getTamanio() {
    return tamanio;
}

template <typename T>
bool ListaSimple<T>::estaVacia() {
    return tamanio == 0;
}

template <typename T>
void ListaSimple<T>::limpiar() {
    while (cabeza != nullptr) {
        NodoLista<T>* temp = cabeza;
        cabeza = cabeza->get_Sgte();
        delete temp;
    }
    tamanio = 0;
}
