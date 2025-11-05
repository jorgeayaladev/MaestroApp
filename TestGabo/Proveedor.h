#pragma once

#include <iostream>

template <typename S, typename I>
class Proveedor {
private:

	S nombre, empresa;
	I idTrabajador;

public:

	Proveedor();
	Proveedor(S nombre_, S empresa_, I id);

	void setNombre(S nombre_);
	void setEmpresa(S empresa_);
	void setIdTrabajador(I id_);
	S getNombre();
	S getEmpresa();
	I getIdTrabajador();

	void datosProveedor();

};

template <typename S, typename I>
Proveedor<S, I>::Proveedor() {
	this->nombre = " ";
	this->empresa = " ";
	this->idTrabajador = 0;
}

template <typename S, typename I>
Proveedor<S, I>::Proveedor(S nombre_, S empresa_, I id) {
	this->nombre = nombre_;
	this->empresa = empresa_;
	this->idTrabajador = id;
}

template <typename S, typename I>
void Proveedor<S, I>::setNombre(S nombre_) { this->nombre = nombre_; }

template <typename S, typename I>
void Proveedor<S, I>::setEmpresa(S empresa_) { this->empresa = empresa_; }

template <typename S, typename I>
void Proveedor<S, I>::setIdTrabajador(I id_) { this->idTrabajador = id_; }

template <typename S, typename I>
S Proveedor<S, I>::getNombre() { return nombre; }

template <typename S, typename I>
S Proveedor<S, I>::getEmpresa() { return empresa; }

template <typename S, typename I>
I Proveedor<S, I>::getIdTrabajador() { return idTrabajador; }

template <typename S, typename I>
void Proveedor<S, I>::datosProveedor() {
	cout << "\t- Nombre del proveedor: " << this->nombre << std::endl;
	cout << "\t- Empresa del proveedor: " << this->empresa << std::endl;
	cout << "\t- ID del trabajador: " << this->idTrabajador << std::endl;
}