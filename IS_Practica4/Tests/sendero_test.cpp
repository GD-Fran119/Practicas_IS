
#include "../src/Sendero.h"
#include "../cute/cute.h"
#include "../cute/ide_listener.h"
#include "../cute/xml_listener.h"
#include "../cute/cute_runner.h"
#include <string>
#include <iostream>

void test_id(){

	Sendero send1(1, 1, 1, "", "", true);
	Sendero send2(1, 1, 1, "", "", true);
	Sendero send3(1, 1, 1, "", "", true);
	Sendero send4(1, 1, 1, "", "", true);
	Sendero send5(1, 1, 1, "", "", true);
	ASSERT(send1.get_ID() == 1);
	ASSERT(send1.get_ID() != send2.get_ID());
	ASSERT(send3.get_ID() != send2.get_ID());
	ASSERT(send3.get_ID() != send4.get_ID());
	ASSERT(send5.get_ID() != send4.get_ID());
	ASSERT(send5.get_ID() == 5);
}

bool runAllTest_Sendero(int argc, const char **argv){
	cute::suite s {};
	s.push_back(CUTE(test_id));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, const char **argv){
	return (runAllTest_Sendero(argc, argv) ? 0 : 1);
}
