#pragma once

#include <iostream>
#include "Producto.h"
#include "Lista.h"

using namespace std;

template <typename S, typename I, typename F>
class Inventory {
private:
    Lista<Producto<S, I, F>*>* productos;

public:
    Inventory();
    ~Inventory();

    void agregarProducto(Producto<S, I, F>* producto);
    void eliminarProducto(I idProducto);
    Producto<S, I, F>* buscarProducto(I idProducto);
    void mostrarInventario();
    Lista<Producto<S, I, F>*>* getProductos();
};

template <typename S, typename I, typename F>
Inventory<S, I, F>::Inventory() {
    this->productos = new Lista<Producto<S, I, F>*>();
}

template <typename S, typename I, typename F>
Inventory<S, I, F>::~Inventory() {
    if (productos != nullptr) {
        delete productos;
    }
}

template <typename S, typename I, typename F>
void Inventory<S, I, F>::agregarProducto(Producto<S, I, F>* producto) {
    this->productos->agregaFinal(producto);
}

template <typename S, typename I, typename F>
void Inventory<S, I, F>::eliminarProducto(I idProducto) {
    for (uint i = 0; i < this->productos->longitud(); i++) {
        if (this->productos->obtenerPos(i)->getIdProducto() == idProducto) {
            this->productos->eliminaPos(i);
            break;
        }
    }
}

template <typename S, typename I, typename F>
Producto<S, I, F>* Inventory<S, I, F>::buscarProducto(I idProducto) {
    for (uint i = 0; i < this->productos->longitud(); i++) {
        if (this->productos->obtenerPos(i)->getIdProducto() == idProducto) {
            return this->productos->obtenerPos(i);
        }
    }
    return nullptr;
}

template <typename S, typename I, typename F>
void Inventory<S, I, F>::mostrarInventario() {
    cout << endl << "========== INVENTARIO ==========" << endl;
    if (this->productos->longitud() == 0) {
        cout << "No hay productos en el inventario." << endl;
    }
    else {
        for (uint i = 0; i < this->productos->longitud(); i++) {
            this->productos->obtenerPos(i)->mostrarProducto();
        }
    }
    cout << "=================================" << endl;
}

template <typename S, typename I, typename F>
Lista<Producto<S, I, F>*>* Inventory<S, I, F>::getProductos() {
    return this->productos;
}

template <typename S, typename I, typename F>
class ItemCarrito {
private:
    Producto<S, I, F>* producto;
    int cantidad;

public:
    ItemCarrito();
    ItemCarrito(Producto<S, I, F>* producto_, int cantidad_);

    void setProducto(Producto<S, I, F>* producto_);
    Producto<S, I, F>* getProducto();
    void setCantidad(int cantidad_);
    int getCantidad();
    F calcularSubtotal();
};

template <typename S, typename I, typename F>
ItemCarrito<S, I, F>::ItemCarrito() {
    this->producto = nullptr;
    this->cantidad = 0;
}

template <typename S, typename I, typename F>
ItemCarrito<S, I, F>::ItemCarrito(Producto<S, I, F>* producto_, int cantidad_) {
    this->producto = producto_;
    this->cantidad = cantidad_;
}

template <typename S, typename I, typename F>
void ItemCarrito<S, I, F>::setProducto(Producto<S, I, F>* producto_) { this->producto = producto_; }

template <typename S, typename I, typename F>
Producto<S, I, F>* ItemCarrito<S, I, F>::getProducto() { return this->producto; }

template <typename S, typename I, typename F>
void ItemCarrito<S, I, F>::setCantidad(int cantidad_) { this->cantidad = cantidad_; }

template <typename S, typename I, typename F>
int ItemCarrito<S, I, F>::getCantidad() { return this->cantidad; }

template <typename S, typename I, typename F>
F ItemCarrito<S, I, F>::calcularSubtotal() {
    return this->producto->getPrecio() * this->cantidad;
}

template <typename S, typename I, typename F>
class ShoppingCart {
private:
    Lista<ItemCarrito<S, I, F>*>* items;

public:
    ShoppingCart();
    ~ShoppingCart();

    void agregarItem(Producto<S, I, F>* producto, int cantidad);
    void eliminarItem(I idProducto);
    void modificarCantidad(I idProducto, int nuevaCantidad);
    void vaciarCarrito();
    F calcularTotal();
    void mostrarCarrito();
    Lista<ItemCarrito<S, I, F>*>* getItems();
};

template <typename S, typename I, typename F>
ShoppingCart<S, I, F>::ShoppingCart() {
    this->items = new Lista<ItemCarrito<S, I, F>*>();
}

template <typename S, typename I, typename F>
ShoppingCart<S, I, F>::~ShoppingCart() {
    if (items != nullptr) {
        delete items;
    }
}

template <typename S, typename I, typename F>
void ShoppingCart<S, I, F>::agregarItem(Producto<S, I, F>* producto, int cantidad) {
    if (producto == nullptr || cantidad <= 0) {
        cout << "Error: Producto invalido o cantidad incorrecta." << endl;
        return;
    }

    if (producto->getStock() < cantidad) {
        cout << "Error: Stock insuficiente. Stock disponible: " << producto->getStock() << endl;
        return;
    }

    for (uint i = 0; i < this->items->longitud(); i++) {
        if (this->items->obtenerPos(i)->getProducto()->getIdProducto() == producto->getIdProducto()) {
            int nuevaCantidad = this->items->obtenerPos(i)->getCantidad() + cantidad;
            if (producto->getStock() >= nuevaCantidad) {
                this->items->obtenerPos(i)->setCantidad(nuevaCantidad);
                cout << "Cantidad actualizada en el carrito." << endl;
                return;
            }
            else {
                cout << "Error: Stock insuficiente para agregar mas unidades." << endl;
                return;
            }
        }
    }

    ItemCarrito<S, I, F>* nuevoItem = new ItemCarrito<S, I, F>(producto, cantidad);
    this->items->agregaFinal(nuevoItem);
    cout << "Producto agregado al carrito exitosamente." << endl;
}

template <typename S, typename I, typename F>
void ShoppingCart<S, I, F>::eliminarItem(I idProducto) {
    for (uint i = 0; i < this->items->longitud(); i++) {
        if (this->items->obtenerPos(i)->getProducto()->getIdProducto() == idProducto) {
            this->items->eliminaPos(i);
            cout << "Producto eliminado del carrito." << endl;
            return;
        }
    }
    cout << "Producto no encontrado en el carrito." << endl;
}

template <typename S, typename I, typename F>
void ShoppingCart<S, I, F>::modificarCantidad(I idProducto, int nuevaCantidad) {
    if (nuevaCantidad <= 0) {
        eliminarItem(idProducto);
        return;
    }

    for (uint i = 0; i < this->items->longitud(); i++) {
        if (this->items->obtenerPos(i)->getProducto()->getIdProducto() == idProducto) {
            if (this->items->obtenerPos(i)->getProducto()->getStock() >= nuevaCantidad) {
                this->items->obtenerPos(i)->setCantidad(nuevaCantidad);
                cout << "Cantidad actualizada." << endl;
                return;
            }
            else {
                cout << "Error: Stock insuficiente." << endl;
                return;
            }
        }
    }
    cout << "Producto no encontrado en el carrito." << endl;
}

template <typename S, typename I, typename F>
void ShoppingCart<S, I, F>::vaciarCarrito() {
    while (this->items->longitud() > 0) {
        this->items->eliminaInicial();
    }
    cout << "Carrito vaciado." << endl;
}

template <typename S, typename I, typename F>
F ShoppingCart<S, I, F>::calcularTotal() {
    F total = 0;
    for (uint i = 0; i < this->items->longitud(); i++) {
        total += this->items->obtenerPos(i)->calcularSubtotal();
    }
    return total;
}

template <typename S, typename I, typename F>
void ShoppingCart<S, I, F>::mostrarCarrito() {
    cout << endl << "========== CARRITO DE COMPRAS ==========" << endl;
    if (this->items->longitud() == 0) {
        cout << "El carrito esta vacio." << endl;
    }
    else {
        for (uint i = 0; i < this->items->longitud(); i++) {
            ItemCarrito<S, I, F>* item = this->items->obtenerPos(i);
            cout << (i + 1) << ". " << item->getProducto()->getNombre()
                << " - Cantidad: " << item->getCantidad()
                << " - Precio unitario: S/." << item->getProducto()->getPrecio()
                << " - Subtotal: S/." << item->calcularSubtotal() << endl;
        }
        cout << "========================================" << endl;
        cout << "TOTAL: S/." << calcularTotal() << endl;
    }
    cout << "=========================================" << endl;
}

template <typename S, typename I, typename F>
Lista<ItemCarrito<S, I, F>*>* ShoppingCart<S, I, F>::getItems() {
    return this->items;
}
