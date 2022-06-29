#ifndef TEST
#define TEST

#include <check.h>

#include "../main.h"

#define PRETTY_PRINT(str) (RED str CRESET)

Suite *suite_polish(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // TEST