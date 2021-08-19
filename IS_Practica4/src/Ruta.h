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
	static int ID;
	int id;
	Date fecha;
	std::list<Sendero> lista_senderos;
	bool bici;
	std::string monitor;
	std::list<Visitante> lista_visitantes;
	unsigned int cantidad, max;
public:
	Ruta();
	inline const int get_ID(){return id;};
	inline Date const get_Fecha(){return fecha;};
	inline void set_Fecha(Date aux){fecha = aux;};
	inline bool get_Bici(){return bici;};
	inline void set_Cantidad(unsigned int new_cant) {max = new_cant;};
	inline void add_Sendero(Sendero aux){lista_senderos.push_back(aux);};
	bool delete_Sendero(Sendero aux);

	inline void add_Cliente(Visitante aux){lista_visitantes.push_back(aux);};
	bool delete_Cliente(Visitante aux);

	virtual ~Ruta();
};

#endif /* SRC_RUTA_H_ */
