#pragma once
#pragma once
#include "main.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
using namespace std;

class Proveedor : public main {
	//atributos
private: int idProveedores;

	   //constructor
public:
	Proveedor() {
	}

	Proveedor(string pro, string n, string dire, string tel) : main(pro, n, dire, tel) {

		//idProveedores = id;
	}

	//metodos
	//set (modificar)
	void setidProveedores(int id) { idProveedores = id; }
	void setProveedor(string pro) { proveedor = pro; }
	void setNit(string n) { nit = n; }
	void setDireccion(string dire) { direccion = dire; }
	void setTelefono(string tel) { telefono = tel; }
	//get (mostrar)

	int getidProveedores() { return idProveedores; }
	string getProveedor() { return proveedor; }
	string getNit() { return nit; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }



	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string idk = to_string(idProveedores);
			string insert = "INSERT INTO proveedores(proveedor, nit, direccion,telefono)VALUES('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso...." << endl;

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "------------------proveedores---------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "-" << fila[1] << "-" << fila[2] << "-" << fila[3] << "-" << fila[4] << "-" << fila[5] << endl;
				}

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}


	void actualizar() {

		int q_estado;
		string str_id, str_new, str_column;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string idk = to_string(idProveedores);
			cout << "ACTUALIZAR";
			string iupdate= "Update proveedores set" + str_column + " = '" + str_new + "' where idProvedores = " + str_id;

			if (!q_estado) {
				cout << "Ingreso Exitoso...." << endl;

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}


	void eliminar() {
		int q_estado;
		string elidat, elid;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
	
			string consulta = "delete from Proveedores where idProveedores=" + elid;
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "Ingrese el ID para eliminar: ";
				cin >> elid;
				cout << "------------------proveedores---------------" << endl;
			
			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}
};
