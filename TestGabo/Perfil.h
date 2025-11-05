#pragma once

#include <iostream>
#include "Direccion.h"
#include "UsuariosHerencia.h"

using namespace std;

template<typename T1, typename T2, typename T3>
class Perfil {
private:
    Usuario<T3, T2>* usuario;
    Direccion* direccion;
    T1 saldo;

public:
    Perfil();
    Perfil(Usuario<T3, T2>* usuario_, Direccion* direccion_, T1 saldo_);
    ~Perfil();

    void setUsuario(Usuario<T3, T2>* usuario_);
    Usuario<T3, T2>* getUsuario();
    void setDireccion(Direccion* direccion_);
    Direccion* getDireccion();
    void setSaldo(T1 saldo_);
    T1 getSaldo();

    void mostrarPerfil();
    T2 nombreCompleto();
};

template<typename T1, typename T2, typename T3>
Perfil<T1, T2, T3>::Perfil() {
    this->usuario = nullptr;
    this->direccion = nullptr;
    this->saldo = 0;
}

template<typename T1, typename T2, typename T3>
Perfil<T1, T2, T3>::Perfil(Usuario<T3, T2>* usuario_, Direccion* direccion_, T1 saldo_) {
    this->usuario = usuario_;
    this->direccion = direccion_;
    this->saldo = saldo_;
}

template<typename T1, typename T2, typename T3>
Perfil<T1, T2, T3>::~Perfil() {
}

template<typename T1, typename T2, typename T3>
void Perfil<T1, T2, T3>::setUsuario(Usuario<T3, T2>* usuario_) { this->usuario = usuario_; }

template<typename T1, typename T2, typename T3>
Usuario<T3, T2>* Perfil<T1, T2, T3>::getUsuario() { return this->usuario; }

template<typename T1, typename T2, typename T3>
void Perfil<T1, T2, T3>::setDireccion(Direccion* direccion_) { this->direccion = direccion_; }

template<typename T1, typename T2, typename T3>
Direccion* Perfil<T1, T2, T3>::getDireccion() { return this->direccion; }

template<typename T1, typename T2, typename T3>
void Perfil<T1, T2, T3>::setSaldo(T1 saldo_) { this->saldo = saldo_; }

template<typename T1, typename T2, typename T3>
T1 Perfil<T1, T2, T3>::getSaldo() { return this->saldo; }

template<typename T1, typename T2, typename T3>
void Perfil<T1, T2, T3>::mostrarPerfil() {
    cout << "========== PERFIL ==========" << endl;
    if (this->usuario != nullptr) {
        cout << this->usuario->toString();
    }
    if (this->direccion != nullptr) {
        cout << "Direccion: " << this->direccion->toString() << endl;
    }
    cout << "Saldo: S/." << this->saldo << endl;
    cout << "=============================" << endl;
}

template<typename T1, typename T2, typename T3>
T2 Perfil<T1, T2, T3>::nombreCompleto() {
    if (this->usuario != nullptr) {
        return this->usuario->getNombre();
    }
    return "";
}
