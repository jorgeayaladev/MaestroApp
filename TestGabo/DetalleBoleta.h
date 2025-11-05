#pragma once

#include <iostream>
#include "Producto.h"
#include "Perfil.h"

using namespace std;

template<typename S, typename I, typename F, typename TPerfil>
class Detalle_Boleta
{
private:
    string coddetalle;
    string nroBoleta;
    int cantidad;
    F precio;
    TPerfil* perfil;
    Producto<S, I, F>* producto;

public:
    Detalle_Boleta()
        : coddetalle(""), nroBoleta(""), cantidad(0), precio(0), perfil(nullptr), producto(nullptr) {
    }

    Detalle_Boleta(string pcoddetalle, string pnroBoleta,
        int pcantidad, F pprecio, TPerfil* pPerfil, Producto<S, I, F>* pProducto)
        : coddetalle(pcoddetalle), nroBoleta(pnroBoleta), cantidad(pcantidad), precio(pprecio), perfil(pPerfil), producto(pProducto) {
    }

    void setCodDetalle(string pcoddetalle) { this->coddetalle = pcoddetalle; }
    string getCodDetalle() { return this->coddetalle; }

    void setNroBoleta(string pnroBoleta) { this->nroBoleta = pnroBoleta; }
    string getNroBoleta() { return this->nroBoleta; }

    void setCantidad(int pcantidad) { this->cantidad = pcantidad; }
    int getCantidad() { return this->cantidad; }

    void setPrecio(F pprecio) { this->precio = pprecio; }
    F getPrecio() { return this->precio; }

    void setPerfil(TPerfil* pPerfil) { this->perfil = pPerfil; }
    TPerfil* getPerfil() { return this->perfil; }

    void setProducto(Producto<S, I, F>* pProducto) { this->producto = pProducto; }
    Producto<S, I, F>* getProducto() { return this->producto; }

    F Subtotal()
    {
        return static_cast<F>(this->cantidad) * this->precio;
    }

    void MostrarDetalle(int nro)
    {
        cout << nro << "\t" << getNroBoleta() << "\t"
            << getProducto()->getNombre() << "\t"
            << getCantidad() << "\t"
            << getPrecio() << "\t"
            << Subtotal() << endl;
    }
};
