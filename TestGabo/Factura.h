#pragma once

#include <iostream>
#include "DetalleFactura.h"
#include "Perfil.h"
#include "Producto.h"

using namespace std;

template<typename S, typename I, typename F, typename TPerfil, typename TVendedor>
class Factura
{
private:
    string nroFactura;
    string fecha;
    TVendedor* vendedor;
    Lista<Detalle_Factura<S, I, F, TPerfil>*>* lst_detalles;
    string ruc;
    string razonSocial;

public:
    Factura()
        : nroFactura(""), fecha(""), vendedor(nullptr), ruc(""), razonSocial(""),
        lst_detalles(new Lista<Detalle_Factura<S, I, F, TPerfil>*>) {
    }

    Factura(string pnroFactura, string pfecha, TVendedor* pvendedor, string pruc, string prazonSocial)
        : nroFactura(pnroFactura), fecha(pfecha), vendedor(pvendedor), ruc(pruc), razonSocial(prazonSocial),
        lst_detalles(new Lista<Detalle_Factura<S, I, F, TPerfil>*>) {
    }

    ~Factura() {}

    void setNroFactura(string pnroFactura) { this->nroFactura = pnroFactura; }
    string getNroFactura() { return this->nroFactura; }

    void setFecha(string pfecha) { this->fecha = pfecha; }
    string getFecha() { return this->fecha; }

    void setVendedor(TVendedor* pvendedor) { this->vendedor = pvendedor; }
    TVendedor* getVendedor() { return this->vendedor; }

    void setRuc(string pruc) { this->ruc = pruc; }
    string getRuc() { return this->ruc; }

    void setRazonSocial(string prazonSocial) { this->razonSocial = prazonSocial; }
    string getRazonSocial() { return this->razonSocial; }

    Lista<Detalle_Factura<S, I, F, TPerfil>*>* getLstDetalles() { return this->lst_detalles; }
    void setLstDetalles(Lista<Detalle_Factura<S, I, F, TPerfil>*>* plst_detalles) { this->lst_detalles = plst_detalles; }

    void MostrarFactura()
    {
        F montoTotal = 0;
        cout << endl;
        cout << "========================================================" << endl;
        cout << "\t\tFACTURA" << endl;
        cout << "========================================================" << endl;
        cout << "NRO. FACTURA : " << this->nroFactura << endl;
        cout << "FECHA        : " << this->fecha << endl;
        cout << "RUC          : " << this->ruc << endl;
        cout << "RAZÓN SOCIAL : " << this->razonSocial << endl;
        if (this->vendedor)
            cout << "VENDEDOR     : " << this->vendedor->nombreCompleto() << endl;
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