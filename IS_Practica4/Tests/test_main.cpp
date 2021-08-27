/*
 * test_main.cpp
 *
 *  Created on: 27 ago. 2021
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
#include "tests.h"



bool runAllTest_login(int argc, const char **argv){
	cute::suite s {};

	s.push_back(CUTE(test_Constructor));
	s.push_back(CUTE(test_comparisons));
	s.push_back(CUTE(test_get_string_format));

	s.push_back(CUTE(test_id));

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

