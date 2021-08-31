/*
 * Ruta.h
 *
 *  Created on: 18 ago. 2021
 *      Author: francisco
 */

#ifndef SRC_RUTA_H_
#define SRC_RUTA_H_
#include <list>
#include <string>
#include "Sendero.h"
#include "Visitante.h"
#include "Date.h"

class Ruta {
private:
	std::string id;
	Date fecha;
	std::list<std::string> lista_senderos;
	bool bici;
	std::string monitor;
	std::list<std::string> lista_visitantes;
	unsigned int cantidad, max;
public:
	static std::string generate_ID();
	Ruta(Date a, bool b, std::string mon, unsigned int m, std::string ID = "");
	inline const std::string get_ID(){return id;};
	inline Date const get_Fecha(){return fecha;};
	inline void set_Fecha(Date aux){fecha = aux;};
	inline bool get_Bici(){return bici;};
	inline void set_Cantidad(unsigned int new_cant) {max = new_cant;};
	inline void add_Sendero(std::string aux){lista_senderos.push_back(aux);};
	bool delete_Sendero(std::string aux);

	inline void add_Cliente(std::string DNI){lista_visitantes.push_back(DNI);};
	bool delete_Cliente(std::string DNI);

	virtual ~Ruta();
};

#endif /* SRC_RUTA_H_ */
