/*
 * login.cpp
 *
 *  Created on: 24 ago. 2021
 *      Author: francisco
 */

#include "login.h"
#include "Monitor.h"
#include "Date.h"
#include "Administrativo.h"
#include <fstream>

bool check_credentials(std::string username, std::string password, bool monitor){
	std::string filename("");
	if(monitor)//looks into monitors' login folder
		filename += "./Monitor_logins/";

	else//looks into admins' login folder
		filename += "./Admin_logins/";

	filename += username+".txt";
	std::ifstream file(filename);

	bool ret_val = file.is_open();
	if(ret_val) {
		std::string pass;
		std::getline(file, pass, '\n');
		ret_val = (pass == password);
		file.close();
	}
	return ret_val;
}

Monitor get_access_m(std::string username){
	std::ifstream file("./Monitor_logins/"+username+".txt");
	std::string name, surnames, DNI, email, address;
	unsigned int day, month, year, tel;
	bool continues = file.is_open();

	if(continues) continues = (std::getline(file, name, '\n') ? true : false);//pass
	if(continues) continues = (std::getline(file, name, '\n') ? true : false);//name
	if(continues) continues = (std::getline(file, surnames, '\n') ? true : false);
	if(continues) continues = (std::getline(file, DNI, '\n') ? true : false);
	if(continues) continues = (std::getline(file, email, '\n') ? true : false);
	if(continues) continues = (std::getline(file, address, '\n') ? true : false);
	if(continues) continues = ((file >> day >> month >> year) ? true : false);
	if(continues) continues = ((file >> tel) ? true : false);

	if(not continues){//If file hadn't the correct format
		name = surnames = DNI = email = address = "";
		day = month = year = tel = 0;
	}
	return Monitor(name, surnames, DNI, email, address, Date(day, month, year),tel);
}

Administrativo get_access_a(std::string username){
	std::ifstream file("./Admin_logins/"+username+".txt");
	std::string name, DNI, email, address;
	unsigned int day, month, year, tel;
	bool continues = file.is_open();

	if(continues) continues = (std::getline(file, name, '\n') ? true : false);//pass
	if(continues) continues = (std::getline(file, name, '\n') ? true : false);//name
	if(continues) continues = (std::getline(file, DNI, '\n') ? true : false);
	if(continues) continues = (std::getline(file, email, '\n') ? true : false);
	if(continues) continues = (std::getline(file, address, '\n') ? true : false);
	if(continues) continues = ((file >> day >> month >> year) ? true : false);
	if(continues) continues = ((file >> tel) ? true : false);

	if(not continues){//If file hadn't the correct format
		name = DNI = email = address = "";
		day = month = year = tel = 0;
	}
	return Administrativo(name, DNI, email, address, Date(day, month, year),tel);
}
