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
	/*
	state:
		1 - Abierto
		2 - Cerrado por mantenimiento
		3 - El sendero no esta disponible

	///////////////////////////
	dificulty:
		1 - Easy
		2 - Average
		3 - Hard
	*/
	int length, state, dificulty;
	std::string name, desc; //El identificador del sendero es el nombre
	bool bike;

public:
	Sendero(int length, int state, int dif, std::string name,
			std::string desc, bool bike);

	inline std::string const get_Nombre(){return name;};
	inline std::string const get_Desc(){return desc;};
	inline bool const get_Bici(){return bike;};

	void set_Info(int lenght, int state, int dif, std::string name,
			std::string desc, bool bike);

	inline std::string const get_estado(){
		switch (state){
		case 1: {return std::string("abierto");}break;
		case 2: {return std::string("cerrado por mantenimiento");}break;
		case 3: {return std::string("no disponible");}break;
		default: return "";
		}
	};

	inline std::string const get_Dificultad(){
		switch (dificulty){
				case 1: {return std::string("facil");}break;
				case 2: {return std::string("medio");}break;
				case 3: {return std::string("dificil");}break;
				default: return "";
				}
	};

	inline int const get_Longitud(){return length;};

	void set_estado(int state);

	bool operator==(Sendero aux){return (this -> name == aux.get_Nombre());};

	virtual ~Sendero();
};

#endif /* SRC_SENDERO_H_ */
