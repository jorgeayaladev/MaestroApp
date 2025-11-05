#include <iostream>
#include <sstream>

using namespace std;

template<typename T1, typename T2>

class Usuario {
private:
	T1 id;
	T2 nombre, eMail, password;
public:
	Usuario(T1 id, T2 nombre, T2 eMail, T2 password);
	T2 toString();

	void setId(T1 id);
	T1 getId();
	void setNombre(T2 nombre);
	T2 getNombre();
	void setEMail(T2 eMail);
	T2 getEMail();
	void setPassword(T2 password);
	T2 getPassword();
};

template<typename T1, typename T2>
Usuario<T1, T2>::Usuario(T1 id, T2 nombre, T2 eMail, T2 password) {
	this->id = id;
	this->nombre = nombre;
	this->eMail = eMail;
	this->password = password;
}

template<typename T1, typename T2>
T2 Usuario<T1, T2>::toString() {
	stringstream s;
	s << "Id: " << this->id << endl;
	s << "Nombre: " << this->nombre << endl;
	s << "eMail: " << this->eMail << endl;
	s << "Password: " << this->password << endl;
	s << "------------------------" << endl;
	return s.str();
}

template<typename T1, typename T2>
void Usuario<T1, T2>::setId(T1 id) {
	this->id = id;
}

template<typename T1, typename T2>
T1 Usuario<T1, T2>::getId() {
	return this->id;
}

template<typename T1, typename T2>
void Usuario<T1, T2>::setNombre(T2 nombre) {
	this->nombre = nombre;
}

template<typename T1, typename T2>
T2 Usuario<T1, T2>::getNombre() {
	return this->nombre;
}

template<typename T1, typename T2>
void Usuario<T1, T2>::setEMail(T2 eMail) {
	this->eMail = eMail;
}

template<typename T1, typename T2>
T2 Usuario<T1, T2>::getEMail() {
	return this->eMail;
}

template<typename T1, typename T2>
void Usuario<T1, T2>::setPassword(T2 password) {
	this->password = password;
}

template<typename T1, typename T2>
T2 Usuario<T1, T2>::getPassword() {
	return this->password;
}


