#ifndef TEST
#define TEST

#include <check.h>

#include "../backend/smartcalc.h"
#include "colors.h"

#define PRETTY_PRINT(str) (RED str CRESET)

Suite *suite_polish(void);
Suite *suite_credit(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // TEST
