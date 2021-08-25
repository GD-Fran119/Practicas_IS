/*
 * login.h
 *
 *  Created on: 24 ago. 2021
 *      Author: francisco
 */

#ifndef SRC_LOGIN_H_
#define SRC_LOGIN_H_
#include <string>
#include "Monitor.h"
#include "Administrativo.h"
#include "Date.h"

bool check_credentials(std::string username, std::string password, bool monitor);

/*
	This function returns the data of the monitor "username"
	The credentials of "username" must be valid, if not this function
	returns a default monitor as an error:
	Name, surnames, DNI, email and address are void strings ("")
	Date is 1/1/0
	Telephone is 0
*/
Monitor get_access_m(std::string username);
Administrativo get_access_a(std::string username);


#endif /* SRC_LOGIN_H_ */
