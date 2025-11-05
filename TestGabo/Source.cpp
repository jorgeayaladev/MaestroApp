#include <iostream>
#include <conio.h>
#include "Perfil.h"
#include "UsuariosHerencia.h"
#include <fstream>
#include "MetodoPago.h"
#include "Pago.h"

using namespace std;
using namespace System;

void Ubicar(int x, int y) {
	Console::SetCursorPosition(x, y);
}

void AjustarTamanioPantalla(int ancho, int alto) {
	Console::SetWindowSize(ancho, alto);
}

int MenuPrincipal() {
	Console::BackgroundColor = ConsoleColor::DarkCyan;
	Console::Clear();
	Console::ForegroundColor = ConsoleColor::White;
	int opc = 0;
	cout << "====================SODIMAC====================" << endl;
	cout << "1. Iniciar Sesion" << endl;
	cout << "2. Registrarse" << endl;
	cout << "3. Visualizar Perfil" << endl;
	cout << "4. Buscar Productos" << endl;
	cout << "5. Listar Productos" << endl;
	cout << "6. Registrar Review" << endl;
	cout << "7. Ver review" << endl;
	cout << "8. Agregar al carrito" << endl;
	cout << "9. Ver carrito" << endl;
	cout << "10. Comprar productos" << endl;
	cout << "11. Salir" << endl;
	cout << "================================================" << endl;
	cout << "Ingrese una opcion: "; cin >> opc;
	if (opc > 0 && opc < 12) return opc;
	else {
		MenuPrincipal();
	}
}

void IniciarSesion(Usuario<int, string>* user) {
	system("cls");
	string email, contraseña;
	cout << "INICIAR SESION" << endl;
	cout << "Ingresa tu eMail: "; cin >> email;
	cout << "Ingresa tu Contraseña: "; cin >> contraseña;
	if ((email != user->getEMail() || contraseña != user->getPassword()) || user == NULL) {
		cout << "DATOS INCORRECTOS\nIngrese de nuevo sus datos";
		_getch();
		IniciarSesion(user);
	}
	else {
		cout << "INICIO DE SESION CORRECTO";
		_getch();
	}
}

void RegistrarUsuario(Usuario<int, string>*& user, Perfil<double, string, Usuario<int, string>*>*& perfil) {
	system("cls");
	int tipo;
	string nickname, email, contraseña, nombreCompleto, DNI, telefono, RUC;
	cout << "REGISTRO DE USUARIO" << endl;
	cout << "Ingresa tu Nickname: "; cin >> nickname;
	cout << "\nIngresa tu eMail: "; cin >> email;
	cout << "\nIngresa tu contraseña: "; cin >> contraseña;
	cout << "\nQue tipo de Cuenta quieres registrar?" << endl;
	do {
		cout << "- Ingresa 1 si registras una Cuenta Personal\n- Ingresa 2 si registras una Cuenta Empresarial" << endl;
		cin >> tipo;
	} while (tipo < 1 || tipo > 2);

	ofstream archivo("usuario.txt", ios::app); 

	if (tipo == 1) {
		cin.ignore();
		cout << "Ingresa tu Nombre Completo: "; getline(cin, nombreCompleto);
		cout << "\nIngresa tu DNI: "; cin >> DNI;
		cout << "\nIngresa tu telefono personal: "; cin >> telefono;
		user = new UsuarioBasico<int, string>(001, nickname, email, contraseña, nombreCompleto, DNI, telefono);
		perfil = new Perfil<double, string, Usuario<int, string>*>(user, 500.00, NULL);

		archivo << "Tipo: Personal\n";
		archivo << "Nickname: " << nickname << "\n";
		archivo << "Email: " << email << "\n";
		archivo << "Contraseña: " << contraseña << "\n";
		archivo << "Nombre Completo: " << nombreCompleto << "\n";
		archivo << "DNI: " << DNI << "\n";
		archivo << "Telefono: " << telefono << "\n";
		archivo << "--------------------------\n";
	}
	else {
		cin.ignore();
		cout << "Ingresa el nombre de la Empresa: "; cin >> nombreCompleto;
		cout << "\nIngresa tu RUC: "; cin >> RUC;
		user = new UsuarioEmpresa<int, string>(001, nickname, email, contraseña, nombreCompleto, RUC);
		perfil = new Perfil<double, string, Usuario<int, string>*>(user, 500.00, NULL);

		archivo << "Tipo: Empresarial\n";
		archivo << "Nickname: " << nickname << "\n";
		archivo << "Email: " << email << "\n";
		archivo << "Contraseña: " << contraseña << "\n";
		archivo << "Nombre Empresa: " << nombreCompleto << "\n";
		archivo << "RUC: " << RUC << "\n";
		archivo << "--------------------------\n";
	}

	archivo.close();
}

void RegistrarProducto(int id_, string nombre_, string tipo_, string color_, string material_, string codTienda_, int stock_,
	double alto_, double ancho_, double precio_, bool descuentoAct, int descuentoPrcnt_, Proveedor<string, int>* proveedor)
{

	ofstream archivo("inventario.txt", ios::app);

	archivo << "=================PRODUCTO REGISTRADO=================\n";
	archivo << "Proovedor: " << proveedor->getNombre() << "\n";
	archivo << "Empresa: " << proveedor->getEmpresa() << "\n";
	archivo << "ID Trabajador: " << proveedor->getIdTrabajador() << "\n";
	archivo << "ID producto: " << id_ << "\n";
	archivo << "Nombre: " << nombre_ << "\n";
	archivo << "Tipo: " << tipo_ << "\n";
	archivo << "Color: " << color_ << "\n";
	archivo << "Material: " << material_ << "\n";
	archivo << "Codigo de Tienda: " << codTienda_ << "\n";
	archivo << "Stock: " << stock_ << "\n";
	archivo << "Alto (m): " << alto_ << "\n";
	archivo << "Ancho (m): " << ancho_ << "\n";
	archivo << "Precio (m): " << precio_ << "\n";
	archivo << "¿Descuento Activo?: " << descuentoAct << "\n";
	if (descuentoAct) archivo << "Descuento en porcentaje: " << descuentoPrcnt_ << "\n\n";

}

void GenerarInventarioInicial(Inventory<string, int, double>* inventario) {
	
	Proveedor<string, int>* pro1 = new Proveedor<string, int>("Juan Perez", "Constructora de las Casas", 1001);
	Proveedor<string, int>* pro2 = new Proveedor<string, int>("Luis Gomez", "Materiales S.A.", 9065);

	int id, stock, descuentoPrcnt, tipo;
	double alto, ancho, precio;
	string nombre, color, material, codTienda;

	id = 001001; nombre = "Cemento Sol"; color = "Gris"; material = "Cemento"; codTienda = "T001"; stock = 50; alto = 0.30; ancho = 0.20; precio = 25.00; descuentoPrcnt = 10, tipo = 1;

	inventario->agregarProducto(new Producto<string, int, double>(id, nombre, tipo, color, material, codTienda, stock, alto, ancho, precio, true, descuentoPrcnt, pro1));

	RegistrarProducto(id, nombre, inventario->getLst_Productos()->obtenerFinal()->especificarTipo(tipo), color, material, codTienda, stock, alto, ancho, precio, true, descuentoPrcnt, pro1);

	id = 001003; nombre = "Pintura Viniltex"; color = "Blanco"; material = "Vinilo"; codTienda = "T003"; stock = 200; alto = 3.5; ancho = 0.30; precio = 75.00; descuentoPrcnt = 15, tipo = 2;

	inventario->agregarProducto(new Producto<string, int, double>(id, nombre, tipo, color, material, codTienda, stock, alto, ancho, precio, true, descuentoPrcnt, pro2));

	RegistrarProducto(id, nombre, inventario->getLst_Productos()->obtenerFinal()->especificarTipo(tipo), color, material, codTienda, stock, alto, ancho, precio, true, descuentoPrcnt, pro2);

	id = 001004; nombre = "Ladrillo Rojo"; color = "Rojo"; material = "Arcilla"; codTienda = "T005"; stock = 500; alto = 0.20; ancho = 0.10; precio = 3.00; descuentoPrcnt = 0, tipo = 3;

	inventario->agregarProducto(new Producto<string, int, double>(id, nombre, tipo, color, material, codTienda, stock, alto, ancho, precio, false, descuentoPrcnt, pro1));

	RegistrarProducto(id, nombre, inventario->getLst_Productos()->obtenerFinal()->especificarTipo(tipo), color, material, codTienda, stock, alto, ancho, precio, false, descuentoPrcnt, pro1);

	id = 001005; nombre = "Madera Triplay"; color = "Marron"; material = "Madera"; codTienda = "T002"; stock = 150; alto = 2.5; ancho = 1.2; precio = 120.00; descuentoPrcnt = 5, tipo = 4;

	inventario->agregarProducto(new Producto<string, int, double>(id, nombre, tipo, color, material, codTienda, stock, alto, ancho, precio, true, descuentoPrcnt, pro2));

	RegistrarProducto(id, nombre, inventario->getLst_Productos()->obtenerFinal()->especificarTipo(tipo), color, material, codTienda, stock, alto, ancho, precio, true, descuentoPrcnt, pro2);

	id = 001006; nombre = "Hierro Corrugado"; color = "Gris"; material = "Hierro"; codTienda = "T004"; stock = 300; alto = 6.0; ancho = 0.02; precio = 50.00; descuentoPrcnt = 0, tipo = 5;

	inventario->agregarProducto(new Producto<string, int, double>(id, nombre, tipo, color, material, codTienda, stock, alto, ancho, precio, false, descuentoPrcnt, pro1));

	RegistrarProducto(id, nombre, inventario->getLst_Productos()->obtenerFinal()->especificarTipo(tipo), color, material, codTienda, stock, alto, ancho, precio, false, descuentoPrcnt, pro1);

	id = 001007; nombre = "Yeso Laminado"; color = "Blanco"; material = "Yeso"; codTienda = "T006"; stock = 80; alto = 2.4; ancho = 1.2; precio = 40.00; descuentoPrcnt = 20, tipo = 6;

	inventario->agregarProducto(new Producto<string, int, double>(id, nombre, tipo, color, material, codTienda, stock, alto, ancho, precio, true, descuentoPrcnt, pro2));

	RegistrarProducto(id, nombre, inventario->getLst_Productos()->obtenerFinal()->especificarTipo(tipo), color, material, codTienda, stock, alto, ancho, precio, true, descuentoPrcnt, pro2);
	
}

void VisualizarPerfil(Perfil<double, string, Usuario<int, string>*>* perfil) {
	system("cls");
	if (perfil == nullptr) {
		cout << "No has iniciado sesion. Por favor, inicia sesion para ver tu perfil." << endl;
		_getch();
	}
	else {
		cout << "PERFIL DE USUARIO" << endl;
		cout << perfil->toString();
		_getch();
	}
}


int validarValor(string comentario, int min, int max)
{

	int x;

	cout << comentario; cin >> x;

	if (x < min || x > max) {
		cout << "Ups! Valor equivocado detectado!\n";
		validarValor(comentario, min, max);
	}
	else return x;

}

Review<string, int, double>* sumarReviews(Producto<string, int, double>* producto, Perfil<double, string, Usuario<int, string>*>* prfl)
{

	int calificacion;
	string comentario;

	calificacion = validarValor("Introduzca la calificacion (1-5): ", 1, 5); cin.ignore();
	cout << "Escriba su comentario: ";  getline(cin, comentario);

	Review<string, int, double>* review = new Review<string, int, double>(calificacion, prfl->getUsuario()->getId(), comentario, prfl->getUsuario()->getNombre());

	producto->nuevaReview(calificacion, prfl->getUsuario()->getId(), comentario, prfl->getUsuario()->getNombre());

	return review;

}

void buscarProductoPorIDParaReview(Inventory<string, int, double>* inventario, Perfil<double, string, Usuario<int, string>*>* prfl)
{
	system("cls");
	int id;

	cout << "Ingrese el ID del producto al que desea añadir una review: "; cin >> id;

	int x = 0;

	for(int i = 0; i < inventario->getLst_Productos()->longitud(); ++i)
		if (inventario->getLst_Productos()->obtenerPos(i)->getID() == id) {
			x = 1;
			cout << "Producto encontrado: " << endl;
			inventario->getLst_Productos()->obtenerPos(i)->mostrarProducto();
			cout << "Ingrese su review para este producto: " << endl;
			prfl->añadirReview(sumarReviews(inventario->getLst_Productos()->obtenerPos(i), prfl));
			cout << "Review añadida con exito!" << endl;
		}

	system("pause>0");
	system("cls");
}

void aniadirACarrito(Perfil<double, string, Usuario<int, string>*>* prfl, Inventory<string, int, double>* inventario)
{

	system("cls");

	int id;

	cout << "Ingrese el ID del producto al que desea añadir una review: "; cin >> id;

	int x = 0;

	for (int i = 0; i < inventario->getLst_Productos()->longitud(); ++i)
		if (inventario->getLst_Productos()->obtenerPos(i)->getID() == id) {
			x = 1;
			cout << "Producto encontrado: " << endl;
			inventario->getLst_Productos()->obtenerPos(i)->mostrarProducto();
			prfl->agregarProductoCarrito(inventario->getLst_Productos()->obtenerPos(i));
		}

	system("pause>0");
	system("cls");

}

void verReviews(Perfil<double, string, Usuario<int, string>*>* prfl)
{

	system("cls");

	for(int i = 0; i < prfl->getLst_Reviews()->longitud(); ++i)
	{
		if (prfl->getLst_Reviews()->longitud() > 0)
		{

			cout << "Review Nro " << i + 1 << ": " << endl;
			prfl->getLst_Reviews()->obtenerPos(i)->verReview();

		}
		else cout << "No hay reviews para mostrar" << endl;
	}

	system("pause>0");
	system("cls");

}

void BuscarProductos(Inventory<string, int, double>* inventario) {

	int x;

	system("cls");

	cout << "MENU DE BUSQUEDA DE PRODUCTOS" << endl << endl;

	cout << "1. Buscar por nombre de proveedor: " << endl;
	cout << "2. Buscar por tipo: " << endl;
	cout << "3. Maximo precio: " << endl;
	cout << "4. Buscar por calificacion: " << endl;
	cout << "5. Volver al menu principal" << endl;

	x = validarValor("- Ingrese una opcion: ", 1, 5);

	string texto;
	int entero;
	double doble;

	switch (x)
	{
	case 1:


		cout << endl << "BUSCAR POR NOMBRE DE PROVEEDOR: "; cin.ignore(); getline(cin, texto);

		system("cls");
		inventario->filtrarPorEmpresa(texto);
		system("pause>0");

		break;

	case 2:

		cout << endl << "BUSCAR POR TIPO: "; cin.ignore(); getline(cin, texto);

		system("cls");
		inventario->filtrarPorTipo(texto);
		system("pause>0");

		break;
		
	case 3:

		cout << endl << "BUSCAR POR MAXIMO PRECIO: "; cin.ignore(); cin >> doble;
		system("cls");
		inventario->filtrarPorPrecio(doble);
		system("pause>0");
		break;

	case 4:

		cout << endl << "BUSCAR POR CALIFICACION: "; cin.ignore(); cin >> entero;
		system("cls");
		inventario->filtrarPorCalificacion(entero);
		system("pause>0");
		break;

	case 5:
		break;

	}

}

void verCarrito(Perfil<double, string, Usuario<int, string>*>* prfl)
{
	system("cls");
	prfl->getCarritoCompras()->mostrarProductos();
	cout << "Total a pagar: S/." << prfl->getCarritoCompras()->calcularMonto() << endl;
	system("pause>0");
	system("cls");
}

void comprarProductos(Perfil<double, string, Usuario<int, string>*>* prfl)
{
	system("cls");
	if (!prfl) {
		cout << "No hay perfil activo.\n";
		system("pause>0");
		system("cls");
		return;
	}

	auto carrito = prfl->getCarritoCompras();
	double total = carrito->calcularMonto();

	if (total <= 0) {
		cout << "El carrito esta vacio.\n";
		_getch();
		system("pause>0");
		system("cls");
		return;
	}

	cout << "TOTAL DE LA COMPRA: S/. " << total << endl;
	cout << "Saldo disponible: S/. " << prfl->getSaldo() << endl;

	if (total > prfl->getSaldo()) {
		cout << "Saldo insuficiente.\n";
		system("pause>0");
		system("cls");
		return;
	}

	int usarExistente = 0;
	auto lstMet = prfl->getMetodosPago();
	if (lstMet && lstMet->longitud() > 0) {
		cout << "\nMetodos de pago guardados:\n";
		for (int i = 0; i < lstMet->longitud(); ++i) {
			cout << i + 1 << ". " << lstMet->obtenerPos(i)->getMetodoPago()
				<< " • Tarjeta ****"
				<< (lstMet->obtenerPos(i)->getNumeroTarjeta().size() >= 4
					? lstMet->obtenerPos(i)->getNumeroTarjeta().substr(lstMet->obtenerPos(i)->getNumeroTarjeta().size() - 4)
					: lstMet->obtenerPos(i)->getNumeroTarjeta())
				<< endl;
		}
		cout << "¿Usar uno existente? (1=Si / 0=No): ";
		cin >> usarExistente;
	}

	MetodoPago<string, int, float>* metodoSeleccionado = nullptr;

	if (usarExistente == 1 && lstMet && lstMet->longitud() > 0) {
		int idx;
		cout << "Seleccione indice: ";
		cin >> idx;
		if (idx < 1 || idx > lstMet->longitud()) {
			cout << "Indice invalido.\n";
			system("pause>0");
			system("cls");
			return;
		}
		metodoSeleccionado = lstMet->obtenerPos(idx - 1);
		metodoSeleccionado->setMonto(static_cast<float>(total));
	}
	else {
		cin.ignore();
		string nombreMetodo, tarjeta, cvv, fecha;
		int cuotas;
		cout << "Metodo (Ej: VISA / MASTERCARD / EFECTIVO): "; getline(cin, nombreMetodo);
		cout << "Numero de tarjeta (o identificador): "; getline(cin, tarjeta);
		cout << "CVV/Codigo: "; getline(cin, cvv);
		cout << "Fecha expiracion (MM/AA o '-'): "; getline(cin, fecha);
		cout << "Cuotas (1 si no aplica): "; cin >> cuotas;

		auto* nuevo = new MetodoPago<string, int, float>(nombreMetodo, tarjeta, cvv, fecha, static_cast<float>(total), cuotas);
		if (!nuevo->validarTarjeta() || !nuevo->validarCodigo()) {
			cout << "Datos de metodo de pago invalidos.\n";
			delete nuevo;
			system("pause>0");
			system("cls");
			return;
		}
		prfl->agregarMetodoPago(nuevo);
		metodoSeleccionado = nuevo;
	}

	// Procesar pago usando clase Pago
	Pago<double, string, Usuario<int, string>*> pago(prfl, carrito);
	bool ok = pago.procesarPago(total);

	if (!ok) {
		cout << "Fallo al debitar el saldo.\n";
		system("pause>0");
		system("cls");
		return;
	}

	// Vaciar carrito
	carrito->vaciarCarrito();

	cout << "Pago exitoso con metodo: " << metodoSeleccionado->getMetodoPago() << endl;
	cout << "Nuevo saldo: S/. " << prfl->getSaldo() << endl;

	// Opcional: generar voucher (si quieres usar Voucher)
	// Voucher<string,int,float> v(fechaHora, id, *metodoSeleccionado);

	system("pause>0");
	system("cls");
}

int main() {

	AjustarTamanioPantalla(50, 20); 
	Usuario<int, string>* usuario = NULL;
	Perfil<double, string, Usuario<int, string>*>* perfil = nullptr;
	Inventory<string, int, double>* inventario = new Inventory<string, int, double>();
	GenerarInventarioInicial(inventario);
	while (1) {
		switch (MenuPrincipal()) {
			case 1:
				IniciarSesion(usuario);
				break;
			case 2:
				RegistrarUsuario(usuario, perfil);
				perfil->getCarritoCompras()->setLst_Productos(inventario->getLst_Productos());
				break;
			case 3: 
				VisualizarPerfil(perfil);
				break;
			case 4:
				BuscarProductos(inventario);
				system("cls");
				break;
			case 5:
				system("cls");
				inventario->mostrarProductos();
				_getch();
				system("cls");
				break;
			case 6:
				//Añadir review
				buscarProductoPorIDParaReview(inventario, perfil);
				break;
			case 7:
				verReviews(perfil);
				break;
			case 8:
				aniadirACarrito(perfil, inventario);
				break;
			case 9:
				verCarrito(perfil);
				break;
			case 10:
				comprarProductos(perfil);
				break;
			case 11:
				return 0;
				break;
		}
	}

	system("pause>0");
	return 0;

}