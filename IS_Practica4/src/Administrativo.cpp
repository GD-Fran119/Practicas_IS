/*
 * Administrativo.cpp
 *
 *  Created on: 19 ago. 2021
 *      Author: francisco
 */

#include "Administrativo.h"
#include <string>
#include "Date.h"

void Administrativo::setInfo(std::string Nombre_completo, std::string DNI,
		std::string email, std::string Direccion, Date fecha, unsigned int tel){
	this -> Nombre_completo = Nombre_completo;
	this -> DNI = DNI;
	this -> email = email;
	this ->Direccion = Direccion;
	this -> Fecha = fecha;
	this -> Telefono = tel;

}

Administrativo::~Administrativo() {
	// TODO Auto-generated destructor stub
}

