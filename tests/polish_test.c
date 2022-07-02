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
    char input[] = "2+2*2";
    double result = smart_calc(input);
    double expected = 6;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_5) {
    char input[] = "sin(1)^cos(1)";
    double result = smart_calc(input);
    double expected = 0.9109582586;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_6) {
    char input[] = "2 - 3";
    double result = smart_calc(input);
    double expected = -1;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_7) {
    char input[] = "atan(1.1)";
    double result = smart_calc(input);
    double expected = 0.8329812667;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_8) {
    char input[] = "acos(asin(0.7777))";
    double result = smart_calc(input);
    double expected = 0.4712559697;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_9) {
    char input[] = "ln(log(11))";
    double result = smart_calc(input);
    double expected = 0.04055893768;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_10) {
    char input[] = "tan(sqrt(4))";
    double result = smart_calc(input);
    double expected = -2.185039863;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_11) {
    char input[] = "3mod2*4mod4";
    double result = smart_calc(input);
    double expected = -2.185039863;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST
START_TEST(hard_test_1) {
    char input[] =
        "cos(tan( 2.0221 + tan( sin( cos( 5.0945 ) ) - tan(cos(3.6593))  ) ^1.4616 )  -sin(4.1949- sin( \
        cos(tan(tan( cos(3.8475 ) )  ) ) ^  8.8451) ^  1.4109) - tan( 2.6884/tan( 5.2519 / 6.5461 ) )  \
        )";
    double result = smart_calc(input);
    double expected = -0.8998910097532222;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(hard_test_2) {
    char input[] =
        "tan( 3.764) ^sin( 9.445-sin( 7.2889 /  8.0438 -cos( sin(cos( tan(8.4448))) - 4.482)  )  / \
        tan(cos(cos(sin(cos( cos(2.003)) )  ) / 0.1315) ))  -  8.8453/ 0.3612";
    double result = smart_calc(input);
    double expected = -23.76667454586336;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(hard_test_3) {
    char input[] =
        "tan(sin(cos( 8.8905 )-9.586)) / tan(9.6334 ) -sin(4.091-  6.8317 ^1.3065 ) +sin(tan( 2.4431 +  \
        7.5867 )^ sin(sin(  6.6115^3.7525) / tan(sin( tan( tan(7.1462)  ) ) /sin( 2.7571)  )  ) )";
    double result = smart_calc(input);
    double expected = 7.167106761528132;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(hard_test_4) {
    char input[] =
        "2.4474 /8.0162/ 3.2142+tan( 0.6211 +sin(tan( 7.5952 +5.3702) ) - 4.7121^sin(  1.9427- 2.8496) ) \
        /cos(0.2688 ^0.5391+cos( tan(cos( cos(  5.6221 ))  ) /sin( 2.3295)  -tan( cos(tan( cos(9.2239)  ))  \
        ) ) )";
    double result = smart_calc(input);
    double expected = 1.660108415837855;
    printf("RESULT : %lf\n", result);
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(hard_test_5) {
    char input[] =
        "tan( 8.6522mod 7.1058 ^ 6.703 -cos( sin(  1.7839 )^tan( 4.0966 ) ^cos(  8.6763 /cos( 3.3663 )  ) ) \
        )/ 5.1847mod 4.8945+  6.9743";
    double result = smart_calc(input);
    double expected = 11.093553257739487;
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
    tcase_add_test(tc, simple_test_11);

    tcase_add_test(tc, hard_test_1);
    tcase_add_test(tc, hard_test_2);
    tcase_add_test(tc, hard_test_3);
    tcase_add_test(tc, hard_test_4);
    // tcase_add_test(tc, hard_test_5);

    suite_add_tcase(s, tc);
    return s;
}