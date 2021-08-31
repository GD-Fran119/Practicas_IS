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
#include <cstdlib>


//This constructor is private and non-used
Ruta::Ruta(Date a, bool b, std::string mon, unsigned int m, std::string ID):fecha(a), bici(b), monitor(mon), max(m){
	// TODO Auto-generated constructor stub
	if(ID == "")
		id = generate_ID();
	else id = ID;


}

std::string Ruta::generate_ID(){
	std::string aux("qwertyuiopasdfghjklzxcvbnm1234567890"), ret("");
	for(int i = 0; i < 10; ++i)
		ret += aux[rand() % aux.size()];

	return ret;
}

bool Ruta::delete_Sendero(std::string aux){
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

