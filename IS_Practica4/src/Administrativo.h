/*
 * Administrativo.h
 *
 *  Created on: 19 ago. 2021
 *      Author: francisco
 */

#ifndef SRC_ADMINISTRATIVO_H_
#define SRC_ADMINISTRATIVO_H_

#include <string>
#include <iostream>
#include "Date.h"

class Administrativo {
private:
	std::string Nombre_completo, DNI, email, Direccion;
	Date Fecha;
	unsigned int Telefono;


public:
	Administrativo(std::string Nombre_completo, std::string DNI, std::string email,
			std::string Direccion, Date fecha, unsigned int tel):
			Nombre_completo(Nombre_completo), DNI(DNI), email(email),
			Direccion(Direccion), Fecha(fecha), Telefono(tel){};
	void setInfo(std::string Nombre_completo, std::string DNI, std::string email,
			std::string Direccion, Date fecha, unsigned int tel);
	inline std::string getDNI(){return DNI;};
	inline void imprimeContacto(){
		std::cout << "Nombre: "+Nombre_completo +"\n";
		std::cout << "Telefono: "+std::to_string(Telefono) +"\n";
		std::cout << "Email: "+email+"\n";
	};


	virtual ~Administrativo();
};

#endif /* SRC_ADMINISTRATIVO_H_ */
