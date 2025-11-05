#pragma once

#include <iostream>
#include <sstream>

using namespace std;

template<typename T1, typename T2, typename T3>
class MetodoPago {
private:
    T2 tipoMetodo;
    T1 monto;
    T2 numeroTarjeta;
    T2 nombreTitular;

public:
    MetodoPago();
    MetodoPago(T2 tipoMetodo_, T1 monto_, T2 numeroTarjeta_, T2 nombreTitular_);

    void setTipoMetodo(T2 tipoMetodo_);
    T2 getTipoMetodo();
    void setMonto(T1 monto_);
    T1 getMonto();
    void setNumeroTarjeta(T2 numeroTarjeta_);
    T2 getNumeroTarjeta();
    void setNombreTitular(T2 nombreTitular_);
    T2 getNombreTitular();

    void mostrarPago();
    T2 toString();
};

template<typename T1, typename T2, typename T3>
MetodoPago<T1, T2, T3>::MetodoPago() {
    this->tipoMetodo = "";
    this->monto = 0;
    this->numeroTarjeta = "";
    this->nombreTitular = "";
}

template<typename T1, typename T2, typename T3>
MetodoPago<T1, T2, T3>::MetodoPago(T2 tipoMetodo_, T1 monto_, T2 numeroTarjeta_, T2 nombreTitular_) {
    this->tipoMetodo = tipoMetodo_;
    this->monto = monto_;
    this->numeroTarjeta = numeroTarjeta_;
    this->nombreTitular = nombreTitular_;
}

template<typename T1, typename T2, typename T3>
void MetodoPago<T1, T2, T3>::setTipoMetodo(T2 tipoMetodo_) { this->tipoMetodo = tipoMetodo_; }

template<typename T1, typename T2, typename T3>
T2 MetodoPago<T1, T2, T3>::getTipoMetodo() { return this->tipoMetodo; }

template<typename T1, typename T2, typename T3>
void MetodoPago<T1, T2, T3>::setMonto(T1 monto_) { this->monto = monto_; }

template<typename T1, typename T2, typename T3>
T1 MetodoPago<T1, T2, T3>::getMonto() { return this->monto; }

template<typename T1, typename T2, typename T3>
void MetodoPago<T1, T2, T3>::setNumeroTarjeta(T2 numeroTarjeta_) { this->numeroTarjeta = numeroTarjeta_; }

template<typename T1, typename T2, typename T3>
T2 MetodoPago<T1, T2, T3>::getNumeroTarjeta() { return this->numeroTarjeta; }

template<typename T1, typename T2, typename T3>
void MetodoPago<T1, T2, T3>::setNombreTitular(T2 nombreTitular_) { this->nombreTitular = nombreTitular_; }

template<typename T1, typename T2, typename T3>
T2 MetodoPago<T1, T2, T3>::getNombreTitular() { return this->nombreTitular; }

template<typename T1, typename T2, typename T3>
void MetodoPago<T1, T2, T3>::mostrarPago() {
    cout << "Metodo de pago: " << this->tipoMetodo << endl;
    cout << "Monto: S/." << this->monto << endl;
    if (this->numeroTarjeta != "") {
        cout << "Tarjeta: **** **** **** " << this->numeroTarjeta.substr(this->numeroTarjeta.length() - 4) << endl;
        cout << "Titular: " << this->nombreTitular << endl;
    }
}

template<typename T1, typename T2, typename T3>
T2 MetodoPago<T1, T2, T3>::toString() {
    stringstream s;
    s << "Metodo: " << this->tipoMetodo << ", Monto: " << this->monto;
    return s.str();
}
