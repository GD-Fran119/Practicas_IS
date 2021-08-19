/*
 * Monitor.cpp
 *
 *  Created on: 19 ago. 2021
 *      Author: francisco
 */

#include "Monitor.h"
#include <string>
#include "Date.h"

void Monitor::setInfo(std::string Nombre, std::string Apellidos, std::string DNI,
		std::string email, std::string Direccion, Date fecha, unsigned int tel){
	this -> Nombre = Nombre;
	this -> Apellidos = Apellidos;
	this -> DNI = DNI;
	this -> email = email;
	this -> Direccion = Direccion;
	this -> Fecha = fecha;
	this -> Telefono = tel;
}

Monitor::~Monitor() {
	// TODO Auto-generated destructor stub
}

