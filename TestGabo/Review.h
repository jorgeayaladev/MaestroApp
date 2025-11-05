#pragma once

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

template <typename S, typename I, typename F>
class Review {
private:
    I calificacion, idUsuario;
    S contenido, hechoPor;
    string fecha;

public:
    Review();
    Review(I calificacion_, I idUsuario_, S contenido_, S hechoPor_);
    //metodos

	I getCalificacion() { return calificacion; }

    void establecerContenido();
    string fechaExacta();
    void verReview();

    S toString() {
        stringstream s;
        s << "Calificacion: " << this->calificacion << ", Contenido: " << this->contenido
            << ", Hecho por: " << this->hechoPor << ", Fecha: " << this->fecha;
        return s.str();
	}

};

template<typename S, typename I, typename F>
Review<S, I, F>::Review() {

    this->calificacion = 0;
	this->idUsuario = 0;
    this->contenido = " ";
	this->hechoPor = " ";
    this->fecha = fechaExacta();

}

template<typename S, typename I, typename F>
Review<S, I, F>::Review(I calificacion_, I idUsuario_, S contenido_, S hechoPor_) {

    this->calificacion = calificacion_;
	this->idUsuario = idUsuario_;
    this->contenido = contenido_;
	this->hechoPor = hechoPor_;
    this->fecha = fechaExacta();

}

template<typename S, typename I, typename F>
void Review<S, I, F>::establecerContenido() {
    S contenido_;
    cout << "Ingrese el contenido de la review: "; cin >> contenido_;
    this->contenido = contenido_;
}

template<typename S, typename I, typename F>
string Review<S, I, F>::fechaExacta() {

    stringstream fechaEN;
    string diaES, mesES, fechaES, aux;

    time_t tiempoCompleto;
    time(&tiempoCompleto);

    fechaEN << ctime(&tiempoCompleto);

    aux = fechaEN.str().substr(0, 3);

    if (aux == "Mon") {
        diaES = "Lunes";
    }
    else if (aux == "Tue") {
        diaES = "Martes";
    }
    else if (aux == "Wed") {
        diaES = "Miercoles";
    }
    else if (aux == "Thu") {
        diaES = "Jueves";
    }
    else if (aux == "Fri") {
        diaES = "Viernes";
    }
    else if (aux == "Sat") {
        diaES = "Sabado";
    }
    else if (aux == "Sun") {
        diaES = "Domingo";
    }

    aux = fechaEN.str().substr(3, 4);

    if (aux == " Jan") {
        mesES = "Enero";
    }
    else if (aux == " Feb") {
        mesES = "Febrero";
    }
    else if (aux == " Mar") {
        mesES = "Marzo";
    }
    else if (aux == " Apr") {
        mesES = "Abril";
    }
    else if (aux == " May") {
        mesES = "Mayo";
    }
    else if (aux == " Jun") {
        mesES = "Junio";
    }
    else if (aux == " Jul") {
        mesES = "Julio";
    }
    else if (aux == " Aug") {
        mesES = "Agosto";
    }
    else if (aux == " Sep") {
        mesES = "Setiembre";
    }
    else if (aux == " Oct") {
        mesES = "Octubre";
    }
    else if (aux == " Nov") {
        mesES = "Noviembre";
    }
    else if (aux == " Dec") {
        mesES = "Diciembre";
    }

    aux = fechaEN.str().erase(0, 8);

    return diaES + ", " + mesES + aux;

}

template<typename S, typename I, typename F>
void Review<S, I, F>::verReview() {

    cout << endl << "Fecha de review: " << this->fecha;
	cout << endl << "Hecho por: " << this->hechoPor << " (" << this->idUsuario << ")";
    cout << endl << "Calificacion: " << this->calificacion << " de 5";
    cout << endl << "Review completa: " << contenido;

}

