// Mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "proveedor.h" 
#include <mysql.h>
using namespace std;
int q_estado;
int main()
{	
	/*
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "1234", "db_empresa", 3306, NULL, 0);
	if (conectar) {
		
		string puesto;
		cout << "Ingrese Puesto: ";
		cin >> puesto;
		string insert = "insert into puestos(puesto) values('" + puesto + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso Exitoso...."<<endl;

		}

	else {
		cout << "Error en El ingreso ..." << endl;
	}

	string consulta = "select * from puesto";
	const char* c = consulta.c_str();
	q_estado = mysql_query(conectar, c);
	if (!q_estado) {
		resultado = mysql_store_result(conectar);
		while (fila = mysql_fetch_row(resultado)) {
			cout << fila[0]<<"-" << fila[1] << endl;
		}

	}

	else {
		cout << "Error en El ingreso ..." << endl;
	}
		}else {
		cout << "Error en la Conexion ..." << endl;
	}*/
	
	string proveedor,nit,direccion,telefono;
	int idProveedores;
	cout << "Ingrese nombre del proveedor: ";
	getline(cin, proveedor);
	cout << "Ingrese Nit;";
	getline(cin,nit);
	cout << "Ingrese direccion: ";
	getline(cin, direccion);
	cout << "Ingrese telefono: ";
	getline(cin, telefono);
	cin.ignore();
	




	Proveedor c = Proveedor(proveedor, nit, direccion, telefono);
c.Crear();
	c.leer();
	c.eliminar();
	c.actualizar();
	system("pause");
	return 0;
}
