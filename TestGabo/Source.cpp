#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "Usuario.h"
#include "UsuariosHerencia.h"
#include "Perfil.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Review.h"
#include "InventoryYCarrito.h"
#include "FiltrosDeProductos.h"
#include "Pago.h"
#include "MetodoPago.h"
#include "Voucher.h"
#include "Boleta.h"
#include "Factura.h"

using namespace std;

void limpiarPantalla() {
    system("cls");
}

void pausar() {
    cout << endl << "Presione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void mostrarMenuPrincipal() {
    cout << "========================================" << endl;
    cout << "  SISTEMA DE VENTA DE MATERIALES DE" << endl;
    cout << "           CONSTRUCCION" << endl;
    cout << "========================================" << endl;
    cout << "1. Gestionar Productos" << endl;
    cout << "2. Gestionar Carrito de Compras" << endl;
    cout << "3. Realizar Compra" << endl;
    cout << "4. Ver Perfil de Usuario" << endl;
    cout << "5. Filtrar Productos" << endl;
    cout << "6. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarMenuProductos() {
    cout << endl << "====== GESTION DE PRODUCTOS ======" << endl;
    cout << "1. Ver todos los productos" << endl;
    cout << "2. Ver detalles de un producto" << endl;
    cout << "3. Agregar review a un producto" << endl;
    cout << "4. Volver al menu principal" << endl;
    cout << "===================================" << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarMenuCarrito() {
    cout << endl << "====== CARRITO DE COMPRAS ======" << endl;
    cout << "1. Ver carrito" << endl;
    cout << "2. Agregar producto al carrito" << endl;
    cout << "3. Eliminar producto del carrito" << endl;
    cout << "4. Modificar cantidad de un producto" << endl;
    cout << "5. Vaciar carrito" << endl;
    cout << "6. Volver al menu principal" << endl;
    cout << "=================================" << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarMenuFiltros() {
    cout << endl << "====== FILTRAR PRODUCTOS ======" << endl;
    cout << "1. Filtrar por empresa" << endl;
    cout << "2. Filtrar por tipo" << endl;
    cout << "3. Filtrar por precio maximo" << endl;
    cout << "4. Filtrar por calificacion minima" << endl;
    cout << "5. Volver al menu principal" << endl;
    cout << "===============================" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Proveedor<string, int>* proveedor1 = new Proveedor<string, int>("Juan Perez", "Cementos Lima", 1001);
    Proveedor<string, int>* proveedor2 = new Proveedor<string, int>("Maria Garcia", "Aceros del Peru", 1002);
    Proveedor<string, int>* proveedor3 = new Proveedor<string, int>("Carlos Ruiz", "Pinturas Total", 1003);

    Inventory<string, int, double>* inventario = new Inventory<string, int, double>();

    Producto<string, int, double>* prod1 = new Producto<string, int, double>(
        1, "Cemento Portland Tipo I", "Cemento", "Cemento de alta calidad para construccion", 25.50, 100, proveedor1);
    Producto<string, int, double>* prod2 = new Producto<string, int, double>(
        2, "Varilla de Acero 3/8", "Acero", "Varilla corrugada de 3/8 pulgadas", 18.00, 200, proveedor2);
    Producto<string, int, double>* prod3 = new Producto<string, int, double>(
        3, "Pintura Latex Blanco", "Pintura", "Pintura latex lavable 5 galones", 89.90, 50, proveedor3);
    Producto<string, int, double>* prod4 = new Producto<string, int, double>(
        4, "Ladrillo King Kong", "Material", "Ladrillo de arcilla 18 huecos", 0.80, 5000, proveedor1);
    Producto<string, int, double>* prod5 = new Producto<string, int, double>(
        5, "Arena Gruesa", "Agregados", "Arena gruesa por metro cubico", 35.00, 80, proveedor1);

    prod1->agregarReview(new Review<string, int, double>(5, 101, "Excelente cemento", "Pedro Lopez"));
    prod1->agregarReview(new Review<string, int, double>(4, 102, "Buena calidad", "Ana Torres"));
    prod2->agregarReview(new Review<string, int, double>(5, 103, "Muy resistente", "Luis Gomez"));
    prod3->agregarReview(new Review<string, int, double>(3, 104, "Precio un poco alto", "Sofia Ramirez"));

    inventario->agregarProducto(prod1);
    inventario->agregarProducto(prod2);
    inventario->agregarProducto(prod3);
    inventario->agregarProducto(prod4);
    inventario->agregarProducto(prod5);

    Usuario<int, string>* usuario = new UsuarioBasico<int, string>(
        1, "jgarcia", "jgarcia@email.com", "pass123", "Jose Garcia Mendoza", "12345678", "987654321");

    Direccion* direccion = new Direccion("Av. Construccion", "123", "Lima", "Piso 2");

    Perfil<double, string, int>* perfil = new Perfil<double, string, int>(usuario, direccion, 5000.00);

    ShoppingCart<string, int, double>* carrito = new ShoppingCart<string, int, double>();

    int opcionPrincipal = 0;
    bool continuar = true;

    while (continuar) {
        limpiarPantalla();
        mostrarMenuPrincipal();
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case 1: {
            int opcionProductos = 0;
            while (opcionProductos != 4) {
                limpiarPantalla();
                mostrarMenuProductos();
                cin >> opcionProductos;

                switch (opcionProductos) {
                case 1:
                    limpiarPantalla();
                    inventario->mostrarInventario();
                    pausar();
                    break;

                case 2: {
                    limpiarPantalla();
                    int idProducto;
                    cout << "Ingrese el ID del producto: ";
                    cin >> idProducto;
                    Producto<string, int, double>* prod = inventario->buscarProducto(idProducto);
                    if (prod != nullptr) {
                        prod->mostrarProducto();
                        prod->mostrarReviews();
                    }
                    else {
                        cout << "Producto no encontrado." << endl;
                    }
                    pausar();
                    break;
                }

                case 3: {
                    limpiarPantalla();
                    int idProducto, calificacion, idUsuario;
                    string contenido, hechoPor;
                    cout << "Ingrese el ID del producto: ";
                    cin >> idProducto;
                    Producto<string, int, double>* prod = inventario->buscarProducto(idProducto);
                    if (prod != nullptr) {
                        cout << "Ingrese su nombre: ";
                        cin.ignore();
                        getline(cin, hechoPor);
                        cout << "Ingrese su ID de usuario: ";
                        cin >> idUsuario;
                        cout << "Ingrese calificacion (1-5): ";
                        cin >> calificacion;
                        cout << "Ingrese su comentario: ";
                        cin.ignore();
                        getline(cin, contenido);

                        Review<string, int, double>* nuevaReview =
                            new Review<string, int, double>(calificacion, idUsuario, contenido, hechoPor);
                        prod->agregarReview(nuevaReview);
                        cout << "Review agregada exitosamente!" << endl;
                    }
                    else {
                        cout << "Producto no encontrado." << endl;
                    }
                    pausar();
                    break;
                }

                case 4:
                    break;

                default:
                    cout << "Opcion invalida." << endl;
                    pausar();
                }
            }
            break;
        }

        case 2: {
            int opcionCarrito = 0;
            while (opcionCarrito != 6) {
                limpiarPantalla();
                mostrarMenuCarrito();
                cin >> opcionCarrito;

                switch (opcionCarrito) {
                case 1:
                    limpiarPantalla();
                    carrito->mostrarCarrito();
                    pausar();
                    break;

                case 2: {
                    limpiarPantalla();
                    inventario->mostrarInventario();
                    int idProducto, cantidad;
                    cout << endl << "Ingrese el ID del producto: ";
                    cin >> idProducto;
                    cout << "Ingrese la cantidad: ";
                    cin >> cantidad;
                    Producto<string, int, double>* prod = inventario->buscarProducto(idProducto);
                    if (prod != nullptr) {
                        carrito->agregarItem(prod, cantidad);
                    }
                    else {
                        cout << "Producto no encontrado." << endl;
                    }
                    pausar();
                    break;
                }

                case 3: {
                    limpiarPantalla();
                    carrito->mostrarCarrito();
                    int idProducto;
                    cout << endl << "Ingrese el ID del producto a eliminar: ";
                    cin >> idProducto;
                    carrito->eliminarItem(idProducto);
                    pausar();
                    break;
                }

                case 4: {
                    limpiarPantalla();
                    carrito->mostrarCarrito();
                    int idProducto, nuevaCantidad;
                    cout << endl << "Ingrese el ID del producto: ";
                    cin >> idProducto;
                    cout << "Ingrese la nueva cantidad: ";
                    cin >> nuevaCantidad;
                    carrito->modificarCantidad(idProducto, nuevaCantidad);
                    pausar();
                    break;
                }

                case 5:
                    carrito->vaciarCarrito();
                    pausar();
                    break;

                case 6:
                    break;

                default:
                    cout << "Opcion invalida." << endl;
                    pausar();
                }
            }
            break;
        }

        case 3: {
            limpiarPantalla();
            carrito->mostrarCarrito();

            if (carrito->getItems()->longitud() == 0) {
                cout << "El carrito esta vacio. No se puede realizar la compra." << endl;
                pausar();
                break;
            }

            double total = carrito->calcularTotal();
            cout << endl << "Total a pagar: S/." << total << endl;
            cout << "Saldo disponible: S/." << perfil->getSaldo() << endl;

            if (perfil->getSaldo() < total) {
                cout << "Saldo insuficiente para realizar la compra." << endl;
                pausar();
                break;
            }

            char confirmar;
            cout << "Desea confirmar la compra? (S/N): ";
            cin >> confirmar;

            if (confirmar == 'S' || confirmar == 's') {
                Pago<double, string, int> pago(perfil, carrito);
                if (pago.procesarPago(total)) {
                    for (uint i = 0; i < carrito->getItems()->longitud(); i++) {
                        ItemCarrito<string, int, double>* item = carrito->getItems()->obtenerPos(i);
                        Producto<string, int, double>* prod = item->getProducto();
                        prod->setStock(prod->getStock() - item->getCantidad());
                    }

                    cout << endl << "========================================" << endl;
                    cout << "   COMPRA REALIZADA EXITOSAMENTE!" << endl;
                    cout << "========================================" << endl;
                    cout << "Nuevo saldo: S/." << perfil->getSaldo() << endl;

                    carrito->vaciarCarrito();
                }
                else {
                    cout << "Error al procesar el pago." << endl;
                }
            }
            else {
                cout << "Compra cancelada." << endl;
            }
            pausar();
            break;
        }

        case 4:
            limpiarPantalla();
            perfil->mostrarPerfil();
            pausar();
            break;

        case 5: {
            int opcionFiltros = 0;
            while (opcionFiltros != 5) {
                limpiarPantalla();
                mostrarMenuFiltros();
                cin >> opcionFiltros;

                FiltrosDeProductos<string, int, double> filtros;
                filtros.setLst_Productos(inventario->getProductos());

                switch (opcionFiltros) {
                case 1: {
                    limpiarPantalla();
                    string empresa;
                    cout << "Ingrese el nombre de la empresa: ";
                    cin.ignore();
                    getline(cin, empresa);
                    filtros.filtrarPorEmpresa(empresa);
                    pausar();
                    break;
                }

                case 2: {
                    limpiarPantalla();
                    string tipo;
                    cout << "Ingrese el tipo de producto: ";
                    cin.ignore();
                    getline(cin, tipo);
                    filtros.filtrarPorTipo(tipo);
                    pausar();
                    break;
                }

                case 3: {
                    limpiarPantalla();
                    double precioMax;
                    cout << "Ingrese el precio maximo: ";
                    cin >> precioMax;
                    filtros.filtrarPorPrecio(precioMax);
                    pausar();
                    break;
                }

                case 4: {
                    limpiarPantalla();
                    int calificacionMin;
                    cout << "Ingrese la calificacion minima (1-5): ";
                    cin >> calificacionMin;
                    filtros.filtrarPorCalificacion(calificacionMin);
                    pausar();
                    break;
                }

                case 5:
                    break;

                default:
                    cout << "Opcion invalida." << endl;
                    pausar();
                }
            }
            break;
        }

        case 6:
            continuar = false;
            cout << endl << "Gracias por usar el sistema. Hasta pronto!" << endl;
            break;

        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            pausar();
        }
    }

    delete proveedor1;
    delete proveedor2;
    delete proveedor3;
    delete inventario;
    delete usuario;
    delete direccion;
    delete perfil;
    delete carrito;

    return 0;
}
