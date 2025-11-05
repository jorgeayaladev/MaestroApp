#pragma once

#include "Producto.h"

template <typename S, typename I, typename F>
class FiltrosDeProductos
{
private:

	Lista<Producto<S, I, F>*>* lst_productos;

public:

	FiltrosDeProductos();

	Lista<Producto<S, I, F>*>* getLst_Productos();
	void setLst_Productos(Lista<Producto<S, I, F>*>* lst_productos_);

	virtual void mostrarProductos();
	void filtrarPorEmpresa(S empresa);
	void filtrarPorTipo(S tipo);
	void filtrarPorPrecio(F precio);
	void filtrarPorCalificacion(I caificacion);

};

template <typename S, typename I, typename F>
FiltrosDeProductos<S, I, F>::FiltrosDeProductos()
{

	lst_productos = new Lista<Producto<S, I, F>*>;

}

template <typename S, typename I, typename F>
Lista<Producto<S, I, F>*>* FiltrosDeProductos<S, I, F>::getLst_Productos() { return lst_productos; }

template <typename S, typename I, typename F>
void FiltrosDeProductos<S, I, F>::setLst_Productos(Lista<Producto<S, I, F>*>* lst_productos_) { this->lst_productos = lst_productos_; }

template <typename S, typename I, typename F>
void FiltrosDeProductos<S, I, F>::mostrarProductos() {

	for (int i = 0; i < lst_productos->longitud(); ++i) {

		cout << "Producto Nro " << i + 1 << ": " << endl << endl;

		lst_productos->obtenerPos(i)->mostrarProducto();

	}

}

template <typename S, typename I, typename F>
void FiltrosDeProductos<S, I, F>::filtrarPorEmpresa(S empresa) {
	for (int i = 0; i < lst_productos->longitud(); ++i) {
		if (empresa == lst_productos->obtenerPos(i)->getProveedor()->getNombre()) {
			cout << "Producto Nro " << i + 1 << ": " << endl << endl;
			lst_productos->obtenerPos(i)->mostrarProducto();
		}
	}
}

template <typename S, typename I, typename F>
void FiltrosDeProductos<S, I, F>::filtrarPorTipo(S tipo) {

	for (int i = 0; i < lst_productos->longitud(); ++i) {

		if (tipo == lst_productos->obtenerPos(i)->getTipo()) {

			cout << "Producto Nro " << i + 1 << ": " << endl << endl;

			lst_productos->obtenerPos(i)->mostrarProducto();

		}

	}

}

template <typename S, typename I, typename F>
void FiltrosDeProductos<S, I, F>::filtrarPorPrecio(F precio) {

	for (int i = 0; i < lst_productos->longitud(); ++i) {

		if (precio >= lst_productos->obtenerPos(i)->getPrecio()) {

			cout << "Producto Nro " << i + 1 << ": " << endl << endl;

			lst_productos->obtenerPos(i)->mostrarProducto();

		}

	}

}

template <typename S, typename I, typename F>
void FiltrosDeProductos<S, I, F>::filtrarPorCalificacion(I caificacion) {

	for (int i = 0; i < lst_productos->longitud(); ++i) {

		if (caificacion >= lst_productos->obtenerPos(i)->verCalificacionNumerica()) {

			cout << "Producto Nro " << i + 1 << ": " << endl << endl;

			lst_productos->obtenerPos(i)->mostrarProducto();

		}

	}

}