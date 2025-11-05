#pragma once

template<typename S, typename I, typename F>
class MetodoPago {
private:
    S metodoPago;
    S numeroTarjeta;
    S codigoVerificacion;
    S fechaExpiracion;
    F monto;
    I cuotas;

public:
    MetodoPago() : metodoPago(""), numeroTarjeta(""), codigoVerificacion(""), fechaExpiracion(""), monto(0), cuotas(0) {}

    MetodoPago(S metodo, S tarjeta, S codigo, S fecha, F monto_, I cuotas_)
        : metodoPago(metodo), numeroTarjeta(tarjeta), codigoVerificacion(codigo), fechaExpiracion(fecha), monto(monto_), cuotas(cuotas_) {
    }

    // Setters
    void setMetodoPago(S metodo) { metodoPago = metodo; }
    void setNumeroTarjeta(S tarjeta) { numeroTarjeta = tarjeta; }
    void setCodigoVerificacion(S codigo) { codigoVerificacion = codigo; }
    void setFechaExpiracion(S fecha) { fechaExpiracion = fecha; }
    void setMonto(F monto_) { monto = monto_; }
    void setCuotas(I cuotas_) { cuotas = cuotas_; }

    // Getters
    S getMetodoPago() { return metodoPago; }
    S getNumeroTarjeta() { return numeroTarjeta; }
    S getCodigoVerificacion() { return codigoVerificacion; }
    S getFechaExpiracion() { return fechaExpiracion; }
    F getMonto() { return monto; }
    I getCuotas() { return cuotas; }

    bool validarTarjeta() {
        // Implementación de validación
        return !numeroTarjeta.empty();
    }

    bool validarCodigo() {
        // Implementación de validación
        return !codigoVerificacion.empty();
    }

    void procesarPago() {
        // Implementación de procesamiento
    }

    void asignarMetodoPago(int n) {
        // Implementación de asignación
    }

    std::string toString() {
        std::stringstream s;
        s << "Metodo: " << metodoPago << ", Tarjeta: " << numeroTarjeta
            << ", Codigo: " << codigoVerificacion << ", Expira: " << fechaExpiracion
            << ", Monto: " << monto << ", Cuotas: " << cuotas;
        return s.str();
    }
};