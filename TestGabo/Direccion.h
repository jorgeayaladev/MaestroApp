#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Direccion {
private: 
	string calle, numVivienda, ciudad, piso;
public:
	Direccion(string calle, string numVivienda, string ciudad, string piso) : calle(calle), numVivienda(numVivienda), ciudad(ciudad), piso(piso) {}
	string getCalle() { return calle; }
	string getNumVivienda() { return numVivienda; }
	string getCiudad() { return ciudad; }
	string getPiso() { return piso; }
	void setCalle(string calle) { this->calle = calle; }
	void setNumVivienda(string numVivienda) { this->numVivienda = numVivienda; }
	void setCiudad(string ciudad) { this->ciudad = ciudad; }
	void setPiso(string piso) { this->piso = piso; }
	string toString() {
		stringstream ss;
		ss << calle << " " << numVivienda << ", " << piso << ", " << ciudad;
		return ss.str();
	}
};
