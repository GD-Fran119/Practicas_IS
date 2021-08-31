/*
 * funciones.cpp
 *
 *  Created on: 30 ago. 2021
 *      Author: francisco
 */

#include "login.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Ruta.h"
#include "funciones.h"

bool login(std::string &user, bool &cargo){
	bool correct = true;
	int counter = 3;
	std::string pass;
	do{
		std::cout << "Usuario: ";
		std::cin >> user;
		std::cout << "Password: ";
		std::cin >> pass;

		if(check_credentials(user, pass, 1)){
			correct = true;
			cargo = true; //Monitor
		}
		else if(check_credentials(user, pass, 0)){
			correct = true;
			cargo = false; //Administrativo
		}
		else{
			std::cout << "Credenciales incorrectas, le quedan " << --counter << " intentos\n\n";
			correct = false;
		}
	}while(counter > 0 and not correct);

	if(counter != 0) correct = true;

	return correct;

}

void print_menu_monitor(){
	std::cout << "<======================================>\nMenu:\n"
			  << "1.- Crear ruta\n"
			  << "2.- Modificar ruta (no implementado)\n"
			  << "3.- Borrar ruta (no implementado)\n"
			  << "Cualquier otra eleccion: exit\n"
			  << "Opcion: ";
}

bool print_senderos(std::vector<std::string> &senderos){
	std::ifstream file("./Parque/senderos.txt");
	if(not file.is_open()) return false;
	std::string aux;
	int index = 1;
	while(std::getline(file, aux, '\n')){
		std::cout << index++ << ".- " + aux + "\n";
		senderos.push_back(aux);
	}
	file.close();
	return true;
}

void save_ruta(std::string id, std::string monitor, std::string max, bool bici, std::string senderos, std::string day, std::string month,
		std::string year){
	std::ofstream file("./Rutas/" + id + ".txt");

	file << "m " + monitor +"\n";
	file << "M " + max + "\n";
	if(bici) file << "b\n";
	file << "s " + senderos + "\n";
	file << "f " + day + " " + month + " " + year + "\n";
	file << "v\n";

	file.close();
	std::cout << "Ruta " + id + " guardada\n";
}

bool create_ruta(std::string name){

	std::string senderos, senderos_names, date, day, month, year, max;
	char bicicleta;

	std::vector<std::string> senderos_v;

	if(not print_senderos(senderos_v)){
		std::cout << "Fichero donde se almacenan los IDs de los senderos no encontrado\n";
		return false;
	}

	auto rellena_senderos = [&]() -> bool{
		std::istringstream string(senderos);
		long unsigned index;
		while(string >> index){
			if(not string or index >= senderos_v.size()) return false;
			senderos_names += senderos_v[index-1] + " ";
		}
		return true;

	};
	auto rellena_date = [&]() -> bool{
		std::istringstream string(date);

		string >> day >> month >> year;

		if(not std::stoi(day) or not std::stoi(month) or not std::stoi (year)) return false;

		Date fecha(std::stoi(day), std::stoi(month), std::stoi(year));
		if(fecha.get_day() != std::stoi(day) or fecha.get_month() != std::stoi(month) or fecha.get_year() != std::stoi(year)) return false;

		return true;
	};

	try{
	std::cout << "\nElija los senderos por su numero y no por su nombre (separacion con espacios): ";
	std::getline(std::cin, senderos, '\n');

	if(not rellena_senderos())return false;

	std::cout << "\nElija la fecha (dd mm aaaa): ";
	std::getline(std::cin, date, '\n');
	if(not rellena_date())return false;

	std::cout << "\nElija el numero maximo de visitantes: ";
	std::cin >> max;
	if(not std::stoi(max)) return false;

	std::cin.ignore(1000, '\n');
	std::cout << "Apta para bici? (S/N): ";
	bicicleta = std::cin.get();
	std::cin.ignore(1000, '\n');
	}
	catch(...){return false;}

	save_ruta(Ruta::generate_ID(), name, max, bicicleta == 'S', senderos_names, day, month, year);
	std::cout << "Pulse \"Enter\" para continuar";
	std::cin.ignore(1000, '\n');




	return true;
}

void menu_monitor(const std::string name){
	bool exit = false;
	std::string opcion;
	int num_opt;
	while(not exit){
		print_menu_monitor();


		std::cin >> opcion;
		std::cin.ignore(1000, '\n');

		try{
			num_opt = std::stoi(opcion);
		}
		catch(...){num_opt = 0;}

		switch(num_opt){
		case 1:{
			bool aux = create_ruta(name);
			if(not aux)
				std::cout << "No se pudo crear la ruta\n";
		} break;
		case 2:{continue;} break;
		case 3:{continue;} break;
		default:{
			std::cout << "EXIT\n";
			exit = true;} break;
		}
	}
	std::cin.ignore(1000, '\n');
}

