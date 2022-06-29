#include "cacl_test.h"

START_TEST(simple_test) {
    char input[] = "1+1=";
    double result = smart_calc(input);
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, 2, 1e-6);
}
END_TEST

Suite *suite_polish(void) {
    Suite *s = suite_create(PRETTY_PRINT("polish"));
    TCase *tc = tcase_create("polish");

    tcase_add_test(tc, simple_test);

    suite_add_tcase(s, tc);
    return s;
}