/*
 * Date.cpp
 *
 *  Created on: 8 ago. 2021
 *      Author: francisco
 */

#include "Date.h"
#include <string>

	Date::Date(unsigned int day, unsigned int month, unsigned int year) {
		if(check_date(day, month, year)){
			this -> day = day;
			this -> month = month;
			this -> year = year;
		}
		else{
			this -> day = 1;
			this -> month = 1;
			this -> year = 0;
		}
	}

	bool Date::check_date(unsigned int day, unsigned int month, unsigned int year){

		if (month > 12 or month == 0 or day == 0) return false;

		//1 febrero
		//2 30 dias
		//3 31 dias

		auto option = [&](void) -> int{

			if(month == 2) return 1;

			else if(month == 4 or month == 6 or month == 11 or month == 9) return 2;

			return 3;
		};

		unsigned int num_dias;

		switch(option()){
			case 1:{
				num_dias = ((year % 4 == 0) ? 29 : 28);
			}break;

			case 2:{
				num_dias = 30;
			}break;

			default:{
				num_dias = 31;
			}break;
		}

		return (day <= num_dias);
	}

	std::string const Date::get_date_string(void){
		std::string fecha("");

		if(day < 10) fecha += "0";

		fecha += std::to_string(day) + "/";

		if(month < 10) fecha += "0";

		fecha += std::to_string(month) + "/" + std::to_string(year);

		return fecha;
	}

	bool Date::set_day(unsigned int const day){
		bool dev = check_date(day, month, year);

		if(dev) this -> day = day;

		return dev;
	}

	bool Date::set_month(unsigned int const month){
		bool dev = check_date(day, month, year);

		if(dev) this -> month = month;

		return dev;
	}

	bool Date::set_year(unsigned int const year){
		bool dev = check_date(day, month, year);

		if(dev) this -> year = year;

		return dev;
	}

	bool Date::operator<(Date const &fecha){

		bool dev = true;

		if(this -> year > fecha.get_year()) dev = false;

		else if(this -> year == fecha.get_year() and
				this -> month > fecha.get_month()) dev = false;

		else if(this -> year == fecha.get_year() and
				this -> month == fecha.get_month() and
				this -> day >= fecha.get_day()) dev = false;

		return dev;
	}

	bool Date::operator<=(Date const &fecha){

		bool dev = ((*this) == fecha or (*this) < fecha);

		return dev;
	}

	bool Date::operator>=(Date const &fecha){

		bool dev = ((*this) == fecha or (*this) > fecha);

		return dev;
	}
	bool Date::operator>(Date const &fecha){

		bool dev = true;

		if(this -> year < fecha.get_year()) dev = false;

		else if(this -> year == fecha.get_year() and
				this -> month < fecha.get_month()) dev = false;

		else if(this -> year == fecha.get_year() and
				this -> month == fecha.get_month() and
				this -> day <= fecha.get_day()) dev = false;

		return dev;
	}
	bool Date::operator==(Date const &fecha){

		return (this -> year == fecha.get_year() and
				this -> month == fecha.get_month() and
				this -> day == fecha.get_day());
	}

Date::~Date() {
	// TODO Auto-generated destructor stub
	//No se codifica porque no hay nada que
	//hacer(p.e. memoria que liberar tras un new)
}

