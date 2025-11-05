#pragma once
#include <iostream>
#include "Producto.h"
#include "Perfil.h"
#include "InventoryYCarrito.h"

using namespace std;

template<typename S, typename I, typename F, typename TPerfil>
class Detalle_Boleta
{
public:
    string coddetalle;
    string nroboleta;
    int cantidad;
    F precio;
    TPerfil* perfil; 
    Producto<S, I, F>* producto;

public:
    Detalle_Boleta()
        : coddetalle(""), nroboleta(""), cantidad(0), precio(0), perfil(nullptr), producto(nullptr) {
    }

    Detalle_Boleta(string pcoddetalle, string pnroboleta,
        int pcantidad, F pprecio, TPerfil* pPerfil, Producto<S, I, F>* pProducto)
        : coddetalle(pcoddetalle), nroboleta(pnroboleta), cantidad(pcantidad), precio(pprecio), perfil(pPerfil), producto(pProducto) {
    }

    //Métodos Setter / Getter
    void setCodDetalle(string pcoddetalle) { this->coddetalle = pcoddetalle; }
    string getCodDetalle() { return this->coddetalle; }
    void setNroBoleta(string pnroboleta) { this->nroboleta = pnroboleta; }
    string getNroBoleta() { return this->nroboleta; }
    void setCantidad(int pcantidad) { this->cantidad = pcantidad; }
    int getCantidad() { return this->cantidad; }
    void setPrecio(F pprecio) { this->precio = pprecio; }
    F getPrecio() { return this->precio; }
    void setPerfil(TPerfil* pPerfil) { this->perfil = pPerfil; }
    TPerfil* getPerfil() { return this->perfil; }
    void setProducto(Producto<S, I, F>* pProducto) { this->producto = pProducto; }
    Producto<S, I, F>* getProducto() { return this->producto; }

    //Métodos de Servicio
    F Subtotal()
    {
        return static_cast<F>(this->cantidad) * this->precio;
    }
    void MostrarDetalle(int nro)
    {
        cout << nro << "\t" << getNroBoleta() << "\t" << getProducto()->getNombre() << "\t" << getCantidad()
            << "\t" << getPrecio() << "\t" << Subtotal() << endl;
    }
};