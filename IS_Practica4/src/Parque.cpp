/*
 * Parque.cpp
 *
 *  Created on: 8 ago. 2021
 *      Author: francisco
 */

#include <iostream>
#include "Parque.h"
#include "Date.h"
#include "Sendero.h"

Parque::Parque(std::string lt, std::string lc, std::string prov, std::string nam,
		int sur, Date dec, std::list<std::string> rec, std::list<Sendero> send):
		fecha_declaracion(dec){
	// TODO Auto-generated constructor stub
	location = lt;
	localidad = lc;
	provincia = prov;
	name = nam;
	surface = sur;
	reconocimientos = rec;
	senderos = send;
}


void Parque::print_Info(){
	std::cout << "Nombre: " << name << '\n';
	std::cout << "Superficie: " << surface << '\n';
	std::cout << "Ubicacion: " << location << '\n';
	std::cout << "Localidad: " << localidad << '\n';
	std::cout << "Provincia: " << provincia << '\n';
	std::cout << "Superficie: " << surface << '\n';
	std::cout << "Fecha de declaracion: " << fecha_declaracion.get_date_string() << '\n';

	std::cout << "Reconocimientos: ";
	for(auto aux : reconocimientos) std::cout << aux + " ";
	std::cout << '\n';

	std::cout << "Senderos: ";
	for(auto aux : senderos) std::cout << aux.get_Nombre() + " ";
	std::cout << '\n';

}


void Parque::set_Info(std::string lt, std::string lc, std::string prov, std::string nam,
			int sur, Date dec, std::list<std::string> rec, std::list<Sendero> send){
	location = lt;
	localidad = lc;
	provincia = prov;
	name = nam;
	surface = sur;
	fecha_declaracion = dec;
	reconocimientos = rec;
	senderos = send;
}

Parque::~Parque() {
	// TODO Auto-generated destructor stub
	senderos.clear();
	reconocimientos.clear();
}

