/*
 * login_tests.cpp
 *
 *  Created on: 24 ago. 2021
 *      Author: francisco
 */


#include "../src/Date.h"
#include "../src/login.h"
#include "../src/Monitor.h"
#include "../src/Administrativo.h"
#include "../cute/cute.h"
#include "../cute/ide_listener.h"
#include "../cute/xml_listener.h"
#include "../cute/cute_runner.h"
#include <string>

void test_check_credentials(){
	ASSERT(check_credentials("monitor", "pass", 1));
	ASSERT(not check_credentials("monitor", "arriba espana", 1));
	ASSERT(check_credentials("admin", "pass", 0));
	ASSERT(not check_credentials("monitor", "pass", 0));
}

void test_get_access(){
	Monitor aux("", "", "", "", "", Date(0,0,0), 0);
	aux = get_access_m("monitor");
	ASSERT(aux.getDNI() == "dni");

	aux = get_access_m("mon");
	ASSERT(aux.getDNI() == "");

	Administrativo aux2("", "", "", "", Date(0,0,0), 0);
	aux2 = get_access_a("admin");
	ASSERT(aux2.getDNI() == "dni");

	aux2 = get_access_a("administrativo");
	ASSERT(aux2.getDNI() == "");
}

bool runAllTest_login(int argc, const char **argv){
	cute::suite s {};
	s.push_back(CUTE(test_check_credentials));
	s.push_back(CUTE(test_get_access));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, const char **argv){
	return (runAllTest_login(argc, argv) ? 0 : 1);
}
