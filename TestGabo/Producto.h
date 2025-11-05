#pragma once

#include <iostream>
#include "Review.h"
#include "Lista.h"
#include "Proveedor.h"

using namespace std;

template <typename S, typename I, typename F>
class Producto
{
private:

	S nombre, color, material, tipo, codTienda;
	I id, stock, reviews, descuentoPrcnt;
	F calificacion, alto, ancho, precio;
	Lista<Review<S, I, F>*>* lst_reviews;
	bool descuentoActivo;
	Proveedor<S, I>* proveedor;

public:

	//constructores

	Producto();

	Producto(I id_, S nombre_, I tipo_, S color_, S material_, S codTienda_, I stock_,
		F alto_, F ancho_, F precio_, bool descuentoAct, I descuentoPrcnt_, Proveedor<S, I>* proveedor_);

	//setters y getters

	void setID(I id);
	void setNombre(S nombre_);
	void setTipo(S tipo_);
	void setColor(S color_);
	void setMaterial(S material_);
	void setStock(I stock_);
	void setCalificacion(F calificacion_);
	void setAlto(F alto_);
	void setAncho(F ancho_);
	void setPrecio(F precio_);

	/*setters desde color a precio hechos con chatGPT para ahorrar tiempo*/

	I getID();
	S getNombre();
	S getTipo();
	S getColor();
	S getMaterial();
	I getStock();
	F getCalificacion();
	F getAlto();
	F getAncho();
	F getPrecio();
	Lista<Review<S, I, F>*>* getLst_Reviews();
	bool getDescuentoActivo() { return this->descuentoActivo; }
	I getDescuentoPrcnt() { return this->descuentoPrcnt; }
	Proveedor<S, I>* getProveedor() { return this->proveedor; }

	/*getters desde color a precio hechos con chatGPT para ahorrar tiempo*/

	//metodos

	S especificarTipo(int n);
	S verCalificacion();
	F verCalificacionNumerica();
	void nuevaReview(I puntos, I ID, S comentario, S hechoPor);
	void mostrarProducto();
	void mostrarReviews();

	S toString() {
		stringstream s;
		s << "ID: " << this->id << ", Nombre: " << this->nombre << ", Tipo: " << this->tipo
			<< ", Color: " << this->color << ", Material: " << this->material
			<< ", Codigo de Tienda: " << this->codTienda << ", Stock: " << this->stock
			<< ", Calificacion: " << this->calificacion << ", Alto: " << this->alto
			<< ", Ancho: " << this->ancho << ", Precio: " << this->precio;
		return s.str();
	}

};

//setters y getters

template <typename S, typename I, typename F>
Producto<S, I, F>::Producto() {
	this->id = 0;
	this->nombre = " ";
	this->tipo = " ";
	this->color = " ";
	this->material = " ";
	this->codTienda = " ";
	this->stock = 0;
	this->calificacion = 0;
	this->alto = 0;
	this->ancho = 0;
	this->precio = 0;
	this->lst_reviews = new Lista<Review<S, I, F>*>;
	this->descuentoActivo = false;
	this->descuentoPrcnt = 0;
	this->proveedor = new Proveedor<S, I>();
}

template <typename S, typename I, typename F>
Producto<S, I, F>::Producto(I id_, S nombre_, I tipo_, S color_, S material_, S codTienda_, I stock_,
	F alto_, F ancho_, F precio_, bool descuentoAct, I descuentoPrcnt_, Proveedor<S, I>* proveedor_) {
	this->id = id_;
	this->nombre = nombre_;
	this->tipo = especificarTipo(tipo_);
	this->color = color_;
	this->material = material_;
	this->codTienda = codTienda_;
	this->stock = stock_;
	this->calificacion = 0;
	this->alto = alto_;
	this->ancho = ancho_;
	this->lst_reviews = new Lista<Review<S, I, F>*>;
	this->descuentoActivo = descuentoAct;
	this->descuentoPrcnt = descuentoPrcnt_;
	this->proveedor = proveedor_;

	if (this->descuentoPrcnt && this->descuentoPrcnt > 0) {
		this->precio = precio_ - (precio_ * (this->descuentoPrcnt / 100.0));
	}
	else {
		this->precio = precio_;
	}

}

//setters

template <typename S, typename I, typename F>
void Producto<S, I, F>::setID(I id) { this->idUnico = id; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setNombre(S nombre_) { this->nombre = nombre_; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setTipo(S tipo_) { this->tipo = tipo_; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setColor(S color_) { this->color = color_; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setMaterial(S material_) { this->material = material_; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setStock(I stock_) { this->stock = stock_; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setCalificacion(F calificacion_) { this->calificacion = calificacion_; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setAlto(F alto_) { this->alto = alto_; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setAncho(F ancho_) { this->ancho = ancho_; }

template <typename S, typename I, typename F>
void Producto<S, I, F>::setPrecio(F precio_) { this->precio = precio_; }

/*setters desde tipo a precio hechos con chatGPT para ahorrar tiempo*/

//getters

template <typename S, typename I, typename F>
I Producto<S, I, F>::getID() { return id; }

template <typename S, typename I, typename F>
S Producto<S, I, F>::getNombre() { return nombre; }

template <typename S, typename I, typename F>
S Producto<S, I, F>::getTipo() { return tipo; }

template <typename S, typename I, typename F>
S Producto<S, I, F>::getColor() { return color; }

template <typename S, typename I, typename F>
S Producto<S, I, F>::getMaterial() { return material; }

template <typename S, typename I, typename F>
I Producto<S, I, F>::getStock() { return stock; }

template <typename S, typename I, typename F>
F Producto<S, I, F>::getCalificacion() { return calificacion; }

template <typename S, typename I, typename F>
F Producto<S, I, F>::getAlto() { return alto; }

template <typename S, typename I, typename F>
F Producto<S, I, F>::getAncho() { return ancho; }

template <typename S, typename I, typename F>
F Producto<S, I, F>::getPrecio() { return precio; }

template <typename S, typename I, typename F>
Lista<Review<S, I, F>*>* Producto<S, I, F>::getLst_Reviews() { return lst_reviews; }

/*getters desde nombre a precio hechos con chatGPT para ahorrar tiempo*/

//metodos

template <typename S, typename I, typename F>
S Producto<S, I, F>::especificarTipo(int n) {
	S tipoEspecifico = " ";

	switch (n)
	{

	case 1:
		tipoEspecifico = "Construccion y ferreteria";
		break;
	case 2:
		tipoEspecifico = "Decohogar";
		break;
	case 3:
		tipoEspecifico = "Jardin y terraza";
		break;
	case 4:
		tipoEspecifico = "Muebles y organizacion";
		break;
	case 5:
		tipoEspecifico = "Tecnologia";
		break;
	case 6:
		tipoEspecifico = "Utiles de aseo y limpieza";
		break;
	case 7:
		tipoEspecifico = "Cocina y baño";
		break;
	case 8:
		tipoEspecifico = "Electrohogar";
		break;
	case 9:
		tipoEspecifico = "Automotriz";
		break;
	case 10:
		tipoEspecifico = "Dormitorio";
		break;
	case 11:
		tipoEspecifico = "Mundo bebe";
		break;
	case 12:
		tipoEspecifico = "Mascotas";
		break;
	default: break;

	}

	return tipoEspecifico;
}

template <typename S, typename I, typename F>
auto division = [](F a, F b) {

	return a / b;

	};

template <typename S, typename I, typename F>
S Producto<S, I, F>::verCalificacion() {

	if (this->lst_reviews->longitud() == 0) return "No hay reviews";
	else {

		F calificacionPromedio = division<S, I, F>(this->calificacion, this->lst_reviews->longitud());
		return to_string(calificacionPromedio);

	}

}

template <typename S, typename I, typename F>
F Producto<S, I, F>::verCalificacionNumerica() {
	if (this->lst_reviews->longitud() == 0) return 0;
	else {
		F calificacionPromedio = division<S, I, F>(this->calificacion, this->lst_reviews->longitud());
		return calificacionPromedio;
	}
}

template <typename S, typename I, typename F>
void Producto<S, I, F>::mostrarProducto() {
	proveedor->datosProveedor();
	cout << "\t- ID producto: " << this->id << endl;
	cout << "\t- Nombre: " << this->nombre << endl;
	cout << "\t- Tipo: " << this->tipo << endl;
	cout << "\t- Color: " << this->color << endl;
	cout << "\t- Material: " << this->material << endl;
	cout << "\t- Codigo de tienda: " << this->codTienda << endl;
	cout << "\t- Stock: " << this->stock << endl;
	cout << "\t- Calificacion: " << verCalificacion() << endl;
	cout << "\t- Alto: " << this->alto << " m" << endl;
	cout << "\t- Ancho: " << this->ancho << " m" << endl;
	cout << "\t- Precio: S/." << this->precio;

	if (this->descuentoActivo) {
		cout << " (Descuento activo: " << this->descuentoPrcnt << "%)";
	}

	cout << endl << endl;
}

template <typename S, typename I, typename F>
void Producto<S, I, F>::nuevaReview(I puntos, I ID, S comentario, S hechoPor) {

	this->lst_reviews->agregaFinal(new Review<S, I, F>(puntos, ID, comentario, hechoPor));

	this->calificacion += F(puntos);

}

template <typename S, typename I, typename F>
void Producto<S, I, F>::mostrarReviews() {

	if (this->lst_reviews->longitud() == 0) cout << "No hay reviews" << endl;
	else {

		for (int i = 0; i < this->lst_reviews->longitud(); ++i) {

			cout << "Review Nro " << i + 1 << ": " << endl;
			this->lst_reviews->obtenerPos(i)->verReview();
			cout << endl;

		}

	}
}

