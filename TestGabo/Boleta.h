#pragma once
#include <iostream>
#include "DetalleBoleta.h"
#include "Perfil.h"
#include "Producto.h"
using namespace std;

template<typename S, typename I, typename F, typename TPerfil, typename TVendedor>
class Boleta
{
private:
    string nroboleta;
    string fecha;
    TVendedor* vendedor;
    Lista<Detalle_Boleta<S, I, F, TPerfil>*>* lst_detalles;

public:
    Boleta()
        : nroboleta(""), fecha(""), vendedor(nullptr), lst_detalles(new Lista<Detalle_Boleta<S, I, F, TPerfil>*>) {
    }

    Boleta(string pnroboleta, string pfecha, TVendedor* pvendedor)
        : nroboleta(pnroboleta), fecha(pfecha), vendedor(pvendedor), lst_detalles(new Lista<Detalle_Boleta<S, I, F, TPerfil>*>) {
    }

    ~Boleta() {}

    void setNroBoleta(string pnroboleta) { this->nroboleta = pnroboleta; }
    string getNroBoleta() { return this->nroboleta; }
    void setFecha(string pfecha) { this->fecha = pfecha; }
    string getFecha() { return this->fecha; }
    void setVendedor(TVendedor* pvendedor) { this->vendedor = pvendedor; }
    TVendedor* getVendedor() { return this->vendedor; }
    Lista<Detalle_Boleta<S, I, F, TPerfil>*>* getLstDetalles() { return this->lst_detalles; }
    void setLstDetalles(Lista<Detalle_Boleta<S, I, F, TPerfil>*>* plst_detalles) { this->lst_detalles = plst_detalles; }

    void MostrarBoleta()
    {
        F montoTotal = 0;
        cout << endl;
        cout << "========================================================" << endl;
        cout << "\t\tBOLETA" << endl;
        cout << "========================================================" << endl;
        cout << "NRO. BOLETA : " << this->nroboleta << endl;
        cout << "FECHA       : " << this->fecha << endl;
        if (this->vendedor)
            cout << "VENDEDOR    : " << this->vendedor->nombreCompleto() << endl;
        cout << "========================================================" << endl;
        cout << "\t\tDETALLES DE BOLETA" << endl;
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

    void AgregarDetalle(Detalle_Boleta<S, I, F, TPerfil>* detalle, int pos)
    {
        this->lst_detalles->agregaPos(detalle, pos);
    }
};