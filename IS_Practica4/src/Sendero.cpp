/*
 * Sendero.cpp
 *
 *  Created on: 9 ago. 2021
 *      Author: francisco
 */

#include "Sendero.h"

unsigned int Sendero::ID = 0;

Sendero::Sendero(int length, int state, int dif, std::string name, std::string desc,
		bool bike):length(length), name(name), desc(desc), bike(bike){
	// TODO Auto-generated constructor stub
	if(state < 4 and state > 0) this -> state = state;
	else state = 3;

	if(dif < 4 and dif > 0) dificulty = dif;
	else dificulty = 1;

	id = ++ID;

}

void Sendero::set_Info(int lenght, int state, int dif, std::string name,
			std::string desc, bool bike){
	this -> length = length;

	if(state < 4 and state > 0) this -> state = state;
	if(dif < 4 and dif > 0) dificulty = dif;

	this -> name = name;
	this -> desc = desc;
	this -> bike = bike;
}

void Sendero::set_estado(int state){
	if(state < 4 and state > 0) this -> state = state;
}


Sendero::~Sendero() {
	// TODO Auto-generated destructor stub
}

