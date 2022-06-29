#include "cacl_test.h"

START_TEST(simple_test) {
}
END_TEST

Suite *suite_polish(void) {
    Suite *s = suite_create(PRETTY_PRINT("polish"));
    TCase *tc = tcase_create("polish");

    tcase_add_test(tc, simple_test);

    suite_add_tcase(s, tc);
    return s;
}