#pragma once
#include "NodoLista.h"
#include <functional>

typedef unsigned int uint;

template <class T>
class Lista {
private:
    NodoLista<T>* ini;
    uint lon;

public:
    Lista() : ini(nullptr), lon(0) {}
    ~Lista();

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
};

template <class T>
Lista<T>::~Lista() {
    while (lon > 0) {
        eliminaInicial();
    }
}

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
        nuevo->set_Sgte(ini);
        ini = nuevo;
        lon++;
    }
}

template <class T>
void Lista<T>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        NodoLista<T>* aux = ini;
        for (uint i = 1; i < pos; i++) {
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
    agregaPos(elem, lon);
}

template <class T>
void Lista<T>::eliminaInicial() {
    if (lon > 0) {
        NodoLista<T>* aux = ini;
        ini = ini->get_Sgte();
        delete aux;
        lon--;
    }
}

template <class T>
void Lista<T>::eliminaPos(uint pos) {
    if (pos >= lon || lon == 0) return;

    if (pos == 0) {
        eliminaInicial();
        return;
    }

    NodoLista<T>* aux = ini;
    for (uint i = 0; i < pos - 1; i++) {
        aux = aux->get_Sgte();
    }

    NodoLista<T>* temp = aux->get_Sgte();
    aux->set_Sgte(temp->get_Sgte());
    delete temp;
    lon--;
}

template <class T>
void Lista<T>::eliminaFinal() {
    if (lon > 0) {
        eliminaPos(lon - 1);
    }
}

template <class T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->set_Elem(elem);
    }
}

template <class T>
void Lista<T>::modificarPos(T elem, uint pos) {
    if (pos < lon) {
        NodoLista<T>* aux = ini;
        for (uint i = 0; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        aux->set_Elem(elem);
    }
}

template <class T>
void Lista<T>::modificarFinal(T elem) {
    modificarPos(elem, lon - 1);
}

template <class T>
T Lista<T>::obtenerInicial() {
    return obtenerPos(0);
}

template <class T>
T Lista<T>::obtenerPos(uint pos) {
    if (pos < lon) {
        NodoLista<T>* aux = ini;
        for (uint i = 0; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        return aux->get_Elem();
    }
    return T();
}

template <class T>
T Lista<T>::obtenerFinal() {
    return obtenerPos(lon - 1);
}
