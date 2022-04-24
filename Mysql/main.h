#pragma once
#include <iostream>
#include <mysql.h>
using namespace std;
class main {
	//atributos
protected: string proveedor, nit, direccion, telefono;
		 int idProveedores;


		 //constructor
protected:
	main() {

	}
	main(string pro, string n, string dire, string tel) {
		proveedor = pro;
		nit = n;
		direccion = dire;
		telefono = tel;
	

	}


};

