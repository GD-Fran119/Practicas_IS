/*
 * Sendero.h
 *
 *  Created on: 9 ago. 2021
 *      Author: francisco
 */

#ifndef SRC_SENDERO_H_
#define SRC_SENDERO_H_

#include <string>

class Sendero {
private:
	static unsigned int ID;//Genera el id para el siguiente sendero
	/*
	state:
		1 - Abierto
		2 - Cerrado por mantenimiento
		3 - No disponible(el sendero, no la opcion)

	///////////////////////////
	dificulty:
		1 - Easy
		2 - Average
		3 - Hard
	*/
	int length, state, dificulty, id;//id del sendero
	std::string name, desc;
	bool bike;

public:
	Sendero(int length, int state, int dif, std::string name,
			std::string desc, bool bike);
	inline std::string const get_Nombre(){return name;};
	inline std::string const get_Desc(){return desc;};
	inline bool const get_Bici(){return bike;};
	void set_Info(int lenght, int state, int dif, std::string name,
			std::string desc, bool bike);
	inline int const get_ID(){return id;};
	inline int const get_estado(){return state;};
	inline int const get_Dificultad(){return dificulty;};
	inline int const get_Longitud(){return length;};
	void set_estado(int state);

	bool operator==(Sendero aux){return (this -> id == aux.get_ID());};

	virtual ~Sendero();
};

#endif /* SRC_SENDERO_H_ */
