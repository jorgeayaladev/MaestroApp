#include "Usuario.h"

template<typename T1, typename T2>
class UsuarioBasico : public Usuario<T1, T2> {
private:
	T2 nombreCompleto, DNI, telefono;
public:
	UsuarioBasico(T1 id, T2 nombre, T2 eMail, T2 password, T2 nombreCompleto, T2 DNI, T2 telefono);
	T2 toString();
	void setNombreCompleto(T2 nombreCompleto);
	T2 getNombreCompleto();
	void setDNI(T2 DNI);
	T2 getDNI();
};

template<typename T1, typename T2>
UsuarioBasico<T1, T2>::UsuarioBasico(T1 id, T2 nombre, T2 eMail, T2 password, T2 nombreCompleto, T2 DNI, T2 telefono)
	: Usuario<T1, T2>(id, nombre, eMail, password) {
	this->nombreCompleto = nombreCompleto;
	this->DNI = DNI;
	this->telefono = telefono;
}

template<typename T1, typename T2>
T2 UsuarioBasico<T1, T2>::toString() {
	stringstream s;
	s << Usuario<T1, T2>::toString();
	s << "Nombre Completo: " << this->nombreCompleto << endl;
	s << "DNI: " << this->DNI << endl;
	s << "Telefono: " << this->telefono << endl;
	s << "------------------------" << endl;
	return s.str();
}

template<typename T1, typename T2>
void UsuarioBasico<T1, T2>::setNombreCompleto(T2 nombreCompleto) {
	this->nombreCompleto = nombreCompleto;
}

template<typename T1, typename T2>
T2 UsuarioBasico<T1, T2>::getNombreCompleto() {
	return this->nombreCompleto;
}

template<typename T1, typename T2>
void UsuarioBasico<T1, T2>::setDNI(T2 DNI) {
	this->DNI = DNI;
}

template<typename T1, typename T2>
T2 UsuarioBasico<T1, T2>::getDNI() {
	return this->DNI;
}

//CLASE DE USUARIO EMPRESA

template<typename T1, typename T2>

class UsuarioEmpresa : public Usuario<T1, T2> {
private:
	T2 nombreEmpresa, RUC;
public:
	UsuarioEmpresa(T1 id, T2 nombre, T2 eMail, T2 password, T2 nombreEmpresa, T2 RUC);
	T2 toString();
	void setNombreEmpresa(T2 nombreEmpresa);
	T2 getNombreEmpresa();
	void setRUC(T2 RUC);
	T2 getRUC();
};

template<typename T1, typename T2>
UsuarioEmpresa<T1, T2>::UsuarioEmpresa(T1 id, T2 nombre, T2 eMail, T2 password, T2 nombreEmpresa, T2 RUC)
	: Usuario<T1, T2>(id, nombre, eMail, password) {
	this->nombreEmpresa = nombreEmpresa;
	this->RUC = RUC;
}

template<typename T1, typename T2>
T2 UsuarioEmpresa<T1, T2>::toString() {
	stringstream s;
	s << Usuario<T1, T2>::toString();
	s << "Nombre Empresa: " << this->nombreEmpresa << endl;
	s << "RUC: " << this->RUC << endl;
	s << "------------------------" << endl;
	return s.str();
}

template<typename T1, typename T2>
void UsuarioEmpresa<T1, T2>::setNombreEmpresa(T2 nombreEmpresa) {
	this->nombreEmpresa = nombreEmpresa;
}

template<typename T1, typename T2>
T2 UsuarioEmpresa<T1, T2>::getNombreEmpresa() {
	return this->nombreEmpresa;
}

template<typename T1, typename T2>
void UsuarioEmpresa<T1, T2>::setRUC(T2 RUC) {
	this->RUC = RUC;
}

template<typename T1, typename T2>
T2 UsuarioEmpresa<T1, T2>::getRUC() {
	return this->RUC;
}