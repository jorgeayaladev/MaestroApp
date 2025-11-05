#pragma once

#include <iostream>
#include <sstream>
#include "Proveedor.h"
#include "Review.h"
#include "Lista.h"

using namespace std;

template <typename S, typename I, typename F>
class Producto {
private:
    I idProducto;
    S nombre, tipo, descripcion;
    F precio;
    int stock;
    Proveedor<S, I>* proveedor;
    Lista<Review<S, I, F>*>* reviews;

public:
    Producto();
    Producto(I idProducto_, S nombre_, S tipo_, S descripcion_, F precio_, int stock_, Proveedor<S, I>* proveedor_);
    ~Producto();

    void setIdProducto(I idProducto_);
    I getIdProducto();
    void setNombre(S nombre_);
    S getNombre();
    void setTipo(S tipo_);
    S getTipo();
    void setDescripcion(S descripcion_);
    S getDescripcion();
    void setPrecio(F precio_);
    F getPrecio();
    void setStock(int stock_);
    int getStock();
    void setProveedor(Proveedor<S, I>* proveedor_);
    Proveedor<S, I>* getProveedor();
    Lista<Review<S, I, F>*>* getReviews();

    void agregarReview(Review<S, I, F>* review);
    F verCalificacionNumerica();
    void mostrarProducto();
    void mostrarReviews();
    S toString();
};

template <typename S, typename I, typename F>
Producto<S, I, F>::Producto() {
    this->idProducto = 0;
    this->nombre = "";
    this->tipo = "";
    this->descripcion = "";
    this->precio = 0;
    this->stock = 0;
    this->proveedor = nullptr;
    this->reviews = new Lista<Review<S, I, F>*>();
}

template <typename S, typename I, typename F>
Producto<S, I, F>::Producto(I idProducto_, S nombre_, S tipo_, S descripcion_, F precio_, int stock_, Proveedor<S, I>* proveedor_) {
    this->idProducto = idProducto_;
    this->nombre = nombre_;
    this->tipo = tipo_;
    this->descripcion = descripcion_;
    this->precio = precio_;
    this->stock = stock_;
    this->proveedor = proveedor_;
    this->reviews = new Lista<Review<S, I, F>*>();
}

template <typename S, typename I, typename F>
Producto<S, I, F>::~Producto() {
    if (reviews != nullptr) {
        delete reviews;
    }
}

template <typename S, typename I, typename F>
void Producto<S, I, F>::setIdProducto(I idProducto_) { this->idProducto = idProducto_; }

template <typename S, typename I, typename F>
I Producto<S, I, F>::getIdProducto() { return this->idProducto; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setNombre(S nombre_) { this->nombre = nombre_; }

template <typename S, typename I, typename F>
S Producto<S, I, F>::getNombre() { return this->nombre; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setTipo(S tipo_) { this->tipo = tipo_; }

template <typename S, typename I, typename F>
S Producto<S, I, F>::getTipo() { return this->tipo; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setDescripcion(S descripcion_) { this->descripcion = descripcion_; }

template <typename S, typename I, typename F>
S Producto<S, I, F>::getDescripcion() { return this->descripcion; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setPrecio(F precio_) { this->precio = precio_; }

template <typename S, typename I, typename F>
F Producto<S, I, F>::getPrecio() { return this->precio; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setStock(int stock_) { this->stock = stock_; }

template <typename S, typename I, typename F>
int Producto<S, I, F>::getStock() { return this->stock; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setProveedor(Proveedor<S, I>* proveedor_) { this->proveedor = proveedor_; }

template <typename S, typename I, typename F>
Proveedor<S, I>* Producto<S, I, F>::getProveedor() { return this->proveedor; }

template <typename S, typename I, typename F>
Lista<Review<S, I, F>*>* Producto<S, I, F>::getReviews() { return this->reviews; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::agregarReview(Review<S, I, F>* review) {
    this->reviews->agregaFinal(review);
}

template <typename S, typename I, typename F>
F Producto<S, I, F>::verCalificacionNumerica() {
    if (this->reviews->longitud() == 0) return 0;

    F suma = 0;
    for (uint i = 0; i < this->reviews->longitud(); i++) {
        suma += this->reviews->obtenerPos(i)->getCalificacion();
    }
    return suma / this->reviews->longitud();
}

template <typename S, typename I, typename F>
void Producto<S, I, F>::mostrarProducto() {
    cout << "======================================" << endl;
    cout << "ID: " << this->idProducto << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Tipo: " << this->tipo << endl;
    cout << "Descripcion: " << this->descripcion << endl;
    cout << "Precio: S/." << this->precio << endl;
    cout << "Stock: " << this->stock << " unidades" << endl;
    if (this->proveedor != nullptr) {
        cout << "Proveedor: " << this->proveedor->getEmpresa() << endl;
    }
    cout << "Calificacion: " << verCalificacionNumerica() << " estrellas" << endl;
    cout << "======================================" << endl;
}

template <typename S, typename I, typename F>
void Producto<S, I, F>::mostrarReviews() {
    if (this->reviews->longitud() == 0) {
        cout << "No hay reviews para este producto." << endl;
        return;
    }

    cout << endl << "========== REVIEWS DEL PRODUCTO ==========" << endl;
    for (uint i = 0; i < this->reviews->longitud(); i++) {
        this->reviews->obtenerPos(i)->verReview();
        cout << endl;
    }
}

template <typename S, typename I, typename F>
S Producto<S, I, F>::toString() {
    stringstream s;
    s << "ID: " << this->idProducto << ", Nombre: " << this->nombre
        << ", Tipo: " << this->tipo << ", Precio: " << this->precio
        << ", Stock: " << this->stock;
    return s.str();
}
