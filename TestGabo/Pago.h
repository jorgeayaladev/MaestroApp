#pragma once
#include "Perfil.h"
#include "InventoryYCarrito.h"

template<typename T1, typename T2, typename T3>
class Pago {
private:
    Perfil<T1, T2, T3>* perfil; 
    ShoppingCart<T2, int, T1>* carrito; 

public:
    Pago(Perfil<T1, T2, T3>* perfil_, ShoppingCart<T2, int, T1>* carrito_)
        : perfil(perfil_), carrito(carrito_) {
    }

    bool procesarPago(T1 monto) {
        if (perfil->getSaldo() >= monto) {
            perfil->setSaldo(perfil->getSaldo() - monto);
            return true;
        }
        return false;
    }

    Perfil<T1, T2, T3>* getPerfil() { return perfil; }
    ShoppingCart<T2, int, T1>* getCarrito() { return carrito; }
};