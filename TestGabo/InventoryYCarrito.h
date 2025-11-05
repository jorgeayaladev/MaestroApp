#pragma once
#include "FiltrosDeProductos.h"
#include "ListaSimple.h"

template <typename S, typename I, typename F>
class Inventory : public FiltrosDeProductos<S, I, F>
{
private:

public:
    Inventory();
    void agregarProducto(Producto<S, I, F>* producto) {
        this->getLst_Productos()->agregaFinal(producto);
    }
};

template <typename S, typename I, typename F>
Inventory<S, I, F>::Inventory() { FiltrosDeProductos(); }

// =====================================================
// Carrito de compras
// =====================================================

template <typename S, typename I, typename F>
class ShoppingCart : public FiltrosDeProductos<S, I, F>
{
private:
    ListaSimple<int>* productos; // IDs de productos
    F monto;

public:
    ShoppingCart();
    ShoppingCart(Lista<Producto<S, I, F>*>* productosInventario_);

    void setProductosInventario(Lista<Producto<S, I, F>*>* productosInventario_);
    F getMonto();
    void setMonto(F monto_);
    ListaSimple<int>* getProductos() { return productos; }

    F calcularMonto();
    void mostrarCarrito(I& n);
    Lista<Producto<S, I, F>*>* sumarProducto(I id, I& n);

    // NUEVO MÉTODO
    void vaciarCarrito();
};

template <typename S, typename I, typename F>
ShoppingCart<S, I, F>::ShoppingCart() { FiltrosDeProductos(); }

template <typename S, typename I, typename F>
ShoppingCart<S, I, F>::ShoppingCart(Lista<Producto<S, I, F>*>* productosInventario) {
    setLst_Productos(productosInventario);
    this->productos = new ListaSimple<I>();
    this->monto = 0;
}

template <typename S, typename I, typename F>
void ShoppingCart<S, I, F>::setProductosInventario(Lista<Producto<S, I, F>*>* productosInventario) {
    this->productosInventario = productosInventario;
}

template <typename S, typename I, typename F>
F ShoppingCart<S, I, F>::getMonto() { return monto; }

template <typename S, typename I, typename F>
void ShoppingCart<S, I, F>::setMonto(F monto_) { this->monto = monto_; }

template <typename S, typename I, typename F>
F ShoppingCart<S, I, F>::calcularMonto() {
    this->monto = 0; // Evitar acumulación en llamadas repetidas
    for (int i = 0; i < productos->longitud(); ++i) {
        for (int j = 0; j < this->getLst_Productos()->longitud(); ++j) {
            if (productos->obtenerPos(i) == this->getLst_Productos()->obtenerPos(j)->getID()) {
                this->monto += this->getLst_Productos()->obtenerPos(j)->getPrecio();
            }
        }
    }
    return this->monto;
}

template <typename S, typename I, typename F>
void ShoppingCart<S, I, F>::mostrarCarrito(I& n) {
    if (n < productos->longitud()) {
        cout << "Codigo del producto " << n + 1 << ": " << productos->obtenerPos(n) << " (";
        for (int i = 0; i < getLst_Productos()->longitud(); ++i)
            if (this->productos->obtenerPos(n) == this->getLst_Productos()->obtenerPos(i)->getID())
                cout << this->getLst_Productos()->obtenerPos(i)->getNombre() << ")" << endl;
        ++n;
        mostrarCarrito(n);
    }
    n = 0;
}

template <typename S, typename I, typename F>
Lista<Producto<S, I, F>*>* ShoppingCart<S, I, F>::sumarProducto(I id, I& n) {
    if (id == this->getLst_Productos()->obtenerPos(n)->getID()) {
        if (this->getLst_Productos()->obtenerPos(n)->getStock() > 0) {
            productos->agregaFinal(id);
            this->getLst_Productos()->obtenerPos(n)->setStock(this->getLst_Productos()->obtenerPos(n)->getStock() - 1);
            n = 0;
            return this->getLst_Productos();
        }
    }
    else {
        n++;
        sumarProducto(id, n);
    }
    n = 0;
    return this->getLst_Productos();
}

template <typename S, typename I, typename F>
void ShoppingCart<S, I, F>::vaciarCarrito() {
    if (productos) {
        delete productos;
        productos = new ListaSimple<int>();
    }
    monto = 0;
}