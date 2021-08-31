/*
 * main.cpp
 *
 *  Created on: 30 ago. 2021
 *      Author: francisco
 */

#ifndef MAIN_CPP
#define MAIN_CPP

#include "login.h"
#include "Monitor.h"
#include "Administrativo.h"
#include "Date.h"
#include "Ruta.h"
#include "Parque.h"
#include "Sendero.h"
#include "Visitante.h"

#include "funciones.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>


//True == monitor
//False == administrativo
bool cargo;

Administrativo * admin;
Monitor * monitor;
std::string user;

int main(){
	srand(time(NULL));
	if(not login(user, cargo)){
		std::cout << "Fallo de login. Fin del programa\n";
		return 1;
	}
	std::cout << "Credenciales correctas\n\n";

	if(cargo){
		monitor = new Monitor(get_access_m(user));

		menu_monitor(user);


		delete monitor;
	}
	else
		std::cout << "Las funciones del administrativo no han sido implementadas. Fin del programa\n";

	return 0;
}

#endif
