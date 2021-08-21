/*
 * Ruta.cpp
 *
 *  Created on: 18 ago. 2021
 *      Author: francisco
 */

#include "Ruta.h"
#include <list>
#include <string>
#include <iterator>

int Ruta::ID = 0;

Ruta::Ruta() {
	// TODO Auto-generated constructor stub

}

bool Ruta::delete_Sendero(Sendero aux){
	auto iterador = lista_senderos.begin();
	bool ret = false;
	for(; iterador != lista_senderos.end() and not ret; iterador++)
		if(ret = (*iterador == aux))
			lista_senderos.erase(iterador);

	return ret;
}
bool Ruta::delete_Cliente(std::string DNI){
	auto iterador = lista_visitantes.begin();
	bool ret = false;
	for(; iterador != lista_visitantes.end() and not ret; iterador++)
		if(ret = (*iterador == DNI))
			lista_visitantes.erase(iterador);

	return ret;
}

Ruta::~Ruta() {
	// TODO Auto-generated destructor stub
}

