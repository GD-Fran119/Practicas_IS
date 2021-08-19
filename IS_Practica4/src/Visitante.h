/*
 * Visitante.h
 *
 *  Created on: 18 ago. 2021
 *      Author: francisco
 */

#ifndef SRC_VISITANTE_H_
#define SRC_VISITANTE_H_

#include <string>
#include <list>
#include "Date.h"
#include "Ruta.h"

class Visitante {
private:
	std::list<Ruta> list_rutas;
	std::string name, DNI, requirements;
	unsigned int tel;
	Date birthday;
public:
	Visitante(std::string nam, std::string DNI_, std::string req,
	unsigned int tel_, Date birth);

	void setInfo(std::string nam, std::string DNI_, std::string req,
			unsigned int tel_, Date birth);

	inline std::list<Ruta> get_list()const{return list_rutas;};

	inline std::string get_DNI()const{return DNI;};

	inline void anade_ruta(Ruta id){list_rutas.push_back(id);};

	bool operator==(Visitante aux){return (this->DNI == aux.get_DNI());};
	virtual ~Visitante();


};

#endif /* SRC_VISITANTE_H_ */
