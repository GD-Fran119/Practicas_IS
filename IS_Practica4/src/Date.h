/*
 * Date.h
 *
 *  Created on: 8 ago. 2021
 *      Author: francisco
 */

#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include <string>

class Date {
private:
	unsigned int day, month, year;
public:
	//Habria que cambiarla a private, esta en public para pruebas;
	Date(unsigned int day = 1, unsigned int month = 1, unsigned int year = 0);
	bool check_date(unsigned int day, unsigned int month, unsigned int year);

	std::string const get_date_string(void);
	inline unsigned int const get_day()const{return day;};
	inline unsigned int const get_month()const{return month;};
	inline unsigned int const get_year()const{return year;};

	inline void set_date(Date const fecha){*this = fecha;};
	bool set_day(unsigned int const day);
	bool set_month(unsigned int const month);
	bool set_year(unsigned int const year);

	bool operator<(Date const &fecha);
	bool operator<=(Date const &fecha);
	bool operator>=(Date const &fecha);
	bool operator>(Date const &fecha);
	bool operator==(Date const &fecha);

	virtual ~Date();
};

#endif /* SRC_DATE_H_ */
