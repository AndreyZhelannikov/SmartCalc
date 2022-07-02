#include "cacl_test.h"

START_TEST(simple_test_1) {
    char input[] = "1+1=";
    double result = smart_calc(input);
    double expected = 2;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_2) {
    char input[] = "sin(1)";
    double result = smart_calc(input);
    double expected = 0.8414709848;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_3) {
    char input[] = "sin(cos(1+1))";
    double result = smart_calc(input);
    double expected = -0.4042391539;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_4) {
    char input[] = "";
    double result = smart_calc(input);
    double expected = 0;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_5) {
    char input[] = "";
    double result = smart_calc(input);
    double expected = 0;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_6) {
    char input[] = "";
    double result = smart_calc(input);
    double expected = 0;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_7) {
    char input[] = "";
    double result = smart_calc(input);
    double expected = 0;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_8) {
    char input[] = "";
    double result = smart_calc(input);
    double expected = 0;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_9) {
    char input[] = "";
    double result = smart_calc(input);
    double expected = 0;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_10) {
    char input[] = "";
    double result = smart_calc(input);
    double expected = 0;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

Suite *suite_polish(void) {
    Suite *s = suite_create(PRETTY_PRINT("polish"));
    TCase *tc = tcase_create("polish");

    tcase_add_test(tc, simple_test_1);
    tcase_add_test(tc, simple_test_2);
    tcase_add_test(tc, simple_test_3);
    tcase_add_test(tc, simple_test_4);
    tcase_add_test(tc, simple_test_5);
    tcase_add_test(tc, simple_test_6);
    tcase_add_test(tc, simple_test_7);
    tcase_add_test(tc, simple_test_8);
    tcase_add_test(tc, simple_test_9);
    tcase_add_test(tc, simple_test_10);

    suite_add_tcase(s, tc);
    return s;
}