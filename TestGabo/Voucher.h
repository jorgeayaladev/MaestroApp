#pragma once
#include <iostream>
#include "MetodoPago.h"
#include "Perfil.h"
#include "InventoryYCarrito.h"
using namespace std;

template<typename T1, typename T2, typename T3>
class Voucher {
private:
    string fechaHora;
    string idVoucher;
    MetodoPago<T1, T2, T3> infoPago; 

public:
    Voucher() : fechaHora(""), idVoucher("") {}

    Voucher(string pfechaHora, string pidVoucher, MetodoPago<T1, T2, T3> pinfoPago)
        : fechaHora(pfechaHora), idVoucher(pidVoucher), infoPago(pinfoPago) {
    }

    ~Voucher() {}

    void setFechaHora(string pfechaHora) { this->fechaHora = pfechaHora; }
    string getFechaHora() { return this->fechaHora; }

    void setIdVoucher(string pidVoucher) { this->idVoucher = pidVoucher; }
    string getIdVoucher() { return this->idVoucher; }

    void setInfoPago(MetodoPago<T1, T2, T3> pinfoPago) { this->infoPago = pinfoPago; }
    MetodoPago<T1, T2, T3> getInfoPago() { return this->infoPago; }

    void MostrarVoucher() {
        cout << endl;
        cout << "===================================" << endl;
        cout << "\t\tVOUCHER" << endl;
        cout << "===================================" << endl;
        cout << "ID VOUCHER : " << this->idVoucher << endl;
        cout << "FECHA/HORA : " << this->fechaHora << endl;
        cout << "===================================" << endl;
        cout << "\tDETALLE DEL PAGO" << endl;
        cout << "===================================" << endl;
        this->infoPago.mostrarPago();
        cout << "===================================" << endl;
    }
};