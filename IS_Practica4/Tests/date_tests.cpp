#include "../src/Date.h"
#include "../cute/cute.h"
#include "../cute/ide_listener.h"
#include "../cute/xml_listener.h"
#include "../cute/cute_runner.h"

void test_Constructor(){

	Date f(29, 2, 4), f2(29, 2, 3), f3(32, 3, 0), f4(30, 6, 3221),
		 f5(0, 0, 0), f6(1, 7, 13), f7(15, 12, 2001);
	ASSERT(f.get_date_string() == "29/02/4");
	ASSERT(f2.get_date_string() == "01/01/0");
	ASSERT(f3.get_date_string() == "01/01/0");
	ASSERT(f4.get_date_string() == "30/06/3221");
	ASSERT(f5.get_date_string() == "01/01/0");
	ASSERT(f6.get_date_string() == "01/07/13");
	ASSERT(f7.get_date_string() == "15/12/2001");

}

bool runAllTest(int argc, const char **argv){
	cute::suite s {};
	s.push_back(CUTE(test_Constructor));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, const char **argv){
	return (runAllTest(argc, argv) ? 0 : 1);
}
