/*
 * Monitor.h
 *
 *  Created on: 19 ago. 2021
 *      Author: francisco
 */

#ifndef SRC_MONITOR_H_
#define SRC_MONITOR_H_

#include <string>
#include <iostream>
#include "Date.h"

class Monitor {
private:
	std::string Nombre, Apellidos, DNI, email, Direccion;
	Date Fecha;
	unsigned int Telefono;

public:
	Monitor(std::string Nombre, std::string Apellidos_, std::string DNI, std::string email,
			std::string Direccion, Date fecha, unsigned int tel):
			Nombre(Nombre), Apellidos(Apellidos_), DNI(DNI), email(email),
			Direccion(Direccion), Fecha(fecha), Telefono(tel){};

	void setInfo(std::string Nombre, std::string Apellidos, std::string DNI, std::string email,
				std::string Direccion, Date fecha, unsigned int tel);

	inline std::string getDNI(){return DNI;};

	inline void imprimeContacto(){
		std::cout << "Nombre: "+Nombre+" "+Apellidos +"\n";
		std::cout << "Telefono: "+std::to_string(Telefono) +"\n";
		std::cout << "Email: "+email+"\n";
	};

	virtual ~Monitor();
};

#endif /* SRC_MONITOR_H_ */
