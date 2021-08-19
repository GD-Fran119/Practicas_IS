/*
 * Visitante.cpp
 *
 *  Created on: 18 ago. 2021
 *      Author: francisco
 */

#include "Visitante.h"

Visitante::Visitante(std::string nam, std::string DNI_, std::string req,
		unsigned int tel_,
		Date birth) {
	// TODO Auto-generated constructor stub
	name = nam;
	DNI = DNI_;
	requirements = req;
	tel = tel_;
	birthday = birth;
}

void Visitante::setInfo(std::string nam, std::string DNI_, std::string req,
			unsigned int tel_,
			Date birth){
	name = nam;
		DNI = DNI_;
		requirements = req;
		tel = tel_;
		birthday = birth;
}

Visitante::~Visitante() {
	// TODO Auto-generated destructor stub
	list_rutas.clear();
}

