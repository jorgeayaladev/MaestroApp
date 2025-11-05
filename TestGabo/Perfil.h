#pragma once
#include <iostream>
#include <sstream>
#include "InventoryYCarrito.h"
#include "MetodoPago.h"
#include "Direccion.h"
using namespace std;

//T1 DOUBLE, T2 STRING, T3 USUARIO*
template<typename T1, typename T2, typename T3>
class Perfil {
private:
    T3 Usuario;
    T1 Saldo;
	Lista<Producto<string, int, T1>*>* lst_Deseos;
	Lista<Review<string, int, T1>*>* lst_Reviews;
	Lista<MetodoPago<string,int, float>*>* lst_MetodosPago;
	ShoppingCart<string, int, T1>* carritoCompras;
	Direccion* direccionEnvio;
public:
    Perfil(T3 Usuario, T1 Saldo, Lista<Producto<string, int, T1>*>* productosDeInventario);
    T2 toString();
    void setUsuario(T3 Usuario);
    T3 getUsuario();
    void setSaldo(T1 Saldo);
    T1 getSaldo();
	Direccion* getDireccionEnvio() { return direccionEnvio; }
	void setDireccionEnvio(Direccion* direccion) { this->direccionEnvio = direccion; }
	ShoppingCart<string, int, T1>* getCarritoCompras() { return carritoCompras; }
	Lista<Review<string, int, T1>*>* getLst_Reviews() { return lst_Reviews; }
	Lista<MetodoPago<string, int, float>*>* getMetodosPago() { return lst_MetodosPago; }
    
    void reasignarCarrito(Inventory<string, int, T1>* inventario)
    {
        this->carritoCompras = new ShoppingCart<string, int, T1>(inventario->getLst_Productos());
    }

    void añadirReview(Review<string, int, T1>* review) {
        if (!lst_Reviews) {
            lst_Reviews = new Lista<Review<string, int, T1>*>();
        }
		//Añadir condicion de si review ya se aplico a un producto, aplicar recursividad
        lst_Reviews->agregaFinal(review);
	}

	Lista<Producto<string, int, T1>*>* getLst_Deseos() { return lst_Deseos; }
    void agregarProductoDeseo(Producto<string, int, T1>* producto) {
        if (!lst_Deseos) {
            lst_Deseos = new Lista<Producto<string, int, T1>*>();
        }
        //Añadir condicion de si producto no existe en el inventario, o si ya esta en la lista de deseos, aplicar recursividad
        lst_Deseos->agregaFinal(producto);
    }

    void agregarProductoCarrito(Producto<string, int, T1>* producto) {
        if (!carritoCompras) {
            carritoCompras = new ShoppingCart<string, int, T1>();
        }
        //Añadir condicion de si producto no existe en el inventario, o si ya esta en el carrito, aplicar recursividad
		carritoCompras->getProductos()->agregaFinal(producto->getID());
	}

    void agregarMetodoPago(MetodoPago<string, int, float>* metodo) {
        if (!lst_MetodosPago) {
            lst_MetodosPago = new Lista<MetodoPago<string, int, float>*>();
        }
        lst_MetodosPago->agregaFinal(metodo);
	}

    void eliminarMetodoPago(int indice) {
        if (lst_MetodosPago && indice >= 0 && indice < lst_MetodosPago->longitud()) {
            lst_MetodosPago->eliminaPos(indice);
        }
	}
};

template<typename T1, typename T2, typename T3>
Perfil<T1, T2, T3>::Perfil(T3 Usuario, T1 Saldo, Lista<Producto<string, int, T1>*>* productosDeInventario) {
    this->Usuario = Usuario;
    this->Saldo = Saldo;
    this->carritoCompras = new ShoppingCart<string, int, T1>(productosDeInventario);
    this->lst_Reviews = new Lista<Review<string, int, T1>*>;
	this->lst_Deseos = new Lista<Producto<string, int, T1>*>();
    this->lst_MetodosPago = new Lista<MetodoPago<string,int, float>*>;
}

template<typename T1, typename T2, typename T3>
T2 Perfil<T1, T2, T3>::toString() {
    stringstream s;
    s << Usuario->toString();
    s << "Saldo: " << this->Saldo << endl;
    s << "------------------------" << endl;
	//Falta mostrar lista de deseos y reviews y metodos de pago y carrito de compras
    return s.str();
}

template<typename T1, typename T2, typename T3>
void Perfil<T1, T2, T3>::setUsuario(T3 Usuario) {
    this->Usuario = Usuario;
}

template<typename T1, typename T2, typename T3>
T3 Perfil<T1, T2, T3>::getUsuario() {
    return this->Usuario;
}

template<typename T1, typename T2, typename T3>
void Perfil<T1, T2, T3>::setSaldo(T1 Saldo) {
    this->Saldo = Saldo;
}

template<typename T1, typename T2, typename T3>
T1 Perfil<T1, T2, T3>::getSaldo() {
    return this->Saldo;
}


