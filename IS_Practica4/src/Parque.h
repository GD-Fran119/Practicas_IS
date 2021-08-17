/*
 * Parque.h
 *
 *  Created on: 8 ago. 2021
 *      Author: francisco
 */

#ifndef SRC_PARQUE_H_
#define SRC_PARQUE_H_
#include "Date.h"
#include "Sendero.h"
#include <string>
#include <list>

class Parque {
private:
	std::string location, localidad, provincia, name;
	int surface;
	std::list<std::string> reconocimientos;
	Date fecha_declaracion;
	std::list<Sendero> senderos;

public:
	Parque(std::string lt, std::string lc, std::string prov, std::string nam,
			int sur, Date dec, std::list<std::string> rec, std::list<Sendero> send);
	void print_Info();
	inline std::list<std::string> get_Senderos(){return senderos;};
	void set_Info(std::string lt, std::string lc, std::string prov, std::string nam,
			int sur, Date dec, std::list<std::string> rec, std::list<Sendero> send);
	inline std::string get_Nombre(){return name;};
	virtual ~Parque();
};

#endif /* SRC_PARQUE_H_ */
