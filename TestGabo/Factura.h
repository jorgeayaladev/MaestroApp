#pragma once
#include <iostream>
#include "DetalleFactura.h"
#include "Perfil.h"
#include "Producto.h"
using namespace std;

template<typename S, typename I, typename F, typename TPerfil, typename TCliente>
class Factura
{
private:
    string nroFactura;
    string fecha;
    TCliente* cliente;
    Lista<Detalle_Factura<S, I, F, TPerfil>*>* lst_detalles;

public:
    Factura()
        : nroFactura(""), fecha(""), cliente(nullptr), lst_detalles(new Lista<Detalle_Factura<S, I, F, TPerfil>*>) {
    }

    Factura(string pnroFactura, string pfecha, TCliente* pcliente)
        : nroFactura(pnroFactura), fecha(pfecha), cliente(pcliente), lst_detalles(new Lista<Detalle_Factura<S, I, F, TPerfil>*>) {
    }

    ~Factura() {}

    void setNroFactura(string pnroFactura) { this->nroFactura = pnroFactura; }
    string getNroFactura() { return this->nroFactura; }
    void setFecha(string pfecha) { this->fecha = pfecha; }
    string getFecha() { return this->fecha; }
    void setCliente(TCliente* pcliente) { this->cliente = pcliente; }
    TCliente* getCliente() { return this->cliente; }
    Lista<Detalle_Factura<S, I, F, TPerfil>*>* getLstDetalles() { return this->lst_detalles; }
    void setLstDetalles(Lista<Detalle_Factura<S, I, F, TPerfil>*>* plst_detalles) { this->lst_detalles = plst_detalles; }

    void MostrarFactura()
    {
        F montoTotal = 0;
        cout << endl;
        cout << "========================================================" << endl;
        cout << "\t\tFACTURA" << endl;
        cout << "========================================================" << endl;
        cout << "NRO. FACTURA: " << this->nroFactura << endl;
        cout << "FECHA       : " << this->fecha << endl;
        if (this->cliente)
            cout << "CLIENTE     : " << this->cliente->nombreCompleto() << endl;
        cout << "========================================================" << endl;
        cout << "\t\tDETALLES DE FACTURA" << endl;
        cout << "========================================================" << endl;
        for (uint i = 0; i < lst_detalles->longitud(); i++)
        {
            lst_detalles->obtenerPos(i)->MostrarDetalle(i + 1);
            montoTotal = montoTotal + lst_detalles->obtenerPos(i)->Subtotal();
        }
        cout << endl;
        cout << "\t\t\t\t-------------------------" << endl;
        cout << "\t\t\t\tMONTO TOTAL: " << montoTotal << endl;
        cout << "\t\t\t\t-------------------------" << endl;
    }

    F MontoTotal()
    {
        F total = 0;
        for (uint i = 0; i < lst_detalles->longitud(); i++)
        {
            total += lst_detalles->obtenerPos(i)->Subtotal();
        }
        return total;
    }

    void AgregarDetalle(Detalle_Factura<S, I, F, TPerfil>* detalle, int pos)
    {
        this->lst_detalles->agregaPos(detalle, pos);
    }
};
