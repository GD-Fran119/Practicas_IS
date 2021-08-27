
#include "../src/Date.h"
#include "../cute/cute.h"
#include "../cute/ide_listener.h"
#include "../cute/xml_listener.h"
#include "../cute/cute_runner.h"
#include "tests.h"

void test_Constructor(){

	Date f(29, 2, 4), f2(29, 2, 3), f3(32, 3, 0), f4(30, 6, 3221),
		 f5(0, 0, 0), f6(1, 7, 13), f7(15, 12, 2001);
	Date fecha(f);
	ASSERT(fecha == f);
	ASSERT(f.get_date_string() == "29/02/4");
	ASSERT(f2.get_date_string() == "01/01/0");
	ASSERT(f3.get_date_string() == "01/01/0");
	ASSERT(f4.get_date_string() == "30/06/3221");
	ASSERT(f5.get_date_string() == "01/01/0");
	ASSERT(f6.get_date_string() == "01/07/13");
	ASSERT(f7.get_date_string() == "15/12/2001");

}

void test_comparisons(){
	Date fecha1(1, 2, 3), fecha2(2, 2, 3), fecha3(2, 2, 3),
		 fecha4(1, 3, 3), fecha5(1, 1, 5);
	ASSERT(fecha1 < fecha2);
	ASSERT(fecha4 > fecha2);
	ASSERT(fecha5 > fecha1);
	ASSERT(fecha2 == fecha3);
	ASSERT(fecha3 >= fecha1);
	ASSERT(fecha2 > fecha1);
	ASSERT(fecha2 <= fecha3);
}

void test_get_string_format(){
	Date fecha1(1, 1, 1), fecha2(12, 12, 12);
	ASSERT(fecha1.get_date_string() == "01/01/1");
	ASSERT(fecha2.get_date_string() == "12/12/12");
}
